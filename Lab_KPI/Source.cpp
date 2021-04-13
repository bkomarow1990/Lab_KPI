#include <iostream>
#include <string>
#include "EOM.h"
#include "PC_Exceptions.h"

using namespace std;
int main() {
	SetConsoleCP(1251); //підключення української мови до програми
	SetConsoleOutputCP(1251); //підключення української мови до програми
	try{
	Monitor monitor(22); // Створення об'єкту монітору
	PC pc(monitor, "Computer", 22.2f); // Створення об'єкту ПК
	pc.print(); // Друк об`єкту ПК
	EOM eom(monitor, "Computer", -1.2f, "Factory"); // Створення об'єкту ЄОМ
	eom.print(); // Друк об`єкту ЄОМ
	}
	catch (const MyException & ex) {
		cerr << ex.what()<<endl;
	}
	catch (...) {

		cerr << "Error..." << endl;
	}
	cout << "Деструктори: " << endl;
	return 0;
}