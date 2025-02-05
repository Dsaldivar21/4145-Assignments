#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void merge(vector<int>& arr, size_t beg, size_t mid, size_t end) {
    vector<int> temp(end - beg);
    size_t i = beg, j = mid, k = 0;

    while (i < mid && j < end) {
        temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    }
    while (i < mid) temp[k++] = arr[i++];
    while (j < end) temp[k++] = arr[j++];

    for (size_t l = 0; l < k; ++l) {
        arr[beg + l] = temp[l];
    }
}

void mergeSort(vector<int>& arr, size_t beg, size_t end) {
    if (beg + 1 >= end) return;
    size_t mid = beg + (end - beg) / 2;
    mergeSort(arr, beg, mid);
    mergeSort(arr, mid, end);
    merge(arr, beg, mid, end);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <size_of_array>\n";
        return 1;
    }

    size_t n = stoull(argv[1]);
    vector<int> arr(n);
    srand(time(0));

    for (size_t i = 0; i < n; i++) arr[i] = rand();

    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();

    double duration = chrono::duration<double>(end - start).count();
    cout << "Sorted " << n << " elements in " << duration << " seconds.\n";

    return 0;
}
