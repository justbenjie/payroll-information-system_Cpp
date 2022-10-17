#pragma once

#include"structs.h"

void modeProc(Employee*& arrE, int& sizeE, Department*& arrD, int& sizeD); //меню режима обработки
void searchEmplByParam(const Employee* const arrE, const int sizeE); // поиск сотрудника по параметрам
void searchByName(const Employee* const arrE, const int sizeE); //поиск сотрудника по имени
void searchBySalary(const Employee* const arrE, const int sizeE); //поиск сотрудника по зарплате
void searchByPosition(const Employee* const arrE, const int sizeE); //поиск сотрудника по должности
void searchDepByName(Employee* arrE, int sizeE, Department* arrD, int sizeD); //поиск отдела по названию
void sortByEmpDep(Employee* arrE, int sizeE); //сортировка сотрудников по отделам
void sortEmployee(Employee* arrE, int sizeE); //сортировка сотрудников по заданному параметру
void sortByEmpName(Employee* arrE, int sizeE); //сортировка по имени
void sortByEmpSalary(Employee* arrE, int sizeE); //сортировка по зарплате
void sortDepartment(Department* arrD, int sizeD); //сортировка отделов по заданному параметру
void sortDepByName(Department* arrD, int sizeD); //сортировка по названию
void sortDepBySum(Department* arrD, int sizeD); //сортировка по сумме зарплат
void sortDepByMean(Department* arrD, int sizeD); //сортировка по средней зарплате
void empSalaryBelow(Employee* arrE, int sizeE); //поиск сотрудников с зарплатой ниже заданной
