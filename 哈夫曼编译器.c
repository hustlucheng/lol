 #include <stdio.h>

#include <stdlib.h>

#include <string.h>



typedef struct{

        int weight;

   	char ch;

        int parent,lchild,rchild;

}HTNode,*HuffmanTree;





typedef char **HuffmanCode; //�洢����������



HuffmanTree HT;

int n=0;

HuffmanCode HC;

int *w;

char *ch;



void welcome();    //����ѡ�����

void select(HuffmanTree HT,int j,int s1,int s2); //ѡ��parentΪ0��weight��С���������

void Init(); //�����ַ�����Ȩֵ��������������

void Encoding(); //����

void Decoding(); //����

void Tree_printing(); //��ӡ��������

void Print();//��ӡ����

void HuffmanCoding(HuffmanTree HT,HuffmanCode HC,int *w,int n,char *ch);

void Free();//�ͷŶ�̬����ռ�



void welcome()

{

	printf("--------��ӭ����ϵͳ---------\n");


	printf("*            I.��ʼ��                *\n");

	printf("*            E.����                  *\n");

	printf("*            D.����                  *\n");

	printf("*            P.ӡ�����ļ�            *\n");

	printf("*            T.��ӡ��������          *\n");

	printf("*            Q.�˳�                  *\n");

	printf("**************************************\n");

}





void Init()

{

	FILE *fp;

	int i;

	printf("�������ַ�����:\n");

	scanf("%d",&n);

	while(n<2){

		printf("�����������������������:\n");

		scanf("%d",&n);

	}

	ch=(char *)malloc(n*sizeof(char));

	printf("�����������ַ�:\n");

	getchar();

	for(i=0;i<n;++i)

		scanf("%c",&ch[i]);

	w=(int *)malloc(n*sizeof(int));

	printf("��������Щ�ַ���Ȩֵ:\n");

	for(i=0;i<n;++i)

		scanf("%d",&w[i]);

	HuffmanCoding(HT,HC,w,n,ch);

	/*printf("����������:\n");

	for(i=1;i<=n;++i)

		printf("%c:%s\n",HT[i].ch,HC[i]);*///����

	fp=fopen("hfmTree.txt","w");

	fprintf(fp,"%d",n);

	for(i=0;i<n;++i)

		fprintf(fp,"%c",ch[i]);

	for(i=0;i<n;++i)

		fprintf(fp,"%5d",w[i]);

	for(i=1;i<=n;++i)

		fprintf(fp,"\n%c:%s",HT[i].ch,HC[i]);

	fclose(fp);

	printf("��ʼ���ɹ�\n");

}



void select(HuffmanTree HT,int j,int s1,int s2)

{

	int i;

	for(i=1;i<=j;i++)

		if(HT[i].parent==0){s1=i;break;}

	for (;i<=j;i++)

   		if ((HT[i].parent==0)&&(HT[i].weight<HT[s1].weight))

    		s1=i;

  	HT[s1].parent=1;

	for(i=1;i<=j;i++)

   		if(HT[i].parent==0){s2=i;break;}

	for(;i<=j;i++)

   		if((HT[i].parent==0)&&(i!=s1)&&(HT[i].weight<HT[s2].weight))

    		s2=i;

}





void HuffmanCoding(HuffmanTree HT,HuffmanCode HC,int *w,int n,char *ch)

{

	int m;

	m=2*n-1;

	int j,s1,s2,k;

	HT=(HTNode *)malloc((m+1)*sizeof(HTNode));

	HTNode *p;

	int i;

	for(p=HT+1,i=1;i<=n;++p,++i,++w,++ch){

		p->ch=*ch;

		p->weight=*w;

		p->parent=p->lchild=p->rchild=0;

	}

	for(;i<=m;++i,++p){

		p->ch=0;

		p->weight=0;

		p->parent=p->lchild=p->rchild=0;

	}

	for(i=n+1;i<=m;++i){

		select(HT,i-1,s1,s2);

		HT[s1].parent=i;HT[s2].parent=i;

		HT[i].lchild=s1;HT[i].rchild=s2;

		HT[i].weight=HT[s1].weight+HT[s2].weight;

	}

	HC=(char**)malloc((n+1)*sizeof(char*));

	char *cd;

	cd=(char *)malloc(n*sizeof(char));

	cd[n-1]='\0';

	int start,c,f;

	for(i=1;i<=n;++i){

		start=n-1;

		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent){

			if(HT[f].lchild==c) cd[--start]='0';

			else cd[--start]='1';

		}

		HC[i]=(char *)malloc((n-start)*sizeof(char));

		strcpy(HC[i],&cd[start]);

	}

	free(cd);

}



