#include"functionPrototype.h"
#include<conio.h>
void OutputResultFunction::outputStringValue(char *data, DWORD size){
	int i = 0;
	while (i < size)
		cout << data[i++];
	cout << endl << endl;
}
void OutputResultFunction::outputRegBinaryValue(char *r, DWORD size){
	int i = 0;
	while (i < size-1){
		cout <<hex<<(int)r[i] << " ";
		i++;
	}
	cout << endl << endl;
}
void OutputResultFunction::outputNumericValue(char *r, DWORD size){
	int i = 0;
	wchar_t wr[MAX_PATH];
	swprintf(wr, L"%s", r);
	wcout << (int)wr[i++];

	cout << endl << endl;
}
bool OutputResultFunction::checkParameterTypeForOutput(DWORD parameterType, char *parameterValue, DWORD parameterSize,string parameterName){

	switch (parameterType){
	case REG_SZ:

		outputParameterNameAndType(parameterName, "REG_SZ");
		cout << "��������: ";
		outputStringValue(parameterValue, parameterSize);
		outputWaitingKeyCode();
		return true;
	case REG_DWORD:

		outputParameterNameAndType(parameterName, "REG_DWORD");
		cout << "��������: ";
		outputNumericValue(parameterValue, parameterSize);
		outputWaitingKeyCode();
		return true;
	case REG_BINARY:

		outputParameterNameAndType(parameterName, "REG_BINARY");
		cout << "��������: ";
		outputRegBinaryValue(parameterValue, parameterSize);
		outputWaitingKeyCode();
		return true;
	case REG_EXPAND_SZ:

		outputParameterNameAndType(parameterName, "REG_EXPAND_SZ");
		cout << "��������: ";
		outputStringValue(parameterValue, parameterSize);
		outputWaitingKeyCode();
		return true;
	case REG_MULTI_SZ:

		outputParameterNameAndType(parameterName, "REG_MULTI_SZ");
		cout << "��������: ";
		outputStringValue(parameterValue, parameterSize);
		outputWaitingKeyCode();
		return true;
	case REG_QWORD:

		outputParameterNameAndType(parameterName, "REG_DWORD");
		cout << "��������: ";
		outputNumericValue(parameterValue, parameterSize);
		outputWaitingKeyCode();
		return true;
	}
	return false;
}

void OutputResultFunction::showMenu(){
	system("cls");
	cout << endl << "�������� ������� ��� ������ � ��������:" << endl;
	cout << endl << "1. ������ �� �������" << endl;
	cout << endl << "2. ������ ��������� � ������" << endl;
	cout << endl << "3. �������� �����" << endl;
	cout << endl << "4. �������� ����� " << endl;
	cout << endl << "5. �������� ���������" << endl;
	cout << endl << "6. ���������� � �������" << endl;
	cout << endl << "7. ����� �����������" << endl;
	cout << endl << "8. ����� ����������" << endl;
	cout << endl << "9. ����������� �����������" << endl;
	cout << endl << "10. ��������� ������ � ����" << endl;
	cout << endl << "11. ��������� ������ �� �����" << endl;
	cout << endl << "0. ����� �� ���������" << endl;
}

void OutputResultFunction::processResultOfFunction(ResultOfRegistryFunctions typevalue){

	if (typevalue == NO_ERRORS)
		return;

	system("cls");
	cout << "�����:" << endl << endl;

	switch (typevalue){
	case ERROR_OPEN_KEY:
		cout << endl << "������ �������� �����!��������� �������� ����." << endl;
		break;
	case ERROR_GET_VALUE:
		cout << endl << "������ ��������� �������� ���������!��������� �������� ���� � ��� ���������." << endl;
		break;
	case ERROR_CREATE_KEY:
		cout << endl << "������ �������� �����!��������� �������� ���� � ��� ���������." << endl;
		break;
	case ERROR_DELETE_KEY:
		cout << endl << "������ �������� �����!��������� ���������� ��������� ���������� �����." << endl;
		break;
	case ERROR_DELETE_PARAMETER:
		cout << endl << "������ �������� ���������!��������� ���� � ����� � ��� ���������." << endl;
		break;
	case ERROR_COPY_KEYS:
		cout << endl << "������ ����������� �����!��������� ���� � ����� � ��� ���������." << endl;
		break;
	case ERROR_NOT_ARE_SUB_KEYS:
		cout << endl << "������ ������ �� �������� �����������." << endl;
		break;
	case ERROR_NOT_ARE_VALUES_IN_KEY:
		cout << endl << "������ ���� �� �������� ����������." << endl;
		break;
	case ERROR_UNSUPPORTED_REG_TYPE:
		cout << endl << "���������������� ��� ������!" << endl;
		break;
	case ERROR_WRITE_KEY_IN_FILE:
		cout << endl << "������ ������ ����� � ����!��������� ���������� ���������� �����������." << endl;
		break;
	case ERROR_READ_KEY_FROM_FILE:
		cout << endl << "������ ������ ����� �� �����!��������� ��� ����� � ���������� ���������� �����������." << endl;
		break;
	case ERROR_CREATE_PARAMETER:
		cout << endl << "������ �������� ������ ���������!��������� �������� ��������������." << endl;
		break;
	case ERROR_ENUM_PARAMETERS:
		cout << endl << "������ ������������ ����������!��������� �������� ��������������." << endl;
		break;
	case ERROR_ENUM_SUB_KEYS:
		cout << endl << "������ ������������ �����������!��������� �������� ��������������." << endl;
		break;
	case ERROR_GET_INFORMATION_ABOUT_REGISTRY:
		cout << endl << "������ ��������� ���������� � ������ �������." << endl;
		break;
	}
	outputWaitingKeyCode();
}

