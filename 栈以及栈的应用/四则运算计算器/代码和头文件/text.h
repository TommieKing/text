#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<stdio.h>
#include<string.h>

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;




typedef  struct StackNode//链栈存储符号的数据结构
{
	char data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack//链栈的数据结构
{
	LinkStackPtr top;//栈顶指针
	int count;//栈中元素个数
}LinkStack;
//链栈
Status initLStack(LinkStack* s);//初始化栈
Status isEmptyLStack(LinkStack* s);//判断栈是否为空
char getTopLStack(LinkStack* s);//得到栈顶元素
Status clearLStack(LinkStack* s);//清空栈
Status destroyLStack(LinkStack* s);//销毁栈
Status LStackLength(LinkStack* s, int* length);//检测栈长度
Status pushLStack(LinkStack* s, char data);//入栈
char popLStack(LinkStack* s);//出栈

//将中缀表达式转化为后缀表达式
void tran(char* ch, char* arr);
char Calculate(char* arr);
//Status deletTopLStack(LinkStack* s, char e);//删除栈顶元素

#endif