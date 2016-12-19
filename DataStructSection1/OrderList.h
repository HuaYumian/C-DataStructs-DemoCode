#ifndef __ORDERLIST_H
#define __ORDERLIST_H

#define ORDERLIST_INIT_SIZE  100  //初始分配量 
#define ORDERLIST_INCREMENT  10   //分配增量 



typedef struct{
	int *element;    //存储空间的基地址 
	int length;      //线性表-当前长度 
	int listSize;    //当前分配的存储容量 
} ORDER_LIST;


extern int Init_OrderList(ORDER_LIST OrderList);
extern int Insert_OrderList(ORDER_LIST OrderList,int element,int pos);
extern bool Delete_OrderList(void);



#endif





