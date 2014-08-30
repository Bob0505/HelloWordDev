#include <stdio.h>
#include <stdlib.h>
#include "type.h" 
#include "Status_Type.h"

//study web : http://openhome.cc/Gossip/CGossip/
//str		: http://pydoing.blogspot.tw/2010/07/c-stdstring.html
//memory	: http://pydoing.blogspot.tw/2010/07/c-free.html

//To Do
//	str
//	memory
//linklist
int main(int argc, char *argv[]) {

	STATUS_TYPE	Status;

//	TestPrint();
	Status = Str_malloc();
	printf("Str_malloc (Status:0x%x)\n", Status);

	//need to check
	Status = STATUS_ERROR_MEMERROR;
	printf("STATUS_ERROR_MEMERROR:0x%x Status:0x%x\n", STATUS_ERROR_MEMERROR, Status);


//	system("PAUSE");
	return 0;
}
