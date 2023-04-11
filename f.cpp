/*

Problem Statement
You are given strings s and t.

Find one longest string that is a subsequence of both s and t.

Notes
A subsequence of a string x is the string obtained by removing zero or more characters
from x and concatenating the remaining characters without changing the order.

Constraints
s and t are strings consisting of lowercase English letters.
1≤∣s∣,∣t∣≤3000

*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define ll long long
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const int N = 3e3 + 5;
const int mod = 1e9 + 7;

int dp[N][N];
string str1, str2;

int solve(int indexOfFirstString, int indexOfSecondString) {
    if (indexOfFirstString >= str1.length( ) || indexOfSecondString >= str2.length( )) {
        return 0;
    }
    if (dp[indexOfFirstString][indexOfSecondString] != -1) {
        return dp[indexOfFirstString][indexOfSecondString];
    }

    if (str1[indexOfFirstString] == str2[indexOfSecondString]) {
        return dp[indexOfFirstString][indexOfSecondString] = solve(indexOfFirstString + 1, indexOfSecondString + 1) + 1;
    }

    return dp[indexOfFirstString][indexOfSecondString] = max(
        solve(indexOfFirstString + 1, indexOfSecondString),
        solve(indexOfFirstString, indexOfSecondString + 1)
    );
}

int main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> str1 >> str2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    solve(0, 0);

    int indexOfFirstString, indexOfSecondString;
    indexOfFirstString = indexOfSecondString = 0;

    while (indexOfFirstString < str1.length( ) && indexOfSecondString < str2.length( )) {
        if (str1[indexOfFirstString] == str2[indexOfSecondString]) {
            cout << str1[indexOfFirstString];
            indexOfFirstString++;
            indexOfSecondString++;
        }
        else {
            if (dp[indexOfFirstString][indexOfSecondString + 1] > dp[indexOfFirstString + 1][indexOfSecondString]) {
                indexOfSecondString++;
            }
            else {
                indexOfFirstString++;
            }
        }
    }

    return 0;
}