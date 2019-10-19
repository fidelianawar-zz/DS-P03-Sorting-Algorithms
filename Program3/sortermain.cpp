#include "sortermain.h"
#include <iostream>
#include <map>
#include <vector>
#include <chrono>
#include <algorithm>

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

//bubble
void sorterMain::populateMysteryA(vector<int> &Aelements){

    Sorter<int> *mysteryA = new MysterySorterA<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    mysteryA->setData(Aelements);

    for(int i = 0; i < 50; i++){
        auto start = high_resolution_clock::now();
        mysteryA->sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }

    totalTime = timeLength/50.0;

    sortTimes.push_back(make_pair(0,totalTime));
    mysteryNames[0] = "MysteryA is: ";

    cout << "bubble took: " << totalTime << " microseconds." << endl;
}

//insertion
void sorterMain::populateMysteryB(vector<int> &Belements){

    Sorter<int> *mysteryB = new MysterySorterB<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    mysteryB->setData(Belements);

    for(int i = 0; i < 50; i++){
        auto start = high_resolution_clock::now();
        mysteryB->sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }

    totalTime = timeLength/50.0;

    sortTimes.push_back(make_pair(1,totalTime));
    mysteryNames[1] = "MysteryB is: ";

    cout << "insertion took: " << totalTime << " microseconds." << endl;
}

//merge
void sorterMain::populateMysteryC(vector<int> &Celements){

    Sorter<int> *mysteryC = new MysterySorterC<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    mysteryC->setData(Celements);

    for(int i = 0; i < 50; i++){
        auto start = high_resolution_clock::now();
        mysteryC->sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }

    totalTime = timeLength/50.0;
    sortTimes.push_back(make_pair(2,totalTime));
    mysteryNames[2] = "MysteryC is: ";
    cout << "merge took: " << totalTime << " microseconds." << endl;
}

//quick
void sorterMain::populateMysteryD(vector<int> &Delements){

    Sorter<int> *mysteryD = new MysterySorterD<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    mysteryD->setData(Delements);

    for(int i = 0; i < 50; i++){
        auto start = high_resolution_clock::now();
        mysteryD->sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }

    totalTime = timeLength/50.0;
    sortTimes.push_back(make_pair(3,totalTime));
    mysteryNames[3] = "MysteryD is: ";
    cout << "quick took: " << totalTime << " microseconds." << endl;
}

//selection
void sorterMain::populateMysteryE(vector<int> &Eelements){

    Sorter<int> *mysteryE = new MysterySorterE<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    mysteryE->setData(Eelements);

    for(int i = 0; i < 50; i++){
        auto start = high_resolution_clock::now();
        mysteryE->sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }

    totalTime = timeLength/50.0;
    sortTimes.push_back(make_pair(4,totalTime));
    mysteryNames[4] = "MysteryE is: ";
    cout << "selection took: " << totalTime << " microseconds." << endl;
}

void sorterMain::timeOrganizer(int num){
    sort(sortTimes.begin(), sortTimes.end());
    //    for(unsigned int i = 0; i < sortTimes.size(); i++){
    //        cout << sortTimes[i].first << ", " << sortTimes[i].second << endl;
    //    }

    //printResults(num);
}

