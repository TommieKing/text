#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\king\Desktop\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\SqStack.h>


Status initStack(SqStack* s, int sizes)//初始化栈
{
	                                              
	s= (SqStack*)malloc(sizeof(SqStack*)); //申请存储空间
	                           
	s->top = -1; //至栈顶标记为-1，表示空栈
	s->size = sizes;//初始化栈的大小
	s->elem = NULL;//链表中为空
	return SUCCESS;
}
Status isEmptyStack(SqStack* s)//判断栈是否为空
{
	if (s->top == -1)
	{
		printf("栈空\n");
		return SUCCESS;
	}
	else
	{
		printf("栈不为空");
		return ERROR;
	}
}
Status getTopStack(SqStack* s, ElemType* e) //得到栈顶元素
{
	if (isEmptyStack(s) != SUCCESS)
	{
		e = *(s->elem);
		printf("栈顶元素为%d",*(s->elem));
	}
	printf("栈为空");
	return ERROR;
}
Status clearStack(SqStack* s)//清空栈
{
	while (isEmptyStack(s) != ERROR)//判断栈是否为空
	{
		int* topData = s->elem;
		s->elem--;//栈内元素减少一个
		s->top--;
		free(topData);
	}
	printf("清空成功");
	return SUCCESS;
}
Status destroyStack(SqStack* s)//销毁栈
{
	while (isEmptyStack(s) != ERROR)//判断栈是否为空
	{
		int* topData = s->elem;
		s->elem--;//栈内元素减少一个
		s->top--;
		free(topData);
	}
	free(s);
	printf("销毁成功");
	return SUCCESS;
}
Status stackLength(SqStack* s, int* length)//检测栈长度
{
	*length = (s->top + 1);
	printf("栈的长度为%d", *length);
	return SUCCESS;
}
Status pushStack(SqStack* s, ElemType data)//入栈
{
	int top = s->top;
	top++;
	if (s->elem != NULL)//判断栈里是否有元素
	{
		s->elem++;
	}
	if (top == (s->size - 1))//判断栈是否满
	{
		printf("栈满了\n");
		return ERROR;
	}
	s->elem = &data;//将数据压入栈
	s->top++;//栈顶标记加一
	return SUCCESS;
}
Status popStack(SqStack* s, ElemType* data)//出栈
{
	if (isEmptyStack(s) != ERROR)//判断栈是否为空
	{
		int topData = &(s->elem);
		s->elem--;//栈内元素减少一个
		printf("元素为%d", topData);
		return SUCCESS;
	}
	printf("栈为空");
	return ERROR;
}