#define _CRT_SECURE_NO_WARNINGS

#include"edit.h"
#include"check_exit.h"

void modeEdit(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD) {
	int c;
	while (true) {
		system("cls");
		cout << "РЕЖИМ РЕДАКТИРОВАНИЯ\n\n";
		cout << " 1 - добавление информации о сотруднике\n 2 - просмотр информации о сотрудниках\n 3 - удаление информации о сотруднике\n 4 - просмотр информации об отделах\n 5 - добавление информации в текстовый файл\n 0 - выход\n";
		c = inputSwitchValue(0, 5);
		if (c == 0) {
			break;
		}
		else {
			switch (c) {
			case 1: inpData(arrE, sizeE, arrD, sizeD); break;
			case 2: reprEmployee(arrE, sizeE); break;
			case 3: delEmployee(arrE, sizeE, arrD, sizeD); break;
			case 4: reprDepartment(arrE, sizeE, arrD, sizeD); break;
			case 5: giveFile(arrE, sizeE, arrD, sizeD); break;
			}
		}
	}
}

void inpData(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD) {
	int m;
	system("cls");
	cout << "Вы уверены, что хотите добавить запись? (1 - продолжить, 0 - выйти)" << endl;
	cin >> m;
	if (m == 1) {
		cout << "Введите информацию о сотруднике(имя, отдел, должность, зарплата)\n";

		//добавление нового сотрудника

		Employee* newArrE = new Employee[sizeE + 1];
		for (int i = 0; i < sizeE; i++) //копирование старого массива
		{
			newArrE[i].nameEmp = arrE[i].nameEmp;
			newArrE[i].position = arrE[i].position;
			newArrE[i].nameDep = arrE[i].nameDep;
			newArrE[i].salaryMonth = arrE[i].salaryMonth;
		}

		cin >> newArrE[sizeE].nameEmp; //ввод информации о новом сотруднике
		cin >> newArrE[sizeE].nameDep;
		cin >> newArrE[sizeE].position;
		newArrE[sizeE].salaryMonth = inputSalaryValue(); //проверка значения зарплаты
		cout << endl << "добавление прошло успешно! " << endl << endl;
		system("pause");

		//добавление нового отдела

		bool flag = true; //если отдел сотрудника не новый, присвоение флагу false
		for (int i = 0; i < sizeD; i++) {
			if (arrD[i].nameDep == newArrE[sizeE].nameDep) {
				flag = false;
			}
		}

		if (flag) { //eсли отдел сотрудника новый, добаление названия отдела 
			Department* newArrD = new Department[sizeD + 1];
			for (int i = 0; i < sizeD; i++) { //копирование массива
				newArrD[i].nameDep = arrD[i].nameDep;
			}
			newArrD[sizeD].nameDep = newArrE[sizeE].nameDep; //добавление названия нового отдела
			sizeD++;
			delete[] arrD;
			arrD = newArrD;
		}
		sizeE++;
		delete[] arrE;
		arrE = newArrE;
	}
	else {
		cin.clear();
		cin.ignore(100, '\n');
	}
}

void reprEmployee(Employee* arrE, int sizeE) {
	system("cls");
	//вывод информации о сотрудниках

	printf("%-10s%-20s%-20s%-20s%-20s\n", "Номер", "Имя", "Отдел", "Должность", "Зарплата");
	for (int i = 0; i < sizeE; i++) {
		printf("%-10d%-20s%-20s%-20s%-20.2f\n", i + 1, arrE[i].nameEmp.c_str(), arrE[i].nameDep.c_str(), arrE[i].position.c_str(), arrE[i].salaryMonth);
	}
	system("pause");
	cout << endl;
}

void delEmployee(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD) {
	system("cls");
	int m;
	cout << "Вы уверены, что хотите удалить запись? (1 - продолжить, 0 - выйти)" << endl;
	cin >> m;
	if (m == 1) {
		int num, counter = 0;
		bool flag = false;
		if (sizeE > 0) {
			Employee* newArrE = new Employee[sizeE - 1];
			num = inputDeleteValue(arrE, sizeE); //ввод и проверка индекса удаляемого сотрудника

			//удаление отдела, если удаляемый сотрудник был единственным в своём отделе

			for (int i = 0; (i < sizeE); i++) {
				if ((arrE[i].nameDep == arrE[num - 1].nameDep) && (i != num - 1)) {
					flag = true;
				}
			}
			if (!flag) {
				Department* newArrD = new Department[sizeD - 1];
				for (int i = 0, j = 0; (j < sizeD - 1); i++, j++) {
					if (arrD[i].nameDep != arrE[num - 1].nameDep)
						newArrD[j].nameDep = arrD[i].nameDep;
					else
						j--;
				}
				sizeD--;
				delete[] arrD;
				arrD = newArrD;
			}

			//удаление сотрудника

			for (int i = 0, j = 0; (j < sizeE - 1); i++, j++)
			{
				if (i != num - 1) {
					newArrE[j].nameEmp = arrE[i].nameEmp;
					newArrE[j].position = arrE[i].position;
					newArrE[j].nameDep = arrE[i].nameDep;
					newArrE[j].salaryMonth = arrE[i].salaryMonth;
				}
				else
					j--;
			}

			cout << "удаление прошло успешно!" << endl << endl;
			system("pause");

			sizeE--;
			delete[] arrE;
			arrE = newArrE;
		}
		else {
			cout << "Удаление невозможно. Список сотрудников пуст!" << endl << endl;
			system("pause");
		}
	}
	else {
		cin.clear();
		cin.ignore(100, '\n');
	}
}

