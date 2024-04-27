#include "Header.h"

void ContentOfFile() {
    ifstream file(path);
    int words = 0;
    if (!file.is_open()) {
        cout << "Не удается открыть файл !" << endl;
        return  ;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
        words++;
    }
    file.close();
}

void FillFile() {
    string input;
    ofstream file(path);
    getline(cin, input);
    if (!file.is_open()) {
        cout << "Не удается открыть файл !" << endl;
    }
    else {
        file << input;
    }
    file.close();

}

int CountOfWords() {
    ifstream file;
    int words = 0;
    file.open(path, ios::in);
    if (!file.is_open()) {
        cout << " Не удается открыть файл !" << endl;
    }
    else {
        string str;
        while (!file.eof()) {
            getline(file, str, ' ');
            words++;
        }
    }
    file.close();
    return words;
}
