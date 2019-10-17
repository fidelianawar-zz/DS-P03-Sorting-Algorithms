#include "sortermain.h"
#include <iostream>
#include <vector>

sorterMain::sorterMain()
{
    vector<int> vector;
    vector.push_back(1);
    vector.push_back(5);
    vector.push_back(2);
    vector.push_back(4);
    vector.push_back(3);
    sortE.setData(vector);
    sortE.sort();


}
