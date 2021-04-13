#include<iostream>

class data
{
public:
    virtual void  showSomthing() = 0;
    virtual void  saveSomthing() = 0;
    virtual void  doSomthing() = 0;
    virtual ~data() { std::cout << "Data deleted" << std::endl; }
};

class signal : public data
{
public:
    virtual void  showSomthing() {}
    virtual void  saveSomthing() {}
    virtual void  doSomthing() {}
    ~signal() { std::cout << "Signal deleted" << std::endl; }
};

class result : public data
{
public:
    virtual void  showSomthing() {}
    virtual void  saveSomthing() {}
    virtual void  doSomthing() {}
};

class subsidiaryData : public data
{
public:
    virtual void  showSomthing() {}
    virtual void  saveSomthing() {}
    virtual void  doSomthing() {}
};
int main()
{
    
    try{
    data* pSignal = new signal();
    delete pSignal;
    data* pResult = new result();
    data* pSubsidiaryData = new subsidiaryData();
    }
    catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
    system("pause");
    return 0;
}
