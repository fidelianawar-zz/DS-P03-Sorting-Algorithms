#include <iostream>
#include <sorter.h>
#include <vector>
#include <sortermain.h>

using namespace std;

int main()
{
    sorterMain sorterObject;
    sorterObject.sortRandomValues();
    sorterObject.sortAscendingValues();
    sorterObject.sortDescendingValues();
    sorterObject.sortDuplicateElements();
    sorterObject.sortAlmostSorted();
    sorterObject.organizeMysteryNames();
    return 1;

}
