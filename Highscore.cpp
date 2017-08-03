#include "Highscore.h"

using namespace std;

ifstream inf;
ofstream ouf;
int highscore;

void inputHscore()
{
    inf.open("Highscore.txt");
    inf >> highscore;

    inf.close();
}

void highScore()
{

}
