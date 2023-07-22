//
// Created by ziad on 7/21/23.
//

#ifndef SORTINGALGORTHIMS_HEAPSORTING_H
#define SORTINGALGORTHIMS_HEAPSORTING_H


class heapsorting {
public:
    void sort(int *arr,int size){
        buildHeap(arr,size);
        for(int i = size-1;i>=0;i--){
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            heapify(arr,i,0);
        }

    }
private:
    void heapify(int *arr,int size,int i){
        int left = 2*i+1;
        int right = 2*i+2;
        int max = i;
        if(left<size && arr[left]> arr[max]){
            max = left;
        }
        if(right<size && arr[right]> arr[max]){
            max = right;
        }
        if(max != i ){
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
            heapify(arr,size,max);
        }

    }
    void buildHeap(int * arr, int size){
        for(int i = size/2 - 1; i>=0;i--){
            heapify(arr,size,i);
        }
    }
};


#endif //SORTINGALGORTHIMS_HEAPSORTING_H
