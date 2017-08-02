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

void loadMap1()
{
    input.open("map\\map1.txt");
    char ch;
    for (int i=0; i<playZoneH+1; i++)
    {
        for (int j=0; j<playZoneW+1; j++)
        {
            input >> ch;
            if (ch == '#' && ch != '\n')
                zone[i][j] = 1;

        }

    }
    input.close();

    for (int i=0; i<playZoneH+1; i++)
    {
        for (int j=0; j<playZoneW+1; j++)
        {
            cout << zone[i][j];
        }
        cout << endl;
    }
}

