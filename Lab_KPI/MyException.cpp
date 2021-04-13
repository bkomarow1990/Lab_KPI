#include "MyException.h"
MyException::MyException(const string& errMessage) // Реалізація конструктора винятка
{
	this->errMessage = errMessage; // Присвоювання поля тексту винятка
}

const string& MyException::what() const // Метод отримування тексту винятку
{
	return errMessage; // Повертаємо текст повідомлення винятку
}
