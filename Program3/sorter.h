#include <iostream>
#include <vector>

#ifndef SORTINGFUN_SORTER_H
#define SORTINGFUN_SORTER_H

template <typename T>
class Sorter{
protected:
    std::vector<T> data;
public:
    Sorter() {}
    Sorter(T& x):data(x){}
    void setData(const std::vector<T>& x){
        data = x;
    }
    virtual void sort() = 0;
};
template <typename T>
class MysterySorterA : public Sorter<T>{
public:
    virtual void sort(){        //quick sort https://gist.github.com/raarce/4069108
        quickSort(this->data, 0, this->data.size()-1);
    }
    int partition(std::vector<int> & a, unsigned int start, unsigned int end) {
        int pivot = a[start];
        unsigned int from_left = start+1;
        unsigned int from_right = end;
        unsigned int tmp;
        while (from_left != from_right) {
            if (a[from_left]  <= pivot) from_left++;
            else {
                while (( from_left != from_right)  && (pivot < a[from_right])) from_right--;
                tmp =  a[from_right];
                a[from_right] = a[from_left];
                a[from_left] = tmp;
            }
        }

        if (a[from_left]>pivot) from_left--;
        a[start] = a[from_left];
        a[from_left] = pivot;

        return (from_left);
    }
    void quickSort(std::vector <int> & a, int p, int r) {
        if (p < r) {
            int q = partition(a, p, r);
            quickSort(a, p, q - 1);
            quickSort(a, q + 1, r);
        }
    }
};
template <typename T>
class MysterySorterB : public Sorter<T>{
public:
    virtual void sort(){        //Selection Sort

        std::vector<int> toBe;
        toBe = this->data;
        int vecsize = toBe.size();
        for (int j = 0; j < vecsize - 1; ++j) {
            int min = j;
            for ( int i = j+1; i < vecsize; ++i) {
                if (toBe.at(min) > toBe.at(i)) {
                    min = i;
                }
            }
            if (min != j)
                std::swap(toBe.at(j), toBe.at(min));
        }
    }
};
template <typename T>
class MysterySorterC : public Sorter<T>{
public:                                                       //Insertion Sort https://www.geeksforgeeks.org/insertion-sort/
        virtual void sort() {
                int key;
                int j;

                for (size_t i = 1; i < this->data.size(); i++)
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
            }
};
template <typename T>
class MysterySorterD : public Sorter<T>{
public:
    virtual void sort(){        //Bubble Sort       https://stackoverflow.com/questions/30963204/c-vector-bubble-sort
        std::vector<int> a;
        a = this->data;
        bool swapp = true;
        while(swapp)
        {
            swapp = false;
            for(unsigned int i = 0; i < a.size()-1; i++)
            {
                if (a[i]>a[i+1] )
                {
                    a[i] += a[i+1];
                    a[i+1] = a[i] - a[i+1];
                    a[i] -=a[i+1];
                    swapp = true;
                }
            }
        }
    }
};
template <typename T>
class MysterySorterE : public Sorter<T>{
public:
    virtual void sort(){    //Merge Sort http://www.codecodex.com/wiki/Merge_sort

        std::vector<int> results;
        results = merge_sort(this->data);

    }
    std::vector<int> merge_sort(std::vector<int>& vec)
    {

        if(vec.size() == 1)
        {
            return vec;
        }
        std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

        std::vector<int> left(vec.begin(), middle);
        std::vector<int> right(middle, vec.end());

        left = merge_sort(left);
        right = merge_sort(right);

        return merge(left, right);
    }
    std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right)
    {
        std:: vector<int> result;
        unsigned left_it = 0, right_it = 0;

        while(left_it < left.size() && right_it < right.size())
        {
            if(left[left_it] < right[right_it])
            {
                result.push_back(left[left_it]);
                left_it++;
            }
            else
            {
                result.push_back(right[right_it]);
                right_it++;
            }
        }
        while(left_it < left.size())
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        while(right_it < right.size())
        {
            result.push_back(right[right_it]);
            right_it++;
        }
        return result;
    }

};
#endif // SORTER_H
