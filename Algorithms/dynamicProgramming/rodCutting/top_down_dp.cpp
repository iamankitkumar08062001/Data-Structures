#include<bits/stdc++.h>
#include<climits>

//This is a program to illustrates Rod cutting through a DP soln
//The below implementation doesn't return solution pieces it just returns the maximum price 

using namespace std;
typedef unsigned long long int UINT;
typedef long long int INT;

//A class to contain utlity functions
class utility {
    public:
        static UINT max(UINT a, UINT b) {
            return (a > b) ? a : b;
        }
};

//Solution
UINT cut_rod(UINT n, vector<UINT> &price);
UINT cut_rod_helper(UINT n, vector<UINT> &price, vector<UINT> &optimal_solutions);

//Driver Function
int main() {
    UINT n;
    cout << "\nEnter the length of the rod : ";
    cin >> n;

    //Price Table
    vector<UINT> price(n + 1);
    price[0] = 0;
    cout << "\nEnter the Prices...\n\n";

    for(UINT i = 1; i <= n; i++) {
        cout << "Enter the price of " + to_string(i) + " length rod : ";
        cin >> price[i];
    }

    cout << "\nThe maximum revenue obtainable is " + to_string(cut_rod(n, price)) << "\n";

    return 0;
}

//Function Definitions

UINT cut_rod(UINT n, vector<UINT> &price) {
    vector<UINT> optimal_solutions(n + 1, INT_MIN);
    optimal_solutions[0] = 0;

    cut_rod_helper(n, price, optimal_solutions);

    return optimal_solutions[n];
}

//The below function calculates the max using the formula
//max(p[n], p[1] + r(n - 1), p[2] + r(n - 2), ...., p[i] + r(n - i) , ....) ; i = 0, 1, 2, 3, ..... 
//and i <= n/2
//This method only decomposes the remainder further and simpifies the recursion tree greatly
UINT cut_rod_helper(UINT n, vector<UINT> &price, vector<UINT> &optimal_solutions) {
    if(n == 0) {
        return price[0];
    }
    else if(n == 1) {
        return price[1];
    }
    else if(optimal_solutions[n] != INT_MIN) {
        return optimal_solutions[n];
    }
    else {
        UINT max_rev = price[n];

        for(UINT i = 1; i <= (n/2); i++) {
            max_rev = utility::max(max_rev, price[i] + cut_rod_helper(n - i, price, optimal_solutions));
        }

        optimal_solutions[n] = max_rev;
        return max_rev;
    }
}