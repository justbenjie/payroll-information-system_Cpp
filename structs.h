#pragma once

#include<iostream>
#include<string>
#include<fstream> 
#include<iomanip>
#include<Windows.h>
using namespace std;

struct Employee
{
	string nameEmp;
	string position;
	string nameDep;
	double salaryMonth;
};

struct Department
{
	string nameDep;
	double salarySum;
	double salaryMean;
};
