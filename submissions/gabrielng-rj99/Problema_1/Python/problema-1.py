import  sys
def knapsack(SPACE, ARRAY):
    n = len(ARRAY)
    dp = [0] * (SPACE + 1)

    for i in range(n):
        wi = ARRAY[i][0]        # Weight
        vi = ARRAY[i][1]        # Value
        for j in range(SPACE, wi - 1, -1):
            dp[j] = max(dp[j], vi + dp[j - wi])

    return dp[SPACE]

def execute_algorithm(file_path):
    with open(file_path, 'r') as file:
        _n, W = map(int, file.readline().split())
        
        file_array = []

        for line in file:
            row = list(map(int, line.split()))
            row += [row[1]/row[0]]
            file_array.append(row)
        
        return knapsack(W, file_array)


if __name__ == '__main__':
    file_path = sys.argv[1]
    print(f"{execute_algorithm(file_path):>10}")