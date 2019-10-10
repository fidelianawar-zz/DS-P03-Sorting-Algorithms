#include <iostream>
#include <vector>

#ifndef SORTINGFUN_SORTER_H
#define SORTINGFUN_SORTER_H

template <typename T>
class Sorter {
protected:
    std::vector<T> data;

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
public:
    int size = this->data.size();
    virtual void sort() {
        // Base case
        if (size == 1){
            return;
        }
        // One pass of bubble sort. After this pass, the largest element is moved/bubbled to end.
        for (int i=0; i<size-1; i++)
            if (this->data[i] > this->data[i+1])
                swap(this->data[i], this->data[i+1]);

        // Largest element is fixed, recur for remaining array
        bubbleSort(this->data, size-1);

        auto& t1 = this->data[0];
        auto& t2 = this->data[1];
        if (t1 < t2){
            std::cout << "Comparing is OK" << std::endl;
        }
        std::cout << "Mystery Sorter A" << std::endl;
    }
};

//insertion
template <typename T>
class MysterySorterB : public Sorter<T> {
public:
    int size = this->data.size();
    virtual void sort() {

        int i, key, j;
        for (i = 1; i < size; i++)
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
    }
};

//merge
template <typename T>
class MysterySorterC : public Sorter<T> {
private:
    void merge(int arr[], int l, int m, int r){
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;

        /* create temp arrays */
        int L[n1], R[n2];

        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = this->data[l + i];
        for (j = 0; j < n2; j++)
            R[j] = this->data[m + 1+ j];

        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                this->data[k] = L[i];
                i++;
            }
            else
            {
                this->data[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy the remaining elements of L[], if there
           are any */
        while (i < n1)
        {
            this->data[k] = L[i];
            i++;
            k++;
        }

        /* Copy the remaining elements of R[], if there
           are any */
        while (j < n2)
        {
            this->data[k] = R[j];
            j++;
            k++;
        }
    }
public:
    virtual void sort() {
        int l = 0;
        int r = this->data.size();

        std::cout << "Mystery Sorter C" << std::endl;
        if (l < r)
        {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            int m = l+(r-l)/2;

            // Sort first and second halves
            mergeSort(this->data, l, m);
            mergeSort(this->data, m+1, r);

            merge(this->data, l, m, r);
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
            quickSort(left, j);
        }
        if (i < right){
            quickSort(i, right);
        }

        std::cout << "Mystery Sorter D" << std::endl;
    }
};

//selection sort
template <typename T>
class MysterySorterE : public Sorter<T> {
public:
    int size = this->data.size();
    virtual void sort() {
        int i, j, imin;
        for(i = 0; i<size-1; i++) {
            imin = i;   //get index of minimum data
            for(j = i+1; j<size; j++)
                if(this->data[j] < this->data[imin])
                    imin = j;
            //placing in correct position
            swap(this->data[i], this->data[imin]);
        }
        std::cout << "Mystery Sorter E" << std::endl;
    }
};

#endif //SORTINGFUN_SORTER_H
