#include "EOM.h"

void EOM::print() const
{
	cout << "EOM: " << endl;
	this->monitor.print();
	cout << "Ім`я: " << name << " Тактова частота: " << frequency << " Назва виробника: " << factory_name << endl;
}

void EOM::setFactoryName(const char* factory_name)
{
	if (factory_name == nullptr)
	{
		throw EOM_Exception("Incorect facotory name");
	}
	this->factory_name = factory_name;
}

EOM::EOM(Monitor monitor, const char* name, float frequency, const char* factory_name)
:PC(monitor,name,frequency){
	setFactoryName(factory_name);
	++count;
}
int EOM::count = 0;
EOM::~EOM()
{
	cout << "Деструктор для ЕОМ" << endl;
}
