// 1 Спосіб --- "Ітераційний"
#include <iostream>
#include <Windows.h>
#include <iomanip>

void matriz_create(int** matriz, const int line, const int column, const int Low, const int High);
void matriz_print(int** matriz, const int line, const int column);
int min_max(int** matriz, const int line, const int column);
void matriz_print1(int* matriz, const int line);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	using std::cout;
	using std::endl;
	using std::cin;

	int line;
	int column;

	cout << "Задайте розмір матриці: " << endl;
	cout << endl;
	cout << "Кількість рядків: ";
	cin >> line;
	cout << endl;
	cout << "Кількість стовпців: ";
	cin >> column;
	cout << endl;

	int** matriz = new int* [line];
	for (int index = 0; index < line; index++)
		matriz[index] = new int[column];

	int High = 40;
	int Low = -40;
	matriz_create(matriz, line, column, Low, High);
	cout << "Сформований масив: " << endl;
	matriz_print(matriz, line, column);

	int min = min_max(matriz, line, column);
	cout << "Найменший з максимальних елементів по всіх рядках матриці (4x4) становить: " << min << endl;

	return 0;
}

void matriz_create(int** matriz, const int line, const int column, const int Low, const int High)
{
	for (int index = 0; index < line; index++)
		for (int index_j = 0; index_j < column; index_j++)
			matriz[index][index_j] = Low + rand() % (High - Low + 1);
}

void matriz_print(int** matriz, const int line, const int column)
{
	using std::cout;
	using std::endl;
	cout << endl;
	for (int index = 0; index < line; index++)
	{
		for (int index_j = 0; index_j < column; index_j++)
			cout << std::setw(4) << matriz[index][index_j];
		cout << endl;
	}
	cout << endl;
}


int min_max(int** matriz, const int line, const int column)
{
	using std::cout;
	using std::endl;
	int* max = new int[line];
	for (int i = 0; i < line; i++)
	{
		max[i] = matriz[i][0];
		for (int j = 1; j < column; j++)
			if (matriz[i][j] > max[i])
				max[i] = matriz[i][j];
	}

	cout << "Сформований масив: " << endl;
	cout << std::endl;
	matriz_print1(max, line);

	int min = max[0];
	for (int i = 1; i < line; i++)
		if (max[i] < min)
			min = max[i];
	delete[] max;
	return min;
}

void matriz_print1(int* matriz, const int line)
{
	using std::cout;
	using std::endl;
	for (int index = 0; index < line; index++)
		std::cout << std::setw(5) << matriz[index];
	cout << endl;
	cout << endl;
}