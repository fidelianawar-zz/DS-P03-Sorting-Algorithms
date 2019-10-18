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

void sorterMain::populateMysteryA(vector<int> &Aelements){
    Sorter<int> *mysteryA = new MysterySorterA<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 100; i++){
        Aelements.push_back(((rand()%100)+1));
    }
    mysteryA->setData(Aelements);

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
    mysteryNames[0] = "MysteryA is: ";

    cout << "MysteryA took: " << totalTime << " microseconds." << endl;
}

void sorterMain::populateMysteryB(vector<int> &Belements){
    Sorter<int> *mysteryB = new MysterySorterB<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 100; i++){
        Belements.push_back(((rand()%100)+1));
    }
    mysteryB->setData(Belements);

    //for(int i = 0; i < 100; i++){
    auto start = high_resolution_clock::now();
    mysteryB->sort();
    auto end = high_resolution_clock::now();
    chrono::duration<double, micro> duration = end-start;

    //timeLength += duration.count();
    //}
    //totalTime = timeLength/100.0;

    sortTimes.push_back(make_pair(1,duration.count()));
    mysteryNames[1] = "MysteryB is: ";

    cout << "MysteryB took: " << duration.count() << " microseconds." << endl;
}

void sorterMain::populateMysteryC(vector<int> &Celements){
    Sorter<int> *mysteryC = new MysterySorterC<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 100; i++){
        Celements.push_back(((rand()%100)+1));
    }
    mysteryC->setData(Celements);

    for(int i = 0; i < 100; i++){
        auto start = high_resolution_clock::now();
        mysteryC->sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }
    totalTime = timeLength/100.0;
    sortTimes.push_back(make_pair(2,totalTime));
    mysteryNames[2] = "MysteryC is: ";
    cout << "MysteryC took: " << totalTime << " microseconds." << endl;
}

void sorterMain::populateMysteryD(vector<int> &Delements){
    Sorter<int> *mysteryD = new MysterySorterD<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

    for(int i = 0; i < 100; i++){
        Delements.push_back(((rand()%100)+1));
    }
    mysteryD->setData(Delements);

    for(int i = 0; i < 100; i++){
        auto start = high_resolution_clock::now();
        mysteryD->sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }
    totalTime = timeLength/100.0;
    sortTimes.push_back(make_pair(3,totalTime));
    mysteryNames[3] = "MysteryD is: ";
    cout << "MysteryD took: " << totalTime << " microseconds." << endl;
}

void sorterMain::populateMysteryE(vector<int> &Eelements){
    Sorter<int> *mysteryE = new MysterySorterE<int>;
    double timeLength = 0.0;
    double totalTime =  0.0;

//    for(int i = 0; i < 100; i++){
//        elementsE.push_back(((rand()%100)+1));
//    }

    mysteryE->setData(Eelements);

    for(int i = 0; i < 100; i++){
        auto start = high_resolution_clock::now();
        mysteryE->sort();
        auto end = high_resolution_clock::now();
        chrono::duration<double, micro> duration = end-start;
        timeLength += duration.count();
    }
    totalTime = timeLength/100.0;
    sortTimes.push_back(make_pair(4,totalTime));
    mysteryNames[4] = "MysteryE is: ";
    cout << "MysteryE took: " << totalTime << " microseconds." << endl;
}

void sorterMain::timeOrganizer(int num){
    sort(sortTimes.begin(), sortTimes.end());
    printResults(num);
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
                        cout << " quick sort." << endl;
                    }
                    else if(sortTimes[j].first == 2){
                        cout << " merge sort." << endl;
                    }
                    else if(sortTimes[j].first == 3){
                        cout << " selection sort." << endl;
                    }
                    else if(sortTimes[j].first == 4){
                        cout << " bubble sort." << endl;
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

int main()
{
    int num = 1000;
    sorterMain object;
    vector<int> populateVector;

    for(int i = 0; i < num; i++){
       populateVector.push_back(((rand()%100)+1));
    }

    //bubble
    object.populateMysteryA(populateVector);

    //insertion
    object.populateMysteryB(populateVector);

    //merge
    object.populateMysteryC(populateVector);

    //quick
    object.populateMysteryD(populateVector);

    //selection
    object.populateMysteryE(populateVector);

    object.timeOrganizer(num);



    return 1;

}