void  OutputResultFunction::outputParameterNameAndType(string parameterName,string parameterType){
	system("cls");
	cout << endl << "�����:" << endl << endl;
	cout << endl << "��� ���������: " << parameterName << endl << endl;
	cout << "���: "<<parameterType << endl << endl;
}


void  OutputResultFunction::outputNewParameter(string parameterName, string parameterType, string parameterValue ){

	system("cls");
	cout << endl << "�����:" << endl << endl;
	cout << endl << "��� ���������: " << parameterName << endl << endl;
	cout << "���: " << parameterType << endl << endl;
	cout << "��������: " << parameterValue << endl << endl;

	outputWaitingKeyCode();
}

void OutputResultFunction::outputKeyName(char *keyName,int index){
	int i = 0;
	if (index == 1){
		system("cls");
		cout << endl << "�����:" << endl << endl << endl;
	}
	cout << index << ". ";
	while (keyName[i])
		cout << keyName[i++];

	cout << endl << endl; 
}

void OutputResultFunction::outputWaitingKeyCode(){
	cout << endl << "������� ����� ������� ��� �������� � ����..." << endl;
	_getche();
}

void OutputResultFunction::outputSuccessCreatingKey(string newKeyNameString){
	system("cls");
	cout << "�����:" << endl << endl;
	cout << endl << "C����� ���� � ������ " << "''" << newKeyNameString << "''" << endl;

	outputWaitingKeyCode();
}

void OutputResultFunction::outputSuccessDeletingKey(string  fullPathToTheKey){
	system("cls");
	cout << "�����: " << endl << endl;
	cout << endl << "���� " << fullPathToTheKey << " �����." << endl;

	outputWaitingKeyCode();

}

void OutputResultFunction::outputSuccessSavingKey(string  fullPathToTheKey,string fileName){
	system("cls");
	cout << endl << "�����:" << endl << endl;
	cout << endl << "���� " << fullPathToTheKey<<" ������� � ���� " << fileName << "." << endl << endl;

	outputWaitingKeyCode();
}

void OutputResultFunction::outputSuccessRestoringKey(string  fullPathToTheKey, string fileName){
	system("cls");
	cout << endl << "�����:" << endl << endl;
	cout << endl << "���� " << fileName << " ������ � ���� " << fullPathToTheKey << "." << endl << endl;

	outputWaitingKeyCode();
}

void OutputResultFunction::outputParameterName(char *keyName, int index,string fullPathToTheKey){
	int i = 0;
	if (index == 1){
		system("cls");
		cout << endl << "�����:" << endl << endl << endl;
		cout << "��������� ����� " << fullPathToTheKey << ":" << endl << endl << endl;
	}
	cout << index << ". ";
	while (keyName[i])
		cout << keyName[i++];

	cout << endl << endl;
}

void OutputResultFunction::outputSuccessDeletingParameter(string parameterNameString,string pathToTheKey){
	system("cls");
	cout << endl << "�����: " << endl << endl;
	cout << endl << "�������� " << parameterNameString << " ����� �� ����� "<<pathToTheKey <<"."<< endl;

	outputWaitingKeyCode();
}

void OutputResultFunction::outputSuccessCopyingKeys(string pathToTheKeySource, string pathToTheKeyDestination){
	system("cls");
	cout << endl << "�����: " << endl << endl;
	cout << endl << "���� " << pathToTheKeySource << " ���������� � ���� " << pathToTheKeyDestination << "." << endl;

	outputWaitingKeyCode();
}
