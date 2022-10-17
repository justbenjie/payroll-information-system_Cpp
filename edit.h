#pragma once

#include"structs.h"

void modeEdit(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD); //меню режима редактирования
void inpData(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD); //добавление информации о сотрудниках
void reprEmployee(Employee* arrE, int sizeE); //просмотр информации о всех сотрудниках
void delEmployee(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD); //удаление информации о сотрудниках
void reprDepartment(Employee* arrE, int sizeE, Department* arrD, int sizeD); //просмотр информации о всех отделах
void giveFile(Employee* arrE, int sizeE, Department* arrD, int sizeD); //заполнение файла информацией о сотрудниках и отделах
void salarySum(Employee* arrE, int sizeE, Department* arrD, int sizeD); //вычисление общей зарплаты отдела
void salaryMean(Employee* arrE, int sizeE, Department* arrD, int sizeD); //вычисление средней зарплаты по отделу
void initStructs(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD); //инициализация структур данными из файла
 