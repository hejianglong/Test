#ifndef STACK  //�������룬��ֹ�ظ�����ͷ�ļ�
#define STACK
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
	void Create(Stack *S,int mSize);   //����һ��������mSize����Ԫ��Ŀն�ջ
	void Destory(Stack *S);			   //����һ�����ڵĶ�ջ
	BOOL IsEmpty(Stack *S);			  //�ж϶�ջ�Ƿ�Ϊ��ջ�����򷵻�TURE,���򷵻�FLASE
	BOOL IsFull(Stack *S);		//�ж϶�ջ�Ƿ����������򷵻�TURE�����򷵻�FLASE
	BOOL Top(Stack *S,ElemType *x);		//��ȡջ��Ԫ�أ���ͨ��x����
	BOOL Push(Stack *S,ElemType x);			//��ջ��λ�ò���Ԫ��
	BOOL Pop(Stack *S);			//ɾ��ջ��Ԫ��
	void Clear(Stack *S);		//�����ջ��ȫ����Ԫ�أ������ͷſռ�
#endif