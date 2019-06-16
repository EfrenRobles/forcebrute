#pragma once

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class recovery
{
	public:
		recovery();
		~recovery();
	
		void start(void);

		typedef unsigned char byte;
	
	private:

		//string generator(unsigned char lengthChar, string password);
		string generator(string password);
		string init_generator(void);
		bool next_character(char& datum);

		bool sigue;
		string base;


		
};

