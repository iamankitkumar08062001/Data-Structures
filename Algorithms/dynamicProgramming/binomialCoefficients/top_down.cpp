#include<bits/stdc++.h>
#include<cmath>
#include<climits>

//This is a top-down DP implementation to calculate binomial coefficient 
//Key Concept -> The relation nCr = (n - 1)Cr + (n - 1)C(r-1) as seen in Pascal Triangle

using namespace std;
typedef unsigned long long int UINT;
typedef long long int INT;

UINT binomial_coefficient(UINT n, UINT r);
UINT binomial_coefficient_helper(UINT n, UINT r, vector<vector<UINT>> &solns);

int main() {
    UINT n, r;
    cout << "\nFor any polyomial like (1 + x)^n...";
    cout << "\nEnter the value of n : ";
    cin >> n;
    cout << "Enter the value of r in x^r : ";
    cin >> r;

    cout << "\nThe coefficient is : " << binomial_coefficient(n, r);

    return 0;
}

UINT binomial_coefficient(UINT n, UINT r) {
    vector<vector<UINT>> solns(n + 1);

    for(UINT i = 0; i <= n; i++) {
        solns[i] = vector<UINT>(i + 1, INT_MIN);
    }

    binomial_coefficient_helper(n, r, solns);

    return solns[n][r];
}

UINT binomial_coefficient_helper(UINT n, UINT r, vector<vector<UINT>> &solns) {
    if(n == r || r == 0) {
        solns[n][r] = 1;
        solns[n][0] = 1;
        return 1;
    }
    else {
        if(solns[n][r] == INT_MIN) {
            solns[n][r] = binomial_coefficient_helper(n - 1, r, solns) + binomial_coefficient_helper(n - 1, r - 1, solns);
            solns[n][n - r] = solns[n][r];
        }
        return solns[n][r];   
    }
}