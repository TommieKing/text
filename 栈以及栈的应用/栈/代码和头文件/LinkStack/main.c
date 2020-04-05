#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\king\Desktop\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\LinkStack.h"

int main()
{
	int a, n;
	int* e, f;
	int* length=NULL;
	LinkStack* s= (LinkStackPtr)malloc(sizeof(StackNode));
	int data;
	while (1)
	{
		printf("******请输入您的选择******\n");
		printf("******1.初始化栈******\n");
		printf("******2.判断栈是否为空******\n");
		printf("******3.得到栈顶元素******\n");
		printf("******4.清空栈******\n");
		printf("******5.销毁栈******\n");
		printf("******6.检测栈长度******\n");
		printf("******7.入栈******\n");
		printf("******8.出栈******\n");
		scanf("%d", &n);



		switch (n)
		{
		case 1:
			initLStack(s);//初始化栈
			break;
		case 2:
			isEmptyLStack(s);   //判断栈是否为空
			break;
		case 3:
			e = NULL;
			getTopLStack(s,e);//得到栈顶元素
			break;
		case 4:
			clearLStack(s);//清空栈
			break;
		case 5:
			destroyLStack( s); //销毁栈
			break;
		case 6:
			LStackLength(s,length);//检测栈长度
			break;
		case 7:
			printf("请输入想要入栈的元素：");
			scanf("%d", &data);
			pushLStack(s, data);// 入栈
			break;
		case 8:
			popLStack(s,data);//出栈
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}