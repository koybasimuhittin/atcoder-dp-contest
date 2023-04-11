/*

Problem Statement
Taro and Jiro will play the following game against each other.
Initially, they are given a sequence a=(a1,a2,…,aN).
Until a becomes empty, the two players perform the following operation alternately, starting from Taro:
Remove the element at the beginning or the end of a.
The player earns x points, where x is the removed element.
Let X and Y be Taro's and Jiro's total score at the end of the game, respectively.
Taro tries to maximize X−Y, while Jiro tries to minimize X−Y.

Assuming that the two players play optimally, find the resulting value of X−Y.

Constraints
All values in input are integers.
1≤N≤3000
1≤ai≤10^9

*/




#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define int long long
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const int N = 3e3 + 5;
const int mod = 1e9 + 7;

int n, stones[N], dp[N][N];

int solve(int left, int right) {
    if (left > right) {
        return 0;
    }

    if (dp[left][right] != LLONG_MIN) {
        return dp[left][right];
    }
    dp[left][right] = max(dp[left][right], stones[left] - solve(left + 1, right));
    dp[left][right] = max(dp[left][right], stones[right] - solve(left, right - 1));

    return dp[left][right];
}

int32_t main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = LLONG_MIN;
        }
    }

    cout << solve(0, n - 1) << endl;


    return 0;
}