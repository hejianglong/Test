#include<stdio.h>
#include<stdlib.h>
#define BOOL int
#define TRUE 1
#define FALSE 0
typedef char ElemType;
typedef struct stack			//��ջ�Ľṹ�嶨��
{
	int top;
	int maxSize;
	ElemType *element;
}Stack;
void Create(Stack *S,int mSize)   //����һ��������mSize����Ԫ��Ŀն�ջ
{
	S->maxSize=mSize;
	S->element=(ElemType*)malloc(sizeof(ElemType)*mSize);
	S->top=-1;
}
void Destory(Stack *S)			   //����һ�����ڵĶ�ջ
{
	S->maxSize=0;
	free(S->element);
	S->top;
}
BOOL IsEmpty(Stack *S)			  //�ж϶�ջ�Ƿ�Ϊ��ջ�����򷵻�TURE,���򷵻�FLASE
{
	return S->top==-1;
}
BOOL IsFull(Stack *S)		//�ж϶�ջ�Ƿ����������򷵻�TURE�����򷵻�FLASE
{
	return S->top==S->maxSize-1;
}
BOOL Top(Stack *S,ElemType *x)		//��ȡջ��Ԫ�أ���ͨ��x����
{
	if(IsEmpty(S))		//��ջ����
		return FALSE;
	*x=S->element[S->top];
	return TRUE;
}
BOOL Push(Stack *S,ElemType x)		//��ջ��λ�ò���Ԫ��
{
	if(IsFull(S))		//�������
		return FALSE;
	S->top++;
	S->element[S->top]=x;
	return TRUE;
}
BOOL Pop(Stack *S)			//ɾ��ջ��Ԫ��
{
	if(IsEmpty(S))		//��ջ����
		return FALSE;
	S->top--;
	return TRUE;
}
void Clear(Stack *S)		//�����ջ��ȫ����Ԫ�أ������ͷſռ�
{
	S->top=-1;
}