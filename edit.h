#pragma once

#include"structs.h"

void modeEdit(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD); //���� ������ ��������������
void inpData(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD); //���������� ���������� � �����������
void reprEmployee(Employee* arrE, int sizeE); //�������� ���������� � ���� �����������
void delEmployee(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD); //�������� ���������� � �����������
void reprDepartment(Employee* arrE, int sizeE, Department* arrD, int sizeD); //�������� ���������� � ���� �������
void giveFile(Employee* arrE, int sizeE, Department* arrD, int sizeD); //���������� ����� ����������� � ����������� � �������
void salarySum(Employee* arrE, int sizeE, Department* arrD, int sizeD); //���������� ����� �������� ������
void salaryMean(Employee* arrE, int sizeE, Department* arrD, int sizeD); //���������� ������� �������� �� ������
void initStructs(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD); //������������� �������� ������� �� �����
 