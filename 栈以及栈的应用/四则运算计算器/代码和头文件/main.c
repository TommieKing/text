#include<stdio.h>
#include<string.h>
#include<D:\�����ϰ\������\text.h>
#define Max 1000 

int main(void)
{
	
	/*LinkStack* s = (LinkStackPtr)malloc(sizeof(StackNode));
	initLStack(s);*/
	char s1[Max]="0";			//���ڴ洢ǰ׺���ʽ 
	char s2[Max]="0";			//���ڴ洢ת����ı��ʽ 
	printf("��������ʽ:");
	scanf("%s", &s1);
    tran(s1, s2);//����׺���ʽת��Ϊ��׺���ʽ
    printf("%s", s2);
	printf("������Ϊ: %c", Calculate(s2));		//��׺���ʽ��ֵ 
    system("pause");
    system("cls");

	return 0;
}

//����׺���ʽת��Ϊ��׺���ʽ
void tran(char* ch, char* arr)
{
    LinkStack* s = (LinkStackPtr)malloc(sizeof(StackNode));
    initLStack(s);//��ʼ��ջ�������
    int i = 0;
    int j = 0;
    while (ch[i] != '\0')
    {
        if (ch[i] >= '1' && ch[i] <= '9')//������ֱ������
        {
            arr[j] = ch[i];
            i++;
            j++;
        }
        else if (ch[i] == '(')//������ѹ���ջ
        {
            pushLStack(s, ch[i]);
            i++;
        }
        else if (ch[i] == '*' || ch[i] == '/')//���ȼ�����ջ�����ȼ���ջ
        {
            pushLStack(s, ch[i]);
            i++;
        }
        else if (ch[i] == '+' || ch[i] == '-')
        {
            char m ='0';//����m����ջ��Ԫ��
            m= getTopLStack(s);
            while (m == '*' || m == '/'||m == '+' || m == '-')//���ջ��Ԫ�����ȼ����ڵ���+-�����
            {
                arr[j] = m;
                j++;
                m = popLStack(s);//���������ջ��Ԫ��
            }
            pushLStack(s, ch[i]);//+-ѹջ
            i++;
        }
        else if (ch[i] == ')')
        {
            char m;//����m����ջ��Ԫ��
            m = popLStack(s);//���������ջ��Ԫ��
            while (m != '(')
            {
                arr[j] = m;
                j++;
                m = popLStack(s);//��ֵ������ջ��Ԫ��
                
            }
            i++;
        }
        
    }
    //��ջ�д����������һ�����
    
    char m = '0';//����m����ջ��Ԫ��
    m = popLStack(s);//��ֵ������ջ��Ԫ��
    while (m != '0')
    {
        arr[j] = m;//*����ط��������ѷ���Խ�磬û���ʲôԭ��
        j++;
        m = popLStack(s);
    }
}
   
   
 


char Calculate(char* arr)
{
    LinkStack* s = (LinkStackPtr)malloc(sizeof(StackNode));
    initLStack(s);
    int j = 0;
    while (arr[j] != '\0')
    {
        if (arr[j] >= '0' && arr[j] <= '9')//������ջ
        {
            pushLStack(s, arr[j]);
            j++;
        }
        else if (arr[j] == '+')
        {
            char m,n,z;//����m����ջ��Ԫ��
            m = popLStack(s);
            n = popLStack(s);
            z = (m - '0') + (n - '0') + '0';
            pushLStack(s,z);
            j++;
        }
        else if (arr[j] == '-')
        {
            char m, n, z;//����m����ջ��Ԫ��
            m = popLStack(s);
            n = popLStack(s);
            z = (m - '0') - (n - '0') + '0';
            pushLStack(s, z);
            j++;
        }
        else if (arr[j] == '*')
        {
            char m, n, z;//����m����ջ��Ԫ��
            m = popLStack(s);
            n = popLStack(s);
            z = (m - '0') *(n - '0') + '0';
            pushLStack(s, z);
           j++;
        }
        else if (arr[j] == '/')
        {
            char m, n, z;//����m����ջ��Ԫ��
            m = popLStack(s, m);
            n = popLStack(s, n);
            z = (m - '0') / (n - '0') + '0';
            pushLStack(s, z);
            j++;
        }
    }
   
    char resuit = s->top->data;//��ȡ����������ڴ�
    return resuit;
}