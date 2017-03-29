// domz2703.cpp: определяет точку входа для консольного приложения.

		/*
			Смоделировать 3 студентов и их успеваемость
			Студент:
					- Группа
					- Фамилия*
					- Личный номер
					- 4 оценки за последнюю сессию
			Сделать запрос этих данных,
			Сделать вывод данных об этих студентах
			Средний балл каждого студента
			Найти наиболее и наименее успевающего студента
		*/
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <locale.h>
using namespace std;
struct ocenki
{
	int matemat, rus, alg, english;
};
struct razdolbai
{
	int gr, num;
	ocenki mark;
	float reit;
};
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	razdolbai sidorenko[3];
	cout << "\t\tЗАПОЛНЕНИЕ ИНФОРМАЦИИ О СТУДЕНТАХ\n";
	for (int i = 1; i < 3+1; i++) {
		/*cout << "\tЗаполнение информации о студенте № " << i << "\nГруппа №: ";
		cin >> sidorenko[i].gr;
		cout << "Личный номер: ";
		cin >> sidorenko[i].num;*/
		cout << "\t<< Сведения об успеваемости  студента >>\n Предмет\t\tОценка\n - Математика\t\t ";
		cin >> sidorenko[i].mark.matemat;
		cout << " - Русский язык\t\t ";
		cin >> sidorenko[i].mark.rus;
		cout << " - Алгоритмизация\t ";
		cin >> sidorenko[i].mark.alg;
		cout << " - Английский язык\t ";
		cin >> sidorenko[i].mark.english;
		cout << "---\t---\t---\t---\t---\t---\t---\n";
	}
	char z;
	cout << "Запросить данные о студентах? y/n : ";
	cin >> z;
	if (z == 'y' || z == 'д') {
		cout << "\n\t ВЫВОД ИНФОРМАЦИИ О СТУДЕНТАХ\n";
		for (int i = 1; i < 3 + 1; i++)
			cout << "Студент №" << i << ":\n\tГруппа: " << sidorenko[i].gr << "\n\tЛичный номер " << sidorenko[i].num << "\n\tДанные об оценках:\n\t\tМатематика:\t\t" << sidorenko[i].mark.matemat << "\n\t\tРусский язык:\t\t" << sidorenko[i].mark.rus << "\n\t\tАлгоритмизация:\t\t" << sidorenko[i].mark.alg << "\n\t\tАнглийский язык:\t" << sidorenko[i].mark.english << endl;
	}
	cout << "Запросить рейтинг студентов? y/n : ";
	cin >> z;
	if (z == 'y' || z == 'д') {
		cout << "\n\t РЕЙТИНГ СТУДЕНТОВ\n";
		for (int i = 1; i < 3 + 1; i++) {
			sidorenko[i].reit = (sidorenko[i].mark.alg + sidorenko[i].mark.rus + sidorenko[i].mark.matemat + sidorenko[i].mark.english) / 4.0;
			cout << i << ":\t " << sidorenko[i].reit << endl;
		}
		float min = sidorenko[1].reit, max = sidorenko[1].reit;
		int min_n;
		int max_n;
		for (int i = 1; i < 3+1; i++) {
			if (min > sidorenko[i].reit) {
				min = sidorenko[i].reit;
				min_n = i;
			}
			if (max < sidorenko[i].reit) {
				max = sidorenko[i].reit;
				max_n = i;
			}
			min = sidorenko[i].reit, max = sidorenko[i].reit;
		}
		cout << "Студент №" << max_n << " самый успивающий студент со средней оценкой " << max<< "\nСтудент №" << min_n << " самый отстающий студент со средней оценкой "<< min;

	}
	_getch();
    return 0;
}
