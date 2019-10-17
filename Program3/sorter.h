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
//        for(int i = 0; i < this->data.size(); i++ ){
//            cout << this->data[i] << ' ';
//        }
//        cout << endl;
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
//        for(int i = 0; i < this->data.size(); i++ ){
//            cout << this->data[i] << ' ';
//        }
//         cout << endl;
    }
};

//merge
template <typename T>
class MysterySorterC : public Sorter<T> {
private:
    // Merges two subarrays of arr[].
    // First subarray is arr[l..m]
    // Second subarray is arr[m+1..r]
    void merge(vector<T> data, int l, int m, int r)
    {
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
    /* l is for left index and r is right index of the
       sub-array of arr to be sorted */
    void mergeSort(vector<T> data, int l, int r)
    {
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

public:
    virtual void sort() {
        int l = 0;
        int r = this->data.size()-1;
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
        std::cout << "Mystery Sorter C" << std::endl;
//        for(int i = 0; i < this->data.size(); i++ ){
//            cout << this->data[i] << ' ';
//        }
//         cout << endl;
    }
};

//quicksort
template <typename T>
class MysterySorterD : public Sorter<T> {
private:
    // A utility function to swap two elements
    void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }

    /* This function takes last element as pivot, places
       the pivot element at its correct position in sorted
        array, and places all smaller (smaller than pivot)
       to left of pivot and all greater elements to right
       of pivot */
    int partition (vector<T> data, int low, int high)
    {
        int pivot = this->data[high];    // pivot
        int i = (low - 1);  // Index of smaller element

        for (int j = low; j <= high- 1; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (this->data[j] <= pivot)
            {
                i++;    // increment index of smaller element
                swap(&this->data[i], &this->data[j]);
            }
        }
        swap(&this->data[i + 1], &this->data[high]);
        return (i + 1);
    }

    /* The main function that implements QuickSort
     arr[] --> Array to be sorted,
      low  --> Starting index,
      high  --> Ending index */
    void quickSort(vector<T> data, int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = partition(this->data, low, high);

            // Separately sort elements before
            // partition and after partition
            quickSort(this->data, low, pi - 1);
            quickSort(this->data, pi + 1, high);
        }
    }
public:
    virtual void sort(){
        int low = 0;
        int high = this->data.size()-1;
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = partition(this->data, low, high);

            // Separately sort elements before
            // partition and after partition
            quickSort(this->data, low, pi - 1);
            quickSort(this->data, pi + 1, high);
        }
        std::cout << "Mystery Sorter D" << std::endl;
//        for(int i = 0; i <  this->data.size(); i++ ){
//            cout << this->data[i] << ' ';
//        }
//         cout << endl;
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
//        for(int i = 0; i < this->data.size(); i++ ){
//            cout << this->data[i] << ' ';
//        }
//         cout << endl;
    }
};

#endif //SORTINGFUN_SORTER_H
