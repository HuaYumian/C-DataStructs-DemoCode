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
 *@Function: 删除L 
 *@params  :
 *@return  :
 *@note    : void free(void *ptr)用来释放动态分配的内存空间，比如malloc、realloc、calloc 
 *如果ptr所指的空间不是由上述那三个函数所分配的空间，会引发意想不到的错误
 *如果ptr为NULL，那么free不会用任何作用
 *需要注意点的是，free不会改变ptr的值，所以调用完free之后要把ptr置为NULL（不是必须） 
 *被释放的内存虽然可以被访问，但是已经不再安全了
 当free一块内存后，free(即运行库)会将这块内存标记为未使用，下次有可能会将这块内存分配出去。
 但这块内存对进程来说仍然是可以读写的，因为运行库已经向操作系统申请，自己来管理这块内存了。 
 */
 Status DestroyList_Sequence(SEQUENCELIST_Ptr L)
 {
 	if(L->element == NULL)
	{
		return Error;
	}
	//free(L);//此处要注意，malloc函数分配的是L->element
	free(L->element); 
	L->length = 0;
	L->listSize=0;
	L->element=NULL;

	return OK;

 } 
 /**
 *@Function: 清空链表L，即将L重置为空表  
 *@params  :  
 *@return  :
 *@note    : 置为空表，空表的概念就是长度为0的表,至于表内元素，根据实际情况来选择是否清0，或者FF 
 */
 Status ClearList_Sequence(SEQUENCELIST_Ptr L)
 {
 	int i=0;
 	if(!L->element)
	{
		return Error;	
	}
	/*for(i=0;i< L->length;i++)
	{
		L->element[i]=0；		
	}*/
	L->length = 0;
	
	return OK;
	
 }
  /**
 *@Function: 判断表是否为空表，如果为空表则返回true，否则返回false 
 *@params  :  
 *@return  :
 *@note    : 其实应该有个初始化条件：链表L已经存在 
 */
 bool ListEmpty_Sequence(SEQUENCELIST_Ptr L)
 {
 	//这个函数是我我的第一思路，显然，是不准确的。何为空表？ 
 /*	if(!L->element)//如果把这个条件认为是空表的条件的话，显然一个已经被分配过内存的L，它的L->element!=NULL,但是它有可能是是空表，因为长度为0 
	{              //还有一种情况是：如果一个未被分配存储空间的L，那么它的L->element=NULL，这根本不是 
		return true;	
	}
	else
		return false;
	return false;*/
	
	//另一思路就是直接判断L的长度是否为0
	if(L->element)//先判断表是否存在 
	{
		if(L->length==0)
		{
			return true;
		}
		else{
			return false;
		}
	} 
	return false;
 } 
 
 /**
 *@Function: 返回链表中数据的长度 
 *@params  :  
 *@return  :
 *@note    : 
 */
 int ListLength_Sequence(SEQUENCELIST_Ptr L)
 {
	return	L->length; 
 } 
 
/**
 *@Function: 返回链表中数据的长度 
 *@params  :  
 *@return  :  pos位置的元素 
 *@note    :  第pos个位置的元素 
 */ 
ElementType GetElem_Sequence(SEQUENCELIST_Ptr L,int pos)
{
	if(L->length < 1 || pos > L->length)
	{
		return Error;	
	}	
	return L->element[pos-1];
} 

 /**
 *@Function: 返回L中第1个与e相等的数据元素的位序，若这个元素不存在，则返回0 
 *@params  :
 *@return  : 
 *@note    : 初始条件：L已经存在，compare()是数据元素判定函数 
 */
 int LocateElement_Sequence(SEQUENCELIST_Ptr L,ElementType e)
 {
 	int i=0;
 	
 	for(i=0;i<L->length;i++)
 	{
 		if(L->element[i]==e)
	    {
 			return i+1;
 		}	
 	} 
 	return 0;
 } 

 /**
 *@Function: 返回元素e的直接前驱 
 *@params  :  
 *@return  :
 *@note    : e是L的数据元素，且不是第一个，则用ptr返回它的前驱，否则操作失败ptr无定义 
 */
 ElementType* PriorElem_Sequence(SEQUENCELIST_Ptr L,ElementType e)
 {
 	ElementType *ptr=NULL;
 	int tmp=0;
 	tmp=LocateElement_Sequence(L,e);
 	if(tmp <= 1)
 	{
	 	ptr=NULL;
	 	return Error;
 	}
 	ptr=&(L->element[tmp-2]);
 	return ptr;
 	
 } 
  /**
 *@Function: 返回元素e的直接后继 
 *@params  :  
 *@return  :
 *@note    : e是L的数据元素，且不是最后一个，则用ptr返回它的前驱，否则操作失败ptr无定义 
 */
 ElementType* NextElem_Sequence(SEQUENCELIST_Ptr L,ElementType e)
 {
 	ElementType *ptr=NULL;
 	int tmp=0;
 	tmp=LocateElement_Sequence(L,e);
 	if(tmp == L->length)
 	{
	 	ptr=NULL;
	 	return Error;
 	}
 	ptr=&(L->element[tmp]);
 	return ptr;
 	
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
	
	if(pos<1 || pos > (L->length+1) || !L->element)
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
 *@Function: 线性表测试
 *@note    :   
 */ 
void SequenceList_Test(void)
{
	ElementType *ptr=NULL;
	SEQUENCELIST L,L1;//SEQUENCELIST_Ptr 此处如果定义结构体指针的话，不妥，结构体指针需要初始化，结构体成员指针也要初始化 
	int i,a,b;	
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
		
		
		a=LocateElement_Sequence(&L,2201);
		b=LocateElement_Sequence(&L,9010);	

	}	
	
	printf("//--遍历操作--\n");
	for(i=0;i<L.length	;i++){
		printf("element[%d] = %d, addr = %p\n",i,L.element[i],&(L.element[i]));	
	}
	printf("----------------------------------------------------\n");
	printf("//--查找与e相等的位序--\n");
	printf("a = %d\n",a);	
	printf("b = %d\n",b);
	printf("----------------------------------------------------\n");
	/*printf("//--删除L--\n");
	if(DestroyList_Sequence(&L))
	{
		printf("删除链表成功！！！\n");	
	}
	if(!ListInsert_Sequence(&L,1,2345))
	{
		printf("表不存在！！！\n");
		printf("表不存在 = %d！！！\n",L.length);
	}
	printf("InitListSequence address : %p\n",L.element);
	for(i=0;i<L.length	;i++){
		printf("element[%d] = %d, addr = %p\n",i,L.element[i],&(L.element[i]));	
	}*/
	printf("----------------------------------------------------\n");	
	if(ListEmpty_Sequence(&L1)==false)
	{
		printf("L1 不存在！！！\n");	
	}
	if(ListEmpty_Sequence(&L)==false)
	{
		printf("L 不为空！！！\n");	
	}	
	printf("----------------------------------------------------\n");
	
	ptr=PriorElem_Sequence(&L,501);	
	printf("prior_ptr_addr = %p\n",ptr);
	
	printf("----------------------------------------------------\n");
	
	ptr=NextElem_Sequence(&L,501);
	printf("next_ptr_addr = %p\n",ptr);	
	
}
 



