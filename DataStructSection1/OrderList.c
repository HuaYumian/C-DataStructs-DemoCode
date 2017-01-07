#include "Includes.h"

/*******************************************************************************
 *@topic:  ���Ա��˳���ʾ��ʵ�� 
 *@date :  2016/12/07
 *@note :  ˳�������˼����һ�������洢�ռ䣬�����ڸ߼�������ǡ��������洢������
           ͨ������������ʾ���ݽṹ�е�˳��洢�ṹ��
           �ο����룺 
		   http://www.jianshu.com/p/347041b45be5 
 *@bugNote��
 --1--��ʼ���ڴ�֮�󣬷�����������ݲ�Ϊ0������ڳ�ʼ����ʱ��ͰѴ洢�ռ����
 --2-- 
*******************************************************************************/


/**
 *@Function: Creat a dynamic order list 
 *@params  :
 *@return  :
 *@note    : ��ʼ�����Ա� 
 *@note2   : malloc����ԭ�ͣ�void *malloc(unsigned int num_size); memory allocation��̬�ڴ���� 
 void* ��ʾδȷ�����͵�ָ�룬void*��ָ���κ��������͡��������ɹ��򷵻�ָ�򱻷���
 �ڴ��ָ�룬���򷵻�Null�����ڴ治��ʹ��ʱ����Ҫfree()�����ͷ� 
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
 *@Function: Insert an element to the order list,�� 
 *@params  : OrderList���Ա� elementԪ�أ� posλ�� 
 *@return  :
 *@note    : �����Ա�OrderList�е�pos��λ�ò�����Ԫ��element 
 *           <1>��ĳ��λ�ò���Ԫ�أ���ô��λ�ü�����Ԫ�ض���������1λ��������Ҫ�����һ��Ԫ�ؿ�ʼ�ƶ� 
 *           <2>Ԫ�ص�λ��ͨ��ָ�������Ĺ�ϵ��ȷ�� 
 */
int Insert_OrderList(ORDER_LIST_PTR OrderListPtr,int pos,int element)
{
	int *q=NULL;
	int *p=NULL;
	int i;
	
    if(pos < 1 || pos > OrderListPtr->listSize-1){//����λ�÷Ƿ� 
	 	return Over;
    }
    
    //�ڴ治������ô���� 
    
    for(i=OrderListPtr->length-1; i>=pos-1; i--){
    	OrderListPtr->element[i+1]=OrderListPtr->element[i];   
	}
	OrderListPtr->length++;
	OrderListPtr->element[pos-1] = element;
    
 	
 	return OK;	
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
 
 
 


void OrderList_Print2Test(void)
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
}
