# Project Euler Solutions

This repository contains all the solutions I've written so far to the [Project Euler](https://projecteuler.net/) problems.
There is a file called `timings.txt`, which contains timings of each of the solutions. My goal is to solve each problem in under 1 second, and so far, I've been successful.
You can use the following commands to get and make my solutions:
```bash
git clone https://github.com/Eppie/euler.git
cd euler
cmake .
make
./euler 1
```
This will run the solution to problem 1. If you want to run all the solutions, you can execute:
```bash
./run.sh
```
This will also overwrite the `timings.txt` file with your timings.

You'll notice that there is a folder called `test`. This folder contains a test case for each solution. In order to make the tests, you will require [Google Test](https://github.com/google/googletest). On Fedora, you can get it by running:
```bash
sudo dnf install gtest
```
Once you've obtained GTest, you can make and run the tests:
```bash
cd euler/test
cmake .
make
cd ../
test/runTests
```
Unfortunately, you can't run the tests from directly within the test directory at the present time. This is a bug that I intend to resolve in the future.
