#include "Stack.h"
#include "stdlib.h"
#include "stdio.h"

// ����һ����ջ
void InitStack(Stack &s)
{
    s.elem = (char *)malloc(initsize * sizeof(char)); // ��ʼ�����ַ
    s.base = 0; // baseָ��ָ��ջ��
    s.top = 0;// ��ʼ��topָ��ָ��ջ��Ԫ�ص���һ��λ��
    s.stacksize = 10; //��ǰ����
}


// ����nΪ�µ�ջ��Ԫ��
void push(Stack &s, char n)
{
    if(s.top - s.base <= initsize) // ����
    {
        /*����������s.top����top*/
        s.elem[s.top] = n; // ����n
        s.top += 1 ; // topָ��+1
    }
    else
    {
        s.elem = (char *)realloc(s.elem, (initsize + increasesize) * sizeof(char)); // ջ����׷�ӿռ�
        s.stacksize += increasesize; // �޸�initsize��ֵ
    }


}

// �յ�ʱ�򷵻�1���ǿշ���0
bool StackEmpty(Stack &s)
{
    if(s.top == s.base) return true; // ��
    else return false;
}

// ���ջ��Ԫ�ط��ظ�e
void pop(Stack &s, char &e)
{
    if(!StackEmpty(s)) // �ǿ�
    {
         s.top --; // ��λ��ջ��Ԫ��
         e = s.elem[s.top]; // ȡ��ջ��Ԫ�ط��ظ�e
    }
    else
        /*����ַ������*/
        printf("error");
}
