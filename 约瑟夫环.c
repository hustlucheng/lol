#include<stdio.h>
#include<stdlib.h>


typedef struct LNode
{
    int data;
    int num;
    struct LNode*next;
}LNode;


int main()
{
    struct LNode *pa,*p,*head;
    head=(struct LNode*)malloc(sizeof(LNode));
    pa=head;
    int i,m,n;
    printf("输入人数n和上限m\n");
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        pa->next=(struct LNode*)malloc(sizeof(LNode));
        pa=pa->next;
        printf("输入第%d个人的密码\n",i);
        scanf("%d",&pa->data);
        pa->num=i;
    }
    pa->next=head->next;
    pa=head->next;
    free(head);



    while(pa->next!=pa)
    {
        for(i=1;i<m;i++)
        {
            p=pa;
            pa=pa->next;
        }
        printf("%d->",pa->num);
        m=pa->data;
        p->next=pa->next;
        free(pa);
        pa=p->next;
    }
    printf("%d\n",pa->num);
    free(pa);
    return 0;
}
