#pragma once
#include <iostream>
#include "MyException.h"
using namespace std;
class PC_Exception : MyException
{
public:
	PC_Exception(const  string& errMessage = "PC error!"); // ���������� ������������ ��� �����
};
