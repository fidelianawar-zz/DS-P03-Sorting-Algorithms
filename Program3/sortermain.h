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
    //Sorter<int> *sortA;
    MysterySorterA<int> sortA;
    MysterySorterB<int> sortB;
    MysterySorterC<int> sortC;
    MysterySorterD<int> sortD;
    MysterySorterE<int> sortE;

    vector<int> elementsA;
    vector<int> elementsB;
    vector<int> elementsC;
    vector<int> elementsD;
    vector<int> elementsE;

    //vector of pairs
    //first element: index 0-5 to represent sorts, second element: sort time
    vector<pair<int, double>> sortTimes;
    string mysteryNames[5];

    int num = 60000;


public:
    sorterMain();
    void bestCaseinOrder();
    void worstCaseReverse();

    void populateBubbleAverage();
    void populateMergeWorst();
    void populateVectorBBest();
    void populateVectorBWorst();
    void populateVectorCBest();
    void populateVectorCWorst();
    void populateVectorDBest();
    void populateVectorDWorst();
    void populateVectorEBest();
    void populateVectorEWorst();

    void populateMysteryA(vector<int> &a);
    void populateMysteryB(vector<int> &b);
    void populateMysteryC(vector<int> &c);
    void populateMysteryD(vector<int> &d);
    void populateMysteryE(vector<int> &e);

    void timeOrganizer(int);
    void printResults(int);
    void performAverageSort();
    void performWorstSort();
    void performBestSort();

};


#endif // SORTERMAIN_H
