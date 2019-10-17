#include "sortermain.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;

//bubble sort best
void sorterMain::populateVectorABest(){
    for(int i = 0; i < 10; i++){
        elementsA.push_back(i);
    }
    sortA.setData(elementsA);

    auto start = high_resolution_clock::now();
    sortA.sort();
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end-start);
    cout << "The time it took to sort was: " << duration.count() << " milliseconds." << endl;
}

//bubble sort worst
void sorterMain::populateVectorAWorst(){
    for(int i = 10; i > 0; i--){
        elementsA.push_back(i);
    }
    sortA.setData(elementsA);

    auto start = high_resolution_clock::now();
    sortA.sort();
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end-start);
    cout << "The time it took to sort was: " << duration.count() << " milliseconds." << endl;
}

sorterMain::sorterMain()
{
    populateVectorABest();
}
