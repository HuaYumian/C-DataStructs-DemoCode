#include "Includes.h"

/*******************************************************************************
 *@topic:  线性表的顺序表示和实现 
 *@date :  2016/12/07
 *@note :  顺序表：顾名思义是一段连续存储空间，数组在高级语言中恰好有随机存储的特性
           通常用数组来表示数据结构中的顺序存储结构。 
*******************************************************************************/
typedef enum{
	Error=0,
	OK=1,
	Over=2,
	Busy=3
}RESULT;

/**
 *@Function: Creat a dynamic order list 
 *@params  :
 *@return  :
 *@note    : 初始化线性表 
 *@note2   : malloc函数原型：void *malloc(unsigned int num_size); memory allocation动态内存分配 
 void* 表示未确定类型的指针，void*可指向任何数据类型。如果分配成功则返回指向被分配
 内存的指针，否则返回Null。当内存不在使用时，需要free()函数释放 
 */
int Init_OrderList(ORDER_LIST_PTR OrderListPtr)
{
	OrderListPtr->element = (int *)malloc(ORDERLIST_INIT_SIZE*sizeof(int));
	if(!OrderListPtr->element) return Error;
	OrderListPtr->length = 0;
	OrderListPtr->listSize = ORDERLIST_INIT_SIZE;
//	printf("--length=%d\n",OrderListPtr->length);
	return OK;	
}

/**
 *@Function: Insert an element to the order list,增 
 *@params  : OrderList线性表， element元素， pos位置 
 *@return  :
 *@note    : 在线性表OrderList中第pos个位置插入新元素element 
 */
int Insert_OrderList(ORDER_LIST_PTR OrderListPtr,int pos,int element)
{
	int *q=NULL;
	int *p=NULL;
	int i;
	
    if(pos < 1 || pos > OrderListPtr->listSize){//插入位置非法 
	 	return Over;
    }
    
    for(i=OrderListPtr->length-1; i>=pos-1; i--){
    	OrderListPtr->element[i+1]=OrderListPtr->element[i];   
	}
	OrderListPtr->length++;
	OrderListPtr->element[pos-1] = element;
    
 	
 	return OK;	
} 
 
 /**
 *@Function:Delete an element from the order list,删 
 *@params:
 *@return:
 *@note:
 */
 bool Delete_OrderList(void)
 {
	
	return false;
	
 }
 
 
 



