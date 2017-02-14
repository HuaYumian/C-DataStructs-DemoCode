#include "Includes.h" 



/**
 *@Function: ������Ľ���(����ͷ���)
 *@params  : 
 *@return  :
 *@note    : 
 */
LINKLIST LinkList_Creat(void)
{
	LNODE *headPtr;  //ͷָ�� 
	LNODE *headNode; //ͷ��� 
	
	headPtr=headNode=(LINKLIST)malloc(sizeof(LNODE));
	if(headPtr == NULL || headNode == NULL){
		printf("����������ʧ�ܣ�����\n");
		return;
	}
	
	headNode->ptr=NULL;
	headNode->data=0; 
	
	//printf("headPtr = %p\n",headPtr);
	printf("headNode = %p\n",headNode);
	//printf("headNode->ptr = %p\n",headNode->ptr);
	printf("headNode->data = %d\n",headNode->data);
	
	return headNode;
	
}
/**
 *@Function: �������Ԫ��--���� 
 *@params  : 
 *@return  :
 *@note    : �ڵ�pos��λ�ò���Ԫ�أ�������Ҫ���pos��ֱ��ǰ��;
 *           Ԫ�صĲ����Ϊ��β��ֱ�Ӳ��룬���м���� 
 */
LINKLIST LinkList_Insert(LINKLIST linklist,int pos,ElementType data)
{
	LNODE *temPtr;
	LNODE *s;
	int i=0;
	temPtr = linklist;
	
	if(pos > (temPtr->data) + 1){ 											    //����λ�÷Ƿ�
		printf("����λ�÷Ƿ�������\n"); 
		return;
	}
	
	for(i=0;i<pos-1;i++){                                                       //��ȡ��pos��λ�õ�ֱ��ǰ����� 
		temPtr=temPtr->ptr;
	} 
	//printf("temPtr=%p\n",temPtr);
	if(pos == (linklist->data + 1)){                                            //�����һ�������ߵ�һ���������ݣ�ʵ���൱��β��ֱ�Ӳ���Ԫ�� 
		s=(LINKLIST)malloc(sizeof(LNODE));
		temPtr->ptr=s;
		s->data = data;
		linklist->data++;                                                       //����+1��������Ϣ������ͷ���������� 
		s->ptr=NULL;                                                            //û��ֱ�Ӻ�̣��������һ���ڵ��ָ����Ϊ�� 
		printf("if-malloc_addr=%p\n",s);
	} 
	else{                                                                       //˵����ֱ�Ӻ��Ԫ�� 
		s=(LINKLIST)malloc(sizeof(LNODE));
		s->ptr=temPtr->ptr;
		temPtr->ptr=s;
		s->data=data;
		linklist->data++;                                                       //����+1��������Ϣ������ͷ����������  
		printf("el-malloc_addr=%p\n",s);
	}
	return linklist;	
}

/**
 *@Function: �������Ԫ��--ɾ�� 
 *@params  : 
 *@return  :
 *@note    : �ڵ�pos��λ��ɾ��Ԫ�أ�������Ҫ���pos��ֱ��ǰ��;
 *           Ԫ�ص�ɾ����Ϊ��β��ֱ��ɾ�������м�ɾ�� 
 */
bool LinkList_Delete(LINKLIST linklist,int pos)
{
	LNODE *tmp; 
	LNODE *tmp1=NULL;
	int i;
	tmp=linklist;
	
	if(pos > linklist->data){
		printf("�Ƿ�ɾ��������\n");
		return;
	}
	for(i=0;i<pos-1;i++){                                                       //��ȡ��pos��λ�õ�ֱ��ǰ����� 
		tmp=tmp->ptr;
	} 
	if(pos == linklist->data){      //pos==�����ȣ�ͷ���������򱣴��˳�����Ϣ                                  
		free(tmp->ptr);
		tmp->ptr=NULL;
		linklist->data--;
	}
	else{
		tmp1=tmp->ptr;
		tmp->ptr=tmp1->ptr;
		linklist->data--;
		free(tmp1);
	}
	return true;
}


/**
 *@Function: �������Ԫ��--��ѯ 
 *@params  : 
 *@return  :
 *@note    : 
 *           
 */
ElementType LinkList_Query(LINKLIST linklist,int pos)
{
	LNODE *tmp;
	int i;
	tmp=linklist->ptr;
	
	if(pos > linklist->data){
		printf("�Ƿ���ѯ������\n"); 
		return;
	}
	
	for(i=1;i<pos;i++){
		tmp=tmp->ptr;	
	}
	printf("--query-data=%d\n",tmp->data);
	printf("--data-addre=%p\n\n",tmp);
	return tmp->data;
	
	 
} 

/**
 *@Function: �ϲ�2������ 
 *@params  : mergeModel�ϲ�ģʽ��true����false���� 
 *@return  :
 *@note    : ���ȴ���һ���ձ��ٶ�2��Ҫ���бȽϵ������Ԫ�ؽ��д�С�жϣ������½��Ŀձ� 
 */
void LinkList_Merge(LINKLIST list1,LINKLIST list2,bool mergeModel)
{
	LINKLIST newLinkList=NULL;
	LNODE *tmp1;
	LNODE *tmp2;
	
	
	newLinkList=LinkList_Creat(); 
	
		
}
 
/**
 *@Function: �����������Ԫ�� 
 *@params  : 
 *@return  :
 *@note    : 
 */
void printAllDatas(LINKLIST linklist)
{
	int i=0;
	LNODE *tmep;
	tmep=linklist->ptr;
	printf("/*--------------------------*/\n");
	for(i=0;i<linklist->data;i++){
		
		printf("data[%d]=%d\n",i,tmep->data);
		printf("addr[%d]=%p\n",i,tmep);
		tmep=tmep->ptr;
		printf("/*--------------------------*/\n");
	}
	printf("length=%d\n",linklist->data);	
}

/**
 *@Function: �㷨���� 
 *@params  : 
 *@return  :
 *@note    : 
 */
void LinkList_Print2Test(void)
{
	int i;
	LINKLIST linklist;
	linklist=LinkList_Creat(); 
	LinkList_Insert(linklist,1,23);
	LinkList_Insert(linklist,2,25);
	LinkList_Insert(linklist,3,27);
	LinkList_Insert(linklist,2,229);
		LinkList_Insert(linklist,1,213);
		LinkList_Insert(linklist,2,215);
		LinkList_Insert(linklist,3,217);
		LinkList_Insert(linklist,2,219);
	
	for(i=1;i<linklist->data+1;i++){
		LinkList_Query(linklist,i);
	}	
	LinkList_Delete(linklist,8);
	LinkList_Delete(linklist,9);
	LinkList_Delete(linklist,1);
	
	LinkList_Insert(linklist,2,2119);
	LinkList_Insert(linklist,5,2134);
	
	printAllDatas(linklist);
}




