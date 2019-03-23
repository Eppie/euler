#!/usr/bin/env python3

d = dict()
TABLE_SIZE = 128

with open('d.txt', 'r') as f:
    for line in f.readlines():
        n, base = map(int, line.strip().split(','))
        if n in d:
            d[n].add(base)
        else:
            d[n] = set([base])

buckets = [set(range(129, 65537)) for _ in range(TABLE_SIZE)]
for n in d.keys():
    v = ( ( 2147429509 * n ) >> 22 ) & (TABLE_SIZE - 1)
    buckets[v] &= (set(range(129, 65537)) ^ d[n])
    print(v, len(buckets[v]))


for i in range(TABLE_SIZE):
    print(i, len(buckets[i]))
    # if len(buckets[i]) == 0:
