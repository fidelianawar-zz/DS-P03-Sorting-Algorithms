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
    vector.push_back(9);
    vector.push_back(2340);
    vector.push_back(35635763);
    vector.push_back(34);
    vector.push_back(234);
    sortA.setData(vector);
    sortA.sort();


}
