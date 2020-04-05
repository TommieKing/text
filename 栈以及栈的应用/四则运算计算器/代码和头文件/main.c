#include<stdio.h>
#include<string.h>
#include<D:\编程练习\计算器\text.h>
#define Max 1000 

int main(void)
{
	
	/*LinkStack* s = (LinkStackPtr)malloc(sizeof(StackNode));
	initLStack(s);*/
	char s1[Max]="0";			//用于存储前缀表达式 
	char s2[Max]="0";			//用于存储转换后的表达式 
	printf("请输入表达式:");
	scanf("%s", &s1);
    tran(s1, s2);//将中缀表达式转换为后缀表达式
    printf("%s", s2);
	printf("计算结果为: %c", Calculate(s2));		//后缀表达式求值 
    system("pause");
    system("cls");

	return 0;
}

//将中缀表达式转化为后缀表达式
void tran(char* ch, char* arr)
{
    LinkStack* s = (LinkStackPtr)malloc(sizeof(StackNode));
    initLStack(s);//初始化栈储存符号
    int i = 0;
    int j = 0;
    while (ch[i] != '\0')
    {
        if (ch[i] >= '1' && ch[i] <= '9')//运算数直接输入
        {
            arr[j] = ch[i];
            i++;
            j++;
        }
        else if (ch[i] == '(')//左括号压入堆栈
        {
            pushLStack(s, ch[i]);
            i++;
        }
        else if (ch[i] == '*' || ch[i] == '/')//优先级大于栈顶优先级入栈
        {
            pushLStack(s, ch[i]);
            i++;
        }
        else if (ch[i] == '+' || ch[i] == '-')
        {
            char m ='0';//定义m储存栈顶元素
            m= getTopLStack(s);
            while (m == '*' || m == '/'||m == '+' || m == '-')//如果栈顶元素优先级大于等于+-则输出
            {
                arr[j] = m;
                j++;
                m = popLStack(s);//输出后销毁栈顶元素
            }
            pushLStack(s, ch[i]);//+-压栈
            i++;
        }
        else if (ch[i] == ')')
        {
            char m;//定义m储存栈顶元素
            m = popLStack(s);//输出后销毁栈顶元素
            while (m != '(')
            {
                arr[j] = m;
                j++;
                m = popLStack(s);//赋值后销毁栈顶元素
                
            }
            i++;
        }
        
    }
    //堆栈中存留的运算符一并输出
    
    char m = '0';//定义m储存栈顶元素
    m = popLStack(s);//赋值后销毁栈顶元素
    while (m != '0')
    {
        arr[j] = m;//*这个地方老是提醒访问越界，没查出什么原因
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
        if (arr[j] >= '0' && arr[j] <= '9')//数字入栈
        {
            pushLStack(s, arr[j]);
            j++;
        }
        else if (arr[j] == '+')
        {
            char m,n,z;//定义m储存栈顶元素
            m = popLStack(s);
            n = popLStack(s);
            z = (m - '0') + (n - '0') + '0';
            pushLStack(s,z);
            j++;
        }
        else if (arr[j] == '-')
        {
            char m, n, z;//定义m储存栈顶元素
            m = popLStack(s);
            n = popLStack(s);
            z = (m - '0') - (n - '0') + '0';
            pushLStack(s, z);
            j++;
        }
        else if (arr[j] == '*')
        {
            char m, n, z;//定义m储存栈顶元素
            m = popLStack(s);
            n = popLStack(s);
            z = (m - '0') *(n - '0') + '0';
            pushLStack(s, z);
           j++;
        }
        else if (arr[j] == '/')
        {
            char m, n, z;//定义m储存栈顶元素
            m = popLStack(s, m);
            n = popLStack(s, n);
            z = (m - '0') / (n - '0') + '0';
            pushLStack(s, z);
            j++;
        }
    }
   
    char resuit = s->top->data;//获取结果并销毁内存
    return resuit;
}