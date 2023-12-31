#include <iostream>
#include <cstring>
#include "include/Box.h"
#include "include/BoxTree.h"

using namespace std;

void runTest(const int numValues,const int* values,const int numRemoveValues,const int* removeValues)
{
    bool passed = true;

    BoxTree bt;

    for (int i=0;i<numValues;i++)
    {
        Box *box = new  Box(values[i],"one");
	    bt.insert(box);
    }

    for (int i=0;i<numRemoveValues;i++)
    {
	bt.remove(removeValues[i]);
    }

    if (numValues > 3)
    {
	int a = values[0];
	int b = values[1];
	if (a > b) 
	{
	    int tmp = a;
	    a = b;
	    b = tmp;
	}
    }

    cout << "Nodes:" << endl;
    cout << endl;
}

int main()
{
    int numValues = 50;
    int values[] = 
	{27, 24, 181, 100, 189, 129, 95, 19, 72, 18, 118, 168, 198, 146, 131, 61, 124, 15, 115, 
	 21, 85, 82, 144, 179, 167, 145, 52, 164, 185, 101, 5, 197, 184, 123, 31, 36, 66, 3, 193, 
	 177, 103, 159, 142, 180, 149, 138, 47, 125, 194, 48};

    int numRemoveValues = 3;
    int removeValues[] =
	{19, 100, 24};

    // debugging remove
    int smallTreeNumValues = 6;
    int smallTreeValues[] = {50, 10, 70, 60, 80, 90};
    int smallTreeNumRemoveValues = 1;
    int smallTreeRemoveValues[] = {10};

    runTest(smallTreeNumValues,smallTreeValues,smallTreeNumRemoveValues,smallTreeRemoveValues);
    runTest(numValues,values,numRemoveValues,removeValues);
    return 0;
}
