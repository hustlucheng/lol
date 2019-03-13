void Delete( int  i, List *PtrL ) {
    int  j;

    if( i < 1 || i > PtrL->Last+1 )
    {
        printf ("不存在第%d个元素", i );
        return ;
    }

    for ( j = i; j <= PtrL->Last; j++ )
        PtrL->Data[j-1] = PtrL->Data[j];
 
    PtrL->Last--;
 
    return;
}
