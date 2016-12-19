#ifndef __ORDERLIST_H
#define __ORDERLIST_H

#define ORDERLIST_INIT_SIZE  100  //��ʼ������ 
#define ORDERLIST_INCREMENT  10   //�������� 



typedef struct{
	int *element;    //�洢�ռ�Ļ���ַ 
	int length;      //���Ա�-��ǰ���� 
	int listSize;    //��ǰ����Ĵ洢���� 
} ORDER_LIST;


extern int Init_OrderList(ORDER_LIST OrderList);
extern int Insert_OrderList(ORDER_LIST OrderList,int element,int pos);
extern bool Delete_OrderList(void);



#endif





