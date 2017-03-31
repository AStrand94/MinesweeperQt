#include "highscore.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <QMessageBox>
#include <QString>

using namespace std;

const char *filename = "/Users/stiangrim/Desktop/highscores.txt";

Highscore::Highscore()
{

}

void Highscore::createHighscore(string s)
{
    ofstream document(filename);

    document << s;

    document.close();

    cout << "Finished." << endl;
}

void Highscore::readFromFile(const char *filename)
{
    string s;
    ifstream file(filename);
    while(!file.eof()) {
        getline(file, s);
        cout << s;
        cout << endl;
    }
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

        if(moveLines && j != 3) {
            t = previousLine;
            previousLine = temp;
            temp = t;
            j++;
        }
        else if(modeFound && j != 3) {
            if(temp.at(0) == ' ') {
                temp = to_string(time);
                temp += " - ";
                temp += name;
                j = 3;
            } else {

                string num;
                for(int i = 0; i < temp.length(); i++) {
                    if(temp.at(i) == ' ') break;
                    num += temp.at(i);
                }

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

        //Finds the correct header in file
        if(mode == temp) {
            modeFound = true;
        }
    }
    s.erase(s.length()-1, s.length());
    createHighscore(s);
}

const char *Highscore::getFileName()
{
    return filename;
}

void Highscore::showHighscore()
{
    string s = getDocumentContent();
    QString qs = QString::fromStdString(s);

    QMessageBox::about(NULL, "Highscore", qs);
}

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

void Highscore::resetHighscore()
{
    ofstream document(filename);

    document << "Easy\n - \n - \n - \n\n"
                "Normal\n - \n - \n - \n\n"
                "Hard\n - \n - \n - ";

    document.close();

    cout << "Highscore is now reset." << endl;
}
