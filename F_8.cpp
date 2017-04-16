// IDZ_F_8.cpp: определяет точку входа для консольного приложения.
// Написать программу с функцией, которая вычисляет стоимость товара с учётом скидки, заданной в процентах. 
// Скидка ограничена диапазоном от 3% до 7%. Ввести признак «Товар на распродаже». 
// Если товар на распродаже, то функция не может применить скидку к данному товару. 

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;
float tovar(float,int);

int main()
{
	setlocale(LC_ALL, "RUS");
	float cost;
	do {
		cout << "Стоимость товара: ";
		cin >> cost;
		if (cost <= 0)
			cout << "Стоимость не может быть меньше или равна нулю! Обдумайте свое поведение\n";
	} while (cost <= 0);
	cout << "Товар на распрадаже? n/y: ";
	char k = _getch();
	if (k == 'n') {
		int sale;
		do {
			cout << "\nСкидка в процентах от 3 до 7: ";
				cin >> sale;
		} while (sale < 3 || sale > 7);
		cout << "Стоимость с учетом скидки: " << tovar(cost,sale);
	}
	else
		cout << "\nСтоимость товара не изменилась";
	_getch();
    return 0;
}

float tovar(float cost,int sale)
{
	return cost / 100 * (100 - sale);
}
