#include <iostream>
#include "include/Box.h"
#include "testutil.h"

using namespace std;

void runTest()
{
    bool passed = true;

    Box b1(1,"one");
    passed &= checkInt(b1.getNum(),1);
    char *name = b1.getPlantName();
    passed &= checkStr(name,"one");

    if (passed)
    {
	cout << "Passed" << endl;
    }
    else
    {
	cout << "Failed" << endl;
    }
}

int main()
{
    runTest();
    return 0;
}
