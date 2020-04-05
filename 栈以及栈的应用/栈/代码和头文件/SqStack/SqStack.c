#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\king\Desktop\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\SqStack.h>


Status initStack(SqStack* s, int sizes)//��ʼ��ջ
{
	                                              
	s= (SqStack*)malloc(sizeof(SqStack*)); //����洢�ռ�
	                           
	s->top = -1; //��ջ�����Ϊ-1����ʾ��ջ
	s->size = sizes;//��ʼ��ջ�Ĵ�С
	s->elem = NULL;//������Ϊ��
	return SUCCESS;
}
Status isEmptyStack(SqStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	if (s->top == -1)
	{
		printf("ջ��\n");
		return SUCCESS;
	}
	else
	{
		printf("ջ��Ϊ��");
		return ERROR;
	}
}
Status getTopStack(SqStack* s, ElemType* e) //�õ�ջ��Ԫ��
{
	if (isEmptyStack(s) != SUCCESS)
	{
		e = *(s->elem);
		printf("ջ��Ԫ��Ϊ%d",*(s->elem));
	}
	printf("ջΪ��");
	return ERROR;
}
Status clearStack(SqStack* s)//���ջ
{
	while (isEmptyStack(s) != ERROR)//�ж�ջ�Ƿ�Ϊ��
	{
		int* topData = s->elem;
		s->elem--;//ջ��Ԫ�ؼ���һ��
		s->top--;
		free(topData);
	}
	printf("��ճɹ�");
	return SUCCESS;
}
Status destroyStack(SqStack* s)//����ջ
{
	while (isEmptyStack(s) != ERROR)//�ж�ջ�Ƿ�Ϊ��
	{
		int* topData = s->elem;
		s->elem--;//ջ��Ԫ�ؼ���һ��
		s->top--;
		free(topData);
	}
	free(s);
	printf("���ٳɹ�");
	return SUCCESS;
}
Status stackLength(SqStack* s, int* length)//���ջ����
{
	*length = (s->top + 1);
	printf("ջ�ĳ���Ϊ%d", *length);
	return SUCCESS;
}
Status pushStack(SqStack* s, ElemType data)//��ջ
{
	int top = s->top;
	top++;
	if (s->elem != NULL)//�ж�ջ���Ƿ���Ԫ��
	{
		s->elem++;
	}
	if (top == (s->size - 1))//�ж�ջ�Ƿ���
	{
		printf("ջ����\n");
		return ERROR;
	}
	s->elem = &data;//������ѹ��ջ
	s->top++;//ջ����Ǽ�һ
	return SUCCESS;
}
Status popStack(SqStack* s, ElemType* data)//��ջ
{
	if (isEmptyStack(s) != ERROR)//�ж�ջ�Ƿ�Ϊ��
	{
		int topData = &(s->elem);
		s->elem--;//ջ��Ԫ�ؼ���һ��
		printf("Ԫ��Ϊ%d", topData);
		return SUCCESS;
	}
	printf("ջΪ��");
	return ERROR;
}