#include <iostream> 
#include <stdio.h> 
#include <Windows.h> 
#include <stdlib.h> 
using namespace std;
class float_p // ����� float_p 
{
private:
    static int count; // ���� � ������� ��������� ����� �����
    float c_value; // ����� c_value 
public:
    float_p() : c_value(0.0) { ++count; } // ����������� ��� ��������� � ������������ c value(0.0) 
    float_p(float value) : c_value(value) {} // ����������� � ������������ �_value(value) 
    operator float() { return c_value; } // operator � ���������� �_value 
    int to_integer() { return static_cast<float>(c_value); } // ������� ����� � ���������� �������� int
};
int float_p::count = 0;
class int_p // ����� int_p 
{
private:
    int c_value;//����� �_value 
public:
    int_p() : int_p(0) {} // ����������� � ������������ int_p(0); 
    int_p(int value) : c_value(value) {} // ������� ����� � ���������� value � ������������ c_value(value)
    operator int() { return c_value; } // operator � ���������� �_value 
    float to_float() { return static_cast<int>(c_value); } // ������� ����� � ���������� �������� float 
};
int main()
{
    SetConsoleOutputCP(1251); // ������������ ��������� ���� ��� ������
    try{
    float_p f1;
    float_p f2(7.8);
    int_p i1;
    int_p i2(9);
    cout << "=====�������� ���=====\n";
    std::cout << "float#1: " << static_cast<float>(f1) << endl;
    std::cout << "float#2: " << static_cast<float>(f2) << endl;
    std::cout << "int#1: " << static_cast<int>(i1) << endl;
    std::cout << "int#2: " << static_cast<int>(i2) << endl;
    f1 = i2.to_float();  i1 = f2.to_integer();
    cout << "=====������������=====\n";
    std::cout << "float#1(����������� � 'int#2' >> 'float#1'): " << static_cast<float>(f1) << endl;
    std::cout << "float#2: " << static_cast<float>(f2) << endl;
    std::cout << "int#1(����������� � 'float#2' >> 'int#1': " << static_cast<int>(i1) << endl;
    std::cout << "int#2: " << static_cast<int>(i2) << endl;
    }
    catch (const std::exception& ex) {
        cerr << ex.what();
    }
    catch (...) {
        cerr << "Error" << endl;
    }
    return 0;
}

