#include "Matrix.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip> 

template<typename T>
Matrix<T>::Matrix(T defaultValue, int cols, int rows)
{
	_internalMatrix = std::vector<std::vector<T>>(rows, std::vector<T>(cols, defaultValue));
}

template<typename T>
Matrix<T>::~Matrix()
{

}

template<typename T>
std::vector<std::vector<T>> Matrix<T>::getMatrix() const
{
	return _internalMatrix;
}

template<typename T>
void Matrix<T>::setMatrix(std::vector<std::vector<T>> inputMatrix)
{
	_internalMatrix = inputMatrix;
}

template<typename T>
std::string Matrix<T>::toString() const
{
	std::stringstream sStream;

	int rows = _internalMatrix.size();
	int cols = _internalMatrix[0].size();

	for (size_t i = 0; i < rows; i++)
	{
		sStream << "|";

		for (size_t j = 0; j < cols; j++)
		{
			sStream << std::setw(4) << _internalMatrix[j][i] << " ";
		}

		sStream << "|" << std::endl;
	}

	return sStream.str();
}

template<typename T>
Matrix<T> Matrix<T>::add(const Matrix<T>& other) const
{
	return add(other.getMatrix());
}

template<typename T>
Matrix<T> Matrix<T>::add(const std::vector<std::vector<T>>& other) const
{
	std::vector<std::vector<T>> result(_internalMatrix.size(), std::vector<T>(_internalMatrix[0].size()));

	if (_internalMatrix.size() != other.size() || _internalMatrix[0].size() != other[0].size())
	{
		std::cout << "Error: Matrices must have the same dimensions for addition." << std::endl;
		return Matrix(result);
	}

	for (size_t i = 0; i < _internalMatrix.size(); i++)
	{
		for (size_t j = 0; j < _internalMatrix[0].size(); j++)
		{
			result[i][j] = _internalMatrix[i][j] + other[i][j];
		}
	}

	return Matrix(result);
}

template<typename T>
Matrix<T> Matrix<T>::subtract(const Matrix<T>& other) const
{
	return subtract(other.getMatrix());
}

template<typename T>
Matrix<T> Matrix<T>::subtract(const std::vector<std::vector<T>>& other) const
{
	std::vector<std::vector<T>> result(_internalMatrix.size(), std::vector<T>(_internalMatrix[0].size()));

	if (_internalMatrix.size() != other.size() || _internalMatrix[0].size() != other[0].size())
	{
		std::cout << "Error: Matrices must have the same dimensions for subtraction." << std::endl;
		return Matrix(result);
	}

	for (size_t i = 0; i < _internalMatrix.size(); i++)
	{
		for (size_t j = 0; j < _internalMatrix[0].size(); j++)
		{
			result[i][j] = _internalMatrix[i][j] - other[i][j];
		}
	}

	return Matrix(result);
}

template<typename T>
Matrix<T> Matrix<T>::multiply(const Matrix<T>& other) const
{
	return multiply(other.getMatrix());
}

template<typename T>
Matrix<T> Matrix<T>::multiply(const std::vector<std::vector<T>>& other) const
{
	std::vector<std::vector<T>> result(_internalMatrix.size(), std::vector<T>(other[0].size()));

	if (_internalMatrix[0].size() != other.size())
	{
		std::cout << "Error: The number of columns in the first matrix must match the number of rows in the second matrix for multiplication." << std::endl;
		return Matrix(result);
	}

	for (size_t i = 0; i < _internalMatrix.size(); i++)
	{
		for (size_t j = 0; j < other[0].size(); j++)
		{
			T sum = 0;
			for (size_t k = 0; k < _internalMatrix[0].size(); k++)
			{
				sum += _internalMatrix[k][i] * other[j][k];
			}

			result[j][i] = sum;
		}
	}

	return Matrix(result);
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const int num) const
{
	Matrix<T> operatorMatrix = Matrix<T>(num, _internalMatrix[0].size(), _internalMatrix.size());
	
	return add(operatorMatrix);
}


template<typename T>
Matrix<T> Matrix<T>::operator-(const int num) const
{
	Matrix<T> operatorMatrix = Matrix<T>(num, _internalMatrix[0].size(), _internalMatrix.size());

	return subtract(operatorMatrix);
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const int num) const
{
	Matrix<T> operatorMatrix = Matrix<T>(num, _internalMatrix[0].size(), _internalMatrix.size());

	return multiply(operatorMatrix);
}

template class Matrix<int>;
template class Matrix<double>;
