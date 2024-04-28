#include "Header.h"

void ContentOfFile() {
    ifstream file(path);
    if (!file.is_open()) {
        cout << "Не удается открыть файл !" << endl;
        return  ;
    }
    string line;
    cout << "Содержимое файла : ";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void FillFile() {
    string input;
    ofstream file(path);
    cout << "Введите текст: ";
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
bool isInteger(string test_string) {
    char* pointer = &test_string[0];

    for (int i = 0; i < test_string.size(); i++) {
        if (isdigit(*pointer) == 0)
            return false;
        pointer++;
    }
    return true;
}
int getNaturalInteger() {
    string user_string;
    int array_size;
    while (true) {
        try {
            cin >> user_string;
            if ((isInteger(user_string) != true)) {
                throw "error";
            }
            array_size = stoi(user_string);
            if (array_size > CountOfWords()) {
                throw "error";
            }
            return array_size;
        }
        catch (...) {
            cout << " Неккоректное значение! Попробуйте еще раз : ";
            cin.clear();
            while (cin.get() != '\n');

            continue;
        }
    }
}
void CutFile(int k) {
    int lenFile = CountOfWords();
    cout << lenFile << endl;
    string* CutArray = new string[lenFile];
    ifstream file(path);
    int step = 0;
    int spaceCount = 0;
    string str = " ";
    while (!file.eof()) {
        file >> str;
        if (str != " ") {
            CutArray[step] = str;
        }
        step++;
    }
    for (int i = 0; i < lenFile; i++) {
        if (CutArray[i] == "") {
            spaceCount++;
        }
    }
    cout << spaceCount << endl;
    if ((k+spaceCount - lenFile) == 0) {
        cout << "Кол-во слов в файле и число k совпадают" << endl;
    }
    else{
        cout << "Отредактированный файл:  ";
        for (int i = 0; i < lenFile - (k+spaceCount); i++) {

            cout << CutArray[i] << "  ";
        }
        
    }
  
}

