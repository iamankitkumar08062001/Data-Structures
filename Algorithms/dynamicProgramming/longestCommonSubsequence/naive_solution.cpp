#include<bits/stdc++.h>
#include<climits>
#include<cmath>

using namespace std;

namespace utility {
    int min(int a, int b) {
        return (a > b)? b : a;
    }

    int max(int a, int b) {
        return (a > b)? a : b;
    }
};

int LCS_length(string s1, string  s2, int i, int j);

int main() {
    string s1, s2;

    s1 = "AGGTAB";
    s2 = "GXTXAYB";

    /*
    cout << "\nEnter the 1st String : ";
    cin >> s1;
    cout << "\nEnter the 2nd String : ";
    cin >> s2;
    */

    cout << "\nThe Longest SubString length is " << LCS_length(s1, s2, s1.length() - 1, s2.length() - 1) << "\n";

    return 0;
}

int LCS_length(string s1, string  s2, int i, int j) {
    cout << "\n" << i << " " << j;
    if(i == -1 || j == -1) {
        return 0;
    }
    else if(s1.at(i) == s2.at(j)) {
        return 1 + LCS_length(s1, s2, i - 1, j - 1); 
    }
    else {
        return utility::max(LCS_length(s1, s2, i - 1, j), LCS_length(s1, s2, i, j - 1));
    }
}