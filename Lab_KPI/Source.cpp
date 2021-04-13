#include <iostream>
#include <string>
#include "EOM.h"
#include "PC_Exceptions.h"

using namespace std;
int main() {
	SetConsoleCP(1251); //���������� ��������� ���� �� ��������
	SetConsoleOutputCP(1251); //���������� ��������� ���� �� ��������
	try{
	Monitor monitor(22); // ��������� ��'���� �������
	PC pc(monitor, "Computer", 22.2f); // ��������� ��'���� ��
	pc.print(); // ���� ��`���� ��
	EOM eom(monitor, "Computer", -1.2f, "Factory"); // ��������� ��'���� ���
	eom.print(); // ���� ��`���� ���
	}
	catch (const MyException & ex) {
		cerr << ex.what()<<endl;
	}
	catch (...) {

		cerr << "Error..." << endl;
	}
	cout << "�����������: " << endl;
	return 0;
}