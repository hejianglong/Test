#include<stdio.h>
#include<stdlib.h>
#define BOOL int
#define TRUE 1
#define FALSE 0
typedef char ElemType;
typedef struct stack			//堆栈的结构体定义
{
	int top;
	int maxSize;
	ElemType *element;
}Stack;
void Create(Stack *S,int mSize)   //创建一个能容纳mSize个单元格的空堆栈
{
	S->maxSize=mSize;
	S->element=(ElemType*)malloc(sizeof(ElemType)*mSize);
	S->top=-1;
}
void Destory(Stack *S)			   //销毁一个存在的堆栈
{
	S->maxSize=0;
	free(S->element);
	S->top;
}
BOOL IsEmpty(Stack *S)			  //判断堆栈是否为空栈，是则返回TURE,否则返回FLASE
{
	return S->top==-1;
}
BOOL IsFull(Stack *S)		//判断堆栈是否已满，是则返回TURE，否则返回FLASE
{
	return S->top==S->maxSize-1;
}
BOOL Top(Stack *S,ElemType *x)		//获取栈顶元素，并通过x返回
{
	if(IsEmpty(S))		//空栈处理
		return FALSE;
	*x=S->element[S->top];
	return TRUE;
}
BOOL Push(Stack *S,ElemType x)		//在栈顶位置插入元素
{
	if(IsFull(S))		//溢出处理
		return FALSE;
	S->top++;
	S->element[S->top]=x;
	return TRUE;
}
BOOL Pop(Stack *S)			//删除栈顶元素
{
	if(IsEmpty(S))		//空栈处理
		return FALSE;
	S->top--;
	return TRUE;
}
void Clear(Stack *S)		//清除堆栈中全部的元素，但不释放空间
{
	S->top=-1;
}