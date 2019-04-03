int Match(ElemType e,ElemType ch)
{
	if(e == '('&&ch == ')')
	{
		return 1;
	}
	else if(e == '['&&ch == ']')
	{
		return 1;
	}
	else if(e == '{'&&ch == '}')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

£¡
