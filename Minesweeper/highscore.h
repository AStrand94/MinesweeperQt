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
    void setHighscore(string, string, int);
    const char* getFileName();
    void showHighscore();
    string getDocumentContent();
    void resetHighscore();
};

#endif // HIGHSCORE_H
