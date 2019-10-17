#include <iostream>
#include <vector>

#ifndef SORTINGFUN_SORTER_H
#define SORTINGFUN_SORTER_H

using namespace std;

template <typename T>
class Sorter {
protected:
    std::vector<T> data;
    int size = this -> data.size();

public:
    Sorter() {}
    Sorter(T& x):data(x) {}
    void setData(const std::vector<T>& x) {
        data = x;
    }
    virtual void sort() = 0;

};

//bubble
template <typename T>
class MysterySorterA : public Sorter<T> {
private:
    void swapElements(int *xp, int *yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

public:
    virtual void sort() {
        int i, j;
        for (i = 0; i < this->data.size()-1; i++){
            // Last i elements are already in place
            for (j = 0; j < this->data.size()-i-1; j++){
                if (this->data[j] > this->data[j+1]){
                    swapElements(&this->data[j], &this->data[j+1]);
                }
            }
        }
        std::cout << "Mystery Sorter A" << std::endl;
        cout<<"size of vector: "<<this->data.size()<<endl;
        for(int i = 0; i < this->data.size(); i++ ){
           cout << this->data[i] << ' ';
        }
    }
};

//insertion
template <typename T>
class MysterySorterB : public Sorter<T> {
public:
    virtual void sort() {

        int i, key, j;
        for (i = 1; i < this->data.size(); i++)
        {
            key = this->data[i];
            j = i - 1;

            /* Move elements of arr[0..i-1], that are greater than key, to one position ahead
               of their current position */
            while (j >= 0 && this->data[j] > key)
            {
                this->data[j + 1] = this->data[j];
                j = j - 1;
            }
            this->data[j + 1] = key;
        }
        std::cout << "Mystery Sorter B" << std::endl;
        for(int i = 0; i < this->data.size(); i++ ){
           cout << this->data[i] << ' ';
        }
    }

};

//merge
template <typename T>
class MysterySorterC : public Sorter<T> {
private:
    /* l is for left index and r is right index of the
       sub-array of arr to be sorted */
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            int m = l+(r-l)/2;

            // Sort first and second halves
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);

            //merge(arr, l, m, r);
        }
    }

public:
    virtual void sort() {


        std::cout << "Mystery Sorter C" << std::endl;
        for(int i = 0; i < this->data.size(); i++ ){
           cout << this->data[i] << ' ';
        }
    }

};

//quicksort
template <typename T>
class MysterySorterD : public Sorter<T> {
public:
    int left;
    int right;
    virtual void sort() {
        int i = left, j = right;
        int temp;

        int pivot = this->data[(left+right)/2];

        while (i <= j) {
            while (this->data[i] < pivot){
                i++;
            }
            while (pivot < this->data[j]){
                j--;
            }
            if (i <= j) {
                temp = this->data[i];
                this->data[i] = this->data[j];
                this->data[j] = temp;
                i++;
                j--;
            }
        }

        if (left < j){
            //quickSort(left, j);
        }
        if (i < right){
            //quickSort(i, right);
        }

        std::cout << "Mystery Sorter D" << std::endl;
        for(int i = 0; i <  this->data.size(); i++ ){
           cout << this->data[i] << ' ';
        }
    }
};

//selection sort
template <typename T>
class MysterySorterE : public Sorter<T> {
private:
    void swapElements(int *xp, int *yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
public:
    virtual void sort() {
        int i, j, imin;
        for(i = 0; i<this->data.size()-1; i++) {
            imin = i;   //get index of minimum data
            for(j = i+1; j<this->data.size(); j++)
                if(this->data[j] < this->data[imin])
                    imin = j;
            //placing in correct position
            swapElements(&this->data[i], &this->data[imin]);
        }
        std::cout << "Mystery Sorter E" << std::endl;
        for(int i = 0; i < this->data.size(); i++ ){
           cout << this->data[i] << ' ';
        }
    }
};

#endif //SORTINGFUN_SORTER_H
