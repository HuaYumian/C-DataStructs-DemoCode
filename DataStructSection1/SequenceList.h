#ifndef __SEQUENCELIST_H
#define __SEQUENCELIST_H


#define SEQUENCELIST_INIT_SIZE  10   //初始分配量 
#define SEQUENCELIST_INCREMENT  10    //分配增量 

 
//顺序表 抽象数据结构定义 
typedef struct SqeList{
	ElementType *element;    	   //存储空间的基地址 
	int length;      			   //线性表-当前长度 
	int listSize;                  //当前分配的存储空间大小 
} SEQUENCELIST,*SEQUENCELIST_Ptr;





extern Status InitList_Sequence(SEQUENCELIST_Ptr L);
extern Status ListInsert_Sequence(SEQUENCELIST_Ptr L,int pos,ElementType e);
extern Status ListInsert_Sequence_2(SEQUENCELIST_Ptr L,int pos,ElementType e); 

extern void SequenceList_Test(void);
#endif





