#!/bin/bash
g++ main.cpp -std=c++17 -o main
echo "algorithm function experiment f" > data.csv
for i in {1..2}
do
    for j in {1..3}
    do
        for k in {1..30}
        do
			echo "Algorithm $i Function $j Execution $k"
            ./main $i 30 100 20 -5 5 $j $k >> data.csv
        done
    done
done
