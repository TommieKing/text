#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\king\Desktop\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\SqStack.h>

int main()
{
	int a, n;
	int* e,f;
	int* length;
	SqStack s;
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
			printf("������ջ��Ԫ�ظ�����");
			scanf("%d", &a);
			initStack(&s, a);//��ʼ��ջ
			break;
		case 2:
			isEmptyStack(&s);   //�ж�ջ�Ƿ�Ϊ��
			break;
		case 3:
			getTopStack(&s, e);//�õ�ջ��Ԫ��
			break;
		case 4:
			clearStack(&s);//���ջ
			break;
		case 5:
			destroyStack(&s); //����ջ
			break;
		case 6:
			stackLength(&s, length);//���ջ����
			break;
		case 7:
			printf("��������Ҫ��ջ��Ԫ�أ�");
			scanf("%d", &data);
			pushStack(&s, data);// ��ջ
			break;
		case 8:
			popStack(&s, f);//��ջ
			break;
		}
		system("pause");
		system("cls");
	}
	
	return 0;
}