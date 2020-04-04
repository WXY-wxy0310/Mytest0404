#include"linkstack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int isnum1(char a)
{
	return (a >= '0'&&a <= '9');
}
int isopera1(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/')
	{
		return 1;
	}
	return 0;
}
void output1(char c)
{
	printf("%c", c);
}

int value(char c)
{
	return c - '0';
}
int resop(int left, int right, char c)
{
	int ret = 0;
	switch (c)
	{
	case'+':
		ret = left + right;
		return ret;
		break;
	case'-':
		ret = left - right;
		return ret;
		break;
	case'/':
		ret = left / right;
		return ret;
		break;
	case'*':
		ret = left * right;
		return ret;
		break;
	default:
		return 0;
		break;
	}
}
void result(const char *node)
{
	Stacklink *stacklink = Stacklink_create();
	int i = 0;
	int left = 0;
	int right = 0;
	int res = 0;
	int ret = 0;
	while (node[i] != '\0')
	{
		if (isnum1(node[i]))
		{
			Stacklink_insert(stacklink, (void *)value(node[i]));
		}
		else if (isopera1(node[i]))
		{
			right = (int)Stacklink_pop(stacklink);
			left= (int)Stacklink_pop(stacklink);
			res = resop(left, right, node[i]);
			
			Stacklink_insert(stacklink, (void *)res);
		}
		else
		{
			printf("expression");
			break;
		}
		i++;
	}
	while (node[i] == '\0'&&Stacklink_size(stacklink) == 1)
	{
		ret=(int)Stacklink_pop(stacklink);
	}
	Stacklink_destory(stacklink);
	printf("%d", ret);
}
void main()
{
	char *node = "194-5*+";
	result(node);
	system("pause");
}