void reprDepartment(Employee* arrE, int sizeE, Department* arrD, int sizeD) {
	system("cls");
	//подсчёт суммы и средней зарплаты по отделам

	salarySum(arrE, sizeE, arrD, sizeD);
	salaryMean(arrE, sizeE, arrD, sizeD);

	//вывод информации об отделах

	printf("%-10s%-20s%-20s%-20s\n", "Номер", "Отдел", "Сумма", "Среднее");
	for (int i = 0; i < sizeD; i++)
	{

		printf("%-10d%-20s%-20.2f%-20.2f\n", i + 1, arrD[i].nameDep.c_str(), arrD[i].salarySum, arrD[i].salaryMean);
	}
	system("pause");

	cout << endl;
}

void giveFile(Employee* arrE, int sizeE, Department* arrD, int sizeD) {
	system("cls");
	int m;
	cout << "Вы уверены, что хотите получить файл с записями? (1 - продолжить, 0 - выйти)" << endl;
	cin >> m;
	if (m == 1) {
		FILE* fout = fopen("out_dataframe.txt", "w"); //открытие файла

		//запись информации о сотрудниках в файл

		fprintf(fout, "%-10s%-20s%-20s%-20s%-20s\n", "Номер", "Имя", "Отдел", "Должность", "Зарплата");

		for (int i = 0; i < sizeE; i++) {
			fprintf(fout, "%-10d%-20s%-20s%-20s%-20.2f\n", i + 1, arrE[i].nameEmp.c_str(), arrE[i].nameDep.c_str(), arrE[i].position.c_str(), arrE[i].salaryMonth);

		}
		fprintf(fout, "\n");

		//запись информации об отделах в файл

		salarySum(arrE, sizeE, arrD, sizeD);
		salaryMean(arrE, sizeE, arrD, sizeD);
		fprintf(fout, "%-10s%-20s%-20s%-20s\n", "Номер", "Отдел", "Сумма", "Среднее");

		for (int i = 0; i < sizeD; i++)
		{

			fprintf(fout, "%-10d%-20s%-20.2f%-20.2f\n", i + 1, arrD[i].nameDep.c_str(), arrD[i].salarySum, arrD[i].salaryMean);

		}
		cout << "Запись была успешно проведена!\n";
		system("pause");
		cout << endl << endl;

		fclose(fout);
	}
	else {
		cin.clear();
		cin.ignore(100, '\n');
	}
}

void salarySum(Employee* arrE, int sizeE, Department* arrD, int sizeD) {

	//подсчёт суммы зарплат по отделу

	for (int i = 0; i < sizeD; i++)
	{
		arrD[i].salarySum = 0;
		for (int j = 0; j < sizeE; j++)
		{
			if (arrE[j].nameDep == arrD[i].nameDep) {
				arrD[i].salarySum += arrE[j].salaryMonth;
			}
		}

	}
}

void salaryMean(Employee* arrE, int sizeE, Department* arrD, int sizeD) {

	//подсчёт средней зарплаты по отделу

	for (int i = 0; i < sizeD; i++)
	{
		arrD[i].salaryMean = 0;
		int counter = 0;
		for (int j = 0; j < sizeE; j++)
		{
			if (arrE[j].nameDep == arrD[i].nameDep) {
				counter++;
				arrD[i].salaryMean += arrE[j].salaryMonth;
			}
		}
		arrD[i].salaryMean = arrD[i].salaryMean / counter;
	}
}

void initStructs(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD) {
	int size = 10;
	const int len = 30;
	string buff;
	ifstream file;
	bool flag;
	file.open("in_dataframe.txt");
	if (file.is_open()) {
		Employee* newArrE = new Employee[sizeE + 10];
		for (int i = 0; i < size; i++)
		{
			getline(file, newArrE[i].nameEmp);
			getline(file, newArrE[i].position);
			getline(file, newArrE[i].nameDep);
			getline(file, buff);
			newArrE[i].salaryMonth = atof(buff.c_str());
			flag = true;
			for (int j = 0; j < sizeD; j++) {
				if (arrD[j].nameDep == newArrE[i].nameDep) {
					flag = false;
				}
			}
			if (flag) {
				Department* newArrD = new Department[sizeD + 1];
				for (int k = 0; k < sizeD; k++) { //копирование массива
					newArrD[k].nameDep = arrD[k].nameDep;
				}
				newArrD[sizeD].nameDep = newArrE[i].nameDep;
				sizeD++;
				delete[] arrD;
				arrD = newArrD;
			}

		}
		sizeE += 10;
		delete[] arrE;
		arrE = newArrE;
		file.close();
	}
	else {
		cout << "Ошибка при открытии файла!" << endl;
	}
}
	