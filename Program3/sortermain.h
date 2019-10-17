#include <vector>
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

public:
    sorterMain();
    void populateVectorABest();
    void populateVectorAWorst();
};


#endif // SORTERMAIN_H
