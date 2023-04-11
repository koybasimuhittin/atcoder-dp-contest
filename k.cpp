/*

Problem Statement
There is a set A={a1,a2,…,aN} consisting ofN positive integers.
Taro and Jiro will play the following game against each other.
Initially, we have a pile consisting of K stones.
The two players perform the following operation alternately, starting from Taro:
Choose an element x in A, and remove exactly x stones from the pile.
A player loses when he becomes unable to play.

Assuming that both players play optimally, determine the winner.

Constraints
All values in input are integers.
1≤N≤100
1≤K≤10^5
1≤a1<a2<⋯<aN≤K

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

int n, k;
int stones[N];
bool dp[N];
bool isDPCalculated[N];

bool solve(int remainingStoneCount) {
    if (remainingStoneCount == 0) {
        return true;
    }

    if (isDPCalculated[remainingStoneCount]) {
        return dp[remainingStoneCount];
    }
    for (int i = 0; i < n; i++) {
        if (stones[i] < remainingStoneCount) {
            dp[remainingStoneCount] |= !solve(remainingStoneCount - stones[i]);
        }
        else {
            if (stones[i] == remainingStoneCount)dp[remainingStoneCount] = true;
        }
    }
    isDPCalculated[remainingStoneCount] = true;
    return dp[remainingStoneCount];
}

int main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    cout << (solve(k) ? "First" : "Second") << endl;

    return 0;
}