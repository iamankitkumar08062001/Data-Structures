#include<bits/stdc++.h>

//This is a implementation of the Merge Sort Algorithm
//Some Details:-
//1. No Type Checking
//2. No Error Handling
//3. Valid for Only Primitive Data Types

using namespace std;

//NameSpace to hold Function Prototypes
namespace mergeSortAlgo {
    //Main Algorithm Procedure
    void mergeSort(vector<int> &arr, int start, int end);
    //Combine and Conquer Procedure
    void merge(vector<int> &arr, int start, int end);
}

void printArray(vector<int> &arr);
void printArray(vector<int> &arr, int start, int end);
void printArray(vector<int> &arr, string space_char, string end);

int main() {
    
    int n;
    cout << "\nEnter the size of the array : ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the Array : ";
    for(vector<int>::iterator it = arr.begin(), temp; it != arr.end(); it++) {
        cin >> *it;
    }

    cout << "\nArray before Sort : ";
    printArray(arr);

    mergeSortAlgo::mergeSort(arr, 0, arr.size() - 1);

    cout << "\nArray After Sort : ";
    printArray(arr, " ", "\n\n");

    return 0;
}

void mergeSortAlgo::mergeSort(vector<int> &arr, int start, int end) {
    if(start >= end) {
        return;
    }
    else {
        int mid = (start + end)/2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end);

        return;
    }
}

void mergeSortAlgo::merge(vector<int> &arr, int start, int end) {
    if(start >= end) {
        return;
    }
    else {
        int mid = (start + end)/2;

        vector<int> left(mid + 1 - start);
        vector<int> right(end - mid);
        
        //Storing into new arrays for further operations
        for(int k = start, i = 0; k <= mid; i++, k++) {
            left[i] = arr[k];
        }

        for(int k = mid + 1, j = 0; k <= end; j++, k++) {
            right[j] = arr[k];
        }

        //Combination Step
        int i, j, k; 
        i = j = 0;
        k = start;

        while(i <= (mid - start) && j <= (end - 1 - mid)) {
            if(left[i] >= right[j]) {
                arr[k] = right[j];
                j++;
            }
            else {
                arr[k] = left[i];
                i++;
            }
            k++;
        }

        //Left-Overs
        while(i <= (mid - start)) {
            arr[k] = left[i];
            k++, i++;
        }

        while(j <= (end - 1 - mid)) {
            arr[k] = right[j];
            k++, j++;
        }

        return;
    }
}


void printArray(vector<int> &arr) {
    for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
    return;
}

void printArray(vector<int> &arr, int start, int end) {
    for(int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return;
}

void printArray(vector<int> &arr, string space_char, string end) {
    for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        cout << to_string(*it) + space_char;
    }
    cout << end;
    return;
}
