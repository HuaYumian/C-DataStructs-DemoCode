#include "Includes.h"

/*******************************************************************************
 *@topic:  ���Ա��˳���ʾ��ʵ�� 
 *@date :  2016/12/07
 *@note :  ˳�������˼����һ�������洢�ռ䣬�����ڸ߼�������ǡ��������洢������
           ͨ������������ʾ���ݽṹ�е�˳��洢�ṹ�� 
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
 *@note    : ��ʼ�����Ա� 
 *@note2   : malloc����ԭ�ͣ�void *malloc(unsigned int num_size); memory allocation��̬�ڴ���� 
 void* ��ʾδȷ�����͵�ָ�룬void*��ָ���κ��������͡��������ɹ��򷵻�ָ�򱻷���
 �ڴ��ָ�룬���򷵻�Null�����ڴ治��ʹ��ʱ����Ҫfree()�����ͷ� 
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
 *@Function: Insert an element to the order list,�� 
 *@params  : OrderList���Ա� elementԪ�أ� posλ�� 
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
 *@Function:Delete an element from the order list,ɾ 
 *@params:
 *@return:
 *@note:
 */
 bool Delete_OrderList(void)
 {
	
	return false;
	
 }
 
 
 



