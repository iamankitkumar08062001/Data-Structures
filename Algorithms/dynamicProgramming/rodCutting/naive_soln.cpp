#include<bits/stdc++.h>
#include<climits>

//This is a program to illustrate Rod cutting through a brute force solution
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

//Two Methods
UINT cut_rod1(UINT n, UINT price[]);
UINT cut_rod2(UINT n, UINT price[]);

//Driver Function
int main() {
    UINT n;
    cout << "\nEnter the length of the rod : ";
    cin >> n;

    //Price Table
    UINT price[n + 1];
    price[0] = 0;
    cout << "\nEnter the Prices...\n\n";

    for(UINT i = 1; i <= n; i++) {
        cout << "Enter the price of " + to_string(i) + " length rod : ";
        cin >> price[i];
    }

    cout << "\nThe maximum revenue obtainable is " + to_string(cut_rod2(n, price)) << "\n";

    return 0;
}

//Function Definitions

//Method 1
//The below function calculates the max using the formula
//max(p[n], r(1) + r(n - 1), r(2) + r(n - 2), ...., r(i) + r(n - i) , ....) ; i = 0, 1, 2, 3, ..... 
//i <= n/2
UINT cut_rod1(UINT n, UINT price[]) {
    if(n == 0) {
        return price[0];
    }
    else if(n == 1) {
        return price[1];
    }
    else {
        UINT max_rev = price[n];
    
        for(UINT i = 1; i <= (n/2); i++) {
            max_rev = utility::max(max_rev, cut_rod1(i, price) + cut_rod1(n - i, price));
        }

        return max_rev;
    }
}

//Method 2
//The below function calculates the max using the formula
//max(p[n], p[1] + r(n - 1), p[2] + r(n - 2), ...., p[i] + r(n - i) , ....) ; i = 0, 1, 2, 3, ..... 
//and i <= n/2
//This method only decomposes the remainder further and simpifies the recursion tree greatly
UINT cut_rod2(UINT n, UINT price[]) {
    if(n == 0) {
        return price[0];
    }
    else if(n == 1) {
        return price[1];
    }
    else {
        UINT max_rev = price[n];
    
        for(UINT i = 1; i <= (n/2); i++) {
            max_rev = utility::max(max_rev, price[i] + cut_rod2(n - i, price));
        }

        return max_rev;
    }
}