#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "type.h" 
#include "Status_Type.h"

void
LineFunc(void)
{
	printf("<bob>[ln%d] %s, HelloWord!!\n", __LINE__, __FUNCTION__);
}

void
TypesOfSize(void)
{
	//UINT8, UINT16, UINT32
	printf("<bob>[sizeof] char:%d, short:%d, int:%d, long:%d, float:%d, double:%d\n", 
		sizeof(char),
		sizeof(short),
		sizeof(int),
		sizeof(long),
		sizeof(float),
		sizeof(double)
	);
}

void
BitsValue(void)
{
	UINT8		index;

	//BITs
	printf("<bob>[BITs Value]\n");
	for(index=0; index<8 ; index++){
		printf("\tBIT(%d):0x%02x", index, BIT(index));
		
		if((NEXT_LINE_ITEM-1)==(index%NEXT_LINE_ITEM))
			printf("\n");
		else
			printf("   ");
	}
}

void
VarMax(void)
{
	//Variable Max bits, Max value
	printf("<bob>[%dbits Variable] Max bits:0x%x, Max value:0x%x\n", 
		8*sizeof(UINT16),
		(UINT32)BIT(8*sizeof(UINT16)-1),
		(UINT32)(pow(2, 8*sizeof(UINT16))-1)
	);

}

void
TestPrint()
{

	PRINT_TYPE	Printflist[] = {LineFunc, TypesOfSize, BitsValue, VarMax, NULL};
	UINT8		index;

#if 0
	LineFunc();
	TypesOfSize();
	BitsValue();
	VarMax();

	printf("------  ------  ------\n\n");
#endif

	for(index=0;NULL!=Printflist[index];index++)
	{ 
		Printflist[index]();
		printf("------  ------  ------\n\n");
	}	


	printf("STATUS_ERROR:0x%x\n", STATUS_ERROR);
}

