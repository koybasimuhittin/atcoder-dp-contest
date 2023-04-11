/*

Problem Statement
There is a grid with H horizontal rows and W vertical columns.
Let (i,j) denote the square at the i-th row from the top and the j-th column from the left.
For each i and j (1≤i≤H,1≤j≤W), Square (i,j) is described by a character a(i,j).
If a(i,j) is ., Square (i,j) is an empty square; if a(i,j) is #, Square(i,j) is a wall square.
It is guaranteed that Squares (1,1) and (H,W) are empty squares.
Taro will start from Square (1,1) and reach (H,W) by repeatedly moving
right or down to an adjacent empty square.

Find the number of Taro's paths from Square (1,1) to (H,W).
As the answer can be extremely large, find the count modulo 10^9+7.

Constraints
H and W are integers.
2≤H,W≤1000
a(i,j) is . or #.
Squares (1,1) and (H,W) are empty squares.

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
const int N = 1e3 + 5;
const int mod = 1e9 + 7;

int n, m, dp[N][N];
char grid[N][N];

bool isValidSquare(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.';
}

int solve(int row, int column) {
    if (row == n - 1 && column == m - 1) {
        return 1;
    }
    if (!isValidSquare(row, column)) {
        return 0;
    }
    if (dp[row][column] != -1) {
        return dp[row][column];
    }

    return dp[row][column] = (solve(row + 1, column) % mod + solve(row, column + 1) % mod) % mod;
}

int main( ) {

    fri("in.txt");
    fro("out.txt");

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    cout << solve(0, 0);

    return 0;
}