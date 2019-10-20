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
    string mysteryNames[5];

    int num = 10000;


public:
    sorterMain();

    void populateMergeWorst();


    void sortRandomValues();
    void sortAscendingValues();
    void sortDescendingValues();
    void sortEvenOddValues();
    void sortDuplicateElements();
    void sortReverseDuplicateElements();

    void populateMysteryA(vector<int> &a);
    void populateMysteryB(vector<int> &b);
    void populateMysteryC(vector<int> &c);
    void populateMysteryD(vector<int> &d);
    void populateMysteryE(vector<int> &e);

    void timeOrganizer();
    void printResults();
};


#endif // SORTERMAIN_H
