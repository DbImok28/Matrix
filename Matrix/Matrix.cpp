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
	


	int getAt(int line, int column)
	{
		return data[columns * column + line];
	}
	void setAt(int line, int column, int newData)
	{
		data[columns * column + line] = newData;
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
	// cij = ... + ain · bnj
	Matrix operator*(Matrix mat)
	{
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

	

	void print()
	{
		std::cout << '(';
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				std::cout << getAt(i, j) << " ";	
			}
			std::cout << std::endl;
		}
		std::cout <<')'<< std::endl;
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
	//auto m4 = m2 * m1;

	m3.print();
	//m4.print();
}