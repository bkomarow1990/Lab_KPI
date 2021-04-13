#pragma once
#include <iostream>
#include "Monitor.h"
using namespace std;
class PC
{
protected:
	// Поля
	Monitor monitor; // Об`єкт монітору
	const char * name; // Назва моделі
	float frequency; // Тактова частота
private:
	static int count;
public:
	void print()const; // Оголошення методу друку
	PC(Monitor monitor, const char * name, float frequency); // Оголошення конструктора ПК
	void setFrequency(const float& freq); // Оголошуємо сетер для тактової частоти
	virtual ~PC(); // Оголошення деструктора ПК
};