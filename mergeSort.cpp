#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;

void merge(vector<int>& arr, vector<int>& temp, size_t beg, size_t mid, size_t end) {
    size_t i = beg, j = mid, k = beg;
    while (i < mid && j < end) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i < mid) temp[k++] = arr[i++];
    while (j < end) temp[k++] = arr[j++];
    for (size_t l = beg; l < end; ++l) {
        arr[l] = temp[l];
    }
}

void mergeSort(vector<int>& arr, vector<int>& temp, size_t beg, size_t end) {
    if (end - beg < 1) return;
    size_t mid = beg + (end - beg) / 2;
    mergeSort(arr, temp, beg, mid);
    mergeSort(arr, temp, mid, end);
    merge(arr, temp, beg, mid, end);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <size_of_array>\n";
        return 1;
    }

    size_t n = atoi(argv[1]);

    vector<int> arr(n), temp(n);
    srand(time(0));
    for (size_t i = 0; i < n; i++) arr[i] = rand();

    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, temp, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();

    double duration = chrono::duration<double>(end - start).count();
    cout << "Sorted " << n << " elements in " << duration << " seconds.\n";

    return 0;
}
