/* File:    main.cpp
 * Author:  Danielle F
 * Created: 11-27-2023 @ 10 PM
 * Purpose:  Shell sort timing analysis v1 
 * https://www.geeksforgeeks.org/shellsort/?ref=header_search
 *  
 * Average Case: O(n*log n)~O(n1.25)
 * 
 * Worst Case: O(n^2)
 * 
 * Heap sort surpasses shell sort in efficiency 
 * as we approach 2000 elements to be sorted.
*/

//System Libraries
#include <bits/stdc++.h> 
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
 /* function to sort arr using shellSort */
int shellSort(int arr[], int n) 
{ 
    // Start with a big gap, then reduce the gap 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = gap; i < n; i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i]; 
  
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
              
            //  put temp (the original a[i]) in its correct location 
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 
  
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; i++) 
        cout << arr[i] << " "; 
} 
 
// Driver's code
int main(int argc, char** argv) {
    
    //Set the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //int arr[] = { 12, 11, 13, 5, 6, 7 };
    //int n = sizeof(arr) / sizeof(arr[0]);
    
    // Timing analysis
    int beg=time(0);
    int n, nLoops=65000;//breaks at 
    for(int i=0;i<nLoops;i++)
    {
        n = 2100;
        int arr[n] = {};
        int num=n;
        for(int i=0;i<n;i++){
            --num;
            arr[i]=num;
        }
    
        //cout << "UnSorted array is \n";
        //printArray(arr, n);
    
    
        shellSort(arr, n); 
    }
    int totTime=time(0)-beg;
    cout<<endl<<"n="<<n<<"\nnLoops="<<nLoops<<"\nTotal Run Time = "<<totTime<<" Seconds\n\n";
    
    //cout << "Sorted array is \n";
    //printArray(arr, n);
}

