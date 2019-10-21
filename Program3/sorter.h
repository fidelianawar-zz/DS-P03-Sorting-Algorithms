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

template <typename T>

class MysterySorterA : public Sorter<T> {

public:

    virtual void sort() {

        // This is Quick sort.  Code is adapted

        // from: https://www.geeksforgeeks.org/quick-sort

        quickSort(0, this->data.size()-1);

    }

private:

    void quickSort(int low, int high) {

        if (low < high)

        {

            int partitionIndex = partition(low, high);

            quickSort(low, partitionIndex - 1);

            quickSort(partitionIndex + 1, high);

        }

    }

    int partition (int low, int high) {

        int pivot = this->data[low];

        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)

        {

            if (this->data[j] < pivot)

            {

                i++;

                T temp = this->data[i];

                this->data[i] = this->data[j];

                this->data[j] = temp;

            }

       }

        T temp = this->data[i+1];

        this->data[i+1] = this->data[low];

        this->data[low] = temp;

        return (i + 1);

     }

};

template <typename T>

class MysterySorterB : public Sorter<T> {

public:

    virtual void sort() {

        // This is Merge sort.  Code is adapted

        // from: https://www.geeksforgeeks.org/merge-sort/

        mergeSort(0, this->data.size()-1);

    }

private:

    void merge(int left, int middle, int right) {

        int n1 = middle - left + 1;

        int n2 =  right - middle;

        std::vector<T> leftArray;

        std::vector<T> rightArray;

        for (int i = 0; i < n1; i++)

            leftArray.push_back(this->data[left + i]);

        for (int j = 0; j < n2; j++)

            rightArray.push_back(this->data[middle + 1 + j]);

        int i = 0;

        int j = 0;

        int k = left;

        while (i < n1 && j < n2)

        {

            if (leftArray[size_t(i)] <= rightArray[size_t(j)])

            {

                this->data[k] = leftArray[i];

                i++;

            }

            else

            {

                this->data[k] = rightArray[j];

                j++;

            }

            k++;

        }

        while (i < n1)

        {

            this->data[k] = leftArray[i];

            i++;

            k++;

        }

        while (j < n2)

        {

            this->data[k] = rightArray[j];

            j++;

            k++;

        }

    }

    void mergeSort(int left, int right) {

        if (left < right)

        {

            int middle = left+(right-left)/2;

            mergeSort(left, middle);

            mergeSort(middle+1, right);

            merge(left, middle, right);

        }

    }

};

template <typename T>

class MysterySorterC : public Sorter<T> {

public:

    virtual void sort() {

        // This is Bubble sort.  Code is adapted

        // from : https://geeksforgeeks.com/bubble-sort/

        bool swapped;

        for (size_t i = 0; i < this->data.size()-1; i++)

        {

          swapped = false;

          for (size_t j = 0; j < this->data.size()-i-1; j++)

          {

             if (this->data[j] > this->data[j+1])

             {

                 T temp = this->data[j];

                 this->data[j] = this->data[j+1];

                 this->data[j+1] = temp;

                 swapped = true;

             }

          }

          if (swapped == false)

            break;

        }

    }

};

template <typename T>

class MysterySorterD : public Sorter<T> {

public:

    virtual void sort() {

        // This is Selection sort.  Code is adapted

        // from: https://www.geeksforgeeks.org/selection-sort/

        int minIndex;

        // Iterate over the data, moving the boundary of the unsorted array.

        for (size_t i = 0; i < this->data.size()-1; i++)

        {

            // Find the minimum element in unsorted array.

            minIndex = i;

            for (size_t j = i+1; j < this->data.size(); j++)

            {

                if (this->data[j] < this->data[minIndex])

                    minIndex = j;

            }

            // Swap the minimum element with the element at the lowest,

            // unsorted index.

            T temp = this->data[i];

            this->data[i] = this->data[minIndex];

            this->data[minIndex] = temp;

        }

    }

};

template <typename T>

class MysterySorterE : public Sorter<T> {

public:

    virtual void sort() {

        // This is Insertion sort.  Code is adapted

        // from: https://www.geeksforgeeks.org/insertion-sort/

        int key;

        int j;

        for (size_t i = 1; i < this->data.size(); i++)

        {

            key = this->data[i];

            j = i - 1;

            // Move elements of data[0..i-1], that are greater than key,

            // to one position ahead of their current position.

            while (j >= 0 && this->data[j] > key)

            {

                this->data[j + 1] = this->data[j];

                j = j - 1;

            }

            this->data[j + 1] = key;

        }

    }

};

#endif
