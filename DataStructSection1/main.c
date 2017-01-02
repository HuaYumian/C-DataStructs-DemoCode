#include "Includes.h"

/**
 *@Project:  DataStruct Practice
 *@author :  Zhongqiang Zhai
 *@Date   :  2016/12/1
 */

int main(int argc, char *argv[])
{
	ORDER_LIST_PTR L;
	int i;
	printf("Hello C-Free!\n");
	
	if(Init_OrderList(L)){
		Insert_OrderList(L,1,101);	
		Insert_OrderList(L,1,102);
		Insert_OrderList(L,1,103);
		Insert_OrderList(L,1,104);
	}
	
	printf("-------------------------------\n");
	printf("DebugNote:\r\n");
	printf("\tlength=%d\n",L->length);	
	printf("\tlistSize=%d\n",L->listSize);
	printf("-------------------------------\n");
	
	for(i=0;i<L->listSize;i++){
		printf("element[%d]=%d\n",i,L->element[i]);	
	}
	
	return 0;
}



