void RRMove(ElemType A[],int k,int n)
{
	ElemType e;
	int i=0,j,p;
	while(i<n-k){
		p=i/k+1;
		for(j=0;j<k;j++){
			e=A[j];
			A[j]=A[(p*k+j)%n];
			A[(p*k+j)%n]=e;
			i++;
		}
	}
}
