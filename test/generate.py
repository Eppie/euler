#!/usr/bin/python

from os import listdir
from os.path import isfile, join
import re

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


pattern = re.compile("Euler([0-9]{1,4})\.cpp")


def filter_files(folder, f):
    if isfile(join(folder, f)):
        matches = pattern.search(f)
        if matches is not None:
            return matches.group(1)
    return None


onlyfolders = [f for f in listdir('../') if not isfile(join('../', f))]
files = []

for folder in onlyfolders:
    folder = '../' + folder
    for f in listdir(folder):
        result = filter_files(folder, f)
        if result is not None:
            files.append(result)

for f in files:
    i = int(f)
    filename = 'test{}.cpp'.format(i)
    if isfile(filename):
        continue
    with open(filename, 'w') as f:
        f.write(s.format(i, i / 10, solutions[i]))
