#include"check_exit.h"
#include"edit.h"
using namespace std;


int inputDeleteValue(Employee* arrE, int sizeE) {

	//��������� �������� ��� ��������
	reprEmployee(arrE, sizeE);
	while(true) {
		int d;
		cout << "������� ����� ���������� �� " << 1 << " �� " << sizeE << " ��� ��������." << endl;
		if ((cin >> d).good() && (1 <= d) && (d <= sizeE)) { //���� �������� ������ � �������� ������� ����������� � �������� ����� ������
			cout << endl;
			return d;
		}
		if (cin.fail()) { //���� �������� �� ������������ ����, �� ������� ��������� �� ������
			cin.clear();
			cout << "������� �������� ��������!\n";
		}
		else {
			cout << "����� ��� ���������!\n"; //���� �������� ������� �� ���������, �� ������� ��������� �� ������
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
		cout << "������� �������� ��������!\n";
		system("pause");

	}
	else {
		cout << "����� ��� ���������!\n";
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
			cout << "������ �����!\n";
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		if (salary < 0) {
			cout << "������� ��������������� �����!\n";
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
	cout << "�� ������� ��� ������ ����� �� ���������? 1 - ����� �� ���������, 0 - ������" << endl;
	while(true) {
		if ((cin >> a).good() && ((0 == a) || (a == 1))) {
			cout << endl;
			c = a;
			break;
		}
		if (cin.fail()) {
			cin.clear();
			cout << "������� �������� ��������!\n";
		}
		else {
			cout << "����� ��� ���������!\n";
		}
		cin.ignore(100, '\n');
	}
	if (c == 1) {
		exit(0);
	}
}