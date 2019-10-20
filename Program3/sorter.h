#include <iostream>
#include <vector>

#ifndef SORTER_H
#define SORTER_H

template <typename T>
class Sorter{
protected:
    std::vector<T> data;
public:
    Sorter(){}
    Sorter(T& x):data(x){}
    void setData(const std::vector<T>& x){data = x;}
    virtual void sort() = 0;
    void print(){
        // for(int i = 0; i<this->data.size(); i++) std::cout << this->data[i] << " ";
        std::cout << std::endl;
    }// print
};

template <typename T>
class MysterySorterA : public Sorter<T>{   // A
public:
    virtual void sort(){                   // Insertion
        int i, j;
        T key;
        for (i = 1; i < this->data.size(); i++){
            key = this->data[i];
            j = i - 1;
            while (j >= 0 && this->data[j] > key){
                this->data[j + 1] = this->data[j];
                j--;
            }// while
            this->data[j + 1] = key;
        }// for
       //for(int i=0; i<this->data.size(); i++) std::cout << this->data[i] << std::endl;
    }// Insertion
};

template <typename T>
class MysterySorterB : public Sorter<T>{   // B
public:
    virtual void sort(){                   // Bubble
        for (int i = 0; i < this->data.size()-1; i++){
            bool sorted = true;
            for (int j = 0; j < this->data.size()-i-1; j++){
                if (this->data[j] > this->data[j+1]){
                    sorted = false;
                    T temp = this->data[j];
                    this->data[j] = this->data[j+1];
                    this->data[j+1] = temp;
                }// if
            }// for
            if (sorted == true) break;
        }// for
        //for(int i=0; i<this->data.size(); i++) std::cout << this->data[i] << std::endl;
    }// Bubble
};

template <typename T>
class MysterySorterC : public Sorter<T>{     // C
public:
    virtual void sort(){                     // Selection
        int min_idx;
        for (int i = 0; i < this->data.size(); i++){
            min_idx = i;
            for (int j = i + 1; j < this->data.size(); j++){
                if (this->data[j] < this->data[min_idx]) min_idx = j;
            }// for
            T temp = this->data[min_idx];
            this->data[min_idx] = this->data[i];
            this->data[i] = temp;
        }// for
       // for(int i=0; i<this->data.size(); i++) std::cout << this->data[i] << std::endl;
    }// Selection
};

template <typename T>
class MysterySorterD : public Sorter<T>{   // D
private:
    int partition(std::vector<T>& vec, int& low, int& high){  // Quick
        T pivot = vec[low];
        int i = low + 1;
        for (int j = low + 1; j <= high; j++){
            if (vec[j] < pivot){
                T temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
                i++;
            }// if
        }// for
        T temp = vec[low];
        vec[low] = vec[i-1];
        vec[i-1] = temp;
        return (i - 1);
    }// partition
    void quickSort(std::vector<T>& vect, int low, int high){
        if (low < high){
            int pi = partition(vect, low, high);
            quickSort(vect, low, pi - 1);
            quickSort(vect, pi + 1, high);
        }// if
    }// quick
public:
    virtual void sort(){                                    // Quick
      quickSort(this->data, 0, this->data.size()-1);
      //for(int i=0; i<this->data.size(); i++) std::cout << this->data[i] << std::endl;
    }// Quick
};

template <typename T>
class MysterySorterE : public Sorter<T>{   // E
private:
    void merge(std::vector<T>& vec, int l, int m, int r){   // Merge
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;
        std::vector<T> L, R;
        for (i = 0; i < n1; i++) L.push_back(vec[l + i]);
        for (j = 0; j < n2; j++) R.push_back(vec[m + 1+ j]);
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2){
            if(L[i] <= R[j]){
                vec[k] = L[i];
                i++;
            }
            else{
                vec[k] = R[j];
                j++;
            }
            k++;
        }// while
        while (i < n1){
            vec[k] = L[i];
            i++;
            k++;
        }// while
        while (j < n2){
            vec[k] = R[j];
            j++;
            k++;
        }// while
    }// merge
    void mergeSort(std::vector<T>& vect, int l, int r){
        if (l < r){
            int m = l+(r-l)/2;
            mergeSort(vect, l, m);
            mergeSort(vect, m+1, r);
            merge(vect, l, m, r);
        }// if
    }// mergeSort
public:
    virtual void sort(){
        mergeSort(this->data, 0, this->data.size()-1);
        //for(int i=0; i<this->data.size(); i++) std::cout << this->data[i] << std::endl;
    }
};

#endif // SORTER_H
