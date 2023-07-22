#ifndef SORTINGALGORTHIMS_SELECTIONSORT_H
#define SORTINGALGORTHIMS_SELECTIONSORT_H

template <class T>
class SelectionSort {
public:
    void selectionSort(int * arr, int size) {

            for (int i = 0; i < size -1; i++) {
                int mindex = minLocaton(arr, i, size-1);
                swap(arr, mindex, i);
            }

    }

private:
    int minLocaton(int *arr, int lower, int upper) {
        int mIndex;
        mIndex = lower;
        for (int i = lower; i <= upper; i++) {
            if (arr[i] < arr[mIndex]) {
                mIndex = i;
            }
        }
        return mIndex;
    }

    void swap(int *arr, int first, int second) {
        T temp;
        temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
};

#endif //SORTINGALGORTHIMS_SELECTIONSORT_H