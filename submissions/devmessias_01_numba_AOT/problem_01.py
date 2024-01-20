from sys import argv
from numpy import genfromtxt, int32
import knapsack


if __name__ == "__main__":
  data = genfromtxt(argv[1], delimiter='\t', dtype=int32)
  capacity = data[0][1]
  items = data[1:]
  solution = knapsack.knapsack(items, capacity)
  print(solution)
