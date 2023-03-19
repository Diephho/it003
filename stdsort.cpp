#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

double a[1000000];

int main()
{
    for (int i = 1; i <= 10; i++)
    {
    auto start = high_resolution_clock::now();
        string s = "test" + to_string(i);
        string s1 = "ans4" + to_string(i);
    ifstream fi(s);
    ofstream fo(s1);
    for (int i = 0; i < 1e6; i++)
        fi >> a[i];
    sort(a, a + 1000000);
    for (int i = 0; i < 1e6; i++)
        fo << a[i] << " ";
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<milliseconds>(end - start);
    cout << "Time taken - Test" << i <<" : " << time_taken.count() << " microseconds." << endl;
    }
    return 0;
}
