#include "sortermain.h"
#include <iostream>
#include <map>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std::chrono;

//calculating the sort time for MysteryA and storing designated values of time and mysteryName
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

    sortTimes.push_back(make_pair(totalTime,0));
    mysteryNames[0] = "Mystery A is: ";
    cout << "insertion time is " << totalTime << endl;
}

//calculating the sort time for MysteryB and storing designated values of time and mysteryName
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

    sortTimes.push_back(make_pair(totalTime,1));
    mysteryNames[1] = "Mystery B is: ";
    cout << "bubble time is " << totalTime << endl;

}

//calculating the sort time for MysteryC and storing designated values of time and mysteryName
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
    sortTimes.push_back(make_pair(totalTime,2));
    mysteryNames[2] = "Mystery C is: ";
    cout << "selection time is " << totalTime << endl;
}

//calculating the sort time for MysteryD and storing designated values of time and mysteryName
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
    sortTimes.push_back(make_pair(totalTime,3));
    mysteryNames[3] = "Mystery D is: ";
    cout << "quick time is " << totalTime << endl;
}

//calculating the sort time for MysteryE and storing designated values of time and mysteryName
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
    sortTimes.push_back(make_pair(totalTime,4));
    mysteryNames[4] = "Mystery E is: ";
    cout << "merge time is " << totalTime << endl;
}

//organizing sortTimes vector pair to be in order
void sorterMain::timeOrganizer(){

    sort(sortTimes.begin(), sortTimes.end());

//    for(unsigned int i = 0; i < sortTimes.size(); i++){
//       cout << sortTimes[i].first << " " << sortTimes[i].second << endl;

//    }
    analyzeResults();
}

void sorterMain::clearVectors(){
    totalInformation.clear();
    sortTimesA.clear();
    sortTimesB.clear();
    sortTimesC.clear();
    sortTimesD.clear();
    sortTimesE.clear();
}

//printing results based up order in sortTimes
void sorterMain::analyzeResults(){
    for(int i = 0; i < 5; i++){
        cout << mysteryNames[i];
        for(unsigned int j = 0; j < 5; j++){
            if(sortTimes[j].second == i){
                if(j == 2){
                    cout << "Insertion sort." << endl;
                }
                else if(j == 4){
                    cout << "Bubble sort." << endl;
                }
                else if(j == 3){
                    cout << "Selection sort." << endl;
                }
                else if(j == 0){
                    cout << "Quick sort." << endl;
                }
                else if(j == 1){
                    cout << "Merge sort." << endl;
                }
            }
        }
    }
}

sorterMain::sorterMain()
{
}

//average case with random elements
void sorterMain::sortRandomValues(){

    vector<int> testVec;

    for(int i = 0; i < num; i++){
        testVec.push_back(((rand()%100)+1));
    }

    populateMysteryA(testVec);
    populateMysteryB(testVec);
    populateMysteryC(testVec);
    populateMysteryD(testVec);
    populateMysteryE(testVec);

    timeOrganizer();

    totalInformation.push_back(sortTimesA);
    totalInformation.push_back(sortTimesB);
    totalInformation.push_back(sortTimesC);
    totalInformation.push_back(sortTimesD);
    totalInformation.push_back(sortTimesE);


}

//scenario with elements in vector in ascending order
void sorterMain::sortAscendingValues(){

    vector<int> testVec;

    for(int i = 0; i < num; i++){
        testVec.push_back(i);
    }

    populateMysteryA(testVec);
    populateMysteryB(testVec);
    populateMysteryC(testVec);
    populateMysteryD(testVec);
    populateMysteryE(testVec);

    timeOrganizer();

}

//elements in vector in descending order
void sorterMain::sortDescendingValues(){

    vector<int> testVec;

    for(int i = 0; i < num; i++){
        testVec.push_back(i);
    }

    reverse(testVec.begin(),testVec.end());

    populateMysteryA(testVec);
    populateMysteryB(testVec);
    populateMysteryC(testVec);
    populateMysteryD(testVec);
    populateMysteryE(testVec);

    timeOrganizer();

//    double longestTime = 0.0;
//    for(unsigned int i = 0; i < sortTimes.size(); i++){
//        if(sortTimes[i].second > longestTime){
//            longestTime = sortTimes[i].second;
//        }
//    }

}

//elements with every other element being even/odd
void sorterMain::sortEvenOddValues(){

    vector<int> testVec;

    for(int i = 0; i < num; i+=2){
        testVec.push_back(i);
    }
    for(int i = 1; i < num; i+=2){
        testVec.push_back(i);
    }

    populateMysteryA(testVec);
    populateMysteryB(testVec);
    populateMysteryC(testVec);
    populateMysteryD(testVec);
    populateMysteryE(testVec);

    timeOrganizer();
}

//elements with duplicate values
void sorterMain::sortDuplicateElements(){

    vector<int> testVec;

    for(int i = 0; i < num; i+=2){
        testVec.push_back(i);
        testVec.push_back(i);
    }

    populateMysteryA(testVec);
    populateMysteryB(testVec);
    populateMysteryC(testVec);
    populateMysteryD(testVec);
    populateMysteryE(testVec);

    timeOrganizer();
}

//elements with duplicate values
void sorterMain::sortReverseDuplicateElements(){

    vector<int> testVec;

    for(int i = 0; i < num; i+=2){
        testVec.push_back(i);
        testVec.push_back(i);
    }

    reverse(testVec.begin(),testVec.end());

    populateMysteryA(testVec);
    populateMysteryB(testVec);
    populateMysteryC(testVec);
    populateMysteryD(testVec);
    populateMysteryE(testVec);

    timeOrganizer();
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



