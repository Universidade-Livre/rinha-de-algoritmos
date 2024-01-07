#include<iostream>

#define MAXN 1000
#define MAXW 2666

int N, W, i;
int S[MAXN + 1], V[MAXN + 1];
int dp[2][MAXW + 1];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::cin >> N >> W;
  for (i = 1; i <= N; i++) {
    std::cin >> S[i] >> V[i];
  }

  bool cur = false;
  
  for (i = 0; i <= W; i++) {
    dp[0][i] = dp[1][i] = 0;
  }

  for (i = 1; i <= N; i++) {
    cur = !cur;
    for (int j = 0; j <= W; j++) {
      if (S[i] > j) {
        dp[cur][j] = dp[!cur][j];
      } else {
        dp[cur][j] = std::max(dp[!cur][j - S[i]] + V[i], dp[!cur][j]);    
      }
    }
  }

  std::cout << dp[cur][W] << '\n';    

  return 0;
}