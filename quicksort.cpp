#include <chrono>
#include <iostream>
#include <fstream>
using namespace std;
using namespace chrono;

void quicksort(double arr[], int left, int right) {
    int i = left, j = right;
    double pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}
    double a[1000000];
int main()
{
    auto start = high_resolution_clock::now();
    string s = "test1", s1 = "ans11";
    for (int i = 1; i <= 10; i++)
    {
        s.pop_back();
        s1.pop_back();
        s.push_back(char(i + '0'));
        s1.push_back(char(i + '0'));
    ifstream fi(s);
    ofstream fo(s1);
    for (int i = 0; i < 1e6; i++)
        fi >> a[i];
    quicksort(a, 0, 1000000 - 1);
    for (int i = 0; i < 1e6; i++)
        fo << a[i] << " ";
    }
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<milliseconds>(end - start);
    cout << "Time taken : " << time_taken.count() << " microseconds." << endl;
    return 0;
}
