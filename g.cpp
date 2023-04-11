/*

Problem Statement
There is a directed graph G with N vertices and M edges. The vertices are numbered 1,2,…,N,
and for each i (1≤i≤M), the i-th directed edge goes from Vertex xi ​to yi.
G does not contain directed cycles.

Find the length of the longest directed path in G.
Here, the length of a directed path is the number of edges in it.

Constraints
All values in input are integers.
2≤N≤10^5
1≤M≤10^5
1≤xi,yi≤N
All pairs (xi,yi) are distinct.
G does not contain directed cycles.

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
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, m, a, b;
vector<int> graph[N];
int dp[N];

int solve(int indexOfNode) {
    if (dp[indexOfNode] != -1) {
        return dp[indexOfNode];
    }

    dp[indexOfNode] = 0;
    for (auto node : graph[indexOfNode]) {
        dp[indexOfNode] = max(dp[indexOfNode], solve(node) + 1);
    }

    return dp[indexOfNode];
}

int main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].pb(b);
    }

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, solve(i));
    }

    cout << ans << endl;

    return 0;
}