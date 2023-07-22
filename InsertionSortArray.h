//
// Created by ziad on 7/19/23.
//

#ifndef SORTINGALGORTHIMS_INSERTIONSORTARRAY_H
#define SORTINGALGORTHIMS_INSERTIONSORTARRAY_H

template <class T>
class InsertionSortArray {
public:
    void Sort(int * arr,int length) {
        T temp;
        int index;
        for (int i = 1; i < length; i++) {
            if (arr[i]<arr[i - 1]){
                temp = arr[i];
                index = i;
                while (index > 0 && arr[index - 1] > temp) {
                    arr[index] = arr[index - 1];
                    index--;
                }
                arr[index] = temp;
            }
        }
    }
};


#endif //SORTINGALGORTHIMS_INSERTIONSORTARRAY_H
