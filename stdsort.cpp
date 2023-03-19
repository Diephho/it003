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
    string s = "test1", s1 = "ans41";
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
    sort(a, a + 1000000);
    for (int i = 0; i < 1e6; i++)
        fo << a[i] << " ";
    }
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<milliseconds>(end - start);
    cout << "Time taken : " << time_taken.count() << " microseconds." << endl;
    return 0;
}
