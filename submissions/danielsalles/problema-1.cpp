#include <iostream>
#include <vector>
#include <algorithm>

struct Seed {
    int cost;
    int profit;
    int space;
    Seed(int c, int p, int s) : cost(c), profit(p), space(s) {}
};

int calculateMaxProfit(const std::vector<Seed>& seeds, int availableSpace, double c1, double c2, double c3) {
    int n = seeds.size();
    std::vector<int> dp(availableSpace + 1, 0);

    for (int i = 0; i < n; i++) {
        int adjustedProfit = static_cast<int>(seeds[i].profit * c1 + seeds[i].cost * c2 + c3);
        for (int j = availableSpace; j >= seeds[i].space; j--) {
            dp[j] = std::max(dp[j], dp[j - seeds[i].space] + adjustedProfit);
        }
    }

    return dp[availableSpace];
}

int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<Seed> seeds;
    seeds.reserve(N);

    for(int i = 0; i < N; i++) {
        int cost, profit, space;
        std::cin >> space >> profit;
        cost = 0;
        seeds.push_back(Seed(cost, profit, space));
    }

    double c1 = 1, c2 = 0.2, c3 = 50;

    int maxProfit = calculateMaxProfit(seeds, W, c1, c2, c3);
    std::cout << maxProfit << std::endl;

    return 0;
}
