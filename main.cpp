#include <iostream>
#include "SelectionSort.h"
#include "InsertionSortArray.h"
#include "InsertionSortList.h"
#include "MergeSortist.h"
#include "QuickSort.h"
#include "heapsorting.h"

using namespace std;
int main() {
    //insertion sort
#if 0
    InsertionSortList<int> list;

    list.push(64);
    list.push(25);
    list.push(12);
    list.push(22);
    list.push(11);

    cout << "Original list: ";
    list.print();

    list.sort();

    cout << "Sorted list: ";
    list.print();

    return 0;
#endif
    //Quick Sort
#if 0
    int arr[] = {9, 5, 8, 3, 1, 6, 4, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSort<int> qs;
    qs.sort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    cout << endl;


#endif
#if 0
    MergeSortist<int> list;
    list.push(4);
    list.push(2);
    list.push(1);
    list.push(5);
    list.push(3);

    cout << "Unsorted list:" << endl;
    list.print();
    list.sort();
    cout << "Sorted list:" << endl;
    list.print();

#endif
#if 1
    int arr[] = { 7, 11, 1,9,8 };
    int size = sizeof(arr) / sizeof(arr[0]);

    heapsorting hs;
    hs.sort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

#endif
}
