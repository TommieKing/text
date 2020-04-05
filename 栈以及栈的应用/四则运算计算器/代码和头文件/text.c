#include<stdio.h>
#include<string.h>
#include<D:\�����ϰ\������\text.h>
#define Max 1000 

//��ʼ��ջ
Status initLStack(LinkStack* s)//��ʼ��ջ
{
if (s == NULL)
{
    printf("s���ڴ棬����");
    return ERROR;
}
s->top = (LinkStackPtr)malloc(sizeof(StackNode));//��ȡ��̬�ڴ�

s->top = '0';
s->count = 0;
return SUCCESS;

}
//�ж�ջ�Ƿ�Ϊ��
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
//�õ�ջ��Ԫ��
char getTopLStack(LinkStack* s)//�õ�ջ��Ԫ��
{
    if (isEmptyLStack(s) == SUCCESS)//�ж��Ƿ�Ϊ��
    {
  
        return '\0';
    }
    char a=s->top->data;//��ջ��ֵ����e


    return a;

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
    *length = s->count;
    printf("����Ϊ%d", *length);
    return SUCCESS;
}
//��ջ
Status pushLStack(LinkStack* s, char data)//��ջ
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
   /* printf("��ջ�ɹ�");*/

    return SUCCESS;


}
//��ջ
char popLStack(LinkStack* s)//��ջ
{
    if (isEmptyLStack(s) == SUCCESS)
    {
   /*     printf("��ջ");*/
        return ERROR;
    }

    char c = s->top->data;
    
    LinkStackPtr p = s->top;
    s->top = s->top->data;
    free(p);
    s->count--;
    return c;
}
//��������ȼ�
