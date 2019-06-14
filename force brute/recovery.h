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

		string generator(unsigned char lengthChar, string password);
		bool sigue;
		string store;

		
};

