#include <vector>
#include <utility>
#include <iostream>
#include <sorter.h>

#ifndef SORTERMAIN_H
#define SORTERMAIN_H

using namespace std;

class sorterMain
{
private:

    MysterySorterC<int> sortC;

    vector<int> elementsC;

    //vector of pairs
    //first element: index 0-5 to represent sorts, second element: sort time
    vector<pair<double, int>> sortTimes;
    vector<pair<double, int>> sortTimesA;
    vector<pair<double, int>> sortTimesB;
    vector<pair<double, int>> sortTimesC;
    vector<pair<double, int>> sortTimesD;
    vector<pair<double, int>> sortTimesE;

    vector<string> randomTest,  descendingTest, duplicateTest, almostSortedTest;


    vector<string> resultsA, resultsB, resultsC, resultsD, resultsE;

    vector<vector<string>> mysteryNamesVector;

    string mysteryNames[5];

    int num = 6000;


public:
    sorterMain();

    vector<string> ascendingTest;

    void populateMergeWorst();


    void sortRandomValues();
    void sortAscendingValues();
    void sortDescendingValues();
    void sortEvenOddValues();
    void sortDuplicateElements();
    void sortReverseDuplicateElements();
    void sortAlmostSorted();

    void populateMysteryA(vector<int> &a);
    void populateMysteryB(vector<int> &b);
    void populateMysteryC(vector<int> &c);
    void populateMysteryD(vector<int> &d);
    void populateMysteryE(vector<int> &e);

    void timeOrganizer();
    void analyzeResults(int);
    void organizeMysteryNames();
    string determineFinal(vector<string> &);
};


#endif // SORTERMAIN_H
