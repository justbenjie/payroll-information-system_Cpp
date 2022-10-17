#include"proc.h"
#include"check_exit.h"
#include"edit.h"

void modeProc(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD) {
	int c;
	while (true) {
		system("cls");
		cout << "РЕЖИМ ОБРАБОТКИ\n\n";
		cout << " 1 - сортировка сотрудников\n 2 - сортировка отделов\n 3 - поиск сотрудников с зарплатой ниже заданной с клавиатуры\n 4 - поиск сотрудников по параметрам\n 5 - поиск отделов по названию \n 0 - выход\n";
		c = inputSwitchValue(0, 5);
		if (c == 0) {
			break;
		}
		else {
			switch (c) {
			case 1: sortEmployee(arrE, sizeE); break;
			case 2: sortDepartment(arrD, sizeD); break;
			case 3: empSalaryBelow(arrE, sizeE); break;
			case 4: searchEmplByParam(arrE, sizeE); break;
			case 5: searchDepByName(arrE, sizeE, arrD, sizeD); break;
			}
		}
	}
}

void searchEmplByParam(const Employee* const arrE, const int sizeE) {
	system("cls");
	int ch;
	cout << "По какому параметру вы хотите найти сотрудников?(1 - имя, 2 - зарплата, 3 - должность)\n";
	cin >> ch; //выбор парараметра сортировки
	cout << endl;
	switch (ch)
	{
	case 1: searchByName(arrE, sizeE); break;
	case 2: searchBySalary(arrE, sizeE); break;
	case 3: searchByPosition(arrE, sizeE);
	}
}

void searchByName(const Employee* const arrE, const int sizeE) {
	string p;
	cout << "Введите имя\n";
	cin.ignore(32767, '\n');
	getline(cin, p);
	cout << endl;
	printf("%-10s%-20s%-20s%-20s%-20s\n", "Номер", "Имя", "Отдел", "Должность", "Зарплата");
	for (int i = 0; i < sizeE; i++) {
		if (arrE[i].nameEmp == p) {
			printf("%-10d%-20s%-20s%-20s%-20.2f\n", i + 1, arrE[i].nameEmp.c_str(), arrE[i].nameDep.c_str(), arrE[i].position.c_str(), arrE[i].salaryMonth);
		}
	}
	system("pause");
	cout << endl;
}

void searchBySalary(const Employee* const arrE, const int sizeE) {
	double p;
	cout << "Введите зарплату\n";
	cin.ignore(32767, '\n');
	cin >> p;
	cout << endl;
	printf("%-10s%-20s%-20s%-20s%-20s\n", "Номер", "Имя", "Отдел", "Должность", "Зарплата");
	for (int i = 0; i < sizeE; i++) {
		if (abs(arrE[i].salaryMonth - p) < 0.00001) {
			printf("%-10d%-20s%-20s%-20s%-20.2f\n", i + 1, arrE[i].nameEmp.c_str(), arrE[i].nameDep.c_str(), arrE[i].position.c_str(), arrE[i].salaryMonth);
		}
	}
	system("pause");
	cout << endl;
}

void searchByPosition(const Employee* const arrE, const int sizeE) {
	string p;
	cout << "Введите должность\n";
	cin.ignore(32767, '\n');
	getline(cin, p);
	cout << endl;
	printf("%-10s%-20s%-20s%-20s%-20s\n", "Номер", "Имя", "Отдел", "Должность", "Зарплата");
	for (int i = 0; i < sizeE; i++) {
		if (arrE[i].position == p) {
			printf("%-10d%-20s%-20s%-20s%-20.2f\n", i + 1, arrE[i].nameEmp.c_str(), arrE[i].nameDep.c_str(), arrE[i].position.c_str(), arrE[i].salaryMonth);
		}
	}
	system("pause");
	cout << endl;
}

void searchDepByName(Employee* arrE, int sizeE, Department* arrD, int sizeD) {
	system("cls");
	string p;
	cout << "Введите название отдела\n";
	cin.ignore(32767, '\n');
	getline(cin, p);
	cout << endl;
	salarySum(arrE, sizeE, arrD, sizeD);
	salaryMean(arrE, sizeE, arrD, sizeD);

	printf("%-10s%-20s%-20s%-20s\n", "Номер", "Отдел", "Сумма", "Среднее");
	for (int i = 0; i < sizeD; i++)
	{
		if (arrD[i].nameDep == p) {
			printf("%-10d%-20s%-20.2f%-20.2f\n", i + 1, arrD[i].nameDep.c_str(), arrD[i].salarySum, arrD[i].salaryMean);
		}
	}
	system("pause");
	cout << endl;
}

