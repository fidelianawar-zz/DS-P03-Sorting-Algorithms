#include "sortermain.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;

//bubble best: ascending sorted
//bubble worst: descending sorter

//insertion best: ascending sorted
//insertion worst: descending sorter

//merge best: ascending order
//merge worst: vector is made of left even sub array, right odd subarray

//selection best: ascending order
//selection worst: descending order

//quick best: median is first element
//quick worst: ascending sorted

void sorterMain::populateBubbleBest(){

    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 1000; i++){
        elementsA.push_back(i);
    }
    sortA.setData(elementsA);

    for(int i = 0; i < 1000; i++){
        auto start = high_resolution_clock::now();
        sortA.sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }
    totalTime = timeLength/1000;
    cout << "The time it took to sort was: " << totalTime << " milliseconds." << endl;
}

//bubble sort worst
void sorterMain::populateBubbleWorst(){

    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 1000; i > 0; i--){
        elementsA.push_back(i);
    }
    sortA.setData(elementsA);

    for(int i = 0; i < 1000; i++){
        auto start = high_resolution_clock::now();
        sortA.sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }
    totalTime = timeLength/1000;
    cout << "The time it took to sort was: " << totalTime << " milliseconds." << endl;
}

void sorterMain::populateBubbleAverage(){

    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 1000; i++){
        elementsA.push_back(((rand()%1000)+1));
    }
    sortA.setData(elementsA);

    for(int i = 0; i < 1000; i++){
        auto start = high_resolution_clock::now();
        sortA.sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }
    totalTime = timeLength/1000;
    cout << "The time it took to sort was: " << totalTime << " milliseconds." << endl;
}

void sorterMain::populateMergeWorst(){

    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 1000; i+=2){
        elementsC.push_back(i);
    }
    for(int i = 1; i < 1000; i+=2){
        elementsC.push_back(i);
    }
    sortC.setData(elementsC);

    for(int i = 0; i < 1000; i++){
        auto start = high_resolution_clock::now();
        sortC.sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }
    totalTime = timeLength/1000;
    cout << "The time it took to sort was: " << totalTime << " milliseconds." << endl;

}

sorterMain::sorterMain()
{
    populateMergeWorst();
}
