// transp10x2.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include<locale.h> 
#include<math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int d;
	char ret;
	do {
		cout << "Выбирете вариант перевода:\n1 - из десятичной в двоичную;\t2 - из двоичной в десятичную:\n";
		cin >> d;
		char re;
		if (d == 1) {
			do {
				long long n, b, o, r = 0;
				cout << "n = ";
				cin >> n;
				for (long int i = 0, c = n; c >= 1; i++)
				{
					o = c % 2;
					c = c / 2;
					b = o * powl(10, i);
					cout << "\nЦелая часть = " << c << "\n\tОстаток = " << o << "\n\t\tБуфер = " << b;
					r += b;
				}
				cout << "\nРЕЗУЛЬТАТ ПЕРЕВОДА: "<< r << "\nЖелаете повторить операцию? y/n: ";
				cin >> re;
			} while (re != 'n');
		}
		else if (d == 2) {
			do {
				__int64 n, num;		// Исходное число в двоичной системе
				cout << "\nВведите двоичное число n = ";
				cin >> n;
				long double r = 0, y, c, num2;
				num = n;
				int N = 0;		//Переменная колличества символов в числе
				while (num) {
					num /= 10;
					N++;
				}
				cout << N << " - символов в числе\n";
				for (; N > 0; N--) {
					cout << "\n\t\tЦикл числа № " << N;
					num2 = n;
					cout << "\nИсходное число цикла: " << num2;
					y = powl(10, N - 1);
					cout << "\nСтепень цикла: " << y;
					num2 /= y;
					cout << "\nДеление числа на степень = " << num2;
					c = floor(num2);
					cout << "\nОкруглем и получаем " << c;
					if (c == 1) {
						n -= y;
						cout << "\n\t(!) НАЧАЛО УСЛОВИЯ =1= (!)\nИзменене значения исходного числа: " << y << "\nРезультат изменения = " << n << "\nРезультат ЦИКЛА\t\t=\t";
						r += powl(2, N - 1);
						cout << r << endl;
					}
					else if (c == 0)
						cout << "\n\t\tУСЛОВИЕ =0=\nЗначение не вычисляется, так как анализируемвй объект равен 0\n";
					else
						cout << "\nОШИБКА нахождения ЦЕЛОГО числа, иходные данные неверны";
					cout << "\nРЕЗУЛЬТАТ ПЕРЕВОДА: " << r << "\nЖелаете повторить операцию? y/n: ";
				}
				cin >> re;
			} while (re != 'n');
		}
		cout << "Изменить вариант перевода? y/n: ";
		cin >> ret;
	} while (ret != 'n');
	return 0;
}
