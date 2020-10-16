#ifndef STACK  //条件编译，防止重复包含头文件
#define STACK
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
	void Create(Stack *S,int mSize);   //创建一个能容纳mSize个单元格的空堆栈
	void Destory(Stack *S);			   //销毁一个存在的堆栈
	BOOL IsEmpty(Stack *S);			  //判断堆栈是否为空栈，是则返回TURE,否则返回FLASE
	BOOL IsFull(Stack *S);		//判断堆栈是否已满，是则返回TURE，否则返回FLASE
	BOOL Top(Stack *S,ElemType *x);		//获取栈顶元素，并通过x返回
	BOOL Push(Stack *S,ElemType x);			//在栈顶位置插入元素
	BOOL Pop(Stack *S);			//删除栈顶元素
	void Clear(Stack *S);		//清除堆栈中全部的元素，但不释放空间
#endif