void sortEmployee(Employee* arrE, int sizeE) {
	system("cls");
	int m;
	cout << "Вы уверены, что хотите отсортировать список сотрудников? (1 - продолжить, 0 - выйти)" << endl;
	cin >> m;
	if (m == 1) {
		int ch;
		cout << "По какому параметру вы хотите провести сортировку?(имя, зарплата)\n";
		cin >> ch; //выбор парараметра сортировки
		cout << endl;
		switch (ch)
		{
		case 1: sortByEmpName(arrE, sizeE); break;
		case 2: sortByEmpSalary(arrE, sizeE); break;
		}
		cout << "сортировка прошла успешно" << endl << endl;
		system("pause");
	}
	else {
		cin.clear();
		cin.ignore(100, '\n');
	}
}

void sortByEmpName(Employee* arrE, int sizeE) {

	//сортировка пузырьком по имени

	for (int i = sizeE - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arrE[i].nameEmp.compare(arrE[j].nameEmp) < 0)
			{
				Employee tmp = arrE[j];
				arrE[j] = arrE[j + 1];
				arrE[j + 1] = tmp;
			}
		}
	}
}

void sortByEmpDep(Employee* arrE, int sizeE) {

	//сортировка пузырьком по названию отдела

	for (int i = sizeE - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arrE[i].nameDep.compare(arrE[j].nameDep) < 0)
			{
				Employee tmp = arrE[j];
				arrE[j] = arrE[j + 1];
				arrE[j + 1] = tmp;
			}
		}
	}
}

void sortByEmpSalary(Employee* arrE, int sizeE) {

	//сортировка пузырьком по зарплате

	for (int i = sizeE - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arrE[j].salaryMonth > arrE[j + 1].salaryMonth)
			{
				Employee tmp = arrE[j];
				arrE[j] = arrE[j + 1];
				arrE[j + 1] = tmp;
			}
		}
	}
}

void sortDepartment(Department* arrD, int sizeD) {
	system("cls");
	int m;
	cout << "Вы уверены, что хотите отсортировать отделы? (1 - продолжить, 0 - выйти)" << endl;
	cin >> m;
	if (m == 1) {
		int ch;
		cout << "По какому параметру вы хотите отсортировать отделы?(имя, сумма, среднее)\n";
		cin >> ch;
		cout << endl;
		switch (ch) //сортировка отделов по заданному параметру
		{
		case 1: sortDepByName(arrD, sizeD); break;
		case 2: sortDepBySum(arrD, sizeD); break;
		case 3: sortDepByMean(arrD, sizeD); break;
		}
		cout << "сортировка прошло успешно" << endl << endl;
		system("pause");
	}
	else {
		cin.clear();
		cin.ignore(100, '\n');
	}
}

void sortDepByName(Department* arrD, int sizeD) {

	//сортировка пузырьком по названию отдела

	for (int i = sizeD - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arrD[i].nameDep.compare(arrD[j].nameDep) < 0)
			{
				Department tmp = arrD[j];
				arrD[j] = arrD[j + 1];
				arrD[j + 1] = tmp;
			}
		}
	}
}

void sortDepBySum(Department* arrD, int sizeD) {
	// сортировка по суммарной зарплате

	for (int i = sizeD - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arrD[j].salarySum > arrD[j + 1].salarySum)
			{
				Department tmp = arrD[j];
				arrD[j] = arrD[j + 1];
				arrD[j + 1] = tmp;
			}
		}
	}
}

void sortDepByMean(Department* arrD, int sizeD) {

	//сортировка по средней зарплате

	for (int i = sizeD - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arrD[j].salaryMean > arrD[j + 1].salaryMean)
			{
				Department tmp = arrD[j];
				arrD[j] = arrD[j + 1];
				arrD[j + 1] = tmp;
			}
		}
	}
}

void empSalaryBelow(Employee* arrE, int sizeE) {
	system("cls");
	//вывод информации о сотрудниках с зарплатой ниже заданной
	int m;

	bool f = true;
	double salary;
	cout << "введите зарплату: " << endl << endl;
	cin >> salary;
	printf("%-10s%-20s%-20s%-20s%-20s\n", "Номер", "Имя", "Отдел", "Должность", "Зарплата");
	for (int i = 0; i < sizeE; i++) {
		if (arrE[i].salaryMonth < salary) {
			printf("%-10d%-20s%-20s%-20s%-20.2f\n", i + 1, arrE[i].nameEmp.c_str(), arrE[i].nameDep.c_str(), arrE[i].position.c_str(), arrE[i].salaryMonth);
			f = false;
		}
	}
	if (f) {
		cout << "таких сотрудников нет\n";
		
	}
	system("pause");
	cout << endl;

}
