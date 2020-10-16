#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#define STACKSIZE 20   //��ջ������
#define ITEMSIZE 20    //���ʽ��Ԫ�ص���󳤶�
#define EXPSIZE 200    //���ʽ����󳤶�
#define FLASE 0
#define TURE 1

//�жϱ��ʽ���Ƿ���ڷǷ��ַ����Ϸ��ַ�������P��Q��R��^,v,���Ϳո�
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

//�ӱ��ʽ��ǰλ��curPos��ȡһ��Ԫ�أ���ȡ֮��curPos�ƶ�����һ��Ԫ�����ַ�λ��
//�����쳣����-1������ǰԪ��Ϊ���������򷵻�0����Ϊ���������򷵻�1
int GetItem(char *postfix,int *curPos,char *item)
{
	int i=0,k=*curPos,flag;
	if(postfix[k]=='P'||postfix[k]=='Q'||postfix[k]=='R')		//��ǰԪ��Ϊ��ĸ
	{
		while(postfix[k]=='P'||postfix[k]=='Q'||postfix[k]=='R')
			item[i++]=postfix[k++];
		item[i]='\0';
		flag=0;
	}
	else				//��ǰԪ��Ϊ������
	{
		item[0]=postfix[k++];
		item[1]='\0';
		flag=1;
	}
	while(postfix[k]==' ')		//������ǰԪ�غ���Ŀո��´�ȡԪ�ص���ʼλ��Ϊ�ǿ��ַ�
		k++;
	*curPos=k;
	return flag;
}

//��ȡ��������ջ�����ȼ�
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
		printf("��׺���ʽ��֧�ֲ�����%c\n",c);
		exit(0);
	}
}

//��ȡ��������ջ�����ȼ�
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
		printf("��׺���ʽ��֧�ֲ�����%c",c);
		exit(0);
	}
}

//����׺���ʽinfixת��Ϊ��׺���ʽpostfix����׺���ʽ������Ԫ���ÿո�ֿ�
void InfixToPostfix(char *infix,char *postfix)
{
	Stack S;
	char item[ITEMSIZE];			//�洢��׺���ʽ
	int flag=-1;				//��ʶ��ǰɨ��Ԫ�ص����ͣ����������Ϊ1�����������Ϊ0�������쳣���Ϊ-1
	int curPos=0;			//��¼��ǰɨ��Ԫ�ص����ַ��±�λ��
	int k=0,i,h;
	char ch,curOP;

	while(infix[curPos]==' ')		//����infix��ǰ������пո�
		curPos++;
	Create(&S,STACKSIZE);		//������ջ����̬����STACKSIZE��С�Ŀռ�
	Push(&S,'#');
	while(curPos<strlen(infix))
	{
		flag=GetItem(infix,&curPos,item);		//��ȡ��ǰɨ����ʽ��Ԫ��
		if(flag==-1)
		{
			printf("�쳣����׺���ʽԪ�ز��Ϸ���\n");
			exit(0);
		}
		else if(flag==1)
		{
			curOP=item[0];		//curOPΪ��ǰɨ��Ĳ�����
			if(curOP=='>')		//ɨ�赽>ʱ�Ĵ���
			{
				h=k+2;
				postfix[h]=curOP;
				
			}
			else			//ɨ�赽����������ʱ�Ĵ���
			{
				Top(&S,&ch);			//��ȡ��ǰջ��������
				while(ICP(curOP)<=ISP(ch))
				{
					Pop(&S);
					postfix[k++]=ch;
					//postfix[k++]=' ';		//����Ԫ���ÿո�ָ�
					Top(&S,&ch);			//��ȡ��ǰջ��������
				}
				Push(&S,curOP);			//��ǰɨ��Ĳ�������ջ
		   }
		}
		else			//��ǰԪ��Ϊ��������ֱ�����
		{
			for(i=0;i<strlen(item);i++,k++)
				postfix[k]=item[i];
			//postfix[k++]=' '	;		//����Ԫ���ÿո�ָ�
		}
		if(postfix[k]=='>')
		k+=1;
	}
	
	while(!IsEmpty(&S))			//���ջ��ʣ�������
	{
		Top(&S,&ch);
		Pop(&S);
		if(ch!='#')
		{
			postfix[k++]=ch;
			//postfix[k++]=' ';		//����Ԫ���ÿո�ֿ�
		}
	}
	postfix[++k]='\0';//ȥ�����һ������Ŀո�
}


void main()
{
	char infix[EXPSIZE]={0};			//�洢�û��������׺���ʽ
	char postfix[EXPSIZE]={0};		//�洢ת�����ɵĺ�׺���ʽ
	printf("��������׺���ʽ��%s \n",infix);
	gets(infix);				//��������������׺���ʽ
	if(!IsLegal(infix))
	{
		printf("�쳣����׺���ʽ�д��ڷǷ��ַ�! \n");
		while(1);
		return;
	}
	InfixToPostfix(infix,postfix);
	printf("%s===>%s\n",infix,postfix);//ȡջ��Ԫ�أ��ý�����
	while(1);
}