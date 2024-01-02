#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, W; cin >> n >> W;
    int dp[W+1][n+1]; 
    
    for (int i = 0; i <= W; i++)
        memset(dp+i, 0, sizeof(int)*(n+1));
   
    int v[n+1], w[n+1]; v[0] = 0; w[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= W; i++){
        for (int j = 1; j <= n; j++){
            int put_new_item = ((i >= w[j])? v[j] + dp[i-w[j]][j-1] : -1);
            dp[i][j] = max(put_new_item,
                            dp[i][j-1]
                            );

        }
    }

    cout << dp[W][n];
}

