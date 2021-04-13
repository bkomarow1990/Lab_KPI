#include "MyException.h"
MyException::MyException(const string& errMessage) // ��������� ������������ �������
{
	this->errMessage = errMessage; // ������������ ���� ������ �������
}

const string& MyException::what() const // ����� ����������� ������ �������
{
	return errMessage; // ��������� ����� ����������� �������
}
