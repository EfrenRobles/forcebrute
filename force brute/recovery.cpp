#include "stdafx.h"
#include "recovery.h"


recovery::recovery()
{
}


recovery::~recovery()
{
}

void recovery::start(void)
{
	char* pass = "";

	pass = ctrl.generator(pass);


//	while(true) {
//		pass = ctrl.next(pass);
//		printf("\nThe password is: %s" , pass);
//	}

	_getch();
}
