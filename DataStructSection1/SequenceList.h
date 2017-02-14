#ifndef __SEQUENCELIST_H
#define __SEQUENCELIST_H


#define SEQUENCELIST_INIT_SIZE  10   //��ʼ������ 
#define SEQUENCELIST_INCREMENT  10    //�������� 

 
//˳��� �������ݽṹ���� 
typedef struct SqeList{
	ElementType *element;    	   //�洢�ռ�Ļ���ַ 
	int length;      			   //���Ա�-��ǰ���� 
	int listSize;                  //��ǰ����Ĵ洢�ռ��С 
} SEQUENCELIST,*SEQUENCELIST_Ptr;





extern Status InitList_Sequence(SEQUENCELIST_Ptr L);
extern Status ListInsert_Sequence(SEQUENCELIST_Ptr L,int pos,ElementType e);
extern Status ListInsert_Sequence_2(SEQUENCELIST_Ptr L,int pos,ElementType e); 

extern void SequenceList_Test(void);
#endif





