#include <iostream>

#include "for_range.h"
#include "test.h"



using namespace std;



int main()
{
    cout << "Example of use:" << endl;
    for(auto i: range(1, 5))
    {
        cout << i << ") Hello, World!" << endl;
    }
    cout << endl;

    time_test(4, 4);

    return 0;
}
