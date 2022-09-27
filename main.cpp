#include <iostream>
#include <chrono>
#include<cstdlib>
#include <stdio.h>
#include <ctime>
#include<list>
#include<cmath>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;
	
class sizeableArray
{
    int size;
public:
    sizeableArray(int size)
    {   
        this->size = size;
    }

    ~sizeableArray()
    {

    }
  

};

void fillArr( int* Arr, int size)
{
    srand(time(0));
    int max = 2*size;

    for(int i = 0; i < size; i++)
    {
        Arr[i] =  rand() % max;
    }

}






void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++){
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl;
} 

int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}


void radixSort(int *arr, int n, int max) {
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket[10];      //radix of decimal number is 10
   for(i = 0; i< max; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;      //find index for pocket array
         pocket[index].push_back(arr[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}

void merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
/* begin is for left index and end is
right index of the sub-array
of array to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}



int main()
{
    int data[5][5];
    int totalTime;

    for(int i = 1; i < 6; i ++)
    {
        int size;
        string length;

        switch(i)
        {
            case 1:
                size = 10;
                length = size;
                break;
            case 2:
                size = 100;
                length = size;
                break;
            case 3:
                size = 500;
                length = size;
                break;
            case 4:
                size = 5000;
                length = size;
                break;
            case 5:
                size = 25000;
                length = size;
                break;
        }

        auto t0 = Clock::now();

        int Arr[size];
        fillArr(Arr, size);
        
        auto t1 = Clock::now();
        bubbleSort(Arr, size);
        auto t2 = Clock::now();
        data[i-1][0] = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

        auto t3 = Clock::now();
	    insertionSort(Arr, size);
	    auto t4 = Clock::now();
        data[i-1][1] = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count();

        auto t5 = Clock::now();
	    mergeSort(Arr, 0, size);
    	auto t6 = Clock::now();
        data[i-1][2] = std::chrono::duration_cast<std::chrono::milliseconds>(t6 - t5).count();

        auto t7 = Clock::now();
    	quickSort(Arr, 0, size);
    	auto t8 = Clock::now();
        data[i-1][3] = std::chrono::duration_cast<std::chrono::milliseconds>(t8 - t7).count();

        auto t9 = Clock::now();
	    radixSort(Arr, size, (2*size));
    	auto t10 = Clock::now();
        data[i-1][4] = std::chrono::duration_cast<std::chrono::milliseconds>(t10 - t9).count();

        auto t11 = Clock::now();
        cout <<"Run " << i <<" - "<< size <<" items:\t" <<std::chrono::duration_cast<std::chrono::seconds>(t11 - t0).count() << " seconds\n";
        totalTime = totalTime + std::chrono::duration_cast<std::chrono::seconds>(t11 - t0).count();
    }
    
    cout << "Total time:\t\t" << totalTime << " seconds\n";

    cout <<"\nMethod\t\t10 Items\t100 Items\t500 Items\t5000 Items\t25000 Items\n";

    cout<<"Bubble sort\t";
    for(int i = 0; i < 5; i++){cout << data[i][0] <<" ms\t\t";}
    cout<<"\nInsertion sort\t";
    for(int i = 0; i < 5; i++){cout << data[i][1] <<" ms\t\t";}
    cout<<"\nMerge-sort\t";
    for(int i = 0; i < 5; i++){cout << data[i][2] <<" ms\t\t";}
    cout<<"\nQuicksort\t";
    for(int i = 0; i < 5; i++){cout << data[i][3] <<" ms\t\t";}
    cout<<"\nRadix-sort\t";
    for(int i = 0; i < 5; i++){cout << data[i][4] <<" ms\t\t";}

}
/*We copied files from lab 2 and just deleted the content
from the other files and then wrote our own main. The program
can take between 2 and 5 minutes to completely output everything, 
so just be patient and five it time as it compiles. Thanks! */