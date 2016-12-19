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
int Init_OrderList(ORDER_LIST OrderList)
{
	OrderList.element = (int *)malloc(ORDERLIST_INIT_SIZE*sizeof(int));
	if(!OrderList.element) return Error;
	OrderList.length = 0;
	OrderList.listSize = ORDERLIST_INIT_SIZE;
	return OK;	
}

/**
 *@Function: Insert an element to the order list,增 
 *@params  : OrderList线性表， element元素， pos位置 
 *@return  :
 *@note    :
 */
int Insert_OrderList(ORDER_LIST OrderList,int element,int pos)
{
	int *q=NULL;
	int *p=NULL;
	
    if(pos < 1 || pos > OrderList.length+1){
	 	return Over;
    }
    
    
 	
 	return false;	
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
 
 
 



