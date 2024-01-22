
from collections import defaultdict


def seeds_who_fits_by_size(ss, sp):
    res = {}
    for size, prices in ss.items():
        res[size] = []
        sm = 0
        prices.sort(reverse=True)
        for p in prices:
            if sm + size <= sp:
                sm += size
                res[size].append(p)

    return res


def price_avg_by_size(ss, sp):
    res = {}
    avsizes = []
    change_avg = False
    for size, prices in ss.items():
        if len(prices) > 0:
            avsizes.append(size)
    if len(avsizes) > 1:
        avsizes.sort()
        change_avg = (avsizes[0] + avsizes[1]) > sp

    for size, prices in ss.items():
        if len(prices) > 0:
            avg = sum(prices) * 1.0 / len(prices)

            if not change_avg:
                avg = avg / size

            res[size] = avg
        else:
            res[size] = 0

    return res


def get_max_key(ss):
    mxk = list(ss.keys())[0]
    for key in ss.keys():
        if ss[key] > ss[mxk]:
            mxk = key
    
    return mxk


seeds = defaultdict(list)

seeds_count, spaces = map(int, input().split())

for i in range(seeds_count):
    space, price = map(int, input().split())
    seeds[space].append(price)

profit = 0
filled = 0

while filled < spaces:

    fits = seeds_who_fits_by_size(seeds, spaces - filled)
    avg = price_avg_by_size(fits, spaces - filled)

    if sum(avg.values()) == 0:
        break

    space = get_max_key(avg)
    price = fits[space].pop(0)

    seeds[space].remove(price)

    profit += price
    filled += space

print(profit)
