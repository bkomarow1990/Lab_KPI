#include <iostream>
#include<math.h>
#include<vector>

class Complex {
public:
    Complex() { re = 0; im = 0; }
    Complex(double r) { re = r; im = 0; }
    Complex(double r, double i) { re = r; im = i; }

    double getRe() { return re; }
    double getIm() { return im; }
    void setRe(double r) { re = r; }
    void setIm(double i) { im = i; }

    bool operator == (Complex C) { return (fabs(this->re - C.getRe()) < 1e-8) && (fabs(this->im - C.getIm()) < 1e-8); }
    bool operator != (Complex C) { return (fabs(this->re - C.getRe()) > 1e-8) || (fabs(this->im - C.getIm()) > 1e-8); }

private:
    static int count;
    double re, im;
};
int Complex::count = 0;

class Base_Abstract_Class
{
public:
    static int count;
    virtual double norm() abstract;
};
int Base_Abstract_Class::count = 0;
class Norm_Matrix : public Base_Abstract_Class
{
public:
    static const size_t Size = 2;
    Norm_Matrix(int m[Size][Size])
    {
        setMatrix(m);
    }
    void setMatrix(int m[Size][Size]) {
        for (size_t i = 0; i < Size; i++)
        {
            for (size_t j = 0; j < Size; j++)
            {
                matrix[i][j] = m[i][j];
            }
        }
    }
    virtual double norm() override {
        double max = matrix[0][0];
        for (size_t i = 0; i < Size; i++)
        {
            for (size_t j = 0; j < Size; j++)
            {
                if (max < matrix[i][i]) {
                    max = matrix[i][i];
                }
            }
        }
        return abs(max);
    }

protected:
    int matrix[2][2];
};


class Norm_vector : public Base_Abstract_Class
{
public:
    const size_t Size = 10;
    Norm_vector(int arr[])
    {
        setElemsInVector(arr);
        ++count;
    }
    Norm_vector(std::vector<int> sendVector)
    {
        if (sendVector.size() == 10)
            this->list_elem = sendVector;

    }
    void setElemsInVector(int arr[]) {
        try
        {
            auto elem = arr[9];
        }
        catch (const std::out_of_range)
        {
            std::cout << "This array have not valid size " << std::endl;
        }
        for (size_t i = 0; i < Size; i++)
        {
            list_elem.push_back(arr[i]);
        }
    }
    virtual double norm() {
        int result = 0;
        for (auto& elem : list_elem)
        {
            result += abs(elem);
        }
        return sqrt(result);
    }
private:
    static int count;
protected:
    std::vector<int> list_elem;
};
int Norm_vector::count = 0;

class Norm_Complex : public  Base_Abstract_Class
{
public:
    Norm_Complex(Complex number)
    {
        complexNumber = number;
        ++count;
    }
    virtual  double norm() {
        return abs(pow(complexNumber.getRe(), 2) + pow(complexNumber.getIm(), 2));
    }
private:
    Complex complexNumber;
    static int count;
};
int Norm_Complex::count = 0;
using namespace std;
int main()
{
    try{
    int arr[] = { 1,2,3,4,5,6,7,8,9 };
    Norm_vector v(arr);
    std::cout << "Func vector norm: " << v.norm() << std::endl;
    int m[][2] = { {1,2},{3,5} };
    Norm_Matrix objM(m);
    std::cout << "Func matrix norm: " << objM.norm() << std::endl;
    Norm_Complex compexNorm(Complex(3, 5));
    std::cout << "Func complex norm: " << compexNorm.norm() << std::endl;
    }
    catch (const exception& ex) {
        cerr << ex.what() << endl;
    }
    catch (...) {
        cerr << "Error" << endl;
    }
}
