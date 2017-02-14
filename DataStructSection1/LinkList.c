#include "Includes.h" 



/**
 *@Function: 单链表的建立(包含头结点)
 *@params  : 
 *@return  :
 *@note    : 
 */
LINKLIST LinkList_Creat(void)
{
	LNODE *headPtr;  //头指针 
	LNODE *headNode; //头结点 
	
	headPtr=headNode=(LINKLIST)malloc(sizeof(LNODE));
	if(headPtr == NULL || headNode == NULL){
		printf("创建单链表失败！！！\n");
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
 *@Function: 单链表的元素--插入 
 *@params  : 
 *@return  :
 *@note    : 在第pos个位置插入元素，首先需要求出pos的直接前驱;
 *           元素的插入分为在尾部直接插入，在中间插入 
 */
LINKLIST LinkList_Insert(LINKLIST linklist,int pos,ElementType data)
{
	LNODE *temPtr;
	LNODE *s;
	int i=0;
	temPtr = linklist;
	
	if(pos > (temPtr->data) + 1){ 											    //插入位置非法
		printf("插入位置非法！！！\n"); 
		return;
	}
	
	for(i=0;i<pos-1;i++){                                                       //获取第pos个位置的直接前驱结点 
		temPtr=temPtr->ptr;
	} 
	//printf("temPtr=%p\n",temPtr);
	if(pos == (linklist->data + 1)){                                            //在最后一个结点或者第一结点插入数据，实际相当于尾部直接插入元素 
		s=(LINKLIST)malloc(sizeof(LNODE));
		temPtr->ptr=s;
		s->data = data;
		linklist->data++;                                                       //长度+1，长度信息保存在头结点的数据域 
		s->ptr=NULL;                                                            //没有直接后继，所以最后一个节点的指针域为空 
		printf("if-malloc_addr=%p\n",s);
	} 
	else{                                                                       //说明有直接后继元素 
		s=(LINKLIST)malloc(sizeof(LNODE));
		s->ptr=temPtr->ptr;
		temPtr->ptr=s;
		s->data=data;
		linklist->data++;                                                       //长度+1，长度信息保存在头结点的数据域  
		printf("el-malloc_addr=%p\n",s);
	}
	return linklist;	
}

/**
 *@Function: 单链表的元素--删除 
 *@params  : 
 *@return  :
 *@note    : 在第pos个位置删除元素，首先需要求出pos的直接前驱;
 *           元素的删除分为在尾部直接删除，在中间删除 
 */
bool LinkList_Delete(LINKLIST linklist,int pos)
{
	LNODE *tmp; 
	LNODE *tmp1=NULL;
	int i;
	tmp=linklist;
	
	if(pos > linklist->data){
		printf("非法删除！！！\n");
		return;
	}
	for(i=0;i<pos-1;i++){                                                       //获取第pos个位置的直接前驱结点 
		tmp=tmp->ptr;
	} 
	if(pos == linklist->data){      //pos==链表长度，头结点的数据域保存了长度信息                                  
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
 *@Function: 单链表的元素--查询 
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
		printf("非法查询！！！\n"); 
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
 *@Function: 合并2个链表 
 *@params  : mergeModel合并模式，true升序；false降序 
 *@return  :
 *@note    : 首先创建一个空表，再对2个要进行比较的链表的元素进行大小判断，存入新建的空表 
 */
void LinkList_Merge(LINKLIST list1,LINKLIST list2,bool mergeModel)
{
	LINKLIST newLinkList=NULL;
	LNODE *tmp1;
	LNODE *tmp2;
	
	
	newLinkList=LinkList_Creat(); 
	
		
}
 
/**
 *@Function: 遍历输出链表元素 
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
 *@Function: 算法测试 
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




