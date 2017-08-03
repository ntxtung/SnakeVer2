#include "Highscore.h"

using namespace std;

ifstream inf;
ofstream ouf;

struct ScoreSet{
    char *name;
    int score;
};

int highscore;

void inputHscore()
{
    inf.open("Highscore.txt");
    inf >> highscore;

    inf.close();
}

void outputHscore()
{
    ouf.open("Highscore.txt");
    ouf << highscore;

    ouf.close();
}

void processHighScore(int score)
{

  //  if (score > highscore)
    {
//        highscore = score;
        outputHscore();
    }
}
