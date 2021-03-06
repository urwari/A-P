// IDZ_3_03.cpp: определяет точку входа для консольного приложения.
//		ВАРИАНТ 3.	ИДЗ 3
//Создать класс, описывающий склад.
//Склад может принимать товары трех типов : товар А, товар В, товар С.
//Создать в программе 1 склад и смоделировать его работу : 
//	 -	приемку определённого товара(товар поступает на склад и остаток этого товара увеличивается), 
//	 -	отгрузку определённого товара(товар покупают и увозят со склада, его остаток уменьшается).
//Учесть, что склад не может вместить бесконечное количество товаров.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

// В данной задаче я буду использовать функции типа void, противоречащие обязательному условию ИДЗ
// Данный факт могу объяснить отсутствием необходимости возврата значения.

const int P = 2;	// Количество типов товаров amount (! Не больше 26 !)			Данное ограничение диктуется таблицей ACII с символами от A до Z
const int S = 1;	// Количество складов [см. первый комментарий в main()]


char Name(int);
int rName(char);
			//==================================//
struct amount 
{
	int max, value;
};
			//==================================//
class stock {
private:
	amount type[P];
public:
		//stock() : type[P].value(0) {}
		// Не воспользовался конструктором в целях сохранения массива P

	// Устанавливаем максимальное значения типа товара
	void set_max(int l) {	// i - номер типа товара;
		cin >> type[l].max;
		while (type[l].max <= 0)
		{
			cout << "Некоректное значение! Повторите ввод: ";
			cin >> type[l].max;
		}
	}
	// Устанавливаем начальное значение на складе
	void set_value(int l) {	// i - номер типа товара;
		cin >> type[l].value;
		while (type[l].value < 0 || type[l].value > type[l].max)
		{
			cout << "Некоректное значение! Повторите ввод: ";
			cin >> type[l].value;
		}
	}
	// Прибавление товара
	int plus(int i) {	// i - номер типа товара;
		int k;
		cout << "\nВведите количество товара: ";
		cin >> k;
		if ((type[i].value + k) <= type[i].max)
			type[i].value += k;
		else cout << "Операция с тами данными невозможна! ";
		return type[i].value; // Текущее количество товара этого типа
	}
	// Уменьшение товара
	int minus(int i) {	// i - номер типа товара;
		int k;
		cout << "\nВведите количество товара: ";
		cin >> k;
		if ((type[i].value - k) >= 0)
			type[i].value -= k;
		else cout << "Операция с тами данными невозможна! ";
		return type[i].value; // Текущее количество товара этого типа
	}
};
			//==================================//
int main()
{
	setlocale(LC_ALL, "RUS");
	// Я усложнил задачу, введя не один, а несколько таких складов

	// Заполнение информации о складах
	stock sklad[S];
	for (int i = 0; i < S; i++) {	// Склад
		cout << "\n\tСклад #" << i + 1<<"\nИнформация о текущем значении";
		for (int l=0; l < P; l++) {	// Данные о каждом ТИПЕ товаров отдельно
			cout << "\n\tМаксимальное количество товара типа " << Name(l) << ":\t";
			sklad[i].set_max(l);
			cout << "\t   Начальное количество товара типа " << Name(l) << ":\t";
			sklad[i].set_value(l);
		}
	}
	cout << "Заполнение данных о складах выполнено.\nДля проведения манипуляции введите соответствующий символ:\n\t + \tПрием товара\n\t - \tОтгрузка товара\n\t 0 \tВыход";
	char y;
	do {
		cout << "\nВыберете манипуляцию: ";
		y = _getche();
		if (y == '+' || y == '-') {
			cout << "\nМанипуляцию осущетвить для склада #";
			int i,l;
			cin >> i;
			while (i <= 0 || i > S) {
				cout << "Склад с таким номером не найден! Номер склада: ";
				cin >> i;
			}
			cout << "Тип товара: ";
			l = _getche();
			while (l < 65 || l >90)
			{
				cout << "\nТакой тип товара не найден! Повторите ввод: ";
				l = _getche();
			}
			if (y == '+')
				cout << "\nВ складе #" << i << " имеется " << sklad[(i - 1)].plus(rName(l)) << " единиц товара типа " << char(l);
			else
				cout << "\nВ складе #" << i << " имеется " << sklad[(i - 1)].minus(rName(l)) << " единиц товара типа " << char(l);
		}
	} while (y != '0');
	cout << "Спасибо за работу! Нажмите любую клавишу...";
	_getch();
    return 0;
}

// Функция определяет букву склада
char Name(int k) {	// k = программный номер типа товара
	return char(65 + k);
}
// Обратная операция Name(), находит номер символа
int rName(char k) {
	return (int(k) - 65);
}
