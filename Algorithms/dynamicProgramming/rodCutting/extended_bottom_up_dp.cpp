#include<bits/stdc++.h>
#include<climits>

//This is a program to illustrates Rod cutting through a DP soln
//The below implementation is extended to returns solution pieces also

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
string cut_rod(UINT n, vector<UINT> &price);

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

    cout << "\nThe optimal cut is " + cut_rod(n, price) << "\n";

    return 0;
}

//Function Definitions

string cut_rod(UINT n, vector<UINT> &price) {
    if(n == 0) {
        return to_string(0);
    }
    else if(n == 1) {
        return to_string(n) + " + " + to_string(0);
    }
    else {
        vector<UINT> optimal_solutions(n + 1);
        optimal_solutions[0] = 0;
        optimal_solutions[1] = price[1];

        vector<string> solns(n + 1, "");
        solns[0] = to_string(0);
        solns[1] = to_string(1);
    
        UINT max;

        for(UINT i = 2; i <= n; i++) {
            optimal_solutions[i] = price[i];
        
            solns[i] = to_string(i);

            for(UINT j = 1; j <= (i/2); j++) {
                max = utility::max(optimal_solutions[i], price[j] + optimal_solutions[i - j]);
            
                if(max != optimal_solutions[i]) {
                    solns[i] = to_string(j) + " + " + solns[i - j];
                }
            
                optimal_solutions[i] = max;
            }
        }

        return solns[n];
    }
}