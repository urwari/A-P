// IDZ_3_01.cpp: определяет точку входа для консольного приложения.
//	ВАРИАНТ 1.	
//Создать класс, описывающий жилой дом(этажность, количество квартир, предельное количество жителей).
//Создать в программе 2 дома, реализовать методы поселения определённого количества людей, выселения, уточнения текущей заселённости.
//Определить, сколько ещё людей может быть поселено.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class CBuildings {
private:
	int lvls, flat, savages, max_s;
public:
	CBuildings() : lvls(0), flat(0), savages(0),max_s(0) {}
	// Инициализация
	bool begin() {
		do {
			cout << "\nКоличество этажей: ";
			cin >> lvls;
			cout << "Количество комнат: ";
			cin >> flat;
			cout << "Максимум жителей: ";
			cin >> max_s;
			cout << "Проживает на данный момент: ";
			cin >> savages;
		} while (lvls < 1 || flat < 1 || max_s < 1 || savages < 0 || savages > max_s);
		return true;
	}
	// Заселение
	int joining(int k) {				
		if ((savages + k) <= max_s)
			savages += k;
		return savages; // Текущее количество жителей
	}
	// Выселение
	int leave(int k) {
		if ((savages - k) >= 0)
			savages -= k;
		return savages;
	}
	// Текущая заселенность
	int viev(bool k) {
		if (k)
			cout << "Здание заполнено на " << float(savages / (max_s *1.0)*100)<< "%\n";
		return savages;
	}
};
int main()
{
	setlocale(LC_ALL, "RUS");
	const int S = 2;	// Количество треугольников
	CBuildings B[S];
	for (int i = 0; i < S; i++) {
		cout << "\n\tЖилой дом #" << i + 1;
		if (B[i].begin())
			cout << "Данные успешно сохранены.\n";
	}
	cout << "\n\nМанипуляции:\n\t+\tзаселить\n\t-\tвыселить\n\t9\tузнать текущую заселенность\n\t8\tузнать число свободных мест во всех зданиях\n\t0\tвыход из программы";
	char l = '\r';
	int k,i;
	do {
		cout << "\nОжидается выбор манипуляции: ";
		l = _getche();
		if (l == '8') {
			int all_svg = 0;
			for (int i = 0; i < S; i++)
				all_svg += B[i].viev(false);
			cout << "\nОБЩЕЕ число свободных мест: " << all_svg;
		} 
		else if (l == '0') {
			cout << "\n\tСпасибо за работу!\nДля выхода из программы нажмите любую клавишу";
			_getch();
		}
		else {
			cout << "\nДействия произвести для дома # ";
			cin >> i;
			while (i <= 1 && i >= S) {
				cout << "Дом с таким номером не найден! Введите номер: ";
				cin >> i;
			}
			switch (l)
			{
			case '+':
				cout << "(+) Укажите количество: ";
				cin >> k;
				cout << "В доме #" << i << " проживает " << B[i-1].joining(k) << " жителей";
				break;
			case '-':
				cout << "(-) Укажите количество: ";
				cin >> k;
				cout << "В доме #" << i << " проживает " << B[i-1].leave(k) << " жителей";
				break;
			case '9':
				cout << "Свободно мест: " << B[i-1].viev(true);
				break;
			default:
				cout << "Неверная манипуляция!";
				break;
			}
		}
	} while (l != '0');
    return 0;
}
