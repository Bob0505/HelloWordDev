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
	//UINT8, UINT16, UINT32, UINT64
	printf("<bob>[sizeof] char:%d, short:%d, int:%d, long:%d, float:%d, double:%d, long long:%d\n", 
		sizeof(char),
		sizeof(short),
		sizeof(int),
		sizeof(long),
		sizeof(float),
		sizeof(double),
		sizeof(long long)
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
StatusPrt(void)
{
	STATUS_TYPE	Status;
	printf("STATUS_ERROR:0x%x\n", STATUS_ERROR);

	//need to check
	printf("sizeof(Status):%d, STATUS_ERROR_MEMERROR:0x%x Status:0x%x\n", 
		sizeof(Status), STATUS_ERROR_MEMERROR, (UINT16)Status);

	printf("  <bob>[ln%d]Status = STATUS_ERROR_MEMERROR;\n", __LINE__);
	Status = STATUS_ERROR_MEMERROR;
	if(STATUS_ERROR_MEMERROR == Status)
		printf("  <bob>[ln%d]STATUS_ERROR_MEMERROR == Status\n", __LINE__);

	printf("  <bob>[ln%d]Status = 0;\n", __LINE__);
	Status = 0;
	printf("  <bob>[ln%d]Status: 0x%x\n", __LINE__, Status);
	if(0x0000 == Status)
		printf("  <bob>[ln%d]0x0000 == Status\n", __LINE__);

	printf("  <bob>[ln%d]Status = 0x8001;\n", __LINE__);
	Status = 0x8001;
	printf("  <bob>[ln%d]Status: 0x%x\n", __LINE__, Status);
	if(0x8001 == Status)
		printf("  <bob>[ln%d]0x8001 == Status\n", __LINE__);

	printf("  <bob>[ln%d]Status &= 0x0000ffff;\n", __LINE__);
	Status &= 0x0000ffff;
	printf("  <bob>[ln%d]Status: 0x%x\n", __LINE__, Status);
	if(0x8001 == Status)
		printf("  <bob>[ln%d]0x8001 == Status\n", __LINE__);

}

void
Strfunc(void)
{
	STATUS_TYPE	Status;

	Status = Str_malloc();
	printf("Str_malloc (Status:0x%x)\n", Status);
}

void
TestPrint()
{

	PRINT_TYPE	Printflist[] = {LineFunc,	TypesOfSize,	BitsValue,	\
								VarMax,		StatusPrt,		Strfunc,	\
								NULL};
	UINT8		index;

	for(index=0;NULL!=Printflist[index];index++)
	{ 
		Printflist[index]();
		printf("------  ------  ------\n\n");
	}


}

