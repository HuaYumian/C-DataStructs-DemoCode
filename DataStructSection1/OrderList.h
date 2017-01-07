#ifndef __ORDERLIST_H
#define __ORDERLIST_H

#define ORDERLIST_INIT_SIZE  10  //��ʼ������ 
#define ORDERLIST_INCREMENT  10   //�������� 

typedef enum{
	Error=0,
	OK=1,
	Over=2,
	Busy=3
}RESULT;

typedef struct{
	int *element;    //�洢�ռ�Ļ���ַ 
	int length;      //���Ա�-��ǰ���� 
	int listSize;    //��ǰ����Ĵ洢���� 
} ORDER_LIST,*ORDER_LIST_PTR;


extern int Init_OrderList(ORDER_LIST_PTR OrderListPtr);
extern int Insert_OrderList(ORDER_LIST_PTR OrderListPtr,int pos,int element);
extern bool Delete_OrderList(void);

extern void OrderList_Print2Test(void);

#endif





