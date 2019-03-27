p= head;
q=NULL;
head=NULL;
 
    while(p) {
    q = p->next;
    p->next = head;
    head = p;
    p = q;
}
