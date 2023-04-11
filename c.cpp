/*

Problem Statement
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.
The vacation consists of N days. For each i (1≤i≤N), Taro will choose one of the following activities and
do it on the i-th day:

A: Swim in the sea. Gain ai points of happiness.
B: Catch bugs in the mountains. Gain bi points of happiness.
C: Do homework at home. Gain ci points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.

Constraints
All values in input are integers.
1≤N≤10'5
1≤ai, bi, ci≤10^4

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

int n, days[N][3];
int dp[N][3];

int solve(int day, int whatIsDone) {
    if (day >= n) {
        return 0;
    }
    if (whatIsDone != -1 && dp[day][whatIsDone] != -1) {
        return dp[day][whatIsDone];
    }

    dp[day][whatIsDone] = 0;
    for (int i = 0; i < 3; i++) {
        if (whatIsDone != i) {
            dp[day][whatIsDone] = max(dp[day][whatIsDone], solve(day + 1, i) + days[day][i]);
        }
    }

    return dp[day][whatIsDone];
}

int main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> days[i][0] >> days[i][1] >> days[i][2];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -1;
        }
    }

    cout << solve(0, -1) << endl;


    return 0;
}