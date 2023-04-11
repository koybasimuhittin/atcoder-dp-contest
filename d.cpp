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
1≤W≤10^5
1≤wi≤W
1≤vi≤10^9

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

int solve(int itemIndex, int currentWeight) {
    if (itemIndex >= n || currentWeight >= w) {
        return 0;
    }
    if (dp[itemIndex][currentWeight] != -1) {
        return dp[itemIndex][currentWeight];
    }

    dp[itemIndex][currentWeight] = max(solve(itemIndex + 1, currentWeight),
        currentWeight + items[itemIndex][0] <= w ? solve(itemIndex + 1, currentWeight + items[itemIndex][0]) + items[itemIndex][1] : 0);

    return dp[itemIndex][currentWeight];
}

int32_t main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> n >> w;

    for (int i = 0; i < n; i++) {
        cin >> items[i][0] >> items[i][1];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < W; j++) {
            dp[i][j] = -1;
        }
    }
    cout << solve(0, 0) << endl;

    return 0;
}