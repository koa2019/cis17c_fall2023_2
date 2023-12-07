/* File:    main.cpp
 * Author:  Danielle F
 * Created: 11-27-2023 @ 10 PM
 * Purpose:  Quick sort timing analysis v1 
 * https://www.geeksforgeeks.org/quick-sort/
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

//Function Prototypes
 int partition(int arr[],int low,int high)
{
  //choose the pivot
   
  int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);
   
  for(int j=low;j<=high;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}
 
// The Quicksort function Implement
            
void quickSort(int arr[],int low,int high)
{
  // when low is less than high
  if(low<high)
  {
    // pi is the partition return index of pivot
     
    int pi=partition(arr,low,high);
     
    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}
 
// Driver's code
int main(int argc, char** argv) {
    
    //Set the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //int arr[] = { 12, 11, 13, 5, 6, 7 };
    //int n = sizeof(arr) / sizeof(arr[0]);
    int n = 30400;//breaks at 30600
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

