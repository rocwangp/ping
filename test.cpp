#include <iostream>
using namespace std;

#include "ping.h"

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        cout << "Enter the ip or port\n";
        return 0;
    }

    CPing myping(argv[1], 1);
    myping.ping();

    return 0;
}
