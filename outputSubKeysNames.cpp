#include"functionPrototype.h"

ResultOfRegistryFunctions RegistryFunctions::outputSubKeysNames(string  fullPathToTheKey){

	char subKeysNames[MAX_PATH];
	DWORD size = MAX_PATH;

	HKEY key;
	string pathToTheKey = "";

	if (fullPathToTheKey.find_first_of('\\') != -1)

		pathToTheKey = fullPathToTheKey.substr(fullPathToTheKey.find_first_of('\\') + 1, fullPathToTheKey.length() - fullPathToTheKey.find_first_of('\\'));

	int i = 0;
	
	if (RegOpenKeyEx(tranformStringToHKEY(fullPathToTheKey.substr(0, fullPathToTheKey.find_first_of('\\'))), pathToTheKey.c_str(), NULL, KEY_WOW64_64KEY | KEY_ALL_ACCESS | KEY_ENUMERATE_SUB_KEYS, &key) != ERROR_SUCCESS)
		return ERROR_OPEN_KEY;

	DWORD countSubkeysInKey = getCountSubKeysInKey(key);

	if (countSubkeysInKey == 0) return ERROR_NOT_ARE_SUB_KEYS;

	while (i<countSubkeysInKey){
		if (RegEnumKey(key, i, (LPSTR)&subKeysNames, size) != ERROR_SUCCESS)
			return ERROR_ENUM_SUB_KEYS;
		i++;
		outputInformation.outputKeyName(subKeysNames, i);
	}

	outputInformation.outputWaitingKeyCode();

	return NO_ERRORS;
}

DWORD RegistryFunctions::getCountSubKeysInKey(HKEY key){
	
	DWORD countSubKeys;

	if (RegQueryInfoKey(key, NULL, NULL, NULL, &countSubKeys, NULL, NULL, NULL, NULL, NULL, NULL, NULL) != ERROR_SUCCESS){
		return ERROR_GET_INFORMATION_ABOUT_REGISTRY;
	}

	return countSubKeys;
}
