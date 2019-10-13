#include <vector>
#include <iostream>
#include <sorter.h>

#ifndef SORTERMAIN_H
#define SORTERMAIN_H

using namespace std;

class sorterMain
{

private:
    vector<int> numberVector;
    MysterySorterA<int> sortA;
    MysterySorterB<int> sortB;
    MysterySorterC<int> sortC;
    //MysterySorterD<int> sortD;
    MysterySorterE<int> sortE;

public:
    sorterMain();
};

#endif // SORTERMAIN_H
