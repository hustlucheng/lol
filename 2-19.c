Status ListDelete_L(LinkList &L,ElemType mink,ElemType maxk)
{
	LinkList p,q,prev=NULL;
	if(mink>maxk)
        return ERROR;
	p=L;
	prev=p;
	p=p->next;
	while(p&&p->data<maxk){
		if(p->data<=mink){
			prev=p;
			p=p->next;
		}
		else{
			prev->next=p->next;
			q=p;
			p=p->next;
			free(q);
		}
	}
	return OK;
}// ±º‰∏¥‘”∂»O(n^2)
