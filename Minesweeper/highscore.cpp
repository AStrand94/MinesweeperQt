#include "highscore.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <QMessageBox>
#include <QString>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QDebug>

using namespace std;

//For Mac --> Will be put in
// /Users/'YOUR_USER'/MinesweeperQt/build-Minesweeper-Desktop_Qt_5_8_0_clang_64bit-Debug/Minesweeper.app/Contents/MacOS/Minesweeper
const char *filename = "./highscores.txt";

Highscore::Highscore()
{

}

//Owerwrites/creates "highscores.txt"
void Highscore::createHighscore(string s)
{
    ofstream document(filename);

    document << s;

    document.close();

    cout << "Finished." << endl;
}

void Highscore::setHighscore(string mode, string name, float time)
{
    string s;
    string temp;
    string t;
    string previousLine;
    int j = 0;
    bool modeFound = false;
    bool moveLines = false;
    ifstream file(filename);

    //Loops through the highscore-document
    while(!file.eof()) {
        getline(file, temp);

        //Moves previous highscores down, if a new highscore is set.
        if(moveLines && j != 3) {
            t = previousLine;
            previousLine = temp;
            temp = t;
            j++;
        }
        //Set new highscore if empty.
        else if(modeFound && j != 3) {
            if(temp.at(0) == ' ') {
                temp = to_string(time);
                temp += " - ";
                temp += name;
                j = 3;
            }
            //Finds the current highscores, and replaces if the time is better.
            else {

                string num;
                for(int i = 0; i < temp.length(); i++) {
                    if(temp.at(i) == ' ') break;
                    num += temp.at(i);
                }

                //Replaces score if the time is better.
                if(time < atoi(num.c_str())) {
                    previousLine = temp;
                    temp = to_string(time);
                    temp += " - ";
                    temp += name;
                    moveLines = true;
                }

                j++;
            }
        }

        s += temp;
        s += "\n";

        //Finds the correct header in file [Easy], [Normal] or [Hard].
        if(mode == temp) {
            modeFound = true;
        }
    }
    s.erase(s.length()-1, s.length());

    //Overwrites file.
    createHighscore(s);
}

const char *Highscore::getFileName()
{
    return filename;
}

void Highscore::showHighscore()
{
    //Checks if file exists
    ifstream file(filename);
    if(!file.good()) {
        resetHighscore();
    }

    string s = getDocumentContent();
    QString qs = QString::fromStdString(s);

    //Opens up a QMessageBox with the highscores
    QMessageBox::about(NULL, "Highscore", qs);
}

//Reads the document, and returns its contaning string
string Highscore::getDocumentContent()
{
    string s;
    string temp;
    ifstream file(filename);
    while(!file.eof()) {
        getline(file, temp);
        s += temp;
        s += "\n";
    }

    return s;
}

//Resets the highscores with empty rankings
void Highscore::resetHighscore()
{
    string s = "Easy\n - \n - \n - \n\n"
               "Normal\n - \n - \n - \n\n"
               "Hard\n - \n - \n - ";

    createHighscore(s);

    cout << "Highscore is now reset." << endl;
}

bool Highscore::newHighscore(string mode, int time)
{
    string temp;
    int j = 0;
    bool modeFound = false;

    ifstream file(filename);

    //Loops through the highscore-document
    while(!file.eof()) {
        getline(file, temp);

        //Set new highscore if empty.
        if(modeFound && j != 3) {
            if(temp.at(0) == ' ') {
                return true;
            }
            //Finds the current highscores, and replaces if the time is better.
            else {
                string num;
                for(int i = 0; i < temp.length(); i++) {
                    if(temp.at(i) == ' ') break;
                    num += temp.at(i);
                }

                //Replaces score if the time is better.
                if(time < atoi(num.c_str())) {
                    return true;
                }
                j++;
            }
        }

        //Finds the correct header in file [Easy], [Normal] or [Hard].
        if(mode == temp) {
            modeFound = true;
        }
    }

    return false;
}
