#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void output(int currentIdBlock, ifstream &fin, int currentIdBlockSize){
	if (currentIdBlock == 4 || currentIdBlock == 6) {
		int intOutput = 0;
		fin.read((char*)&intOutput, 1);
		cout << intOutput;
	}
	else {
		char* charOutput = new char[currentIdBlockSize];
		fin.read((char*)charOutput, currentIdBlockSize);
		for (int i = 0; i < currentIdBlockSize; i++) {
			cout << charOutput[i];
		}
		delete charOutput;
	}
}

int select(char var, ifstream &fin, string path, int numPers) {
	if (var == 'e') {
		fin.close();
		return  0;
	}
	int intVar = var - '0';
	if (intVar > numPers) {
		cout << "No information about this ID..."<<endl;
		return 0;
	}
	cout << "*****************************" << endl;
	int bytePos = 1;
	int currentIdSize = 0;
	for (int k = 0; k < intVar; k++) {
		bytePos++;
		fin.seekg(bytePos);
		currentIdSize = 0;
		fin.read((char*)&currentIdSize, 1);
		bytePos +=currentIdSize+1;
	//	cout << "currentIDSize" << currentIdSize << endl;
	}
	//cout <<"bytePos 1   "<< bytePos;
	bytePos -= (currentIdSize);
	//cout << "bytePos 2   " << bytePos<< endl;
	int currentIdBlock = 0;
	int currentIdBlockSize = 0;
	for (int j = 1; j < 7; j++) {
		fin.seekg(bytePos);
		fin.read((char*)&currentIdBlock, 1);
		cout << currentIdBlock<<": ";
		if (currentIdBlock == j) {
			bytePos++;
			fin.seekg(bytePos);
			fin.read((char*)&currentIdBlockSize, 1);
			output(currentIdBlock, fin, currentIdBlockSize);
			bytePos += currentIdBlockSize + 1;
			cout << "" << endl;
		}
		else {
			bytePos++;
			fin.seekg(bytePos);
			fin.read((char*)&currentIdBlockSize, 1);
			output(currentIdBlock, fin, currentIdBlockSize);
			bytePos += currentIdBlockSize + 1;
			j = currentIdBlock;
			cout << "" << endl;
		}
	}
	cout << "*****************************"<<endl;
	return 0;

}
	int main()
	{
		string path = "UserData.bin";
		ifstream fin;
		fin.open(path);

		if (fin.is_open())
		{
			cout << "All is good!" << endl;
			cout << "Enter comand:" << endl;
			char var; // id запрашиваемого человек
			bool checkComand; // проверка на допустимую команду 
			char arrayComand[11] = {'0','1','2','3','4','5','6','7','8','9','e'};
			int numPers = 0; // Кол-во человек в списке
			fin.seekg(0);
			fin.read((char*)&numPers, 1);

			while (fin.is_open()) {  // пока открыт файл, читаю команды с клавиатуры 
				cin >> var;
				if (var == 'E') var = 'e';
				if (var == arrayComand[0]) {
					system("cls");
					for (int n = 1; n <= numPers; n++) {
						char m = n + '0';
						select(m, fin, path, numPers);
						checkComand = true;
					}
				}
				for (int i = 1; i < 11; i++) {
						if(var == arrayComand[i]) {
						system("cls");
						select(var, fin, path, numPers); // функция вывода информации по запрашиваемому номеру id
						checkComand = true;
					}
				}
				if (!checkComand) continue;
			}
		}
		else
		{
			cout << "Error: it's not working :(";
		}
				fin.close();
	}


