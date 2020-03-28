#include <iostream>

using namespace std;

void print(const int *const array, int size);
int* apply_all(const int *const arr1, int size1, const int *const arr2, int size2);
int main()
{
	int array1[] {1,2,3,4,5};
	int array2[] {10,20,30};

	cout<<"Array 1: ";
	print(array1,5);

	cout<<"Array 2: ";
	print(array2,3);

	int *results = apply_all(array1, 5, array2, 3);
	cout<<"Result: ";
	print(results,15);

	delete[] results;
	cout<<endl;
	return 0;
}

void print(const int *const array, int size)
{
	cout<<"[ ";
	for(size_t i{0};i<size;i++)
		cout<<array[i]<<" ";
	cout<<"]";
	cout<<endl;
}

int * apply_all(const int *const arr1, int size1, const int *const arr2, int size2)
{
	int *new_array {};
	new_array = new int[size1 * size2];
	int position {0};
	for(size_t i{0}; i<size2; ++i) {
		for(size_t j{0}; j<size1; ++j) {
			new_array[position] = arr2[i] * arr1[j];
			++position;
		}
	}
	return new_array;
}
