#pragma once

#include <iostream>
#include <string>
#include "global.h"

using namespace std;

class recovery : public global
{
	public:
		recovery();
		~recovery();
	
		void start(void);

	private:
		const char* clave = "OXXO";

		string result = "";


		unsigned __int64 contador = 0;
		bool sigue = true;
		byte len = 0;
		string store = "";

		string incrementalNumber(const char* buffer);
		string nextNumber(string password);




};

