#ifndef __ORDERLIST_H
#define __ORDERLIST_H

#define ORDERLIST_INIT_SIZE  10  //初始分配量 
#define ORDERLIST_INCREMENT  10   //分配增量 

typedef enum{
	Error=0,
	OK=1,
	Over=2,
	Busy=3
}RESULT;

typedef struct{
	int *element;    //存储空间的基地址 
	int length;      //线性表-当前长度 
	int listSize;    //当前分配的存储容量 
} ORDER_LIST,*ORDER_LIST_PTR;


extern int Init_OrderList(ORDER_LIST_PTR OrderListPtr);
extern int Insert_OrderList(ORDER_LIST_PTR OrderListPtr,int pos,int element);
extern bool Delete_OrderList(void);

extern void OrderList_Print2Test(void);

#endif





