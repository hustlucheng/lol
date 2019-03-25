
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct SListNode
{
	struct SListNode* _next;
	DataType _data;
}SListNode;

SListNode* BuySListNode(DataType x)
{

	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	if (tmp != NULL)
	{
		tmp->_data = x;
		tmp->_next = NULL;
		return tmp;
	}
	printf("�ڵ㴴��ʧ�ܣ�");
	return tmp;
}

void SListPushBack(SListNode** ppHead, DataType x)//��β����������
{
	SListNode* newNode;
	SListNode* tmp;
	newNode = BuySListNode(x);
	tmp = *ppHead;
	if (NULL == *ppHead)
	{
		*ppHead = newNode;
		(*ppHead)->_next = NULL;
	}
	else
	{
		while (tmp->_next)
		{
			tmp = tmp->_next;
		}
		tmp->_next = newNode;
		newNode->_next = NULL;
	}
}

SListNode* SListFind(SListNode* pHead, DataType x)//�ҵ������е�ĳ��Ԫ��
{
	SListNode* tmp;
	tmp = pHead;
	while (tmp)
	{
		if (tmp->_data == x)
		{
			return tmp;
		}
		tmp = tmp->_next;
	}
	return tmp;
}

SListNode* SListJosephCircle(SListNode* pHead, int k)//������ʵ��Լɪ��(JosephCircle)
{
	SListNode* cur = pHead;
	SListNode* tmp = NULL;
	while (cur != cur->_next)
	{
		int count = k;
		while (--count)
		{
			cur = cur->_next;
		}
		tmp = cur->_next;
		cur->_data = tmp->_data;
		cur->_next = tmp->_next;
		free(tmp);
	}
	return cur;
}


int main()
{

	SListNode* SList1 = NULL;
	SListPushBack(&SList1, 1);
	SListPushBack(&SList1, 2);
	SListPushBack(&SList1, 3);
	SListPushBack(&SList1, 4);
	SListPushBack(&SList1, 5);
	SListPushBack(&SList1, 6);
	SListPushBack(&SList1, 7);
	SListFind(SList1, 8)->_next = SListFind(SList1,1);
	printf("%d\n", SListJosephCircle(SList1, 3)->_data);
	return 0;
}
