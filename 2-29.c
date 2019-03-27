Status ListUnion_Sq(SqList &D,SqList &A,SqList &B,SqList &C)
{
	SqList Temp;
	InitList_Sq(Temp);
ListCross_L(B,C,Temp);
	ListMinus_L(A,Temp,D);
}
