#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\king\Desktop\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\LinkStack.h"

Status initLStack(LinkStack* s)//��ʼ��ջ
{
    if (s == NULL)
    {
        printf("s���ڴ棬����");
        return ERROR;
    }
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));//��ȡ��̬�ڴ�
    
    s->top = NULL;
    s->count = 0;
    return SUCCESS;

}
Status isEmptyLStack(LinkStack* s)//�ж�ջ�Ƿ�Ϊ��
{
    if (s->count == 0)
    {
        return SUCCESS;
    }
    else {
        return ERROR;
    }
}
Status getTopLStack(LinkStack* s, ElemType* e)//�õ�ջ��Ԫ��
{
    if (isEmptyLStack(s) == SUCCESS)//�ж��Ƿ�Ϊ��
    {
        printf("Ϊ��ջ");
        return ERROR;
    }

    int a = s->top->data;//��ջ��ֵ����e
   
    printf("Ԫ��Ϊ%d", a);
    
    return SUCCESS;

}
Status clearLStack(LinkStack* s)//���ջ
{
    if (isEmptyLStack(s) == SUCCESS)//�ж��Ƿ�Ϊ��
    {
        printf("Ϊ��ջ");
        return SUCCESS;
    }
    while (s->count != 0)//�ж�ջ���Ƿ���Ԫ��
    {
        LinkStackPtr temp = s->top;
        s->top = temp->next;// �ƶ�ջ��ָ�� 
        s->count--;// ��ջ���ȼ�һ    
        free(temp);// �ͷ�temp�ռ�
    }
    printf("��ճɹ�");
    return SUCCESS;
    
}
Status destroyLStack(LinkStack* s)//����ջ
{
    while (s->count != 0)//�ж�ջ���Ƿ���Ԫ��
    {
        LinkStackPtr temp = s->top;
        s->top = temp->next;// �ƶ�ջ��ָ�� 
        s->count--;// ��ջ���ȼ�һ    
        free(temp);// �ͷ�temp�ռ�
    }
    free(s);
    printf("���ٳɹ�");
    return SUCCESS;
   
}
Status LStackLength(LinkStack* s, int* length)//���ջ����
{
    if (isEmptyLStack(s) == SUCCESS)//�ж��Ƿ�Ϊ��
    {
        printf("Ϊ��ջ");
        return SUCCESS;
    }
    int n = s->count;
    printf("����Ϊ%d",n );
    return SUCCESS;
}
Status pushLStack(LinkStack* s, ElemType data)//��ջ
{
    LinkStackPtr temp = (LinkStackPtr)malloc(sizeof(StackNode));
    if (temp == NULL) 
    {
        printf(" ����ռ�ʧ��");
        return ERROR;
    }

    temp->data = data;//��������
    temp->next = s->top; // ����Ԫ����Ϊջ��ָ��
      
    s->top = temp;// ��ջ���ȼ�һ
    
    s->count++;//Ԫ��������һ
    printf("��ջ�ɹ�");

    return SUCCESS;
   

}
Status popLStack(LinkStack* s, ElemType* data)//��ջ
{
    if (isEmptyLStack(s) == SUCCESS)
    {
        printf("��ջ");
        return ERROR;
    }

    int c = s->top->data;
    printf("%d", c);
    LinkStackPtr p = s->top;
    s->top = s->top->data;
    free(p);
    s->count--;

    return SUCCESS;
}
                                             