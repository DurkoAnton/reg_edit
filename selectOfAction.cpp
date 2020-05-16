#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#include<iostream>
#include<Windows.h>
#include<string>
#include<locale.h>
#include<regex>
#include<tchar.h>
#include"functionPrototype.h"

int main(){

	setlocale(LC_ALL, "russian");
	
	RegistryFunctions registryFinction;
	CheckingForRegularExpression regularExpression;
	OutputResultFunction outputInformation;

	string pathToTheKey, pathToTheKey_;

	fflush(stdin);

	while (true){

		outputInformation.showMenu();
		fflush(stdin);
		
		switch (regularExpression.inputAndCheckChoiseActionOfMenu(0,12))
		{
		case 1:

			cout << endl << "������� ���� � �����, ��� ���������� ����������� ��������." << endl;
			pathToTheKey = regularExpression.inputAndCheckPathToTheKeyForRegExp();
			outputInformation.processResultOfFunction(registryFinction.readParameterValue(pathToTheKey));
			break;
		case 3:

			cout << endl << "������� ���� � �����, ��� ���������� ����� ���� ��������.\n����� ���� �� ����� ���� ����������� HKLM ��� HKU." << endl;
			pathToTheKey = regularExpression.inputAndCheckPathToTheKeyForRegExp();
			outputInformation.processResultOfFunction(registryFinction.createNewKey(pathToTheKey));
			break;
		case 4:
			
			cout << endl << "������� ���� � �����, ������� ����� �����." << endl;
			pathToTheKey = regularExpression.inputAndCheckPathToTheKeyForRegExp();
			outputInformation.processResultOfFunction(registryFinction.deleteKey(pathToTheKey));
			break;
		case 2:

			cout << endl << "������� ���� � �����, ��� ����� ���������� ����� ��������." << endl;
			pathToTheKey = regularExpression.inputAndCheckPathToTheKeyForRegExp();
			outputInformation.processResultOfFunction(registryFinction.createNewParameter(pathToTheKey));
			break;
		case 5:

			cout << endl << "������� ���� � �����, ��� ���������� ��������� ��������." << endl;
			pathToTheKey = regularExpression.inputAndCheckPathToTheKeyForRegExp();
			outputInformation.processResultOfFunction(registryFinction.deleteParameter(pathToTheKey));
			break;
		case 6:

			outputInformation.processResultOfFunction(registryFinction.getInformationAboutRegistry());
			break;
		case 7:
			
			cout << endl << "������� ���� � �����, ����� ����������� �������� ����� �������� �� �����." << endl;
			pathToTheKey = regularExpression.inputAndCheckPathToTheKeyForRegExp();
			outputInformation.processResultOfFunction(registryFinction.outputSubKeysNames(pathToTheKey));
			break;
		case 9:
			
			cout << endl << "������� ���� � �����-���������." << endl;
			pathToTheKey = regularExpression.inputAndCheckPathToTheKeyForRegExp();

			cout << endl<<endl << "������� ���� � �����-��������." << endl;
			pathToTheKey_ = regularExpression.inputAndCheckPathToTheKeyForRegExp();
			outputInformation.processResultOfFunction(registryFinction.copyKeys(pathToTheKey,pathToTheKey_));
			break;
		case 8:

			cout << endl << "������� ���� � �����, ����� ���������� �������� ����� �������� �� �����." << endl;
			pathToTheKey = regularExpression.inputAndCheckPathToTheKeyForRegExp();
			outputInformation.processResultOfFunction(registryFinction.outputParameterNamesInKey(pathToTheKey));
			break;
		case 10:

			cout << endl << "������� ���� � �����, ������� ����� �������� � ����." << endl;
			pathToTheKey = regularExpression.inputAndCheckPathToTheKeyForRegExp();
			outputInformation.processResultOfFunction(registryFinction.writeKeyInFile(pathToTheKey));
			break;
		case 11:

			cout << endl << "������� ���� � �����, � ������� ����� ������ ����." << endl;
			pathToTheKey = regularExpression.inputAndCheckPathToTheKeyForRegExp();
			outputInformation.processResultOfFunction(registryFinction.readKeyFromFile(pathToTheKey));
			break;
		case 0:
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}