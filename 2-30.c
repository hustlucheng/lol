Status ListUnion_L(LinkList &A,LinkList &B,LinkList &C)
{
	ListCross_L(B,C);
	ListMinus_L(A,B);
}

Status ListMinus_L(LinkList &A,LinkList &B)
{
	LinkList pa,pb,qa,qb,pt;
	pa=A;
	pb=B;
	qa=pa;
	qb=pb;
	pa=pa->next;
	pb=pb->next;
	while(pa&&pb){
		if(pb->data<pa->data){
			pt=pb;
			pb=pb->next;
			qb->next=pb;
			free(pt);
		}
		else
			if(pb->data>pa->data){
				qa=pa;
				pa=pa->next;
			}
			else{
				pt=pa;
				pa=pa->next;
				qa->next=pa;
				free(pt);
			}
	}
	while(pb){
		pt=pb;
		pb=pb->next;
		qb->next=pb;
		free(pt);
	}
	pb=B;
	free(pb);
}
