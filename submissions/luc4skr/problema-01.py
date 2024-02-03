import sys

def get_spaces(file):
    file.seek(0)
    return int(file.read().split()[1])

def format_file(file):
    file.seek(0)
    lines = file.read().splitlines()[1:]
    return [tuple(map(int, linha.split())) for linha in lines]

def max_profit(content, W):
    dp = [0] * (W + 1)

    for i in range(len(content)):
        for j in range(W, content[i][0] - 1, -1):
            dp[j] = max(dp[j], content[i][1] + dp[j - content[i][0]])

    return dp[W]

def main():
    with open(file_path, "r") as file:
        W = get_spaces(file)
        content = format_file(file)
        profit = max_profit(content, W)

        print(profit)

if __name__ == "__main__":
    file_path = sys.argv[1]

    main()