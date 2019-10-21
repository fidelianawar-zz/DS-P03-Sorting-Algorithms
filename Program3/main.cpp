#include <iostream>
#include <sorter.h>
#include <vector>
#include <sortermain.h>

using namespace std;

int main()
{
    sorterMain sorterObject;

    cout<<"The times of sort random are: " << endl;
    sorterObject.sortRandomValues();

    cout << endl;

    cout<<"The times of sort ascending are: " << endl;
    sorterObject.sortAscendingValues();

    cout << endl;

    cout<<"The times of sort descending are: " << endl;
    sorterObject.sortDescendingValues();

    cout << endl;

    cout<<"The times of sort duplicates are: " << endl;
    sorterObject.sortDuplicateElements();

    cout << endl;

    cout<<"The times of sort of almost sorted are: " << endl;
    sorterObject.sortAlmostSorted();

    sorterObject.organizeMysteryNames();

    return 1;

}
