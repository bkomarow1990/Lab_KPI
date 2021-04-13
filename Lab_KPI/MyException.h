#pragma once
#include <iostream>
using namespace std;
class MyException
{
public:
	MyException(const  string& errMessage = "MyException error!"); // Оголошення конструктора для класу
	virtual const string& what() const; // Оголошення методу для роботи з винятком
private:
	string errMessage; // Поле для тексту винятка
};
