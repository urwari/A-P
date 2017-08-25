#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	vector <int> v(0);
	vector <int> ::iterator it;
	//vector <int> ::iterator it_end;
	char ch = ' ';
	cout << "Ожидается ввод";
	while (ch != 0x09) {
		if (ch == 'b') {
			cout << "\nОсущесвтяем покупку +1 количество";
			v.push_back(3);
		}
		cout << "\nSIZE: " << v.size() << " | EMK " << v.capacity() << "\n";
		it = v.begin();
		while (it != v.end()) {
			cout << *it << " ";
			if (*it <= 0)
				cout << "!!";
				//v.erase(it);
			++it;
		}
		ch = _getch();
		if (v.end() != v.begin())
			for (int i = 0; i < v.size(); i++) {
				if (v[i] <= 0)
					v.erase(v.begin() + i);
				v[i]--;
			}
	}

	cout << "\nНажат TAB!";
	_getch();
    return 0;
}
