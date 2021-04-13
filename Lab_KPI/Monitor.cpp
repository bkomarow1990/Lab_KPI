#include "Monitor.h"

void Monitor::print() const
{
	cout << "Монітор з діагоналлю: " << this->diagonal << endl;
}
void Monitor::setDiagonal(const float& diagonal)
{
}
Monitor::Monitor(float diagonal)
{
	if (diagonal < 0) // Якщо введена діагональ менша 0
	{
		throw MonitorExcpetion("Некоректна діагональ");
	}
	this->diagonal = diagonal;
	++count;
}
int Monitor::count = 0;
Monitor::~Monitor() // Реалізація деструктора монітору
{
	cout << "Спрацював деструктор Монітору" << endl;
}
