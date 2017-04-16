// IDZ_F_11.cpp: определяет точку входа для консольного приложения.

// Написать программу и в ней функцию, вычисляющую страховой тариф на автомобиль. 
// Cтраховой тариф составляет 7% от стоимости автомобиля и дополнительно
// уменьшается на 0,15% за каждый безаварийный год вождения.  

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

double traffic(int, int, int);

int main()
{
	setlocale(LC_ALL, "RUS");
	int costCar, N, M;			// costCar - стоимость автомобиля; N - кол-во месяцев, m - кол-во лет с авариями
	cout << "Стоимость автомобиля: ";
	cin >> costCar;
	cout << "Количество месяцев: ";
	cin >> N;
	do {
		cout << "Количество аварийных лет: ";
		cin >> M;
	} while (M > ceil (N/12));
	cout << "Страховой тариф: " << traffic(costCar, N,M);

	_getch();
    return 0;
}

double traffic(int cost, int n, int m)
{
	double x;
	x = 0.07 * cost - 0.15 * (floor(n/12)-m);
	return x;
}
