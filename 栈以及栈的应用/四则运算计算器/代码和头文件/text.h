#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<stdio.h>
#include<string.h>

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;




typedef  struct StackNode//��ջ�洢���ŵ����ݽṹ
{
	char data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack//��ջ�����ݽṹ
{
	LinkStackPtr top;//ջ��ָ��
	int count;//ջ��Ԫ�ظ���
}LinkStack;
//��ջ
Status initLStack(LinkStack* s);//��ʼ��ջ
Status isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
char getTopLStack(LinkStack* s);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack* s);//���ջ
Status destroyLStack(LinkStack* s);//����ջ
Status LStackLength(LinkStack* s, int* length);//���ջ����
Status pushLStack(LinkStack* s, char data);//��ջ
char popLStack(LinkStack* s);//��ջ

//����׺���ʽת��Ϊ��׺���ʽ
void tran(char* ch, char* arr);
char Calculate(char* arr);
//Status deletTopLStack(LinkStack* s, char e);//ɾ��ջ��Ԫ��

#endif