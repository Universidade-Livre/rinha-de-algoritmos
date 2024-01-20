from numba import jit, int64
import numpy as np
from numba.pycc import CC

cc = CC('knapsack')
cc.verbose = True

@cc.export('knapsack', 'int64(int64[:, :], int64)')
def knapsack(items, capacity):
    dp = np.zeros(capacity + 1, dtype=np.int64)
    for weight, value in items:
        for w in range(capacity, weight - 1, -1):
            dp[w] = max(dp[w], dp[w - weight] + value)
    return dp[capacity]

if __name__ == "__main__":
    cc.compile()
