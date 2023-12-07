/* File:    main.cpp
 * Author:  Danielle F
 * Created: 11-27-2023 @ 10 PM
 * Purpose:  Quick sort timing analysis v2_random pivot partition
 * https://www.geeksforgeeks.org/quick-sort/
 * https://www.geeksforgeeks.org/quicksort-using-random-pivoting/
 * 
 * Average Case: θ ( N log (N))
 * 
 * Worst Case: O(N2)
 * The worst-case Scenario for Quicksort occur when the pivot 
 * at each step consistently results in highly unbalanced 
 * partitions. When the array is already sorted and the pivot 
 * is always chosen as the smallest or largest element. 
 * To mitigate the worst-case Scenario, various techniques 
 * are used such as choosing a good pivot (e.g., median of three) 
 * and using Randomized algorithm (Randomized Quicksort ) to shuffle 
 * the element before sorting.
*/

//System Libraries
#include <bits/stdc++.h> 
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

// This function takes last element
// as pivot, places
// the pivot element at its correct
// position in sorted array, and 
// places all smaller (smaller than pivot)
// to left of pivot and all greater 
// elements to right of pivot
int partition(int arr[], int low, int high)
{
    // pivot
    int pivot = arr[high]; 
   
    // Index of smaller element
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++) 
    {
        // If current element is smaller
        // than or equal to pivot
        if (arr[j] <= pivot) {
 
            // increment index of 
            // smaller element
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);
 
    return partition(arr, low, high);
}
 
/* The main function that implements
QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
 
        /* pi is partitioning index,
        arr[p] is now
        at right place */
        int pi = partition_r(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout<<arr[i]<<" "; 
}
 
// Driver's code
int main(int argc, char** argv) {
    
    //Set the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //int arr[] = { 12, 11, 13, 5, 6, 7 };
    //int n = sizeof(arr) / sizeof(arr[0]);
    int n = 55000;//v1 without random pivot partition breaks at 30600
    int arr[n] = {};
    int num=n;
    for(int i=0;i<n;i++){
        --num;
        arr[i]=num;
    }
    
    //cout << "UnSorted array is \n";
    //printArray(arr, n);
    
    // Timing analysis
    int beg=time(0);
    int nLoops=1;
    //for(int i=0;i<nLoops;i++)
    //{
        quickSort(arr,0,n-1);
    //}
    int totTime=time(0)-beg;
    cout<<endl<<"n="<<n<<"\nnLoops="<<nLoops<<"\nTotal Run Time = "<<totTime<<" Seconds\n\n";
    
    //cout << "Sorted array is \n";
    //printArray(arr, n);
}

