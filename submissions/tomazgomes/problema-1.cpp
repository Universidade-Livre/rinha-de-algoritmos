#include <iostream>
#include <fstream>

const int NMAX = 1024;
const int WMAX = 3000;

int w[NMAX], v[NMAX];
int n, W;
int dp[NMAX][WMAX];

int main(int argc, char * argv[])
{
  std::ios::sync_with_stdio(false);  
  std::cin.tie(0);

  if (argc != 2) {
    std::cout << "[ERRO]: Esse programa requer exatamente 1 argument - o caminho para o arquivo de entrada.\n";
    std::exit(1);
  }

  std::ifstream fs(argv[1]);
  fs >> n >> W;

  for (int i = 0; i < n; ++i) {
    fs >> w[i] >> v[i];
  }

  for (int weight = 0; weight <= W; weight++) {
    if (weight >= w[0])
      dp[0][weight] = v[0];
    else
      dp[0][weight] = 0;
  }
  for (int i = 1; i < n; i++) {
    for (int weight = 0; weight <= W; weight++) {
      if (weight >= w[i])
        dp[i][weight] = std::max(dp[i - 1][weight - w[i]] + v[i], dp[i - 1][weight]);
      else
        dp[i][weight] = dp[i - 1][weight];
    }
  }
  
  std::cout << dp[n - 1][W] << "\n";
  return 0;
}
