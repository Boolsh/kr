

#include <iostream>
#include <array>
#include <cmath>
#include <Windows.h>
const size_t Size = 15;

void arr_fill(int arr[])
{
    for (int i{}; i < Size ; ++i)
        arr[i] = rand() % 100 + 1;
}
void arr_print(int arr[])
{
    for (int i{}; i < Size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


void circle_move_to_right(int arr[], int ind_f, int ind_l)
{
    int tmp = arr[ind_l];
    for (int i{ ind_l }; i > ind_f; --i)
    {
        arr[i] = arr[i - 1];
    }
    arr[ind_f] = tmp;
}
void insert_sort(int arr[]) {
    for (int i = 1; i < Size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            j--;
        }
        if (j + 1 != i) {
            circle_move_to_right(arr, j + 1, i);
        }
    }
}


void shake_sort(int arr[])
{
    int start = 0, end = Size - 1, k = Size - 1;
    while (start < end)
    {
        for (int i = end; i >start; --i)
            if (arr[i - 1] > arr[i])
            {
                std::swap(arr[i - 1], i);
                k = i;
            }
        start = k;


        for (int i = start; i < end; i++)
            if (arr[i + 1] < arr[i]) 
            {
                std::swap(arr[i + 1], i);
                k = i;
            }
        end = k;
    }
}


void Merge(int a[], size_t begin, size_t middle, size_t end, int b[]) 
{
    size_t i = begin, j = middle;
    for (size_t k = begin; k < end; ++k) {
        if (i < middle && (j >= end || a[i] <= a[j])) {
            b[k] = a[i];
            i++;
        }
        else {
            b[k] = a[j];
            j++;
        }
    }
}
void CopyArray(int a[], size_t begin, size_t end, int b[]) 
{
    for (size_t k = begin; k < end; ++k) 
        b[k] = a[k];
}
void merge_sort(int a[], int b[]) 
{
    for (size_t width = 1; width < Size; width = 2 * width) {
        for (size_t i = 0; i < Size; i = i + 2 * width) {
            Merge(a, i, min(i + width, Size), min(i + 2 * width, Size), b);
        }
        CopyArray(b, 0, Size, a); 
    }
}


//void quick_sort(int arr[], int left = 0, int right = Size-1)
//{
//    int i = left;
//    int j = right;
//    int x = arr[(left + right) / 2];
//    do {
//        while (arr[i] <= x) i++;
//        //поиск с левой стороны элемента большего, чем разделитель
//        while (x < arr[j]) j--;
//        //поиск с правой стороны элемента меньшего, чем разделитель
//        if (i < j) {
//            std::swap(arr[i], arr[j]);
//            i++;
//            j - i;
//        }
//    } while (i <= j);
//    if (left < j) quick_sort(arr, left, j);
//    //применить процедуру сортировки для левой части массива
//    if (i < right) quick_sort(arr, i, right);
//    //применить процедуру сортировки для правой части массива
//}
void swap(int numbers[], size_t first, size_t second)
{
    auto temp{ numbers[first] };
    numbers[first] = numbers[second];
    numbers[second] = temp;
}
void quick_sort(int numbers[], size_t start = 0 , size_t end = Size- 1)
{
    if (start >= end)
        return;
    size_t current{ start };
    for (size_t i{ start + 1 }; i <= end; i++)
    {
        if (numbers[i] < numbers[start])
        {
            swap(numbers, ++current, i);
        }
    }
    swap(numbers, start, current); 
    if (current > start)
    {
        quick_sort(numbers, start, current - 1); 
    }
    if (end > current + 1)
    {
        quick_sort(numbers, current + 1, end);
    }
}


int main()
{

    srand(GetTickCount64());

    int arr[Size];
    int b[Size] = {};
    arr_fill(arr);
    std::cout << "default"; arr_print(arr);
    insert_sort(arr);
    std::cout << "insert "; arr_print(arr);
    shake_sort(arr);
    std::cout << "shake  "; arr_print(arr);
    merge_sort(arr, b);
    std::cout << "merge  "; arr_print(arr);
    quick_sort(arr);
    std::cout << "quick  "; arr_print(arr);
    

}

