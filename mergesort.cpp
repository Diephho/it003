#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

void merge(double arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int i,j,k;
    double *L = new double[n1];
    double *R = new double[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(double arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

double a[1000000];

int main()
{
    auto start = high_resolution_clock::now();
    ifstream fi("test.txt");
    ofstream fo("ans.txt");
    for (int i = 0; i < 1e6; i++)
        fi >> a[i];
    mergeSort(a, 0, 1000000 - 1);
    for (int i = 0; i < 1e6; i++)
        fo << a[i] << " ";
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<milliseconds>(end - start);
    cout << "Time taken : " << time_taken.count() << " msecs." << endl;
    return 0;
}
