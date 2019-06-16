#include "stdafx.h"
#include "recovery.h"


recovery::recovery()
{
	base = "";
	//base += "0123456789";
	base += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	base += "abcdefghijklmnopqrstuvwxyz";
	//base += "!#$%&()*+,-./:;<=>?@[]^{|}~ `\"\\'";

	sigue = true;
}


recovery::~recovery()
{
	base = "";
	sigue = false;
}

void recovery::start(void)
{
	string password = init_generator();
	
	while (sigue && password != "oXXo") {
		password = generator(password);
	}

	printf("\nThe password is: %s" , password.c_str());
	getch();
}

string recovery::init_generator(void)
{
	printf("Searching: ");
	string password = "";
	password += base[0];
	//password += "999";
	return password;
}

string recovery::generator(string password)
{
	size_t len = password.length();

	bool result = false;

	do {
		len--;
		char temp = password[len];
		result = next_character(temp);
		password.replace(len, 1, 1, temp);  
	} while (result && len > 0);


	if (result) {
		password = base[0] + password;
	}

	return password;

}

bool recovery::next_character(char& datum)
{
	size_t i = 0;
	size_t len = base.length() - 1;

	while(i < len) {
		if (base[i] != datum) {
			i++;
			continue;
		}
		datum = base[i + 1];
		return false;
	}
	datum = base[0];
	return true;
}