#!/bin/bash
set -e

#../compile-statement.sh statement.md
rm -rf instances
mkdir -p instances
# g++ -std=c++11 gen.cpp -O2

echo "Generating instances..."
for i in {001..100}; do
    echo "Generating $i..."
    ./a.exe --instance $i > "instances/instance$i.in"
done

