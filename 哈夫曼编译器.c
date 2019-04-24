 #include <stdio.h>

#include <stdlib.h>

#include <string.h>



typedef struct{

        int weight;

   	char ch;

        int parent,lchild,rchild;

}HTNode,*HuffmanTree;





typedef char **HuffmanCode; //存储哈夫曼编码



HuffmanTree HT;

int n=0;

HuffmanCode HC;

int *w;

char *ch;



void welcome();    //操作选择界面

void select(HuffmanTree HT,int j,int s1,int s2); //选择parent为0且weight最小的两个结点

void Init(); //输入字符及其权值，建立哈夫曼树

void Encoding(); //编码

void Decoding(); //译码

void Tree_printing(); //打印哈夫曼树

void Print();//打印代码

void HuffmanCoding(HuffmanTree HT,HuffmanCode HC,int *w,int n,char *ch);

void Free();//释放动态分配空间



void welcome()

{

	printf("--------欢迎进入系统---------\n");


	printf("*            I.初始化                *\n");

	printf("*            E.编码                  *\n");

	printf("*            D.译码                  *\n");

	printf("*            P.印代码文件            *\n");

	printf("*            T.打印哈夫曼树          *\n");

	printf("*            Q.退出                  *\n");

	printf("**************************************\n");

}





void Init()

{

	FILE *fp;

	int i;

	printf("请输入字符个数:\n");

	scanf("%d",&n);

	while(n<2){

		printf("输入的数据有误，请重新输入:\n");

		scanf("%d",&n);

	}

	ch=(char *)malloc(n*sizeof(char));

	printf("请输入所有字符:\n");

	getchar();

	for(i=0;i<n;++i)

		scanf("%c",&ch[i]);

	w=(int *)malloc(n*sizeof(int));

	printf("请输入这些字符的权值:\n");

	for(i=0;i<n;++i)

		scanf("%d",&w[i]);

	HuffmanCoding(HT,HC,w,n,ch);

	/*printf("编码结果如下:\n");

	for(i=1;i<=n;++i)

		printf("%c:%s\n",HT[i].ch,HC[i]);*///调试

	fp=fopen("hfmTree.txt","w");

	fprintf(fp,"%d",n);

	for(i=0;i<n;++i)

		fprintf(fp,"%c",ch[i]);

	for(i=0;i<n;++i)

		fprintf(fp,"%5d",w[i]);

	for(i=1;i<=n;++i)

		fprintf(fp,"\n%c:%s",HT[i].ch,HC[i]);

	fclose(fp);

	printf("初始化成功\n");

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

			printf("请先初始化哈夫曼树！\n");

		}

		ch=(char *)malloc(n*sizeof(char));

		for(i=0;i<n;++i)

			fscanf(fp,"%c",&ch[i]);

		w=(int *)malloc(n*sizeof(int));

		for(i=0;i<n;++i)

			fscanf(fp,"%d",&w[i]);

		HuffmanCoding(HT,HC,w,n,ch);

		printf("已载入哈夫曼树！\n");

		fclose(fp);

	}

	fp=fopen("ToBeTran.txt","r");

	printf("成功读取ToBeTran.txt\n");

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

	printf("\n编码结束，结果已存入CodeFile.txt文件中！\n");

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

			printf("请先初始化哈夫曼树！\n");

		}

		ch=(char *)malloc(n*sizeof(char));

		for(i=0;i<n;++i)

			fscanf(fp,"%c",&ch[i]);

		w=(int *)malloc(n*sizeof(int));

		for(i=0;i<n;++i)

			fscanf(fp,"%d",&w[i]);

		HuffmanCoding(HT,HC,w,n,ch);

		printf("已载入哈夫曼树！\n");

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

		printf("\n译码结束，译码结果已保存到TextFile.txt文件中！\n");

		fclose(fp);

		fclose(fp1);

}

void Print()

{

	FILE *fp,*fp1;

	int i=0;

	char in;

	printf("代码文件为:\n");

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

	printf("代码文件已存入CodePrin.txt文件中");

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

	printf("哈夫曼树已存入TreePrint.txt\n");

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
//老师，代码是我copy过来的，大致理解了一下
