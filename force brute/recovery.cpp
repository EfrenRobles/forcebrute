#include "pch.h"
#include "recovery.h"


recovery::recovery()
{
	store = "";
	//store += alphabetLower;
	//store += alphabetUpper;
	//store += specialSymbols;

	store += digits;
	len = store.size() - 1;
}


recovery::~recovery()
{
	store = "";
	sigue = false;
	len = 0;
	contador = 0;
}

void recovery::start(void)
{
	
	string password = "";

	while (true) {
		password = nextNumber(password);
	}

}

string recovery::nextNumber(string password)
{
	size_t len = password.size();
	const char* buffer = password.c_str();
	password = "";

	if (len == 0) {
		return incrementalNumber(buffer);
	}

	
	for (size_t i = len; i > 0; i--)
	{
		string cad = "" + buffer[i];
		string res = incrementalNumber(cad.c_str());

		if (res == "" + store[0]) {

		}

	}


	return "";
}

string recovery::incrementalNumber(const char* buffer)
{
	string temp = "";

	if (strlen(buffer) == 1) {
		byte seed = buffer[0];
		size_t index = store.find(seed);

		return (index == len) ? temp + store[0] : temp + store[index + 1];
	} 
		
	return temp + store[0];
}

//void recovery::generator(byte lengthChar, string password)
//{
//
//	if (lengthChar == 0) {
//
//		if (password == clave) {
//			cout << "password is:" << password << "\n";
//			sigue = false;
//			cin;
//		}
//
//		cout << "\rsearching: " << password << " contador: " << contador;
//		contador++;
//		return; // password;
//	}
//	
//
//	unsigned __int64 i = 0;
//	unsigned __int64 j = store.length();
//
//	while (i < j && sigue) {
//		generator(lengthChar - 1, password + store[i]);
//		i++;
//	}
//
//	return; // password;
//}
