#!/usr/bin/python


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


for i in range(1, 36):
    # Because problem 24 returns a string, let's just leave it alone
    if i == 24:
        continue
    filename = 'test{}.cpp'.format(i)
    with open(filename, 'w') as f:
        f.write(s.format(i, i / 10, solutions[i]))
