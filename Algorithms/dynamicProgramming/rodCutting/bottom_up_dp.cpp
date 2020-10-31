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
    vector<UINT> optimal_solutions(n + 1);
    optimal_solutions[0] = 0;
    optimal_solutions[1] = price[1];

    for(UINT i = 2; i <= n; i++) {
        optimal_solutions[i] = price[i];
        for(UINT j = 1; j <= (n/2); j++) {
            optimal_solutions[i] = utility::max(optimal_solutions[i], price[j] + optimal_solutions[i - j]);
        }
    }

    return optimal_solutions[n];
}