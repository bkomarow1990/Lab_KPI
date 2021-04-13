#pragma once
#include <iostream>
#include <string.h>
#include <Windows.h>
#include "MonitorExcpetion.h"
using namespace std;
//���� �������
class Monitor {
public:
	void print()const; // ����� �����
	void setDiagonal(const float& diagonal); // ���������� ������ ��� ���� � ���������
	Monitor(float diagonal = 1.0); // ���������� ������������ � ���������� ������� � � ����������� ��������� �������
	~Monitor(); // ���������� �����������
private:
	static int count;
protected: // ��� ���������� ������� �������� �� ����
    float diagonal;   //���� ������� �������
};