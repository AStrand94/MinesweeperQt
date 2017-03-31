#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <iostream>
#include <QString>

using namespace std;

class Highscore
{
public:
    Highscore();
    void createHighscore(string);
    void setHighscore(string, string, float);
    const char* getFileName();
    void showHighscore();
    string getDocumentContent();
    void resetHighscore();
    bool newHighscore(string, int);
};

#endif // HIGHSCORE_H
