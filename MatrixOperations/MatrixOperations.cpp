#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	std::cout << "Hello World!\n";

	std::vector<std::vector<double>> matrixData1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	std::vector<std::vector<double>> matrixData2 = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };

	Matrix<double> matrix1(matrixData1);
	Matrix<double> matrix2(matrixData2);

	Matrix<double> additionResult = matrix1.add(matrix2);
	std::cout << matrix1.toString() << " \n+\n\n " << matrix2.toString() << std::endl;
	std::cout << "Result:\n" << additionResult.toString();

	std::cout << "\n---------\n\n";

	Matrix<double> subtractionResult = matrix1.subtract(matrix2);
	std::cout << matrix1.toString() << " \n-\n\n " << matrix2.toString() << std::endl;
	std::cout << "Result:\n" << subtractionResult.toString();

	std::cout << "\n---------\n\n";

	Matrix<double> multiplicationResult = matrix1.multiply(matrix2);
	std::cout << matrix1.toString() << " \n*\n\n " << matrix2.toString() << std::endl;
	std::cout << "Result:\n" << multiplicationResult.toString();

	std::cout << "\n---------\n\n";

	Matrix<double> overloadAddResult = matrix1 + 1;
	std::cout << matrix1.toString() << " \n+\n\n 1\n";
	std::cout << "Result:" << std::endl << overloadAddResult.toString();

	return 0;
}

#endif // MATRIX_H