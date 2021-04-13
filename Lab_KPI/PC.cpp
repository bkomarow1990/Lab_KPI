#include "PC.h"
#include "PC_Exceptions.h"


void PC::print() const
{
	cout << "ПК: " << endl;
	this->monitor.print();
	cout << "Ім`я: " << name << " Тактова частота: " << frequency << endl;
}
int PC::count = 0;
PC::PC(Monitor monitor, const char* name, float frequency) // Реалізація конструктора ПК
{
	if (name == nullptr) // Якщо Ім`я nullptr
	{
		throw PC_Exception("Name is empty"); //Кидаємо виняток
	}
	this->monitor = monitor;
	this->name = name;
	setFrequency(frequency);
	++count;
}

void PC::setFrequency(const float& freq) // Реалізація сетера
{
	if (freq < 0)
	{
		throw PC_Exception("Frequency less than 0");
	}
	this->frequency = freq;
}

PC::~PC() // Реалізація деструктора ПК
{
	cout << "Деструктор для ПК" << endl;
}
