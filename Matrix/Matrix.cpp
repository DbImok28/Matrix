#include <iostream>
#include <string>
#include "Matrix.hpp"

Matrix::Matrix(int lines, int columns)
{
	this->columns = columns;
	this->lines = lines;

	data = new float[columns * lines];
}
Matrix::~Matrix()
{
	delete[] data;
}

Matrix::Matrix(const Matrix& mat)
{
	columns = mat.columns;
	lines = mat.lines;
	data = new float[columns * lines];

	for (int i = 0; i < columns * lines; i++)
	{
		data[i] = mat.data[i];
	}
}
Matrix& Matrix::operator=(const Matrix& mat)
{
	columns = mat.columns;
	lines = mat.lines;
	data = new float[columns * lines];

	for (int i = 0; i < columns * lines; i++)
	{
		data[i] = mat.data[i];
	}
}

bool Matrix::isQuad()
{
	return lines == columns;
}

float Matrix::getAt(int line, int column)
{
	return data[(columns)*line + column];
}
void Matrix::setAt(int line, int column, float newData)
{
	data[(columns)*line + column] = newData;
}
Matrix Matrix::operator+(Matrix mat)
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
Matrix Matrix::operator-(Matrix mat)
{
	Matrix result(lines, columns);
	for (int i = 0; i < columns * lines; i++)
	{
		result.data[i] = data[i] - mat.data[i];
	}
	return result;
}
Matrix Matrix::operator*(Matrix mat)
{
	// cij = ... + ain · bnj
	Matrix result(lines, mat.columns);
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < mat.columns; j++)
		{
			float sum;
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
Matrix Matrix::operator*(float value)
{
	Matrix result(lines, columns);
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			result.setAt(i, j, getAt(i, j) * value);
		}
	}
	return result;
}

Matrix Matrix::pow(int value)
{
	if (value != 1)
		return *this * pow(value - 1);
	else
		return *this;
}
void Matrix::makeTranspose()
{
	float* mat = new float[columns * lines];
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//std::cout << "{["<< (lines) * j + i <<"]<- "<< getAt(i, j)<<"}" << std::endl;
			mat[(lines)*j + i] = getAt(i, j);
		}
	}
	int temp = lines;
	lines = columns;
	columns = temp;

	delete[] data;
	data = mat;
}
Matrix Matrix::transpose()
{
	Matrix result(columns, lines);
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			result.setAt(j, i, getAt(i, j));
		}
	}
	return result;
}
float Matrix::minor(int line, int column)
{
	if (isQuad())
	{
		Matrix result(lines - 1, columns - 1);

		for (int i = 0, lof = 0; i < lines; i++)
		{
			if (i != line)
			{
				for (int j = 0, cof = 0; j < columns; j++)
				{
					if (column != j)
						result.setAt(i - lof, j - cof, getAt(i, j));
					else
						cof = 1;
				}
			}
			else
				lof = 1;
		}

		return powf(-1, line + column) * result.det();
	}
}
float Matrix::det()
{
	if (isQuad())
	{
		if (lines > 2)
		{
			float sum = 0;
			for (int j = 0; j < columns; j++)
			{
				sum += getAt(0, j) * minor(0, j);
			}
			return sum;
		}
		else if (lines == 2)
			return getAt(0, 0) * getAt(1, 1) - getAt(1, 0) * getAt(0, 1);
		else if (lines == 1)
			return getAt(0, 0);
	}
}
Matrix Matrix::attached()
{
	Matrix result(lines, columns);
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			result.setAt(i, j, minor(i, j));
	return result;
}
Matrix Matrix::inverse()
{
	return attached().transpose() * (1 / det());
}
void Matrix::print()
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << '[' << getAt(i, j) << ']';
		}
		std::cout << std::endl;
	}
}