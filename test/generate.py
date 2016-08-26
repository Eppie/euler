#!/usr/bin/python

from os.path import isfile

s = """#include "../{1}/Euler{0}.cpp"
#include <gtest/gtest.h>

TEST( Problem{0}, Test1 ) {{
	ASSERT_EQ( {2}, solve{0}() );
}}

"""

solutions = [0]

with open('../solutions.txt', 'r') as f:
    for line in f:
        try:
            solutions.append(line.split()[1])
        except IndexError:
            solutions.append(0)


for i in range(1, 48):
    filename = 'test{}.cpp'.format(i)
    if isfile(filename):
        continue
    with open(filename, 'w') as f:
        f.write(s.format(i, i / 10, solutions[i]))
