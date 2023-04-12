/**

Problem Statement
Find the number of integers between 1 and K (inclusive) satisfying the following condition, modulo 10^9+7:
The sum of the digits in base ten is a multiple of D.

Constraints
All values in input are integers.
1≤K<10^10000
1≤D≤100

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
const int N = 1e4 + 5;
const int mod = 1e9 + 7;

string k;
int d, dp[N][105][2];

int solve(int index, int sum, bool flag) {
    if (index >= k.length( )) {
        return (sum % d) == 0;
    }

    if (dp[index][sum][flag] != -1) {
        return dp[index][sum][flag];
    }

    dp[index][sum][flag] = 0;

    if (flag) {
        for (int i = 0; i < 10; i++) {
            dp[index][sum][flag] += solve(index + 1, (sum + i) % d, true) % mod;
            dp[index][sum][flag] %= mod;
        }
    }
    else {
        for (int i = 0; char(i + '0') < k[index]; i++) {
            dp[index][sum][flag] += solve(index + 1, (sum + i) % d, true) % mod;
            dp[index][sum][flag] %= mod;
        }
        dp[index][sum][flag] += solve(index + 1, (sum + k[index] - '0') % d, false) % mod;
        dp[index][sum][flag] %= mod;
    }

    return dp[index][sum][flag];
}

int32_t main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> k >> d;

    memset(dp, -1, sizeof dp);

    cout << (solve(0, 0, false) - 1 + mod) % mod << endl;
    return 0;
}