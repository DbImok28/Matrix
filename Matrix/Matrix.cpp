#include <iostream>
#include <string>

class Matrix
{
public:
	int columns;
	int lines;
	int* data;

	Matrix(int lines, int columns)
	{
		this->columns = columns;
		this->lines = lines;

		data = new int[columns * lines];
	}
	~Matrix()
	{
		delete[] data;
	}

	Matrix(const Matrix& mat)
	{
		columns = mat.columns;
		lines = mat.lines;
		data = new int[columns * lines];

		for (int i = 0; i < columns * lines; i++)
		{
			data[i] = mat.data[i];
		}
	}
	Matrix& operator=(const Matrix& mat)
	{
		columns = mat.columns;
		lines = mat.lines;
		data = new int[columns * lines];

		for (int i = 0; i < columns * lines; i++)
		{
			data[i] = mat.data[i];
		}
	}

	bool isQuad()
	{
		return lines == columns;
	}

	int getAt(int line, int column)
	{
		return data[(lines - 1) * line + column];
	}
	void setAt(int line, int column, int newData)
	{
		data[(lines - 1) * line + column] = newData;
	}
	Matrix operator+(Matrix mat)
	{
		Matrix result(lines, columns);
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				result.setAt(i, j, getAt(i, j) + mat.getAt(i, j));
			}
		}
		return result;
	}
	Matrix operator-(Matrix mat)
	{
		Matrix result(lines, columns);
		for (int i = 0; i < columns * lines; i++)
		{
			result.data[i] = data[i] - mat.data[i];
		}
		return result;
	}
	Matrix operator*(Matrix mat)
	{
		// cij = ... + ain · bnj
		Matrix result(lines, mat.columns);
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < mat.columns; j++)
			{
				int sum;
				sum = 0;
				for (int n = 0; n < columns; n++)
				{
					sum += getAt(i, n) * mat.getAt(n, j);
				}
				result.setAt(i, j, sum);
			}
		}
		return result;
	}
	
	void transpose()
	{
		int temp;
		if (isQuad())
		{
			for (int i = 0; i < lines / 2; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					temp = getAt(i, j);
					setAt(i, j, getAt(j, i));
					setAt(j, i, temp);
				}
			}
		}
		else
		{
			int* mat = new int[columns * lines];

			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					mat[lines * j + i] = getAt(i, j);
				}
			}
			delete[] data;

			temp = lines;
			lines = columns;
			columns = temp;

			data = mat;
		}
	}

	void print()
	{
		std::cout << '(';
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				std::cout << getAt(i, j);
				if (j != columns - 1)
					std::cout << ',';
			}
			if (i != lines - 1)
				std::cout << std::endl << ' ';
		}
		std::cout << ')' << std::endl;
	}
};

int main()
{
	Matrix m1(1, 2);
	m1.setAt(0, 0, 2);
	m1.setAt(0, 1, 3);
	//m1.setAt(1, 0, 5);
	//m1.setAt(1, 1, 4);
	m1.print();

	Matrix m2(2, 2);
	m2.setAt(0, 0, 6);
	m2.setAt(0, 1, 1);
	m2.setAt(1, 0, 9);
	m2.setAt(1, 1, 9);
	m2.print();

	auto m3 = m1 * m2;
	m3.print();

	m1.transpose();
	m1.print();
}