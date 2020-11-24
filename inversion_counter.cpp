#include <iostream>

using namespace std; //divide&conquer  O(n^2) merge-sort kullanilmadi

int main(){

   int counter = 0;

   int numInversion = 0;

   int Array[100000];

   for (int i = 0; i < 100000; ++i)
   {
      cin >> Array[i];
   }

   size_t size = sizeof(Array) / sizeof(Array[0]);

   for (size_t i = 0; i < size-1; ++i)
   {
      for (size_t j = i+1; j < size; ++j)
      {
         counter += 1;

         if (Array[i] > Array[j])
         {
            //cout << "pair("<<Array[i]<<","<<Array[j]<<")"<<endl;
            numInversion += 1;
         }
      }
   }

   cout << "counter: " << counter << endl;
   cout <<"number of inversion in given array: " << numInversion << endl;

   return 0;
}