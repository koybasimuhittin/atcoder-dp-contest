/*

Problem Statement
There are N stones, numbered 1,2,…,N.
For each i (1≤i≤N), the height of Stone i is hi.
There is a frog who is initially on Stone 1.
He will repeat the following action some number of times to reach Stone N:
If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K.
Here, a cost of ∣hi − hj∣ is incurred, where j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone N.

Constraints
All values in input are integers.
2≤N≤10^5
1≤K≤100
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
int n, k, costs[N];

int solve(int index) {
    if (index == (n - 1)) {
        return 0;
    }

    if (dp[index] != -1) {
        return dp[index];
    }

    dp[index] = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (index + i < n) {
            dp[index] = min(dp[index], solve(index + i) + abs(costs[index] - costs[index + i]));
        }
    }

    return dp[index];
}

int main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    memset(dp, -1, N);

    cout << solve(0) << endl;



    return 0;
}