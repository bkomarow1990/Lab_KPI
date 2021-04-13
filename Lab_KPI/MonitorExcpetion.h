#pragma once
#include <iostream>
#include "MyException.h"
using namespace std;
class MonitorExcpetion : MyException
{
public:
	MonitorExcpetion(const  string& errMessage = "Monitor error!"); // Оголошення конструктора для класу
};