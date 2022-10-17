#include"edit.h"
#include"check_exit.h"
#include"proc.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	//задание начальных значений размера массивов
	int sizeD = 0;
	int sizeE = 0;
	int a;

	//создание динамических массивов сорудников и отделов
	cout << "ИНФОРМАЦИОННАЯ СИСТЕМА УЧЁТА ВЫПЛАТ ЗАРАБОТНОЙ ПЛАТЫ СОТРУДНИКАМ\n";
	Department* arrD = new Department[sizeD];
	Employee* arrE = new Employee[sizeE];
	initStructs(arrE, sizeE, arrD, sizeD);
	system("pause");
	while (true) {
		system("cls");
		cout << "МЕНЮ\n\n";
		//ввод значения операции

		cout << " 1 - режим редактирования\n 2 - режим обработки \n 0 - выход\n";
		a = inputSwitchValue(0, 3);
		switch (a)
		{
		case 0: exit(); break;
		case 1: modeEdit(arrE, sizeE, arrD, sizeD); break;
		case 2: modeProc(arrE, sizeE, arrD, sizeD); break;
		}
	}

	//удаление старых массивов сотрудников и отделов

	delete[] arrD;
	delete[] arrE;

}