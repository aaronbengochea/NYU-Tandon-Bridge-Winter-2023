#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

template <class T>
int linearSearch(vector<T>& v, T item){ //O(N)
	for (int i = 0; i < v.size(); i++)
		if (v[i] == item)
			return i;
	return -1;
}


template <class T>
class DynArray{
	T* arr;
	int capacity;
	int numOfItems;
public:
	DynArray() :arr(nullptr), capacity(0), numOfItems(0){}
	~DynArray(){ delete[] arr; }
	DynArray(const DynArray& rhs) :arr(nullptr){ *this = rhs; }
	void pop_back(){ if (numOfItems > 0)numOfItems--; }
	T& operator[](int position){ return arr[position]; }
	T operator[](int position)const{ return arr[position]; }

	DynArray& operator=(const DynArray& rhs);
	void push_back(const T& value);
	void resize(int newsize);
};
template <class T>
void DynArray<T>::push_back(const T& value){
	if (capacity == numOfItems)
		resize(capacity * 2);
	arr[numOfItems++] = value;
}





template <class T>
int binarySearch(vector<T>& v, T item, int start, int end){
	int mid = (start + end) / 2;
	if (start > end) //it's not in the vector
		return -1;
	if (v[mid] == item)
		return mid;
	else if (v[mid]>item) //mid is greater so item would be on the left
		return binarySearch(v, item, start, mid - 1);
	else //item would be on the right
		return binarySearch(v, item, mid+1,end);
}
template <class T>
int binarySearch(vector<T>& v, T item){ //driver
	return binarySearch(v, item, 0, v.size() - 1);
}

template <class T>
void selectionSort(vector<T>& v){ //O(N^2)
	for (int i = 0; i < v.size(); i++){
		int indexOfLowest = i;
		for (int j = i + 1; j < v.size(); j++)
			if (v[j] < v[indexOfLowest])
				indexOfLowest = j;
		T temp = v[i];
		v[i] = v[indexOfLowest];
		v[indexOfLowest] = temp;
	}
}

void merge(vector<int>& v, vector<int>& temp, int start, int mid, int end){
	int leftpos = start;
	int rightpos = mid + 1;
	int temppos = start;
	while (leftpos <= mid && rightpos <= end){
		if (v[leftpos] < v[rightpos])
			temp[temppos++] = v[leftpos++];
		else
			temp[temppos++] = v[rightpos++];
	}
	while (leftpos <= mid)
		temp[temppos++] = v[leftpos++];
	while (rightpos <= mid)
		temp[temppos++] = v[rightpos++];
	for (int i = start; i <= end; i++)
		v[i] = temp[i];

}
void mergeSort(vector<int>& v, vector<int>& temp, int start, int end){
	if (start < end){
		int mid = (start + end) / 2;
		mergeSort(v, temp, start, mid); //sort the two halves, recursively
		mergeSort(v, temp, mid + 1, end);
		merge(v, temp, start, mid, end);

	}
}
template <class T>
void quicksort(vector<T>& v, int start, int end){
	if ((start + 10) > end){
		insertionSort(v, start, end);
		return;
	}
	int center = (start + end) / 2;
	if (v[center] < v[start])  //begin median-of-three partitioning
		swap(v[center], v[start]);
	if (v[end] < v[start])
		swap(v[end], v[start]);
	if (v[end] < v[center])
		swap(v[end], v[center]);

	T pivot = v[center];
	swap(v[center], v[end - 1]);
	int i = start;
	int j = end - 1;
	for (;;){
		while (v[++i] < pivot){}
		while (pivot < v[--j]){}
		if (i < j)
			swap(v[i], v[j]);
		else
			break;
	}
	swap(v[i], v[end - 1]);//Move pivot into its final position!

	quicksort(v, start, i - 1);
	quicksort(v, i + 1, end);

}

template <class T>
void quicksort(vector<T>& v){
	quicksort(v, 0, v.size() - 1);
}



void mergeSort(vector<int>& v){ //driver
	vector<int> temp;
	temp.resize(v.size());
	mergeSort(v, temp, 0, v.size() - 1);
}

class Timer{
	int start;
public:
	Timer(){ start = clock(); }
	void reset(){ start = clock(); }
	double elapsed(){ return ((double)(clock() - start) / CLOCKS_PER_SEC); }
};

int main(){

	DynArray<int> d;
	vector<int> v;

	int stepSize = 10000;
	srand(time(NULL)); //Seed the random number generator
	Timer t;
	double elapsed;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < stepSize; j++){
			v.push_back(rand());
		}
		t.reset();
		mergeSort(v);
		elapsed = t.elapsed();
		cout << "v.size()=" << v.size() << "; sorting took " << elapsed << " seconds" << endl;
	}
}