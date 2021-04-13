#include "PC.h"
#include "PC_Exceptions.h"


void PC::print() const
{
	cout << "��: " << endl;
	this->monitor.print();
	cout << "��`�: " << name << " ������� �������: " << frequency << endl;
}
int PC::count = 0;
PC::PC(Monitor monitor, const char* name, float frequency) // ��������� ������������ ��
{
	if (name == nullptr) // ���� ��`� nullptr
	{
		throw PC_Exception("Name is empty"); //������ �������
	}
	this->monitor = monitor;
	this->name = name;
	setFrequency(frequency);
	++count;
}

void PC::setFrequency(const float& freq) // ��������� ������
{
	if (freq < 0)
	{
		throw PC_Exception("Frequency less than 0");
	}
	this->frequency = freq;
}

PC::~PC() // ��������� ����������� ��
{
	cout << "���������� ��� ��" << endl;
}
