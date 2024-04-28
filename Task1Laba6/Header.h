#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include <sstream>
using namespace std;
const string path = "UserFile.txt";
void ContentOfFile();
void FillFile();
int CountOfWords();
bool isInteger(string test_string);
int getNaturalInteger();
void CutFile(int k);