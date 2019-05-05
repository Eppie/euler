#!/usr/bin/env python

from collections import defaultdict, Counter
from random import randint, choice

with open('log_256') as f:
    x = [list(map(int, line.strip().split(','))) for line in f.readlines()]

# base, hash value

base_to_hash = defaultdict(set)
hash_to_base = defaultdict(set)

best_result = 256
while best_result > 255:
    result = []
    for r in x:
        base_to_hash[r[0]].add(r[1])
        hash_to_base[r[1]].add(r[0])

    while any([len(base_to_hash[i]) for i in base_to_hash]):
        best_size = 0
        best_base = -1
        if randint(0, 100) > 90:
            c = Counter()
            for i in base_to_hash:
                c.update(list(base_to_hash[i]))
            least_common = c.most_common()[-1]
            for i in hash_to_base[least_common[0]]:
                if len(base_to_hash[i]) > best_size and randint(0, 100) > 10:
                    best_size = len(base_to_hash[i])
                    best_base = i
                if len(base_to_hash[i]) == best_size and i < best_base and randint(0, 100) > 10:
                    best_base = i
        else:
            for i in base_to_hash:
                if len(base_to_hash[i]) > best_size and randint(0, 100) > 10:
                    best_size = len(base_to_hash[i])
                    best_base = i
                if len(base_to_hash[i]) == best_size and i < best_base and randint(0, 100) > 10:
                    best_base = i
        if best_base == -1:
            continue
        vals = set(list(base_to_hash[best_base]))
        result.append((best_base, vals))
        for i in base_to_hash:
            base_to_hash[i] -= vals

    if len(result) < best_result:
        best_result = len(result)
        arr = [-1 for _ in range(256)]
        bases = [0 for _ in range(best_result)]
        i = 0
        for r in result:
            best_base, vals = r
            for v in vals:
                arr[v] = i
            bases[i] = best_base
            i += 1
        print(arr)
        print(bases)
    print(len(result), best_result)
