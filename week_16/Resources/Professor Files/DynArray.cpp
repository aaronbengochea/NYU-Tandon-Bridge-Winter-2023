#include <iostream>
#include <string>

using namespace std;
template <class T>
class DynArray{
	T* data; //the array for the elements
	int numOfElements; //how many elements
	int cap; //capacity
public:
	DynArray() :cap(5), numOfElements(0){ data = new T[cap]; }
	virtual ~DynArray(){ delete[] data; }
	DynArray(const DynArray<T>& rhs) :data(nullptr){ *this = rhs; }//to save work, the copy constructor could
								//"defaultly" construct an object and then call assignment operator!
	T pop_back(){ 
		if (numOfElements > 0) 
			numOfElements--; 
		return data[numOfElements]; 
	} //delete the last item off of the array
	void clear(){ numOfElements = 0; } //empty the entire array
	int size() const{ return numOfElements; }
	T operator[](int position) const{ return data[position]; }
	T& operator[](int position){ return data[position]; }

	DynArray<T>& operator=(const DynArray<T>& rhs);
	void push_back(const T& newdata); //add an item to the array
	
};
template <class T>
void DynArray<T>::push_back(const T& newdata){
	if (numOfElements == cap){ //adding an elementing to a full array means we need to resize!
		cap *= 2; 
		T * temp = new T[cap];
		for (int i = 0; i < numOfElements; i++)
			temp[i] = data[i];
		
		delete[] data;
		data = temp;
	}
	data[numOfElements++] = newdata; //store the new value at the end of the array and update numOfElements
}

template <class T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T>& rhs){
	if (this == &rhs)//test for self assignment; arr=arr, silly users. :)
		return *this;
	delete[] data;
	numOfElements = rhs.numOfElements;
	cap = rhs.cap;
	data = new T[cap];
	for (int i = 0; i < numOfElements; i++)
		data[i] = rhs.data[i];
	return *this;

}
int main(){
	DynArray<int> d;
	for (int i = 0; i < 100; i++)
		d.push_back(i * 10);

	for (int i = 0; i < d.size(); i++)
		cout << d[i] << endl;

	DynArray<string> ds;
	ds.push_back("Hello");
	ds.push_back("World!");

	for (int i = 0; i < ds.size(); i++)
		cout << ds[i] << endl;
}