#ifndef __LINKLIST_H
#define __LINKLIST_H



typedef struct LNode{
	ElementType data;
	struct LNode *ptr;
}LNODE,*LINKLIST;


extern LINKLIST LinkList_Creat(void);
extern LINKLIST LinkList_Insert(LINKLIST linklist,int pos,ElementType data);
extern bool LinkList_Delete(LINKLIST linklist,int pos);
extern void printAllDatas(LINKLIST linklist);
extern ElementType LinkList_Query(LINKLIST linklist,int pos);
extern void  LinkList_Print2Test(void); 



#endif





