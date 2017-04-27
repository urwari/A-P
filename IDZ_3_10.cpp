// IDZ3.cpp:
//						ИДЗ №3: КЛАССЫ
//	ВАРИАНТ 10. 
//	Создать класс, моделирующий треугольник, заданный координатами вершин на плоскости.
//	Создать в программе 2 треугольника.
//	Выяснить, являются ли они прямоугольными, равнобедренными.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
	///////////////////////////////////////
			// Координаты точек //
struct decart	
{
	int x, y;
};
	//////////////////////////////////////
class Triangle {
private:
	decart A, B, C;		// Точки
	int AB, BC, CA;		// Катеты
public:
	Triangle() : A({ 0,0 }), B({ 0,0 }), C({ 0,0 }) {}
	// Заполнение координат
	bool setPoint() {
		cout << "\nВведите координаты вершины А (х, у): ";
		cin >> A.x >> A.y;
		cout << "Введите координаты вершины B (х, у): ";
		cin >> B.x >> B.y;
		cout << "Введите координаты вершины C (х, у): ";
		cin >> C.x >> C.y;
		if ((A.x != B.x && B.x != C.x) || (C.y != B.y && B.y != A.y))
			return true;
		else
			return false;
	}
	// Находим катеты
	bool catets() {
		AB = abs((B.x - A.x) + (B.y - A.y));
		//cout << "\n\tAB: " << AB;
		BC = abs((C.x - B.x) + (C.y - B.y));
		//cout << "\n\tBC: " << BC;
		CA = abs((A.x - C.x) + (A.y - C.y));
		//cout << "\n\tCD: " << CA;
		return true;
	}
	bool square() {
		if ((A.x == B.x && B.y == C.y) || (B.x == A.x && A.y == C.y) || (A.x == C.x && C.y == B.y))
			return true;
		else
			return false;
	}
	bool isoscales() {
		if (AB == BC || AB == CA || BC == AB )
			return true;
		else
			return false;
	}
};
		///////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "RUS");
	const int S = 3;	// Количество треугольников
	Triangle T[S];
	for (int i=0; i < S; i++) {
		cout << "\nТреугольник #"<< i+1;
		if (T[i].setPoint()) {					// Ввод координат
			cout << "\nПрямоугольный:\t\t";
			if (T[i].square())
				cout << "Да";
			else
				cout << "Нет";
			T[i].catets();						// Вычисляем катеты
			cout << "\nРавнобедренный:\t\t";
			if (T[i].isoscales())
				cout << "Да\n";
			else cout << "Нет\n";
		}
		else
			cout << "(!)\tВведенные параметры некорректны\n";
	}

	_getch();
    return 0;
}

