#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int LineNum;

	LineNum = __LINE__;
	printf("<bob>[ln%d] %s, HelloWord!!\n", LineNum, __FUNCTION__);
	
//	system("PAUSE");
	return 0;
}
