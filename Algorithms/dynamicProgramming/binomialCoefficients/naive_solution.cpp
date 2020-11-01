#include<bits/stdc++.h>
#include<cmath>
#include<climits>

/*Method 1:-
* ==========
* Warning -> This will cause Intger overflow for large Integers
* Calcuate n!, r! and (n - r)! in nCr 
* 
* Method 2:-
* ==========
* This is a Naive solution to calculate binomial coefficient 
* Key Concept -> The relation nCr = (n - 1)Cr + (n - 1)C(r-1) as seen in Pascal Triangle
* for method 2
*/

using namespace std;
typedef unsigned long long int UINT;
typedef long long int INT;

//Two Methods
UINT binomial_coefficient1(UINT n, UINT r);
UINT binomial_coefficient2(UINT n, UINT r);

int main() {
    UINT n, r;
    cout << "\nFor any polyomial like (1 + x)^n...";
    cout << "\nEnter the value of n : ";
    cin >> n;
    cout << "Enter the value of r in x^r : ";
    cin >> r;

    cout << "\nThe coefficient is : " << binomial_coefficient1(n, r);

    return 0;
}

UINT binomial_coefficient1(UINT n, UINT r) {
    UINT n1, n2, n3;
    n1 = n2 = n3 = 1;

    for(UINT i = 1; i <= n; i++) {
        n1 *= i;
    }

    for(UINT i = 1; i <= r; i++) {
        n2 *= i;
    }

    for(UINT i = 1; i <= (n - r); i++) {
        n3 *= i;
    }

    return (n1/(n2*n3));
}

UINT binomial_coefficient2(UINT n, UINT r) {
    if(n == r || r == 0) {
        return 1;
    }
    else {
        return binomial_coefficient2(n - 1, r) + binomial_coefficient2(n - 1, r - 1);
    }
}