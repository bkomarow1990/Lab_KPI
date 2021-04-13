#pragma once
#include <iostream>
#include "Monitor.h"
using namespace std;
class PC
{
protected:
	// ����
	Monitor monitor; // ��`��� �������
	const char * name; // ����� �����
	float frequency; // ������� �������
private:
	static int count;
public:
	void print()const; // ���������� ������ �����
	PC(Monitor monitor, const char * name, float frequency); // ���������� ������������ ��
	void setFrequency(const float& freq); // ��������� ����� ��� ������� �������
	virtual ~PC(); // ���������� ����������� ��
};