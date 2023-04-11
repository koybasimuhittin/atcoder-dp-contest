/*

Problem Statement
There are N stones, numbered 1,2,…,N.
For each i (1≤i≤N), the height of Stone i is hi.
There is a frog who is initially on Stone 1.
He will repeat the following action some number of times to reach Stone N:
If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2.
Here, a cost of ∣hi − hj∣ is incurred, where j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone N.

Constraints
All values in input are integers.
2≤N≤10^5
1≤hi≤10^4

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
const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int dp[N];
int n, costs[N];

int solve(int index) {
    if (index == (n - 1)) {
        return 0;
    }

    if (dp[index] != -1) {
        return dp[index];
    }

    int oneStep, twoStep;
    oneStep = twoStep = INT_MAX;
    if (index + 1 < n) {
        oneStep = solve(index + 1) + abs(costs[index + 1] - costs[index]);
    }
    if (index + 2 < n) {
        twoStep = solve(index + 2) + abs(costs[index + 2] - costs[index]);
    }
    dp[index] = min(oneStep, twoStep);

    return dp[index];
}

int main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    memset(dp, -1, N);

    cout << solve(0) << endl;



    return 0;
}