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

int LCS_length(string s1, string  s2);
int LCS_length_helper(string s1, string  s2, int i, int j, vector<vector<int>> &answer);

int main() {
    string s1, s2;

    s1 = "AGGTAB";
    s2 = "GXTXAYB";

    cout << "\nThe Longest SubString length is " << LCS_length(s1, s2) << "\n";

    return 0;
}

int LCS_length(string s1, string  s2) {
    vector<vector<int>> answer(s1.length(), vector<int>(s2.length(), INT_MIN));

    LCS_length_helper(s1, s2, s1.length() - 1, s2.length() - 1, answer);

    return answer[s1.length() - 1][s2.length() - 1];
}

int LCS_length_helper(string s1, string  s2, int i, int j, vector<vector<int>> &answer) {
    if(i == -1 || j == -1) {
        return 0;
    }
    else if(answer[i][j] != INT_MIN) {
        return answer[i][j];
    }
    else {
        if(s1.at(i) == s2.at(j)) {
            answer[i][j] = 1 + LCS_length_helper(s1, s2, i - 1, j - 1, answer); 
        }
        else {
            answer[i][j] = utility::max(LCS_length_helper(s1, s2, i - 1, j, answer), LCS_length_helper(s1, s2, i, j - 1, answer));
        }
        return answer[i][j];
    }
}