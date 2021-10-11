#!/bin/bash
set -e

#../compile-statement.sh statement.md
rm -rf tests
mkdir -p tests/main
g++ -std=c++11 gen.cpp -O2 -o /tmp/gen
g++ -std=c++11 sol.cpp -O2 -o /tmp/sol

# Generate Tests
echo "Generating samples..."
printf "4\n1 2 3 4\n5 6 7 8\n1 3 5 7\n2 4 6 8\n1 2" > "tests/main/001.in"
printf "4\n1 2 3 4\n5 6 7 8\n1 3 5 7\n2 4 6 8\n2 1" > "tests/main/002.in"
printf "3\n1 2 3\n4 5 6\n7 8 9\n1 1" > "tests/main/003.in"

echo "Generating corner-cases tests..."
printf "1\n10\n0 0" > "tests/main/004.in"

echo "Generating small tests..."
for i in {005..017}; do
    echo "Generating $i..."
    /tmp/gen > "tests/main/$i.in"
done
echo "Generating big tests..."
for i in {018..020}; do
    echo "Generating $i..."
    /tmp/gen big > "tests/main/$i.in"
done

# Solve Tests
for i in {001..020}; do
    echo "Solving $i..."
    /tmp/sol < "tests/main/$i.in" > "tests/main/$i.out"
done
