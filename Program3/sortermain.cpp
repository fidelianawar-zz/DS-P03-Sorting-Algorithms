#include "sortermain.h"
#include <iostream>
#include <map>
#include <vector>
#include <chrono>

using namespace std::chrono;

//bubble best: ascending sorted
//bubble worst: descending sorter

//insertion best: ascending sorted
//insertion worst: descending sorter
//efficient for small data sets

//merge best: ascending order
//merge worst: vector is made of left even sub array, right odd subarray

//selection best: ascending order
//selection worst: descending order

//quick best: median is first element
//quick worst: ascending sorted

void sorterMain::populateBubbleBest(){

    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 15; i++){
        elementsA.push_back(i);
    }
    sortA.setData(elementsA);

    for(int i = 0; i < 15; i++){
        auto start = high_resolution_clock::now();
        sortA.sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }
    totalTime = timeLength/15;
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

void sorterMain::populateMysteryA(){
    Sorter<int> *mysteryA = new MysterySorterA<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 100; i++){
        elementsA.push_back(((rand()%100)+1));
    }
    mysteryA->setData(elementsA);

    for(int i = 0; i < 100; i++){
        auto start = high_resolution_clock::now();
        mysteryA->sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }
    totalTime = timeLength/100.0;

    //sortTimes.reserve(1);
    sortTimes.push_back(make_pair(0,totalTime));

    cout << "Bubble sort took: " << totalTime << " microseconds." << endl;
}

void sorterMain::populateMysteryB(){
    Sorter<int> *mysteryB = new MysterySorterB<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 100; i++){
        elementsB.push_back(((rand()%100)+1));
    }
    mysteryB->setData(elementsB);

    //for(int i = 0; i < 100; i++){
    auto start = high_resolution_clock::now();
    mysteryB->sort();
    auto end = high_resolution_clock::now();
    chrono::duration<double, micro> duration = end-start;

    //timeLength += duration.count();
    //}
    //totalTime = timeLength/100.0;

//    sortTimes.at(1).first = 1;
//    sortTimes.at(1).second = duration.count();

    sortTimes.push_back(make_pair(1,duration.count()));

    cout << "Insertion sort took: " << duration.count() << " microseconds." << endl;
}

void sorterMain::populateMysteryC(){
    Sorter<int> *mysteryC = new MysterySorterC<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 100; i++){
        elementsC.push_back(((rand()%100)+1));
    }
    mysteryC->setData(elementsC);

    for(int i = 0; i < 100; i++){
        auto start = high_resolution_clock::now();
        mysteryC->sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }
    totalTime = timeLength/100.0;
    sortTimes.push_back(make_pair(2,totalTime));
    cout << "Merge sort took: " << totalTime << " microseconds." << endl;
}

void sorterMain::populateMysteryD(){
    Sorter<int> *mysteryD = new MysterySorterD<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 100; i++){
        elementsD.push_back(((rand()%100)+1));
    }
    mysteryD->setData(elementsD);

    for(int i = 0; i < 100; i++){
        auto start = high_resolution_clock::now();
        mysteryD->sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }
    totalTime = timeLength/100.0;
    sortTimes.push_back(make_pair(3,totalTime));
    cout << "Quick sort took: " << totalTime << " microseconds." << endl;
}

void sorterMain::populateMysteryE(){
    Sorter<int> *mysteryE = new MysterySorterE<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 100; i++){
        elementsE.push_back(((rand()%100)+1));
    }
    mysteryE->setData(elementsE);

    for(int i = 0; i < 100; i++){
        auto start = high_resolution_clock::now();
        mysteryE->sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }
    totalTime = timeLength/100.0;
    sortTimes.push_back(make_pair(3,totalTime));
    cout << "Selection sort took: " << totalTime << " microseconds." << endl;
}

void sorterMain::timeOrganizer(){

}

sorterMain::sorterMain()
{
    populateMysteryA();
    populateMysteryB();
    populateMysteryC();
    populateMysteryD();
    populateMysteryE();
}
