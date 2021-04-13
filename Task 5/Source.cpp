#include <iostream>
#include <string.h>
#include <Windows.h>
#include<cmath>
#include <math.h>
#include <vector>
using namespace std;
class Norma {       //Абстрактний базовий клас - Норма
public:
    virtual void norma() = 0;       //Оголошення віртуальної ф-ції
protected:
    float rez;     //Змінна результат (тут будуть зберігатися остаточнірозрахунки ф-цій в об'єктах)
};
class Kompleksni_chisla : public Norma {        //Похідний клас - Комплексне число
public:
    //Оголошення конструктора класу
    Kompleksni_chisla(int a, int b);
    void norma()                            //Перевизначння віртуальної ф-ції
    {
        modul = sqrt(pow(a, 2) + pow(b, 2));     //Розрахунок модуля комплесного числа
        rez = pow(modul, 2);                  //Розрахунок модуля в квадраті
        cout << "Модуль в квадраті комплексного числа " << a << "+(" << b << "*i) = " << rez << "\n" << endl;
    }
private:
    int a;              //Змінна числа а
    int b;              //Змінна числа b
    float modul;        //Змінна модуль комплексного числа
};
//Визначення конструктора
Kompleksni_chisla::Kompleksni_chisla(int a, int b) {
    Kompleksni_chisla::a = a;
    Kompleksni_chisla::b = b;
}
class Vector : public Norma {          //похідний клас - Вектор
public:
    //Визначення конструктора класу
    Vector(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10) {
        v.push_back(v1);
        v.push_back(v2);
        v.push_back(v3);
        v.push_back(v4);
        v.push_back(v5);
        v.push_back(v6);
        v.push_back(v7);
        v.push_back(v8);
        v.push_back(v9);
        v.push_back(v10);
    };
    void norma()                //Перевизначення віртуальної ф-ції
    {
        int suma = 0;
        for (int i = 0; i < v.size(); i++)
        {
            suma = suma + v[i];
        }
        rez = sqrt(abs(suma));
        cout << "Корень квадратний з суми елементів ветора по модулю = " << rez << "\n" << endl;
    }
private:
    std::vector<int> v{ 10 };     //Оголошення векторп на 10 елеентів
};
class Matrix : public Norma {          //Похідний клас - Матриця
public:
    //Визначення конструктора класу
    Matrix(int m1_1, int m1_2, int m2_1, int m2_2) {
        m[0][0] = m1_1;
        m[0][1] = m1_2;
        m[1][0] = m2_1;
        m[1][1] = m2_2;
    };
    void norma()                              //Перевизначена віртуальної ф-ції
    {
        int max = m[0][0];     //Змінні max призначається значення 1 рядка 1 стовпчика матриці
        for (int i = 0; i < 2; i++) //В циклі пройдемо всі елементи матриці та порівляємо їх з змінною max
        {
            for (int j = 0; j < 2; j++)
            {
                if (abs(max) < abs(m[i][j]))       //За допомогою ф-ції abs отримуємо значееня по модулю (абсолютне)
                {
                    max = m[i][j];
                }
            }
        }
        rez = abs(max);       //В змінну rez записано значення змінної max по модулю
        cout << "Максимальне значення по модулю елементів матриці = " << rez << "\n" << endl;
    }
private:
    int m[2][2];     //Оголошення матриці розміром 2х2
};
//головна ф-ція main()
int main() {
    SetConsoleOutputCP(1251);               //підключення української мови до програми
    try{
    Kompleksni_chisla komp_ch(4, 3);           //Створення об'єкта komp_ch класу Комплесне число
    Vector vec(1, -2, -3, 4, -5, 6, -7, -8, 9, -10);        //Створення об'єкта vec класу Вектор
    Matrix matrix(-2, 6, -8, 5);                   //Створення об'єкта matrix класу Матриця
    Norma* k, * v, * m;                      //Покажчики на базовий клас
    k = &komp_ch;                            //Привласнення покажчику на базовий клас
    v = &vec;                                //значення покажчика на похідний клас
    m = &matrix;     // Доступ до віртуальних функцій через покажчик на базовий клас:
    k->norma();
    v->norma();
    m->norma();
    }
    catch(const exception &ex){
        cerr << ex.what();
    }
    catch (...) {
        cerr << "Error" << endl;
    }
    return 0;
}
