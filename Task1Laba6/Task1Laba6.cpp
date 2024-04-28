#include"Header.h"
#include<Windows.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k = 0;
	FillFile();
	ContentOfFile();
	cout << "Введите число k: ";
	k = getNaturalInteger();
	CutFile(k);
}

