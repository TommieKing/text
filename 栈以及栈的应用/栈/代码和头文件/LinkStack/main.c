#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\king\Desktop\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\LinkStack.h"

int main()
{
	int a, n;
	int* e, f;
	int* length=NULL;
	LinkStack* s= (LinkStackPtr)malloc(sizeof(StackNode));
	int data;
	while (1)
	{
		printf("******����������ѡ��******\n");
		printf("******1.��ʼ��ջ******\n");
		printf("******2.�ж�ջ�Ƿ�Ϊ��******\n");
		printf("******3.�õ�ջ��Ԫ��******\n");
		printf("******4.���ջ******\n");
		printf("******5.����ջ******\n");
		printf("******6.���ջ����******\n");
		printf("******7.��ջ******\n");
		printf("******8.��ջ******\n");
		scanf("%d", &n);



		switch (n)
		{
		case 1:
			initLStack(s);//��ʼ��ջ
			break;
		case 2:
			isEmptyLStack(s);   //�ж�ջ�Ƿ�Ϊ��
			break;
		case 3:
			e = NULL;
			getTopLStack(s,e);//�õ�ջ��Ԫ��
			break;
		case 4:
			clearLStack(s);//���ջ
			break;
		case 5:
			destroyLStack( s); //����ջ
			break;
		case 6:
			LStackLength(s,length);//���ջ����
			break;
		case 7:
			printf("��������Ҫ��ջ��Ԫ�أ�");
			scanf("%d", &data);
			pushLStack(s, data);// ��ջ
			break;
		case 8:
			popLStack(s,data);//��ջ
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}