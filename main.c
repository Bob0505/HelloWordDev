#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "type.h" 
#include "Status_Type.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	UINT16	LineNum;
	UINT8	index;

	printf("------  ------  ------\n\n");

	LineNum = __LINE__;
	printf("<bob>[ln%d] %s, HelloWord!!\n", LineNum, __FUNCTION__);

	//UINT8, UINT16, UINT32
	printf("<bob>[sizeof] char:%d, short:%d, int:%d, long:%d, float:%d, double:%d\n", 
		sizeof(char),
		sizeof(short),
		sizeof(int),
		sizeof(long),
		sizeof(float),
		sizeof(double)
	);

	printf("------  ------  ------\n\n");
	//BITs
	printf("<bob>[BITs Value]\n");
	for(index=0; index<8 ; index++){
		printf("\tBIT(%d):0x%02x", index, BIT(index));
		
		if((NEXT_LINE_ITEM-1)==(index%NEXT_LINE_ITEM))
			printf("\n");
		else
			printf("   ");
	}

	printf("------  ------  ------\n\n");
	//Variable Max bits, Max value
	printf("<bob>[%dbits Variable] Max bits:0x%x, Max value:0x%x\n", 
		8*sizeof(UINT16),
		(UINT32)BIT(8*sizeof(UINT16)-1),
		(UINT32)(pow(2, 8*sizeof(UINT16))-1)
	);

	printf("------  ------  ------\n\n");
	printf("STATUS_ERROR:0x%x\n", STATUS_ERROR);

//	system("PAUSE");
	return 0;
}
