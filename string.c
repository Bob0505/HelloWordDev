#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"
#include "Status_Type.h"

STATUS_TYPE Str_malloc(void)
{
    char	SampleStr1[] = {"History repeats"};
	char	SampleStr2[] = {" itself.\n"};
    UINT8	SampleStr1_len, SampleStr2_len;
    char	*str_ptr;

	SampleStr1_len = strlen(SampleStr1);
	SampleStr2_len = strlen(SampleStr2);

	printf("[ln%d] str1:%d, str2:%d\n", __LINE__, SampleStr1_len, SampleStr2_len);

	str_ptr = malloc(SampleStr1_len);
	if (NULL == str_ptr)
	{
		printf("Memory Allocate fail\n");
		return STATUS_ERROR_MEMERROR;
	}

	strcpy(str_ptr, SampleStr1);
 	printf("\n[ln%d] %s",__LINE__, str_ptr);
 
    str_ptr = realloc(str_ptr, SampleStr2_len);
    if(NULL == str_ptr)
    {
		printf("Expansion Memory fail\n");
		return STATUS_ERROR_MEMERROR;
	}

	strcat(str_ptr, SampleStr2);
    printf("\n[ln%d] %s", __LINE__, str_ptr);

	free(str_ptr);
    return STATUS_SUCCESS;
}

