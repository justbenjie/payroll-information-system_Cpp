#pragma once

#include"structs.h"

void modeProc(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD); //���� ������ ���������
void searchEmplByParam(const Employee* const arrE, const int sizeE); // ����� ���������� �� ����������
void searchByName(const Employee* const arrE, const int sizeE); //����� ���������� �� �����
void searchBySalary(const Employee* const arrE, const int sizeE); //����� ���������� �� ��������
void searchByPosition(const Employee* const arrE, const int sizeE); //����� ���������� �� ���������
void searchDepByName(Employee* arrE, int sizeE, Department* arrD, int sizeD); //����� ������ �� ��������
void sortByEmpDep(Employee* arrE, int sizeE); //���������� ����������� �� �������
void sortEmployee(Employee* arrE, int sizeE); //���������� ����������� �� ��������� ���������
void sortByEmpName(Employee* arrE, int sizeE); //���������� �� �����
void sortByEmpSalary(Employee* arrE, int sizeE); //���������� �� ��������
void sortDepartment(Department* arrD, int sizeD); //���������� ������� �� ��������� ���������
void sortDepByName(Department* arrD, int sizeD); //���������� �� ��������
void sortDepBySum(Department* arrD, int sizeD); //���������� �� ����� �������
void sortDepByMean(Department* arrD, int sizeD); //���������� �� ������� ��������
void empSalaryBelow(Employee* arrE, int sizeE); //����� ����������� � ��������� ���� ��������
