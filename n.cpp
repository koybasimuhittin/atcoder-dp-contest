/*

Problem Statement
There are N slimes lining up in a row. Initially, the i-th slime from the left has a size of ai.
Taro is trying to combine all the slimes into a larger slime.
He will perform the following operation repeatedly until there is only one slime:
Choose two adjacent slimes, and combine them into a new slime. The new slime has a size of x+y,
where x and y are the sizes of the slimes before combining them.
Here, a cost of x+y is incurred. The positional relationship of the slimes does not change while combining slimes.

Find the minimum possible total cost incurred.

Constraints
All values in input are integers.
2≤N≤400
1≤ai≤10

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
const int N = 4e2 + 5;
const int mod = 1e9 + 7;

int n, dp[N][N], prefixSum[N], slimes[N];

int solve(int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) {
        return 0;
    }

    if (dp[leftIndex][rightIndex] != -1) {
        return dp[leftIndex][rightIndex];
    }

    dp[leftIndex][rightIndex] = LLONG_MAX;
    for (int i = leftIndex; i < rightIndex; i++) {
        dp[leftIndex][rightIndex] = min(dp[leftIndex][rightIndex], solve(leftIndex, i) + solve(i + 1, rightIndex));
    }
    return dp[leftIndex][rightIndex] += prefixSum[rightIndex] - prefixSum[leftIndex - 1];
}

int32_t main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> slimes[i];
        prefixSum[i + 1] = prefixSum[i] + slimes[i];
    }

    memset(dp, -1, sizeof dp);

    cout << solve(1, n);

    return 0;
}