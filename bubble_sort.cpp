#include <iostream>
#include <algorithm>

using namespace std;

void bubblesort(int array[], int length){

	for (int i = length-1; i>=1 ; i--)
	{
		for (int j = 0; j < i ; j++)
		{
			if(array[j] > array[j+1])
				swap(array[j],array[j+1]);
		}
	}

}


int main(){

	int a[] = {12,32,43,12,32};
	int lenA = sizeof(a) / sizeof(a[0]);

	bubblesort(a,lenA);

	for (int i = 0; i < lenA; ++i)
	{
		cout << a[i] <<"\t";
	}

	return 0;
}