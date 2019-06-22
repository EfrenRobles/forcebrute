#pragma once

#include "stdafx.h"

class Control
{
	public:

		Control(void);
		virtual ~Control(void);

		char* generator(char* password);


	protected:
		typedef unsigned char byte;

	private:

		char pass[100];
		byte index[100];

		byte len_pass;
		byte len_base;

		char base[100];
		byte sigue;

		void initIndex(char* password);
		bool next_character(byte len);
		void next(void);
		
};
