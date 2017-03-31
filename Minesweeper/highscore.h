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
    void readFromFile(const char*);
    void setHighscore(string, string, float);
    const char* getFileName();
    void showHighscore();
    string getDocumentContent();
    void resetHighscore();
};

#endif // HIGHSCORE_H
