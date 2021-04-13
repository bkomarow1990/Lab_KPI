#pragma once
#include <iostream>
#include "PC.h"
#include "EOM_Exception.h"
using namespace std;
class EOM : public PC
{
private:
	const char* factory_name;
	static int count;
public:
	void print()const; // Метод друку
	void setFactoryName(const char * factory_name);
	EOM(Monitor monitor, const char* name="NoNameEOM", float frequency=1.0,const char* factory_name="NoNameFactory");
	~EOM();
};

