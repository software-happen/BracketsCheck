#include <iostream>
#include "StackOperation.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    printf("����淶���ʽ��");
    Stack s;
    char str[20]; /* �������ó� char * ���� InititStack �ᱨ�� */
    //str = (char *)malloc(sizeof(char));
    /* scanf ���ܶ�ȡ���� */
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
        while(str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']' || str[i] == '{' || str[i] == '}') // ��( �� ) �� [ �� ] �� { �� }
        {/*��������whileѭ����һ���жϱ��ʽ�Ƿ������һ���ж��Ƿ�������*/
            switch(str[i])
            {
            // ��������ջ
            case '(': push(s,'('); break;
            case '[': push(s,'['); break;
            case '{': push(s,'{'); break;
            // �����ų�ջ
            case ')': pop(s,e);
                if(e != '(') return false; /* ��ƥ���ֱ�ӽ��� return ֱ�ӷ��ؽ���*/
            break;
            case ']': pop(s,e);
                if(e != '[') return false;
            break;
            case '}': pop(s,e);
                if(e != '{') return false;
            break;
            } // switch
            i++; /* break����switchѭ����ִ���ж��Ƿ������ŵ�whileѭ����������switch���������ڶ���whileѭ�������һֱ���ж�str[0]*/
        } // while

        i++;
    }// while
    if(!StackEmpty(s))
    {
        printf("���Ų�ƥ��\n");
        return false;
    }
    else
    {
        printf("����ƥ��\n");
        return true;
    }
}
