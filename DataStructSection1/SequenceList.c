#include "Includes.h"

/*******************************************************************************
 *@topic:  ���Ա���˳���ʾ��ʵ�� 
 *@date :  2016/12/07
 *@note :  ˳���������˼����һ�������洢�ռ䣬�����ڸ߼�������ǡ��������洢������
           ͨ������������ʾ���ݽṹ�е�˳��洢�ṹ��
           �ο����룺 
		   http://www.jianshu.com/p/347041b45be5 
 *@bugNote��
 --1--��ʼ���ڴ�֮�󣬷�����������ݲ�Ϊ0������ڳ�ʼ����ʱ��ͰѴ洢�ռ����
 --2-- 
*******************************************************************************/



/**
 *@Function: ����һ���յ����Ա� 
 *@params  :
 *@return  :
 *@note    : ��ʼ�����Ա� 
 *@note2   : malloc����ԭ�ͣ�void *malloc(unsigned int num_size); memory allocation��̬�ڴ���� 
 void* ��ʾδȷ�����͵�ָ�룬void*��ָ���κ��������͡��������ɹ��򷵻�ָ�򱻷���
 �ڴ��ָ�룬���򷵻�Null�����ڴ治��ʹ��ʱ����Ҫfree()�����ͷ� 
 */
Status InitList_Sequence(SEQUENCELIST_Ptr spe_ptr)
{
	spe_ptr->element=(ElementType *)malloc(SEQUENCELIST_INIT_SIZE * sizeof(ElementType));
	if(!spe_ptr->element)
	{
		return Error;
	}
	spe_ptr->length=0;
	spe_ptr->listSize=SEQUENCELIST_INIT_SIZE;
	return OK;
}

/**
 *@Function: ����Ԫ�أ�������Ϊn����ʱ�临�Ӷ�O(n)  
 *@params  : L���Ա�, posλ��, e Ԫ�� 
 *@return  :
 *@note    : �ڵ�pos��1<= pos <=n����Ԫ��֮ǰ����һ��Ԫ�� ����Ҫ����n����pos����n-pos+1����Ԫ������ƶ�һ��λ�� 
             Ҫ�������������
			 1. ����λ���Ƿ�Ϸ�
			 2.�洢�ռ��Ƿ��㹻�������Ļ���ô���� 
 */
Status ListInsert_Sequence(SEQUENCELIST_Ptr L,int pos,ElementType e)
{
	int i;
	ElementType *newBase=NULL;
	
	if(pos<1 || pos > (L->length+1))
	{
		return Error;
	}
	if(L->length >= L->listSize)
	{
		newBase = (ElementType *)realloc(L->element,(L->listSize+SEQUENCELIST_INCREMENT) * sizeof(ElementType));
		if(!newBase)
		{
			return Error;
		}
		L->element = newBase;
		L->listSize += SEQUENCELIST_INCREMENT;	
	}
	
	for(i=L->length;i>pos-1;i--)
	{
		L->element[i]=L->element[i-1];	
	}
	L->element[pos-1]=e;
	
	++L->length;
	
	return OK;
}
//���㷨����ͬ���� 
Status ListInsert_Sequence_2(SEQUENCELIST_Ptr L,int pos,ElementType e)
{
	int i;
	ElementType *p=NULL,*q=NULL; 
	
	if(pos<1 || pos > (L->length+1))
	{
		return Error;
	}

	p=&(L->element[pos-1]);
	
	for(q=&(L->element[L->length-1]);q>=p;q--)
	{
		*(q+1) = *q;
	}
	*p = e;
	
	++L->length;
	
	return OK;
} 

 /**
 *@Function:ɾ��Ԫ�أ�������Ϊn����ʱ�临�Ӷ�O(n) 
 *@params:
 *@return: 
 *@note:   һ������£�ɾ����pos(1<=pos<=n)��Ԫ��ʱ����Ҫ���ӵ�pos+1����n����i-1����Ԫ��������ǰ�ƶ�һ��λ�� 
 *         �������Ա���ֻ��1��Ԫ�أ�ɾ����һ��λ�õ�Ԫ�أ���ô������ 
 */
Status ListDelete_Sequence(SEQUENCELIST_Ptr L,int pos)
{
	int i=0;
	
	if(pos < 1 || pos > L->length)
	{
		return Error;
	}
	
	for(i=pos-1;i<L->length-1;i++)
	{
		L->element[i]=L->element[i+1];
	}
	
	L->length--;
	
	return OK;
}
 /**
 *@Function: ����L�е�1����e�����ϵcompare()������Ԫ�ص�λ�������Ԫ�ز����ڣ��򷵻�0 
 *@params  :
 *@return  : 
 *@note    : ��ʼ������L�Ѿ����ڣ�compare()������Ԫ���ж����� 
 */
 int LocateElement_Sequence(SEQUENCELIST_Ptr L,ElementType e)
 {
 	
 } 
 
 /**
 *@Function: ���Ա�����
 *@note    :   
 */ 
void SequenceList_Test(void)
{
	SEQUENCELIST L;//SEQUENCELIST_Ptr �˴��������ṹ��ָ��Ļ������ף��ṹ��ָ����Ҫ��ʼ�����ṹ���Աָ��ҲҪ��ʼ�� 
	int i;	
	printf("----------------------------------------------------\n");
	if(InitList_Sequence(&L))
	{
		printf("InitListSequence address : %p\n",L.element);
		ListInsert_Sequence(&L,1,101);
		ListInsert_Sequence(&L,1,201);	
		ListInsert_Sequence(&L,1,301);
		ListInsert_Sequence(&L,1,401);
		ListInsert_Sequence(&L,1,501);	
		ListInsert_Sequence(&L,1,601);	
		ListInsert_Sequence(&L,1,701);
		ListInsert_Sequence(&L,1,801);	
		ListInsert_Sequence(&L,1,901);
		ListInsert_Sequence(&L,1,1001);
		ListInsert_Sequence(&L,1,2001);	
		ListInsert_Sequence(&L,1,3001);		
			
		ListInsert_Sequence_2(&L,1,4001);
		ListInsert_Sequence_2(&L,1,5001);	
		ListInsert_Sequence_2(&L,1,6001);
		ListInsert_Sequence_2(&L,1,7001);
		ListInsert_Sequence_2(&L,1,8001);	
		ListInsert_Sequence_2(&L,1,9001);
		ListInsert_Sequence_2(&L,1,1101);	
		ListInsert_Sequence_2(&L,1,2201);		

	}	
	printf("\tlength=%d\n",L.length);	
	printf("\tlistSize=%d\n",L.listSize);
	
	printf("------------------����Ԫ��------------------\n");
	
	for(i=0;i<L.length	;i++){
		printf("element[%d] = %d, addr = %p\n",i,L.element[i],&(L.element[i]));	
	}	
	
	printf("------------------ɾ��Ԫ��------------------\n");
	ListDelete_Sequence(&L,1);
	printf("\tlength=%d\n",L.length);
	
	for(i=0;i<L.length	;i++){
		printf("element[%d] = %d, addr = %p\n",i,L.element[i],&(L.element[i]));	
	}	
	
	printf("------------------ɾ��Ԫ��------------------\n");
	ListDelete_Sequence(&L,5);
	printf("\tlength=%d\n",L.length);
	
	for(i=0;i<L.length	;i++){
		printf("element[%d] = %d, addr = %p\n",i,L.element[i],&(L.element[i]));	
	}
	printf("----------------------------------------------------\n");
}
 


