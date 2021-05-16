#include <iostream>
#include "StackOperation.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    printf("输入规范表达式：");
    Stack s;
    char str[20]; /* 类型设置成 char * 类型 InititStack 会报错 */
    //str = (char *)malloc(sizeof(char));
    /* scanf 不能读取括号 */
    cin>>str;
    bool BracketsCheck(char *str, Stack s);
    BracketsCheck(str, s);
    //free(str);
    return 0;
}

bool BracketsCheck(char *str, Stack s)
{
    InitStack(s); //
    int i=0;
    char e;
    while(str[i] != '\0')
    {
        while(str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']' || str[i] == '{' || str[i] == '}') // 是( 或 ) 或 [ 或 ] 或 { 或 }
        {/*设置两个while循环，一个判断表达式是否结束，一个判断是否是括号*/
            switch(str[i])
            {
            // 左括号入栈
            case '(': push(s,'('); break;
            case '[': push(s,'['); break;
            case '{': push(s,'{'); break;
            // 右括号出栈
            case ')': pop(s,e);
                if(e != '(') return false; /* 不匹配就直接结束 return 直接返回结束*/
            break;
            case ']': pop(s,e);
                if(e != '[') return false;
            break;
            case '}': pop(s,e);
                if(e != '{') return false;
            break;
            } // switch
            i++; /* break跳出switch循环后执行判断是否是括号的while循环，即跳出switch不会跳出第二个while循环，因此一直在判断str[0]*/
        } // while

        i++;
    }// while
    if(!StackEmpty(s))
    {
        printf("括号不匹配\n");
        return false;
    }
    else
    {
        printf("括号匹配\n");
        return true;
    }
}
