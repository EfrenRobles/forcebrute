#include "stdafx.h"
#include "recovery.h"


recovery::recovery()
{
	store = "";
	store += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//store += "abcdefghijklmnopqrstuvwxyz";
	//store += "0123456789";
	//store += "!#$%&()*+,-./:;<=>?@[]^{|}~ `\"\\'";

	sigue = true;
}


recovery::~recovery()
{
	store = "";
}

void recovery::start(void)
{
	unsigned char lengthChar = 1;

	while (sigue) {
		generator(lengthChar, "");
		lengthChar++;
	}

}

string recovery::generator(unsigned char lengthChar, string password)
{
	if (lengthChar == 0) {

		if (password == "OXXO") {
			cout << "password is:" << password << "\n";
			sigue = false;
			cin;
		}

		return password;
	}

	size_t i = 0;
	size_t j = store.length();

	while (i < j && sigue) {
		string buffer = password + store[i];
		generator(lengthChar - 1, buffer);
		cout << "\rsearching: " << password;
		i++;
	}

	return password;
}
