typedef int ElemType;
typedef struct NodeType{
	ElemType data;
	NodeType *next;
}QNode,*QPtr;
typedef struct{
	QPtr rear;
	int size;
}Queue;
Status InitQueue(Queue& q)
{
	q.rear=NULL;
	q.size=0;
	return OK;
}
Status EnQueue(Queue& q,ElemType e)
{
	QPtr p;
	p=new QNode;
	if(!p) return FALSE;
	p->data=e;
	if(!q.rear){
		q.rear=p;
		p->next=q.rear;
	}
	else{
		p->next=q.rear->next;
		q.rear->next=p;
		q.rear=p;
	}
	q.size++;
	return OK;
}
Status DeQueue(Queue& q,ElemType& e)
{
	QPtr p;
	if(q.size==0)return FALSE;
	if(q.size==1){
		p=q.rear;
		e=p->data;
		q.rear=NULL;
		delete p;
	}
	else{
		p=q.rear->next;
		e=p->data;
		q.rear->next=p->next;
		delete p;
	}
	q.size--;
	return OK;
}
