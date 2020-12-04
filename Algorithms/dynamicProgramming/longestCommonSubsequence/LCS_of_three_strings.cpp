#include<bits/stdc++.h>
#include<climits>
#include<cmath>

using namespace std;

typedef unsigned long long int UINT;
typedef long long int INT;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int find_LCS_length(string &str1, int length1, string &str2, int length2, string &str3, int length3, vector<vector<vector<int>>> &answers);

int main() {

    string str1, str2, str3;

    str1 = "geeks";
    str2 = "geeksfor";
    str3 = "geeksforgeeks";

    vector<vector<vector<int>>> answers(str1.length() + 1, vector<vector<int>>(str2.length() + 1, vector<int>(str3.length() + 1, INT_MIN)));

    for(int i = 0; i < str1.length(); i++) {
        for(int j = 0; j < str2.length(); j++) {
            answers[i][j][0] = 0;
        }
    }

    for(int j = 0; j < str2.length(); j++) {
        for(int k = 0; k < str3.length(); k++) {
            answers[0][j][k] = 0;
        }
    }

    for(int i = 0; i < str1.length(); i++) {
        for(int k = 0; k < str3.length(); k++) {
            answers[i][0][k] = 0;
        }
    }

    cout << find_LCS_length(str1, str1.length(), str2, str2.length(), str3, str3.length(), answers) << "\n";

    return 0;
}

int find_LCS_length(string &str1, int length1, string &str2, int length2, string &str3, int length3, vector<vector<vector<int>>> &answers) {
    if(answers[length1][length2][length3] != INT_MIN) {
        return answers[length1][length2][length3];
    }
    else if(length1 == 0 || length2 == 0 || length3 == 0) {
        return 0;
    }   
    else if(str1.at(length1 - 1) == str2.at(length2 - 1) && str2.at(length2 - 1) == str3.at(length3 - 1)) {
        answers[length1][length2][length3] = 1 + find_LCS_length(str1, length1 - 1, str2, length2 - 1, str3, length3 - 1, answers);
        return answers[length1][length2][length3];
    }
    else {
        int res = 0;

        for(int i = 0; i <= 1; i++) {
            for(int j = 0; j <= 1; j++) {
                for(int k = 0; k <= 1; k++) {
                    if(i == 0 && j == 0 && k == 0) {
                        continue;
                    }
                    else {
                        res = max(res, find_LCS_length(str1, length1 - i, str2, length2 - j, str3, length3 - k, answers));
                    }
                }
            }
        }

        answers[length1][length2][length3] = res;
        return res;
    }
}