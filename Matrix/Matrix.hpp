#pragma once

class Matrix
{
public:
	int columns;
	int lines;
	float* data;

	Matrix(int lines, int columns);
	~Matrix();
	Matrix(const Matrix& mat);
	Matrix& operator=(const Matrix& mat);
	bool isQuad();
	float getAt(int line, int column);
	void setAt(int line, int column, float newData);
	Matrix operator+(Matrix mat);
	Matrix operator-(Matrix mat);
	Matrix operator*(Matrix mat);
	Matrix operator*(float value);
	Matrix pow(int value);
	Matrix transpose();
	Matrix attached();
	Matrix inverse();
	void makeTranspose();
	float minor(int line, int column);
	float det();
	void print();
};