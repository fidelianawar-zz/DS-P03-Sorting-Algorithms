#include <iostream>
#include <vector>

#ifndef SORTER_H
#define SORTER_H

template <typename T>
class Sorter{
protected:
    std::vector<T> data;
    std::vector<T> revData;
    int size;
public:
    Sorter(){}
    Sorter(T& x):data(x){}
    void setData(const std::vector<T>& x){
        data = x;
    }
    void swap(T* a, T* b){
           T tmp = *a;
           *a = *b;
           *b = tmp;
       }
    std::vector<T> getData(){
        return this->data;
    }

    virtual void sort() = 0;

};

template <typename T>
//QuickSort
class MysterySorterA : public Sorter<T> {
public:
    int partition(std::vector<T>& data, int start, int end){
        T pivot = data[start];
        int pIndex = start + 1;
        int i;
        T temp;
        for(i = start + 1; i <= end; i++){
            if(data[i] < pivot){
                temp = data[i];
                data[i] = data[pIndex];
                data[pIndex] = temp;
                pIndex++;
            }
        }
        temp = data[start];
        data[start] = data[pIndex - 1];
        data[pIndex - 1] = temp;
        return pIndex-1;
    }

    void QuickSort(std::vector<T> & data, int start, int end){
        if(start < end){
            int pIndex = partition(data, start, end);
            QuickSort(data, start, pIndex - 1);
            QuickSort(data, pIndex + 1, end);
        }
    }
    virtual void sort(){
        QuickSort(this->data, 0, this->size - 1);
//        for(int i = 0; i < this->size; i++){
//            std::cout << this->data[i] << std::endl;
//        }
    }

};

template <typename T>
//Selection Sort
class MysterySorterB : public Sorter<T>{
public:
    virtual void sort(){
        int i, j, smallestIndex;
        T temp;
        for(i = 0; i < this->size - 1; i++){
            smallestIndex = i;
            for(j = i + 1; j < this->size; j++){
                if(this->data[j] < this->data[smallestIndex]){
                    smallestIndex = j;
                }
            }
            temp = this->data[i];
            this->data[i] = this->data[smallestIndex];
            this->data[smallestIndex] = temp;
        }
//        for(int i = 0; i < this->size; i++){
//            std::cout << this->data[i] << std::endl;
//        }
    }
};

template <typename T>
//Merge sort
class MysterySorterC : public Sorter<T>{
public:
    void Merge(std::vector<T>& data, int i, int j, int k){
        int mergedSize;
        int mergePos;
        int leftPos;
        int rightPos;
        T* mergedNumbers = nullptr;
        mergePos = 0;
        mergedSize = k - i + 1;
        leftPos = i;
        rightPos = j + 1;
        mergedNumbers = new T[mergedSize];

        while (leftPos <= j && rightPos <= k) {
            if (data[leftPos] < data[rightPos]) {
                mergedNumbers[mergePos] = data[leftPos];
                ++leftPos;
            }
            else {
                mergedNumbers[mergePos] = data[rightPos];
                ++rightPos;
            }
            ++mergePos;
        }

        while (leftPos <= j) {
            mergedNumbers[mergePos] = data[leftPos];
            ++leftPos;
            ++mergePos;
        }

        while (rightPos <= k) {
            mergedNumbers[mergePos] = data[rightPos];
            ++rightPos;
            ++mergePos;

        }
        for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
            data[i + mergePos] = mergedNumbers[mergePos];
        }
        delete [] mergedNumbers;
    }
    void MergeSort(std::vector<T>& data, int i, int k){
        int j;
        if(i < k){
            j = (i+k)/2;
            MergeSort(data, i, j);
            MergeSort(data, j + 1, k);
            Merge(data, i, j, k);
        }
    }
    virtual void sort(){
        MergeSort(this->data, 0,this->size - 1);
//        for(int i = 0; i < this->size; i++){
//            std::cout << this->data[i] << std::endl;
//        }
    }
};

template <typename T>
//bubble sort
class MysterySorterD : public Sorter<T>{
public:
    virtual void sort(){
           std::vector<T> arr = (this->data);
           bool swapped = false;
           int size = arr.size();
           do{
              swapped = false;
              for(int i = 1; i < size; ++i){
                  if(arr[i-1] > arr[i]){
                      this->swap(&arr[i-1],&arr[i]);
                      swapped = true;
                  }
              }
              --size;
           }while(swapped);

//        for(int i = 0; i < this->size; i++){
//            std::cout << this->data[i] << std::endl;
//        }
    }
};

template <typename T>
//insertion sort
class MysterySorterE : public Sorter<T>{
public:
    virtual void sort(){
        int i, j;
        T key;
            for (i = 1; i < this->size; i++)
            {
                key = this->data[i];
                j = i - 1;
                while (j >= 0 && this->data[j] > key)
                {
                    this->data[j + 1] = this->data[j];
                    j = j - 1;
                }
                this->data[j + 1] = key;
            }
//            for(int i = 0; i < this->size; i++){
//                std::cout << this->data[i] << std::endl;
//            }
    }
};
#endif // SORTER_H
