#pragma once
#include <iostream>
#include <vector>

template<typename T>
class Matrix
{
private:
	std::vector<std::vector<T>> _internalMatrix;

public:
	Matrix(T defaultValue, int cols, int rows);
	Matrix(std::vector<std::vector<T>> inputMatrix) : _internalMatrix(inputMatrix) {}
	~Matrix();

	std::vector<std::vector<T>> getMatrix() const;
	void setMatrix(std::vector<std::vector<T>> inputMatrix);

	Matrix<T> operator+(const int num) const;
	Matrix<T> add(const std::vector<std::vector<T>>& other) const;
	Matrix<T> add(const Matrix<T>& other) const;

	Matrix<T> operator-(const int num) const;
	Matrix<T> subtract(const std::vector<std::vector<T>>& other) const;
	Matrix<T> subtract(const Matrix<T>& other) const;

	Matrix<T> operator*(const int num) const;
	Matrix<T> multiply(const std::vector<std::vector<T>>& other) const;
	Matrix<T> multiply(const Matrix<T>& other) const;
	
	std::string toString() const;
};

