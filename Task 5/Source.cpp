#include <iostream>
#include <string.h>
#include <Windows.h>
#include<cmath>
#include <math.h>
#include <vector>
using namespace std;
class Norma {       //����������� ������� ���� - �����
public:
    virtual void norma() = 0;       //���������� ��������� �-���
protected:
    float rez;     //����� ��������� (��� ������ ���������� ������������������ �-��� � ��'�����)
};
class Kompleksni_chisla : public Norma {        //�������� ���� - ���������� �����
public:
    //���������� ������������ �����
    Kompleksni_chisla(int a, int b);
    void norma()                            //������������� ��������� �-���
    {
        modul = sqrt(pow(a, 2) + pow(b, 2));     //���������� ������ ����������� �����
        rez = pow(modul, 2);                  //���������� ������ � �������
        cout << "������ � ������� ������������ ����� " << a << "+(" << b << "*i) = " << rez << "\n" << endl;
    }
private:
    int a;              //����� ����� �
    int b;              //����� ����� b
    float modul;        //����� ������ ������������ �����
};
//���������� ������������
Kompleksni_chisla::Kompleksni_chisla(int a, int b) {
    Kompleksni_chisla::a = a;
    Kompleksni_chisla::b = b;
}
class Vector : public Norma {          //�������� ���� - ������
public:
    //���������� ������������ �����
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
    void norma()                //�������������� ��������� �-���
    {
        int suma = 0;
        for (int i = 0; i < v.size(); i++)
        {
            suma = suma + v[i];
        }
        rez = sqrt(abs(suma));
        cout << "������ ���������� � ���� �������� ������ �� ������ = " << rez << "\n" << endl;
    }
private:
    std::vector<int> v{ 10 };     //���������� ������� �� 10 �������
};
class Matrix : public Norma {          //�������� ���� - �������
public:
    //���������� ������������ �����
    Matrix(int m1_1, int m1_2, int m2_1, int m2_2) {
        m[0][0] = m1_1;
        m[0][1] = m1_2;
        m[1][0] = m2_1;
        m[1][1] = m2_2;
    };
    void norma()                              //������������� ��������� �-���
    {
        int max = m[0][0];     //���� max ������������ �������� 1 ����� 1 ��������� �������
        for (int i = 0; i < 2; i++) //� ���� �������� �� �������� ������� �� ��������� �� � ������ max
        {
            for (int j = 0; j < 2; j++)
            {
                if (abs(max) < abs(m[i][j]))       //�� ��������� �-��� abs �������� �������� �� ������ (���������)
                {
                    max = m[i][j];
                }
            }
        }
        rez = abs(max);       //� ����� rez �������� �������� ����� max �� ������
        cout << "����������� �������� �� ������ �������� ������� = " << rez << "\n" << endl;
    }
private:
    int m[2][2];     //���������� ������� ������� 2�2
};
//������� �-��� main()
int main() {
    SetConsoleOutputCP(1251);               //���������� ��������� ���� �� ��������
    try{
    Kompleksni_chisla komp_ch(4, 3);           //��������� ��'���� komp_ch ����� ��������� �����
    Vector vec(1, -2, -3, 4, -5, 6, -7, -8, 9, -10);        //��������� ��'���� vec ����� ������
    Matrix matrix(-2, 6, -8, 5);                   //��������� ��'���� matrix ����� �������
    Norma* k, * v, * m;                      //��������� �� ������� ����
    k = &komp_ch;                            //������������ ��������� �� ������� ����
    v = &vec;                                //�������� ��������� �� �������� ����
    m = &matrix;     // ������ �� ���������� ������� ����� �������� �� ������� ����:
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
