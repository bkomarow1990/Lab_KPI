#pragma once
#include <iostream>
using namespace std;
class MyException
{
public:
	MyException(const  string& errMessage = "MyException error!"); // ���������� ������������ ��� �����
	virtual const string& what() const; // ���������� ������ ��� ������ � ��������
private:
	string errMessage; // ���� ��� ������ �������
};
