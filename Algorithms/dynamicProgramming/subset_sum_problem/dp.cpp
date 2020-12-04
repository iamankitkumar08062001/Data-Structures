#include<bits/stdc++.h>
#include<climits>
#include<cmath>

using namespace std;

typedef unsigned long long int UINT;
typedef long long int INT;

bool equalPartition(vector<UINT> &array, INT sum);
bool equalPartition_helper(vector<UINT> &array, INT sum, INT n, vector<vector<INT>> &ans);

int main() {
    vector<UINT> array = {3, 34, 4, 12, 5, 2};
    UINT sum = 9;

    if(equalPartition(array, 10)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}

bool equalPartition(vector<UINT> &array, INT sum) {
    vector<vector<INT>> ans(array.size() + 1, vector<INT>(sum + 1, INT_MIN));

    equalPartition_helper(array, sum, array.size(), ans);

    return ans[array.size()][sum];
}

bool equalPartition_helper(vector<UINT> &array, INT sum, INT n, vector<vector<INT>> &ans) {
    if(sum == 0) {
        return true;
    }
    else if(sum < 0) {
        return false;
    }
    else if(n == 0) {
        return false;
    }
    else if(ans[n][sum] != INT_MIN) {
        if(ans[n][sum] == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        ans[n][sum] = equalPartition_helper(array, sum, n - 1, ans) || equalPartition_helper(array, sum - array[n - 1], n - 1, ans); 
        if(ans[n][sum] == 1) {
            return true;
        }
        else {
            return false;
        }
    }
}