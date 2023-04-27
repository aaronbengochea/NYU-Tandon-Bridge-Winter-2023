#include <iostream>
#include <vector>
#include <string>

using namespace std;

//size_t == unsigned int

int findIndex(const vector<int>& v, int toFind) { //Linear Search: Theta(n)
	for (size_t i = 0; i < v.size(); i++) //Theta(n)
		if (v[i] == toFind) //Theta(1)
			return i;
	return -1;
}

int binarySearch(const vector<int>& v, int toFind) { //Theta(log N)
	if (v.size() <= 0)
		return -1;
	size_t low = 0;
	size_t high = v.size() - 1;
	while (low <= high) {
		size_t mid = (low+high) / 2;
		if (v[mid] == toFind)
			return mid;
		else if (v[mid] > toFind) //toFind is a value less than the mid, so look to left!
			high = mid - 1;
		else //look to the right!
			low = mid + 1;
	}
	return -1;
}

void selectionSort(vector<int>& v) { //(n(n-1))/2 Theta(n^2)
	for (size_t i = 0; i < v.size(); i++) { //Theta(N)
		int index_of_min = i;
		for (size_t j = i + 1; j < v.size(); j++) //Theta((n-1)/2)
			if (v[j] < v[index_of_min])
				index_of_min = j;
		int temp = v[index_of_min];
		v[index_of_min] = v[i];
		v[i] = temp;
	}
}

void insertionSort(vector<int>& v) { //Best Case: Theta(n), worst Case: Theta(n^2), average: Theta(n^2)
	for (size_t i = 1; i < v.size(); i++) { //Theta(n)
		size_t j = i;
		int curr = v[i];
		while (j > 0 && v[j - 1] > curr) { // Worst case: Theta((n-1)/2)
			v[j] = v[j - 1];
			j--;
		}
		v[j] = curr;
	}
}

void merge(vector<int>& v, vector<int>& temp, int start, int mid, int end) {
	int leftpos = start;
	int rightpos = mid + 1;
	int temppos = start;
	while (leftpos <= mid && rightpos <= end) {
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
void mergeSort(vector<int>& v, vector<int>& temp, int start, int end) {//Theta (N log N)
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(v, temp, start, mid); //sort the two halves, recursively
		mergeSort(v, temp, mid + 1, end);
		merge(v, temp, start, mid, end);

	}
}
void mergeSort(vector<int>& v) { //driver
	vector<int> temp;
	temp.resize(v.size());
	mergeSort(v, temp, 0, v.size() - 1);
}
void insertionSort(vector<int>& v, int start, int end) { //Best Case: Theta(n), worst Case: Theta(n^2), average: Theta(n^2)
	for (size_t i = start+1; i < end; i++) { //Theta(n)
		size_t j = i;
		int curr = v[i];
		while (j > start && v[j - 1] > curr) { // Worst case: Theta((n-1)/2)
			v[j] = v[j - 1];
			j--;
		}
		v[j] = curr;
	}
}
void quicksort(vector<int>& v, int start, int end) {//worst case: Theta(n^2) average: Theta(N log N)
	if ((start + 10) > end) {
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

	int pivot = v[center];
	swap(v[center], v[end - 1]);
	int i = start;
	int j = end - 1;
	for (;;) { //same as while(true)
		while (v[++i] < pivot) {}
		while (pivot < v[--j]) {}
		if (i < j)
			swap(v[i], v[j]);
		else
			break;
	}
	swap(v[i], v[end - 1]);//Move pivot into its final position!

	quicksort(v, start, i - 1);
	quicksort(v, i + 1, end);

}


void quicksort(vector<int>& v) {
	quicksort(v, 0, v.size() - 1);
}

int main() {



}