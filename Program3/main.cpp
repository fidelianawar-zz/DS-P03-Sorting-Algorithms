#include <iostream>
#include <sorter.h>
#include <vector>
#include <sortermain.h>

using namespace std;

int main()
{
    sorterMain sorterObject;

//    cout << "the average sort times are: "<< endl;
//    sorterObject.performAverageSort();

//    cout << "the worst sort times are: "<< endl;
//    sorterObject.performWorstSort();

//    cout << "the best sort times are: "<< endl;
    sorterObject.performBestSort();

    return 1;

}
