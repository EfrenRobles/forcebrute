#include "stdafx.h"
#include "Control.h"
#include <iostream>

Control::Control(void)
{
	pass[1] = '\0';
	strcpy_s(base, "");
	strcat_s(base, "0123456789");
	strcat_s(base, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	strcat_s(base, "abcdefghijklmnopqrstuvwxyz");
	strcat_s(base, "!#$%&()*+,-./:;<=>?@[]^{|}~ `\"\\'");
}

Control::~Control(void)
{
	strcpy_s(pass, "");
	strcpy_s(base, "");
	sigue = 0;
	len_pass = 0;
	len_base = 0;
}


void Control::next(void)
{
	bool result = true;
	byte len = len_pass;
	
	while (result && len > 0) {
		len--;
		result = next_character(len);
	};

	if (result) {
		index[len_pass] = 0;
		pass[len_pass] = base[0];
		len_pass++;
		pass[len_pass] = '\0';

	}
}

void Control::initIndex(char* password) {
	byte i = 0;
	len_pass = strlen(password);
	len_base = strlen(base);

	while (i < len_pass - 1) {
		byte j = 0;
		while (j < len_base) {
			if (pass[i] == base[j]) {
				index[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
}

bool Control::next_character(byte len)
{
	if (index[len] < len_base - 1) {
		index[len] = index[len] + 1;
		pass[len] = base[index[len]];
		return false;
	}
	index[len] = 0;
	pass[len] = base[0];

	return true;
}

char* Control::generator (char* password) {
	initIndex(password);

	while(true) {
		next();
		printf("\nThe password is: %s" , pass);
	}
	return pass;
}