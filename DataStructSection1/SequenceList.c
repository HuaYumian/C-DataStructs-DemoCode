#include "Includes.h"

/*******************************************************************************
 *@topic:  线性表的顺序表示和实现 
 *@date :  2016/12/07
 *@note :  顺序表：顾名思义是一段连续存储空间，数组在高级语言中恰好有随机存储的特性
           通常用数组来表示数据结构中的顺序存储结构。
           参考代码： 
		   http://www.jianshu.com/p/347041b45be5 
 *@bugNote：
 --1--初始化内存之后，发现里面的数据不为0，如何在初始化的时候就把存储空间清空
 --2-- 
*******************************************************************************/



/**
 *@Function: 构造一个空的线性表 
 *@params  :
 *@return  :
 *@note    : 初始化线性表 
 *@note2   : malloc函数原型：void *malloc(unsigned int num_size); memory allocation动态内存分配 
 void* 表示未确定类型的指针，void*可指向任何数据类型。如果分配成功则返回指向被分配
 内存的指针，否则返回Null。当内存不在使用时，需要free()函数释放 
 */
Status InitList_Sequence(SEQUENCELIST_Ptr spe_ptr)
{
	spe_ptr->element=(ElementType *)malloc(SEQUENCELIST_INIT_SIZE * sizeof(ElementType));
	if(!spe_ptr->element)
	{
		return Error;
	}
	spe_ptr->length=0;
	spe_ptr->listSize=SEQUENCELIST_INIT_SIZE;
	return OK;
}

/**
 *@Function: 插入元素，若表长为n，则时间复杂度O(n)  
 *@params  : L线性表, pos位置, e 元素 
 *@return  :
 *@note    : 在第pos（1<= pos <=n）个元素之前插入一个元素 ，需要将第n至第pos（共n-pos+1）个元素向后移动一个位置 
             要考虑以下情况：
			 1. 插入位置是否合法
			 2.存储空间是否足够，不够的话怎么处理 
 */
Status ListInsert_Sequence(SEQUENCELIST_Ptr L,int pos,ElementType e)
{
	int i;
	ElementType *newBase=NULL;
	
	if(pos<1 || pos > (L->length+1))
	{
		return Error;
	}
	if(L->length >= L->listSize)
	{
		newBase = (ElementType *)realloc(L->element,(L->listSize+SEQUENCELIST_INCREMENT) * sizeof(ElementType));
		if(!newBase)
		{
			return Error;
		}
		L->element = newBase;
		L->listSize += SEQUENCELIST_INCREMENT;	
	}
	
	for(i=L->length;i>pos-1;i--)
	{
		L->element[i]=L->element[i-1];	
	}
	L->element[pos-1]=e;
	
	++L->length;
	
	return OK;
}
//此算法基本同上面 
Status ListInsert_Sequence_2(SEQUENCELIST_Ptr L,int pos,ElementType e)
{
	int i;
	ElementType *p=NULL,*q=NULL; 
	
	if(pos<1 || pos > (L->length+1))
	{
		return Error;
	}

	p=&(L->element[pos-1]);
	
	for(q=&(L->element[L->length-1]);q>=p;q--)
	{
		*(q+1) = *q;
	}
	*p = e;
	
	++L->length;
	
	return OK;
} 

 /**
 *@Function:删除元素，若表长为n，则时间复杂度O(n) 
 *@params:
 *@return: 
 *@note:   一般情况下，删除第pos(1<=pos<=n)个元素时，需要将从第pos+1至第n（共i-1）个元素依次向前移动一个位置 
 *         假如线性表内只有1个元素，删除第一个位置的元素，怎么处理？ 
 */
Status ListDelete_Sequence(SEQUENCELIST_Ptr L,int pos)
{
	int i=0;
	
	if(pos < 1 || pos > L->length)
	{
		return Error;
	}
	
	for(i=pos-1;i<L->length-1;i++)
	{
		L->element[i]=L->element[i+1];
	}
	
	L->length--;
	
	return OK;
}
 /**
 *@Function: 返回L中第1个与e满足关系compare()的数据元素的位序，若这个元素不存在，则返回0 
 *@params  :
 *@return  : 
 *@note    : 初始条件：L已经存在，compare()是数据元素判定函数 
 */
 int LocateElement_Sequence(SEQUENCELIST_Ptr L,ElementType e)
 {
 	
 } 
 
 /**
 *@Function: 线性表测试
 *@note    :   
 */ 
void SequenceList_Test(void)
{
	SEQUENCELIST L;//SEQUENCELIST_Ptr 此处如果定义结构体指针的话，不妥，结构体指针需要初始化，结构体成员指针也要初始化 
	int i;	
	printf("----------------------------------------------------\n");
	if(InitList_Sequence(&L))
	{
		printf("InitListSequence address : %p\n",L.element);
		ListInsert_Sequence(&L,1,101);
		ListInsert_Sequence(&L,1,201);	
		ListInsert_Sequence(&L,1,301);
		ListInsert_Sequence(&L,1,401);
		ListInsert_Sequence(&L,1,501);	
		ListInsert_Sequence(&L,1,601);	
		ListInsert_Sequence(&L,1,701);
		ListInsert_Sequence(&L,1,801);	
		ListInsert_Sequence(&L,1,901);
		ListInsert_Sequence(&L,1,1001);
		ListInsert_Sequence(&L,1,2001);	
		ListInsert_Sequence(&L,1,3001);		
			
		ListInsert_Sequence_2(&L,1,4001);
		ListInsert_Sequence_2(&L,1,5001);	
		ListInsert_Sequence_2(&L,1,6001);
		ListInsert_Sequence_2(&L,1,7001);
		ListInsert_Sequence_2(&L,1,8001);	
		ListInsert_Sequence_2(&L,1,9001);
		ListInsert_Sequence_2(&L,1,1101);	
		ListInsert_Sequence_2(&L,1,2201);		

	}	
	printf("\tlength=%d\n",L.length);	
	printf("\tlistSize=%d\n",L.listSize);
	
	printf("------------------插入元素------------------\n");
	
	for(i=0;i<L.length	;i++){
		printf("element[%d] = %d, addr = %p\n",i,L.element[i],&(L.element[i]));	
	}	
	
	printf("------------------删除元素------------------\n");
	ListDelete_Sequence(&L,1);
	printf("\tlength=%d\n",L.length);
	
	for(i=0;i<L.length	;i++){
		printf("element[%d] = %d, addr = %p\n",i,L.element[i],&(L.element[i]));	
	}	
	
	printf("------------------删除元素------------------\n");
	ListDelete_Sequence(&L,5);
	printf("\tlength=%d\n",L.length);
	
	for(i=0;i<L.length	;i++){
		printf("element[%d] = %d, addr = %p\n",i,L.element[i],&(L.element[i]));	
	}
	printf("----------------------------------------------------\n");
}
 



