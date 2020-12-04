#include<bits/stdc++.h>
#include<climits>
#include<cmath>

using namespace std;

typedef unsigned long long int UINT;
typedef long long int INT;

bool equalPartition(vector<UINT> &array, INT sum, INT n);

int main() {
    vector<UINT> array = {3, 34, 4, 12, 5, 2};
    UINT sum = 30;

    if(equalPartition(array, 10, array.size())) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}

bool equalPartition(vector<UINT> &array, INT sum, INT n) {
    if(sum == 0) {
        return true;
    }
    else if(sum < 0) {
        return false;
    }
    else if(n == 0) {
        return false;
    }
    else {
        return equalPartition(array, sum, n - 1) || equalPartition(array, sum - array[n - 1], n - 1); 
    }
}