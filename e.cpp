/*

Problem Statement
There are N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of wi and a value of vi.
Taro has decided to choose some of the N items and carry them home in a knapsack.
The capacity of the knapsack is W,
which means that the sum of the weights of items taken must be at most W.

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1≤N≤100
1≤W≤10^9
1≤wi≤W
1≤vi≤10^3

*/



#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define int long long
#define fri(a) freopen(a, "r", stdin);
#define fro(a) freopen(a, "w", stdout);
const int W = 1e5 + 5;
const int N = 1e2 + 5;
const int mod = 1e9 + 7;

int n, w, items[N][2], dp[N][W];

int maxVal = 0;

int solve(int itemIndex, int currentValue) {
    if (itemIndex >= n && currentValue == 0) {
        return 0;
    }
    if (itemIndex >= n && currentValue > 0) {
        return INT_MAX;
    }
    if (currentValue <= 0)return 0;

    if (dp[itemIndex][currentValue] != -1) {
        return dp[itemIndex][currentValue];
    }

    dp[itemIndex][currentValue] = min(solve(itemIndex + 1, currentValue),
        solve(itemIndex + 1, currentValue - items[itemIndex][1]) + items[itemIndex][0]);

    return dp[itemIndex][currentValue];
}

int32_t main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> n >> w;

    for (int i = 0; i < n; i++) {
        cin >> items[i][0] >> items[i][1];
        maxVal += items[i][1];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < W; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = maxVal; i >= 0; i--) {
        if (solve(0, i) <= w) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}