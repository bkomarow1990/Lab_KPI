#pragma once
#include <iostream>
#include "MyException.h"
using namespace std;
class EOM_Exception : MyException
{
public:
	EOM_Exception(const  string& errMessage = "PC error!"); // Оголошення конструктора для класу
};
