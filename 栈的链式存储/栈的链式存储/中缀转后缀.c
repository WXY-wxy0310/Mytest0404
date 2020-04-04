#include"linkstack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int prim(char a)
{
	if (a == '+' || a == '-')
	{
		return 2;
	}
	if (a == '(')
	{
		return 1;
	}
	if (a == '*' || a == '/')
	{
		return 3;
	}
}
int isstrcmp(char left, char right)
{
	int ret = 0;
	switch (left)
	{
	case '(':
		if (right == ')')
			ret = 1;
		break;
	default:ret = 0;
	}
	return ret;
}
int isnum(char a)
{
	return (a >= '0'&&a <= '9');
}
int isopera(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/')
	{
		return 1;
	}
	return 0;
}
void output(char c)
{
	printf("%c", c);
}
int isleft1(char c)
{
	if (c == '(')
		return 1;
	return 0;
}
int isright1(char c)
{
	if (c == ')')
		return 1;
	return 0;
}
void tranfrom(const char *node)
{
	Stacklink *stacklink = Stacklink_create();
	int i = 0;

	while (node[i] != '\0')
	{
		if (isnum(node[i]))
		{
			output(node[i]);
		}
		else if (isopera(node[i]))
		{
			
			while (Stacklink_size(stacklink) > 0 && prim(node[i]) <= prim((char)(int)Stacklink_top(stacklink)))
			{
				output((char)(int)Stacklink_pop(stacklink));
			}
			Stacklink_insert(stacklink, (void *)(int)node[i]);
		}
		else if (isleft1(node[i]))
		{
			Stacklink_insert(stacklink, (void *)(int)node[i]);
		}
		else if (isright1(node[i]))
		{
			if (Stacklink_size(stacklink) > 0)
			{
				while (!isleft1((char)(int)Stacklink_top(stacklink)))
				{
					output((char)(int)Stacklink_pop(stacklink));
				}
			}
			Stacklink_pop(stacklink);
		}
		else
		{
			printf("expression");
			break;
		}
		i++;
	}
	while (node[i] == '\0'&&Stacklink_size(stacklink) > 0)
	{
		output((char)(int)Stacklink_pop(stacklink));
	}
	Stacklink_destory(stacklink);
}
void main12()
{
	char *node = "1+(9-4)*5";
	tranfrom(node);
	system("pause");
}