#include"check_exit.h"
#include"edit.h"
using namespace std;


int inputDeleteValue(Employee* arrE, int sizeE) {

	//проверяем параметр для удаления
	reprEmployee(arrE, sizeE);
	while(true) {
		int d;
		cout << "Введите номер сотрудника от " << 1 << " до " << sizeE << " для удаления." << endl;
		if ((cin >> d).good() && (1 <= d) && (d <= sizeE)) { //если параметр входит в диапазон номеров сотрудников и является целым числом
			cout << endl;
			return d;
		}
		if (cin.fail()) { //если параметр не сответствует типу, то выводим сообщение об ошибке
			cin.clear();
			cout << "Введите числовое значение!\n";
		}
		else {
			cout << "Число вне диапазона!\n"; //если параметр выходит из интервала, то выводим сообщение об ошибке
		}
		cin.ignore(100, '\n');
	}
}

int inputSwitchValue(int l, int h) {
	int a;
	if ((cin >> a).good() && (l <= a) && (a <= h)) {
		cout << endl;
		return a;
	}
	if (cin.fail()) {
		cin.clear();
		cout << "Введите числовое значение!\n";
		system("pause");

	}
	else {
		cout << "Число вне диапазона!\n";
		system("pause");

	}
	cin.ignore(100, '\n');
}

double inputSalaryValue() {
	while (true) {
		double salary;
		cin >> salary;

		if (cin.fail())
		{
			cout << "Ведите число!\n";
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		if (salary < 0) {
			cout << "Введите неотрицательное число!\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		else
			return salary;
	}
}

void exit() {
	system("cls");
	int a, c;
	cout << "Вы уверены что хотите выйти из программы? 1 - выйти из программы, 0 - отмена" << endl;
	while(true) {
		if ((cin >> a).good() && ((0 == a) || (a == 1))) {
			cout << endl;
			c = a;
			break;
		}
		if (cin.fail()) {
			cin.clear();
			cout << "Введите числовое значение!\n";
		}
		else {
			cout << "Число вне диапазона!\n";
		}
		cin.ignore(100, '\n');
	}
	if (c == 1) {
		exit(0);
	}
}