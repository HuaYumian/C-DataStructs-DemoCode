#include "Includes.h"

/**
 *@Project:  DataStruct Practice
 *@author :  Zhongqiang Zhai
 *@Date   :  2016/12/1
 *@Note   :  This code update to GitHub.
 */

int main(int argc, char *argv[])
{
	clock_t begin,end;
	double cost_time=0;
	begin=clock();
	/*�������*/
	SequenceList_Test();

	
	end=clock();
	cost_time=(double)(end-begin)/CLOCKS_PER_SEC;
	printf("�����ʱ��%lf seconds\n\n", cost_time);
	return 0;
}



