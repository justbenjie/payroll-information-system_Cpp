#define _CRT_SECURE_NO_WARNINGS

#include"edit.h"
#include"check_exit.h"

void modeEdit(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD) {
	int c;
	while (true) {
		system("cls");
		cout << "����� ��������������\n\n";
		cout << " 1 - ���������� ���������� � ����������\n 2 - �������� ���������� � �����������\n 3 - �������� ���������� � ����������\n 4 - �������� ���������� �� �������\n 5 - ���������� ���������� � ��������� ����\n 0 - �����\n";
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
	cout << "�� �������, ��� ������ �������� ������? (1 - ����������, 0 - �����)" << endl;
	cin >> m;
	if (m == 1) {
		cout << "������� ���������� � ����������(���, �����, ���������, ��������)\n";

		//���������� ������ ����������

		Employee* newArrE = new Employee[sizeE + 1];
		for (int i = 0; i < sizeE; i++) //����������� ������� �������
		{
			newArrE[i].nameEmp = arrE[i].nameEmp;
			newArrE[i].position = arrE[i].position;
			newArrE[i].nameDep = arrE[i].nameDep;
			newArrE[i].salaryMonth = arrE[i].salaryMonth;
		}

		cin >> newArrE[sizeE].nameEmp; //���� ���������� � ����� ����������
		cin >> newArrE[sizeE].nameDep;
		cin >> newArrE[sizeE].position;
		newArrE[sizeE].salaryMonth = inputSalaryValue(); //�������� �������� ��������
		cout << endl << "���������� ������ �������! " << endl << endl;
		system("pause");

		//���������� ������ ������

		bool flag = true; //���� ����� ���������� �� �����, ���������� ����� false
		for (int i = 0; i < sizeD; i++) {
			if (arrD[i].nameDep == newArrE[sizeE].nameDep) {
				flag = false;
			}
		}

		if (flag) { //e��� ����� ���������� �����, ��������� �������� ������ 
			Department* newArrD = new Department[sizeD + 1];
			for (int i = 0; i < sizeD; i++) { //����������� �������
				newArrD[i].nameDep = arrD[i].nameDep;
			}
			newArrD[sizeD].nameDep = newArrE[sizeE].nameDep; //���������� �������� ������ ������
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
	//����� ���������� � �����������

	printf("%-10s%-20s%-20s%-20s%-20s\n", "�����", "���", "�����", "���������", "��������");
	for (int i = 0; i < sizeE; i++) {
		printf("%-10d%-20s%-20s%-20s%-20.2f\n", i + 1, arrE[i].nameEmp.c_str(), arrE[i].nameDep.c_str(), arrE[i].position.c_str(), arrE[i].salaryMonth);
	}
	system("pause");
	cout << endl;
}

void delEmployee(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD) {
	system("cls");
	int m;
	cout << "�� �������, ��� ������ ������� ������? (1 - ����������, 0 - �����)" << endl;
	cin >> m;
	if (m == 1) {
		int num, counter = 0;
		bool flag = false;
		if (sizeE > 0) {
			Employee* newArrE = new Employee[sizeE - 1];
			num = inputDeleteValue(arrE, sizeE); //���� � �������� ������� ���������� ����������

			//�������� ������, ���� ��������� ��������� ��� ������������ � ���� ������

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

			//�������� ����������

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

			cout << "�������� ������ �������!" << endl << endl;
			system("pause");

			sizeE--;
			delete[] arrE;
			arrE = newArrE;
		}
		else {
			cout << "�������� ����������. ������ ����������� ����!" << endl << endl;
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
	//������� ����� � ������� �������� �� �������

	salarySum(arrE, sizeE, arrD, sizeD);
	salaryMean(arrE, sizeE, arrD, sizeD);

	//����� ���������� �� �������

	printf("%-10s%-20s%-20s%-20s\n", "�����", "�����", "�����", "�������");
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
	cout << "�� �������, ��� ������ �������� ���� � ��������? (1 - ����������, 0 - �����)" << endl;
	cin >> m;
	if (m == 1) {
		FILE* fout = fopen("out_dataframe.txt", "w"); //�������� �����

		//������ ���������� � ����������� � ����

		fprintf(fout, "%-10s%-20s%-20s%-20s%-20s\n", "�����", "���", "�����", "���������", "��������");

		for (int i = 0; i < sizeE; i++) {
			fprintf(fout, "%-10d%-20s%-20s%-20s%-20.2f\n", i + 1, arrE[i].nameEmp.c_str(), arrE[i].nameDep.c_str(), arrE[i].position.c_str(), arrE[i].salaryMonth);

		}
		fprintf(fout, "\n");

		//������ ���������� �� ������� � ����

		salarySum(arrE, sizeE, arrD, sizeD);
		salaryMean(arrE, sizeE, arrD, sizeD);
		fprintf(fout, "%-10s%-20s%-20s%-20s\n", "�����", "�����", "�����", "�������");

		for (int i = 0; i < sizeD; i++)
		{

			fprintf(fout, "%-10d%-20s%-20.2f%-20.2f\n", i + 1, arrD[i].nameDep.c_str(), arrD[i].salarySum, arrD[i].salaryMean);

		}
		cout << "������ ���� ������� ���������!\n";
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

	//������� ����� ������� �� ������

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

	//������� ������� �������� �� ������

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
				for (int k = 0; k < sizeD; k++) { //����������� �������
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
		cout << "������ ��� �������� �����!" << endl;
	}
}
	