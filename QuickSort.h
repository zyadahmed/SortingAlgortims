template <class T>
class QuickSort {
public:
    void sort(T *arr, int begin, int end) {
        if (begin < end) {
            int p = partition(arr, begin, end);
            sort(arr, begin, p);
            sort(arr, p + 1, end);
        }
    }
private:
    int partition(T *arr, int lower, int upper) {
        T pivot = arr[lower];
        int i = lower + 1;
        int j = upper;
        while (i <= j) {
            while (i <= j && arr[i] < pivot) {
                i++;
            }
            while (i <= j && arr[j] > pivot) {
                j--;
            }
            if (i < j) {
                swap(arr, i, j);
            }
        }
        swap(arr, lower, j);
        return j;
    }
    void swap(T *arr, int firstIndex, int secondIndex) {
        T temp;
        temp = arr[firstIndex];
        arr[firstIndex] = arr[secondIndex];
        arr[secondIndex] = temp;
    }
};