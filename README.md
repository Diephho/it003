# Cấu trúc dữ liệu và giải thuật - IT003.N21.CTTN
## Báo cáo thực nghiệm Sorting Algorithms	
*Tên:* Hồ Hoàng Diệp

*Lớp:* ATTN2022

*MSSV:* 22520249

## Mục lục
- [Đề bài](#Đề_bài)
- [Công cụ](#Công_cụ)
- [Tạo	bộ	dữ	liệu](#Tạo_10_bộ_dữ_liệu)
- [QuickSort](#QuickSort)
- [HeapSort](#HeapSort)
- [MergeSort](#MergeSort)
- [Chương trình gọi hàm Sort C++ (std::sort)](#std.sort)
- [Kết quả thử nghiệm](#Kết_quả_thử_nghiệm)
- [Nhận xét kết quả thực nghiệm](#Nhận_xét_kết_quả_thực_nghiệm)
## Đề_bài
1. Tạo bộ dữ liệu gồm 10 dãy, mỗi dãy khoảng 1 triệu số thực (ngẫu nhiên); dãy thứ nhất đã có thứ tự tăng dần, dãy thứ hai có thứ tự giảm dần, 8 dãy còn lại trật tự ngẫu nhiên;
2. Viết các chương trình sắp xếp dãy theo các thuật toán QuickSort, HeapSort, MergeSort và chương trình gọi hàm sort của C++;
3. Chạy thử nghiệm mỗi chương trình đã viết ở trên với bộ dữ liệu đã tạo, ghi nhận thời gian thực thi từng lần thử nghiệm
4. Viết báo cáo thử nghiệm: kết quả thử nghiệm ở dạng bảng dữ liệu và dạng biểu đồ; nhận xét kết quả thực nghiệm; báo cáo nộp bằng file PDF

## Công_cụ
> Máy tính cá nhân( Inspiron 15 5000 )     
> Code::Blocks 20.03     
> Visual Studio Code    
## Tạo_10_bộ_dữ_liệu
```
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Tạo dãy tăng dần và giảm dần
    vector<double> ascending_array(1000000);
    vector<double> descending_array(1000000);
    generate(ascending_array.begin(), ascending_array.end(), []()
             {
        static double current = 0.0;
        return current += 0.01; });
    reverse_copy(ascending_array.begin(), ascending_array.end(), descending_array.begin());

    vector<double> random_array(1000000);

    ofstream f1("test1");
    for (int i = 0; i < 1e6; i++)
        f1 << ascending_array[i] << " ";
        f1.close();
    ofstream f2("test2");
    for (int i = 0; i < 1e6; i++)
        f2 << descending_array[i] << " ";
        f2.close();
    // Tạo 8 dãy số ngẫu nhiên
    for (int i = 3; i <= 10; i++)
    {
        string s = "test" + to_string(i);
        generate(random_array.begin(), random_array.end(), rand);
    ofstream f3(s);
    for (int i = 0; i < 1e6; i++)
        f3 << random_array[i] << " ";
    }
    return 0;
}
```
## QuickSort
```
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
```
## HeapSort
```
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
```
## MergeSort
```
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
```
## std.sort
`std::sort(a,a+n);`

## Kết_quả_thử_nghiệm

- Bảng dữ liệu
`Đơn vị đo lường : micro giây `

| Test |QuickSort|HeapSort|MergeSort|std::sort|
|------|-----------|---------|-----------|-----------|
|   1  |    4037   |   4594  |    4549   |    4344   | 
|   2  |    3884   |   4451  |    4493   |    4267   | 
|   3  |    3943   |   3879  |    4022   |    3723   | 
|   4  |    3910   |   4156  |    3920   |    3697   | 
|   5  |    4075   |   3896  |    3851   |    3766   | 
|   6  |    3842   |   3859  |    3884   |    3817   | 
|   7  |    3703   |   3923  |    3961   |    3911   | 
|   8  |    3675   |   3891  |    3872   |    3699   |
|   9  |    3654   |   3862  |    3874   |    3701   | 
|   10 |    3669   |   3846  |    3877   |    3836   |

- Biểu đồ

![Biểu đồ so sánh thời gian (1)](https://user-images.githubusercontent.com/126962960/224552286-a208a1eb-c707-4089-b643-a8d7eb858cf6.png)
![Biểu đồ so sánh thời gian](https://user-images.githubusercontent.com/126962960/224552291-a78eba04-8d10-4850-8be9-8c393b65a145.png)

## Nhận_xét_kết_quả_thực_nghiệm
- Đối với bộ dữ liệu gồm một triệu phần tử, các thuật toán sắp xếp có thời gian giao động từ khoảng 3600-4600 micro giây.
- Trường hợp dữ liệu tăng dần (Test1): HeapSort có tốc độ chậm hơn các thuật toán khác
- Trường hợp dữ liệu giảm dần (Test2): QuickSort có tốc độ nhanh hơn các thuật toán khác
- Trường hợp dữ liệu ngẫu nhiên (Test3,Test4...): QuickSort là thuật toán có nhiều trường hợp nhanh nhất trong số các thuật toán được đánh giá. std::sort cũng chiếm một vài trường hợp nhanh nhất.
- Từ kết quả đánh giá, ta có thể nhận thấy rằng QuickSort là thuật toán sắp xếp nhanh nhất trong số các thuật toán được đánh giá, và có thể hiệu quả trong hầu hết các trường hợp. std::sort cũng là một lựa chọn tốt với thời gian sắp xếp khá nhanh và đáp ứng được nhiều yêu cầu hiệu suất.
- HeapSort và MergeSort đều đảm bảo thời gian sắp xếp ổn định và không bị ảnh hưởng bởi trường hợp tốt hoặc xấu của bộ dữ liệu, nhưng chúng không thể sắp xếp dữ liệu nhanh như QuickSort và std::sort.
- Với bộ dữ liệu ngẫu nhiên, QuickSort và std::sort là những lựa chọn tốt, vì chúng có thể sắp xếp các phần tử của bộ dữ liệu một cách nhanh chóng và hiệu quả. MergeSort và HeapSort cũng có thể được sử dụng, nhưng có thể không hiệu quả bằng QuickSort và std::sort trong một số trường hợp.

  Tóm lại, việc chọn thuật toán phù hợp nhất để sắp xếp dữ liệu phụ thuộc vào các yêu cầu hiệu suất của ứng dụng và tính chất của bộ dữ liệu. 
