#pragma once
#include <iostream>
#include <string.h>
#include <Windows.h>
#include "MonitorExcpetion.h"
using namespace std;
//Клас Монитор
class Monitor {
public:
	void print()const; // Метод друку
	void setDiagonal(const float& diagonal); // Оголошення сетера для поля з діагоналлю
	Monitor(float diagonal = 1.0); // Оголошення конструктора з параметром діагоналі і з стандартним значенням діагоналі
	~Monitor(); // Оголошення Деструктора
private:
	static int count;
protected: // При наслідуванні зможемо змінювати це поле
    float diagonal;   //поле діагоналі монітора
};