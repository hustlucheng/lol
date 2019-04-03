void InversePolandExpression(char Buffer[])
{
	Stack s;
	InitStack(s);
	int i=0,j=0;
	ElemType e;

	Push(s,Buffer[i]);
	i++;
	while(Buffer[i]!='#'){
		if(!IsOperator(Buffer[i])){
			Buffer[j]=Buffer[i];
			i++;
			j++;
		}
		else{
			GetTop(s,e);
			if(Prior(e,Buffer[i])){
				Pop(s,e);
				Buffer[j]=e;
				j++;
			}
			else{
				Push(s,Buffer[i]);
				i++;
			}
		}
	}
	while(!StackEmpty(s)){
		Pop(s,e);
		Buffer[j]=e;
		j++;
	}
}

Status IsOpertor(char c)
{
	char *p="#+-*/";
	while(*p){
		if(*p==c)
			return TRUE;
		p++;
	}
	return FALSE;
}

Status Prior(char c1,char c2)
{
	char ch[]="#+-*/";
	int i=0,j=0;
	while(ch[i] && ch[i]!=c1) i++;
	if(i==2) i--;
	if(i==4) i--;
	while(ch[j] && ch[j]!=c2) j++;
	if(j==2) j--;
	if(j==4) j--;
	if(i>=j) return TRUE;
	else return FALSE;
}
