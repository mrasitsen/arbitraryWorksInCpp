#include <iostream>
#include <algorithm>
using namespace std;

int main(){

int a[] = {10,5,74,32,45,62,12,112,4,32,12,55,143,21,5};
int n = sizeof(a) / sizeof(a[0]);

	for (int i = n-1; i >= 1; i--) {

	int maxitem = 0;

		for (int j = 0; j <= i; j++){

			if(a[j] > a[maxitem]){
				maxitem = j;
			}
		}
	swap(a[i], a[maxitem]);
	}		

	for (int i = 0; i < n; ++i){

		cout << a[i] <<"\t";
	}
}
