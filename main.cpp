#include"edit.h"
#include"check_exit.h"
#include"proc.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	//������� ��������� �������� ������� ��������
	int sizeD = 0;
	int sizeE = 0;
	int a;

	//�������� ������������ �������� ���������� � �������
	cout << "�������������� ������� �ר�� ������ ���������� ����� �����������\n";
	Department* arrD = new Department[sizeD];
	Employee* arrE = new Employee[sizeE];
	initStructs(arrE, sizeE, arrD, sizeD);
	system("pause");
	while (true) {
		system("cls");
		cout << "����\n\n";
		//���� �������� ��������

		cout << " 1 - ����� ��������������\n 2 - ����� ��������� \n 0 - �����\n";
		a = inputSwitchValue(0, 3);
		switch (a)
		{
		case 0: exit(); break;
		case 1: modeEdit(arrE, sizeE, arrD, sizeD); break;
		case 2: modeProc(arrE, sizeE, arrD, sizeD); break;
		}
	}

	//�������� ������ �������� ����������� � �������

	delete[] arrD;
	delete[] arrE;

}