/*
Rinha de algoritmos - Problema 01
https://github.com/olegon/rinha-de-algoritmos/blob/main/how_to_participate.md#problema-01
*/

#include <bits/stdc++.h>

using namespace std;

int optimize(int i, int n, vector<int> &w, vector<int> &v, int W, vector<vector<int>> &dp);

int main(void) {
    ios::sync_with_stdio(false);

    int n, W;
    
    cin >> n >> W;

    vector<int> w(n), v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        cin >> v[i];
    }

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    cout << optimize(0, n, w, v, W, dp) << endl;

    return EXIT_SUCCESS;
}

int optimize(int i, int n, vector<int> &w, vector<int> &v, int W, vector<vector<int>> &dp) {
    if (i >= n) return 0;

    if (dp[i][W] != -1) return dp[i][W];

    if (w[i] > W) return optimize(i + 1, n, w, v, W, dp);

    int value_taking_current_seed = v[i] + optimize(i + 1, n, w, v, W - w[i], dp);
    int value_skipping_current_seed = optimize(i + 1, n, w, v, W, dp);

    dp[i][W] = max(value_taking_current_seed, value_skipping_current_seed);

    return dp[i][W];
}
