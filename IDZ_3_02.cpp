// IDZ_3_02.cpp: определяет точку входа для консольного приложения.
//		ВАРИАНТ 2.	ИДЗ 3
//Создать класс, описывающий железнодорожный вагон.
//Вагон может иметь тип : плацкартный вагон или купейный вагон.
//Плацкартный вагон вмещает 54 пассажира, купейный – 36. 
//Создать в программе не менее 2 вагонов, используя при этом оба типа.
//Смоделировать посадку и высадку пассажиров в / из вагона.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <locale.h> 

class CCarriage {
private:
	int type, max_pass, pass_value;
	const int K = 36, P = 54;
public:
	CCarriage (): type(0), max_pass(0), pass_value(0) {}
	bool set() {
		std::cout << "\nТип вагона (k/p): ";
		char v = _getche();
		while (v != 'k' && v !='p')
		{
			std::cout << "\nПовторите выбор: ";
			v = _getche();
		}
		if (v == 'k')
			max_pass = K;
		else
			max_pass = P;
		return true;
	}
	// Поскадка пассажиров, k - количество 
	int add_pass(int k) {
		if (pass_value + k <= max_pass)
			pass_value += k;
		else
			std::cout << "Недопустимое значение!";
		return pass_value;
	}
	int out_pass(int k) {
		if (pass_value - k >= 0)
			pass_value -= k;
		else
			std::cout << "Недопустимое значение!";
		return pass_value;
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");
	const int S = 2;	//Количество вагонов
	CCarriage Vagn[S];
	for (int i = 0; i < S; i++) {
		std::cout << "\n\tВагон #" << i + 1;
		if (Vagn[i].set())
			std::cout << "\nДанные успешно внесены";
	}
	char l = ' ';
	do {
		std::cout << "\nВыберете манипуляцию:\n\t+\tпосадка;\n\t-\tвысадка\n\t0\tзавершение работы\n ";
		l = _getche();
		if (l != '0') {
			std::cout << "\nВведите номер вагона: ";
			int i, k;
			std::cin >> i;
			while (i <= 0 || i > S) {
				std::cout << "Вагон с таким номером не найден, повторите ввод: ";
				std::cin >> i;
			}
			std::cout << "Количество человек: ";
			std::cin >> k;
			if (l == '+')
				std::cout << "\tВ " << i << " вагоне " << Vagn[i - 1].add_pass(k) << " пассажиров";
			else if (l == '-')
				std::cout << "\tВ " << i << " вагоне " << Vagn[i - 1].out_pass(k) << " пассажиров";
		}
		else
			std::cout << "\nДля завершения работы нажмите любую клавишу...";
	} while (l != '0');
	_getch();
    return 0;
}
