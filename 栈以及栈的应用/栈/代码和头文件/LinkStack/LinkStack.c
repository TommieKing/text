#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\king\Desktop\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\LinkStack.h"

Status initLStack(LinkStack* s)//初始化栈
{
    if (s == NULL)
    {
        printf("s无内存，错误");
        return ERROR;
    }
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));//获取动态内存
    
    s->top = NULL;
    s->count = 0;
    return SUCCESS;

}
Status isEmptyLStack(LinkStack* s)//判断栈是否为空
{
    if (s->count == 0)
    {
        return SUCCESS;
    }
    else {
        return ERROR;
    }
}
Status getTopLStack(LinkStack* s, ElemType* e)//得到栈顶元素
{
    if (isEmptyLStack(s) == SUCCESS)//判断是否为空
    {
        printf("为空栈");
        return ERROR;
    }

    int a = s->top->data;//将栈顶值赋给e
   
    printf("元素为%d", a);
    
    return SUCCESS;

}
Status clearLStack(LinkStack* s)//清空栈
{
    if (isEmptyLStack(s) == SUCCESS)//判断是否为空
    {
        printf("为空栈");
        return SUCCESS;
    }
    while (s->count != 0)//判断栈中是否还有元素
    {
        LinkStackPtr temp = s->top;
        s->top = temp->next;// 移动栈顶指针 
        s->count--;// 链栈长度减一    
        free(temp);// 释放temp空间
    }
    printf("清空成功");
    return SUCCESS;
    
}
Status destroyLStack(LinkStack* s)//销毁栈
{
    while (s->count != 0)//判断栈中是否还有元素
    {
        LinkStackPtr temp = s->top;
        s->top = temp->next;// 移动栈顶指针 
        s->count--;// 链栈长度减一    
        free(temp);// 释放temp空间
    }
    free(s);
    printf("销毁成功");
    return SUCCESS;
   
}
Status LStackLength(LinkStack* s, int* length)//检测栈长度
{
    if (isEmptyLStack(s) == SUCCESS)//判断是否为空
    {
        printf("为空栈");
        return SUCCESS;
    }
    int n = s->count;
    printf("长度为%d",n );
    return SUCCESS;
}
Status pushLStack(LinkStack* s, ElemType data)//入栈
{
    LinkStackPtr temp = (LinkStackPtr)malloc(sizeof(StackNode));
    if (temp == NULL) 
    {
        printf(" 申请空间失败");
        return ERROR;
    }

    temp->data = data;//储存数据
    temp->next = s->top; // 将新元素作为栈顶指针
      
    s->top = temp;// 链栈长度加一
    
    s->count++;//元素数量加一
    printf("入栈成功");

    return SUCCESS;
   

}
Status popLStack(LinkStack* s, ElemType* data)//出栈
{
    if (isEmptyLStack(s) == SUCCESS)
    {
        printf("空栈");
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
                                             