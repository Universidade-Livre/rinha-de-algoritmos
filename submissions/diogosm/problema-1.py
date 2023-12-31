import sys
#from numba import jit, njit
#import numpy as np

n, s = map(int, next(sys.stdin).strip().split())
tuples = [tuple(map(int, next(sys.stdin).strip().split())) for _ in range(n)]

## remove solucoes impossiveis
tuples.sort(key=lambda x: x[1]/x[0], reverse=True)
tuples = [tup for tup in tuples if tup[0] <= s]

memoization = {}

## calc pd
#@njit
def calc_lucro(n_aux, s_aux):
	if (n_aux, s_aux) in memoization:
		return memoization[(n_aux, s_aux)]
	if n_aux == 0 or s_aux == 0:
		return 0
	if tuples[n_aux-1][0] > s_aux:
		memoization[(n_aux, s_aux)] = calc_lucro(n_aux - 1, s_aux)
	else:
		## verifico adicionando e nao adicionando
		memoization[(n_aux, s_aux)] = max( tuples[n_aux-1][1] + calc_lucro(n_aux-1, s_aux - tuples[n_aux-1][0]),
											calc_lucro(n_aux - 1, s_aux))
	return memoization[(n_aux, s_aux)]
	
print(calc_lucro(n,s))
#print(memoization)
