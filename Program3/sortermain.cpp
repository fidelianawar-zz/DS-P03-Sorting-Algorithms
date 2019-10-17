#include "sortermain.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;

//bubble sort best
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

sorterMain::sorterMain()
{
    populateBubbleWorst();
}
