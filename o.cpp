/*

Problem Statement
There are N men and N women, both numbered 1,2,…,N.
For each i,j (1≤i,j≤N), the compatibility of Man i and Woman j is given as an integer a(i,j).
If a(i,j) = 1, Man i and Woman j are compatible; if a(i,j) = 0, they are not.
Taro is trying to make N pairs, each consisting of a man and a woman who are compatible.
Here, each man and each woman must belong to exactly one pair.

Find the number of ways in which Taro can make N pairs, modulo 10^9+7.

Constraints
All values in input are integers.
1≤N≤21
a(i,j) is 0 or 1.

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
const int N = 22;
const int mod = 1e9 + 7;

int n;
bool grid[N][N];
int dp[N][1 << N];

int solve(int index, int mask) {
    if (index >= n) {
        return 1;
    }
    if (dp[index][mask] != -1) {
        return dp[index][mask];
    }

    dp[index][mask] = 0;
    int masker = 1;
    for (int i = 0; i < n; i++) {
        if ((mask & masker) == 0 && grid[index][i]) {
            dp[index][mask] += solve(index + 1, (mask | masker)) % mod;
            dp[index][mask] %= mod;
        }
        masker = masker << 1;
    }

    return dp[index][mask];
}

int main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0) << endl;

    return 0;
}