void Encoding()

{

	FILE *fp,*fp1;

	int i;

	char in;

	if(n==0)

	{

		fp=fopen("hfmTree.txt","r");

		fscanf(fp,"%d",&n);

		if(feof(fp)){

			printf("���ȳ�ʼ������������\n");

		}

		ch=(char *)malloc(n*sizeof(char));

		for(i=0;i<n;++i)

			fscanf(fp,"%c",&ch[i]);

		w=(int *)malloc(n*sizeof(int));

		for(i=0;i<n;++i)

			fscanf(fp,"%d",&w[i]);

		HuffmanCoding(HT,HC,w,n,ch);

		printf("���������������\n");

		fclose(fp);

	}

	fp=fopen("ToBeTran.txt","r");

	printf("�ɹ���ȡToBeTran.txt\n");

	fp1=fopen("CodeFile.txt","w");

	fscanf(fp,"%c",&in);

	while(!feof(fp))

	{

		for(i=1;i<=n;++i){

		if(HT[i].ch==in)

				break;

		}



		fprintf(fp1,"%s",HC[i]);

		fscanf(fp,"%c",&in);

	}

	printf("\n�������������Ѵ���CodeFile.txt�ļ��У�\n");

	fclose(fp);

	fclose(fp1);

}



void Decoding()

{

	FILE *fp,*fp1;

	int i,m;

	char in;

		if(n==0)

	{

		fp=fopen("hfmTree.txt","r");

		fscanf(fp,"%d",&n);

		if(feof(fp)){

			printf("���ȳ�ʼ������������\n");

		}

		ch=(char *)malloc(n*sizeof(char));

		for(i=0;i<n;++i)

			fscanf(fp,"%c",&ch[i]);

		w=(int *)malloc(n*sizeof(int));

		for(i=0;i<n;++i)

			fscanf(fp,"%d",&w[i]);

		HuffmanCoding(HT,HC,w,n,ch);

		printf("���������������\n");

		fclose(fp);

	}

	fp=fopen("CodeFile.txt","r");

	fp1=fopen("TextFile.txt","w");

	for(i=1;HT[i].parent!=0;++i);

	m=i;

	while(!feof(fp)){

	if(HT[m].lchild && HT[m].rchild){

		fscanf(fp,"%c",&in);

		if(in=='0') m=HT[m].lchild;

		else m=HT[m].rchild;

		}

	else{

		fprintf(fp1,"%c",HT[m].ch);

		m=i;

		}

	}

		printf("\n����������������ѱ��浽TextFile.txt�ļ��У�\n");

		fclose(fp);

		fclose(fp1);

}

void Print()

{

	FILE *fp,*fp1;

	int i=0;

	char in;

	printf("�����ļ�Ϊ:\n");

	fp=fopen("CodeFile.txt","r");

	fp1=fopen("CodePrin.txt","w");

	fscanf(fp,"%c",&in);

	while(!feof(fp))

	{

		printf("%c",in);

		fprintf(fp1,"%c",in);

			i++;

		if(i==50){

			printf("\n");

			fprintf(fp1,"\n");

			i=0;

		}

		fscanf(fp,"%c",&in);

	}

	printf("\n");

	fclose(fp);

	fclose(fp1);

	printf("�����ļ��Ѵ���CodePrin.txt�ļ���");

	printf("\n");

}





void Tree_printing()

{

	FILE *fp;

	fp=fopen("TreePrint.txt","w");

	int i;

	for(i=1;i<2*n;i++){

		printf("%c%8d%8d%8d%8d\n",HT[i].ch,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);

		fprintf(fp,"%c%8d%8d%8d%8d",HT[i].ch,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);

		fprintf(fp,"\n");

	}

	fclose(fp);

	printf("���������Ѵ���TreePrint.txt\n");

}



void Free()

{

	free(HT);

	free(HC);

	free(w);

	free(ch);

}







int main()

{

	char choice;

	while(1)

	{

	   welcome();

	   scanf("%c",&choice);

	   switch(choice)

	   {

		case 'i':

		case 'I':Init();break;

		case 'e':

		case 'E':Encoding();break;

		case 'd':

		case 'D':Decoding();break;

		case 'p':

		case 'P':Print();break;

		case 't':

		case 'T':Tree_printing();break;

		case 'q':

		case 'Q':Free();exit(1);

		default :printf("Input error!\n");

	   }

		getchar();

	}

return 0;

}
//��ʦ����������copy�����ģ����������һ��
