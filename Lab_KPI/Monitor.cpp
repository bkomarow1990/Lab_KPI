#include "Monitor.h"

void Monitor::print() const
{
	cout << "������ � ���������: " << this->diagonal << endl;
}
void Monitor::setDiagonal(const float& diagonal)
{
}
Monitor::Monitor(float diagonal)
{
	if (diagonal < 0) // ���� ������� �������� ����� 0
	{
		throw MonitorExcpetion("���������� ��������");
	}
	this->diagonal = diagonal;
	++count;
}
int Monitor::count = 0;
Monitor::~Monitor() // ��������� ����������� �������
{
	cout << "��������� ���������� �������" << endl;
}
