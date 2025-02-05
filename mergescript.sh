#!/bin/bash
#SBATCH --job-name=myjob
#SBATCH --partition=Centaurus
#SBATCH --time=01:00:00

./mergeSort 10
./mergeSort 100
./mergeSort 1000
./mergeSort 10000
./mergeSort 100000
./mergeSort 1000000
./mergeSort 10000000
./mergeSort 100000000
./mergeSort 1000000000