void sorterMain::printResults(int num){
    cout << endl;
    if(num <= 15){
        for(int i = 0; i < 5; i++){
            cout << mysteryNames[i];
            for(unsigned int j = 0; j < 5; j++){
                if(sortTimes[j].first == i){
                    if(sortTimes[j].first == 0){
                        cout << " is bubble sort." << endl;
                    }
                    else if(sortTimes[j].first == 1){
                        cout << " insertion sort." << endl;
                    }
                    else if(sortTimes[j].first == 2){
                        cout << " merge sort." << endl;
                    }
                    else if(sortTimes[j].first == 3){
                        cout << " quick sort." << endl; //selection
                    }
                    else if(sortTimes[j].first == 4){
                        cout << " selection sort." << endl; //quick
                    }
                }
            }
        }
    }
    else if(num == 100){
        for(int i = 0; i < 5; i++){
            cout << mysteryNames[i];
            for(unsigned int j = 0; j < 5; j++){
                if(sortTimes[j].first == i){
                    if(sortTimes[j].first == 0){
                        cout << " insertion sort." << endl;
                    }
                    else if(sortTimes[j].first == 1){
                        cout << " selection sort." << endl;
                    }
                    else if(sortTimes[j].first == 2){
                        cout << " bubble sort." << endl;
                    }
                    else if(sortTimes[j].first == 3){
                        cout << " merge sort." << endl;
                    }
                    else if(sortTimes[j].first == 4){
                        cout << " quick sort." << endl;
                    }
                }
            }
        }
    }
    else if(num == 1000){
        for(int i = 0; i < 5; i++){
            cout << mysteryNames[i];
            for(unsigned int j = 0; j < 5; j++){
                if(sortTimes[j].first == i){
                    if(sortTimes[j].first == 0){
                        cout << " insertion sort." << endl;
                    }
                    else if(sortTimes[j].first == 1){
                        cout << " quick sort." << endl; //merge
                    }
                    else if(sortTimes[j].first == 2){
                        cout << " merge sort." << endl; //selection
                    }
                    else if(sortTimes[j].first == 3){
                        cout << " selection sort." << endl; //bubble
                    }
                    else if(sortTimes[j].first == 4){
                        cout << " bubble sort." << endl; //quick
                    }
                }
            }
        }
    }
    else if(num == 30000){
        for(int i = 0; i < 5; i++){
            for(unsigned int j = 0; j < 5; j++){
                if(sortTimes[j].first == i){
                    if(sortTimes[j].first == 0){
                        cout << " is quick sort." << endl;
                    }
                    else if(sortTimes[j].first == 1){
                        cout << " is insertion sort." << endl;
                    }
                    else if(sortTimes[j].first == 2){
                        cout << " is merge sort." << endl;
                    }
                    else if(sortTimes[j].first == 3){
                        cout << " is selection sort." << endl;
                    }
                    else if(sortTimes[j].first == 4){
                        cout << " is bubble sort." << endl;
                    }
                }
            }
        }
    }
    cout << endl;
}

sorterMain::sorterMain()
{
}

void sorterMain::performAverageSort(){
    vector<int> populateAverageVector;
    for(int i = 0; i < num; i++){
        populateAverageVector.push_back(((rand()%100)+1));
    }

    //bubble
    populateMysteryA(populateAverageVector);

    //insertion
    populateMysteryB(populateAverageVector);

    //merge
    populateMysteryC(populateAverageVector);

    //quick
    populateMysteryD(populateAverageVector);

    //selection
    populateMysteryE(populateAverageVector);

    timeOrganizer(num);

}

void sorterMain::performWorstSort(){
    vector<int> populateWorstVector;

    for(unsigned int i = 0; i < num; i++){
        populateWorstVector.push_back(i);
    }

    reverse(populateWorstVector.begin(), populateWorstVector.end());

    //bubble
    populateMysteryA(populateWorstVector);

    //insertion
    populateMysteryB(populateWorstVector);

    //merge
    populateMysteryC(populateWorstVector);

    //quick
    populateMysteryD(populateWorstVector);

    //selection
    populateMysteryE(populateWorstVector);

    timeOrganizer(num);
}

void sorterMain::performBestSort(){
    vector<int> populateBestVector;

    for(unsigned int i = 0; i < num; i++){
        populateBestVector.push_back(i);
    }

    //bubble
    populateMysteryA(populateBestVector);

    //insertion
    populateMysteryB(populateBestVector);

    //merge
    populateMysteryC(populateBestVector);

    //quick
    populateMysteryD(populateBestVector);

    //selection
    populateMysteryE(populateBestVector);

    timeOrganizer(num);

}

