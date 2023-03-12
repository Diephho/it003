#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

double a[1000000];

int main()
{
    auto start = high_resolution_clock::now();
    ifstream fi("test.txt");
    ofstream fo("ans.txt");
    for (int i = 0; i < 1e6; i++)
        fi >> a[i];
    sort(a, a + 1000000);
    for (int i = 0; i < 1e6; i++)
        fo << a[i] << " ";
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<milliseconds>(end - start);
    cout << "Time taken : " << time_taken.count() << " msecs." << endl;
    return 0;
}
