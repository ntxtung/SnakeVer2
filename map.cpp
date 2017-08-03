#include <fstream>
#include <iostream>

#include "Map.h"
#include "Declaration.h"

using namespace std;

extern int zone[playZoneH+1][playZoneW+1];

ifstream input;
ofstream output;

void makeTemplateMap()
{
    output.open(MAP_TEMPLATE);
    for (int i=0; i<playZoneH+1; i++)
    {
        for (int j=0; j<playZoneW+1; j++)
        {
            output << 'O';
        }
        output << endl;
    }
    output.close();
}


