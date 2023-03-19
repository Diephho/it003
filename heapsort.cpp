#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

void heapify(double arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(double arr[]) {
    int n = 1000000;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
double a[1000000];
int main()
{
    auto start = high_resolution_clock::now();
    ifstream fi("test1.txt");
    ofstream fo("ans22.txt");
    for (int i = 0; i < 1e6; i++)
        fi >> a[i];
    heapsort(a);
    for (int i = 0; i < 1e6; i++)
        fo << a[i];
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << time_taken.count() << " microseconds." << endl;
    return 0;
}
