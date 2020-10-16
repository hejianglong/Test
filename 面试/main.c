#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#define STACKSIZE 20   //堆栈的容量
#define ITEMSIZE 20    //表达式中元素的最大长度
#define EXPSIZE 200    //表达式的最大长度
#define FLASE 0
#define TURE 1

//判断表达式中是否存在非法字符，合法字符仅包含P、Q、R、^,v,→和空格
int IsLegal(char *postfix)
{
	int i;
	char c;
	for(i=0;i<strlen(postfix);i++)
	{
		c=postfix[i];
		if(!(c=='P'||c=='Q'||c=='R'||c=='^'||c=='v'||c=='-'||c=='>'))
			return FLASE;
	}
	return TURE;
}

//从表达式当前位置curPos获取一个元素，获取之后curPos移动到下一个元素首字符位置
//出现异常返回-1，若当前元素为操作数，则返回0，若为操作符，则返回1
int GetItem(char *postfix,int *curPos,char *item)
{
	int i=0,k=*curPos,flag;
	if(postfix[k]=='P'||postfix[k]=='Q'||postfix[k]=='R')		//当前元素为字母
	{
		while(postfix[k]=='P'||postfix[k]=='Q'||postfix[k]=='R')
			item[i++]=postfix[k++];
		item[i]='\0';
		flag=0;
	}
	else				//当前元素为操作符
	{
		item[0]=postfix[k++];
		item[1]='\0';
		flag=1;
	}
	while(postfix[k]==' ')		//跳过当前元素后面的空格，下次取元素的起始位置为非空字符
		k++;
	*curPos=k;
	return flag;
}

//获取操作符的栈外优先级
int ICP(char c)
{
	if(c=='#')
		return 0;
	else
	if(c=='-')
		return 10;
	else
	if(c=='>')
		return 4;
	else
	if(c=='v')
		return 6;
	else
	if(c=='^')
		return 8;
	else
	{
		printf("后缀表达式不支持操作符%c\n",c);
		exit(0);
	}
}

//获取操作符的栈内优先级
int ISP(char c)
{
	if(c=='#')
		return 0;
	else
	if(c=='-')
		return 11;
	else 
	if(c=='>')
		return 5;
	else
	if(c=='v')
		return 7;
	else 
	if(c=='^')
		return 9;
	else
	{
		printf("后缀表达式不支持操作符%c",c);
		exit(0);
	}
}

//将中缀表达式infix转换为后缀表达式postfix，后缀表达式中相邻元素用空格分开
void InfixToPostfix(char *infix,char *postfix)
{
	Stack S;
	char item[ITEMSIZE];			//存储中缀表达式
	int flag=-1;				//标识当前扫描元素的类型，操作符标记为1，操作数标记为0，存在异常标记为-1
	int curPos=0;			//记录当前扫描元素的首字符下标位置
	int k=0,i,h;
	char ch,curOP;

	while(infix[curPos]==' ')		//过滤infix最前面的所有空格
		curPos++;
	Create(&S,STACKSIZE);		//创建堆栈，动态申请STACKSIZE大小的空间
	Push(&S,'#');
	while(curPos<strlen(infix))
	{
		flag=GetItem(infix,&curPos,item);		//获取当前扫描表达式的元素
		if(flag==-1)
		{
			printf("异常：中缀表达式元素不合法！\n");
			exit(0);
		}
		else if(flag==1)
		{
			curOP=item[0];		//curOP为当前扫描的操作符
			if(curOP=='>')		//扫描到>时的处理
			{
				h=k+2;
				postfix[h]=curOP;
				
			}
			else			//扫描到其他操作符时的处理
			{
				Top(&S,&ch);			//获取当前栈顶操作符
				while(ICP(curOP)<=ISP(ch))
				{
					Pop(&S);
					postfix[k++]=ch;
					//postfix[k++]=' ';		//相邻元素用空格分割
					Top(&S,&ch);			//获取当前栈顶操作符
				}
				Push(&S,curOP);			//当前扫描的操作符进栈
		   }
		}
		else			//当前元素为操作数，直接输出
		{
			for(i=0;i<strlen(item);i++,k++)
				postfix[k]=item[i];
			//postfix[k++]=' '	;		//相邻元素用空格分隔
		}
		if(postfix[k]=='>')
		k+=1;
	}
	
	while(!IsEmpty(&S))			//输出栈内剩余操作符
	{
		Top(&S,&ch);
		Pop(&S);
		if(ch!='#')
		{
			postfix[k++]=ch;
			//postfix[k++]=' ';		//相邻元素用空格分开
		}
	}
	postfix[++k]='\0';//去除最后一个多余的空格
}


void main()
{
	char infix[EXPSIZE]={0};			//存储用户输入的中缀表达式
	char postfix[EXPSIZE]={0};		//存储转换生成的后缀表达式
	printf("请输入中缀表达式：%s \n",infix);
	gets(infix);				//从输入流读入中缀表达式
	if(!IsLegal(infix))
	{
		printf("异常：中缀表达式中存在非法字符! \n");
		while(1);
		return;
	}
	InfixToPostfix(infix,postfix);
	printf("%s===>%s\n",infix,postfix);//取栈顶元素，得结果输出
	while(1);
}