#include <iostream>
#include <algorithm>
using namespace std;
template<typename T>
T getProductArray(T arr[], int size) {
	T product= 1;
	for (size_t i = 0; i < size; i++)
	{
		product *= arr[i];
	}
	return product;
}
void task1() {
	int* arr = new int[5]{ 1,2,3,4,5 };
	cout << getProductArray(arr, 5) << endl;

}

template<typename T>
void bubbleSort(T arr[], int n)
{
	int i, j;
	T tmp;
	for (i = 0; i < n - 1; i++){
		for (j = 0; j < n - i - 1; j++){
			if (arr[j] > arr[j + 1]){
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
class my_Type {
	string name;
public:
	const int& getSize() const{
		return name.size();
	}
	const string& getName()const {
		return name;
	}
	my_Type(string name="NoName")
	{
		this->name = name;
	}
	const bool& operator<(const my_Type& obj) {
		if (this->getSize() < obj.getSize())
		{
			return true;
		}
		else if (this->getSize() == obj.getSize())
		{
			return this->name < obj.getName();
		}
		else if(this->getSize() > obj.getSize()){
			return false;
		}
	}
	const bool& operator>(const my_Type& obj) {
		if (this->getSize() > obj.getSize())
		{
			return true;
		}
		else if (this->getSize() == obj.getSize())
		{
			return this->name > obj.getName();
		}
		else if (this->getSize() < obj.getSize()) {
			return false;
		}
	}
};
int main() {
	my_Type* arr = new my_Type[3];
	arr[0] = my_Type("Test2");
	arr[1] = my_Type("Test");
	
	arr[2] = my_Type("1");
	
	
	bubbleSort(arr, 3);
	for (size_t i = 0; i < 3; i++)
	{
		cout << arr[i].getName() << endl;
	}

	return 0;
}