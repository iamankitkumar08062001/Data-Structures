#include<bits/stdc++.h>

using namespace std;

//Quicksort Implementation using Lomato's Partitioning Scheme

void printArray(vector<int> &array);

namespace quicksortAlgo {
    void swap(int &a, int &b);
    void quicksort(vector<int> &arr, int start, int end);
    int partition(vector<int> &arr, int start, int end);
}

int main() {

    int n;
    cout << "\nEnter the size of the array : ";
    cin >> n;

    vector<int> array(n);

    cout << "\nEnter Array Elements : ";
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cout << "\n";

    /*
    cout << "Array Before Sorting : ";
    printArray(array);
    */

    quicksortAlgo::quicksort(array, 0, array.size() - 1);

    cout << "Array After Sorting : ";
    printArray(array);

    return 0;
}

void quicksortAlgo::quicksort(vector<int> &arr, int start, int end) {
    if(start >= end) {
        return;
    } 
    else {
        bool swaps = false;
        for(int i = 0; i < end; i++) {
            if(arr[i] > arr[i + 1]) {
                swaps = true;
            }
        }

        if(swaps) {
            int q = quicksortAlgo::partition(arr, start, end);
        
            //Calling quicksort on left partition
            quicksortAlgo::quicksort(arr, start, q - 1);
            //Calling quicksort on right partition
            quicksortAlgo::quicksort(arr, q + 1, end);
        }

        return;
    }
}

//In Ascending Order
int quicksortAlgo::partition(vector<int> &arr, int start, int end) {
    int x = arr[end];
    int i = -1, j = 0;

    //Partition the Array
    while(i != end && j != end) {
        if(arr[j] <= x) {
            i += 1;
            swap(arr[j] , arr[i]);
        }
        j++;
    }

    i += 1;
    swap(arr[i], arr[end]);

    return i;
}

void quicksortAlgo::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;

    return;
}

void printArray(vector<int> &array) {
    for(vector<int>::iterator it = array.begin(); it != array.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
    
    return;
}