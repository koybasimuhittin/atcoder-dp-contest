/*

Problem Statement
Let N be a positive odd number.
There are N coins, numbered 1,2,…,N. For each i (1≤i≤N),
when Coin i is tossed, it comes up heads with probability pi and tails with probability 1 − pi.
Taro has tossed all the N coins.

Find the probability of having more heads than tails.

Constraints
N is an odd number.
1≤N≤2999
pi is a real number and has two decimal places.
0<pi<1

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

int n;
double p[N], dp[N][N], ans;

double solve(int indexOfCoin, int numberOfHeads) {
    if (indexOfCoin >= n) {
        if (2 * numberOfHeads > n) {
            return 1.0;
        }
        return 0.0;
    }

    if (dp[indexOfCoin][numberOfHeads] != -1) {
        return dp[indexOfCoin][numberOfHeads];
    }

    return dp[indexOfCoin][numberOfHeads] =
        solve(indexOfCoin + 1, numberOfHeads + 1) * p[indexOfCoin] +
        solve(indexOfCoin + 1, numberOfHeads) * (1.0 - p[indexOfCoin]);
}

int main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    cout.precision(10);
    cout << solve(0, 0);


    return 0;
}