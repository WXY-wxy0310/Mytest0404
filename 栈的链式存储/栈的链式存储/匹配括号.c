#include"linkstack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isleft(char p)
{
	int ret = 0;
	switch (p)
	{
	case '<':
	case '[':
	case '{':
	case '(':
		ret = 1;
		break;
	default:
		ret = 0;
	}
	return ret;
}
int isright(char p)
{
	int ret = 0;
	switch (p)
	{
	case '>':
	case ']':
	case '}':
	case ')':
		ret = 1;
		break;
	default:
		ret = 0;
	}
	return ret;
}
int isstrcmp2(char left,char right)
{
	int ret = 0;
	switch (left)
	{
	case '<':
		if (right == '>')
			ret = 1;
		break;
	case '[':
		if (right == ']')
			ret = 1;
		break;
	case '{':
		if (right == '}')
			ret = 1;
		break;
	case '(':
		if (right == ')')
			ret = 1;
		break;
	default:ret = 0;
	}
	return ret;
}
void search(char *node)
{
	Stacklink *stacklink = NULL;
	stacklink = Stacklink_create();
	int i = 0;
	while (node[i] != '\0')
	{
		if (isleft(node[i]))
		{
			Stacklink_insert(stacklink, &node[i]);
		}
		if (isright(node[i]))
		{
			char c = *(char *)Stacklink_top(stacklink);
			if (c == NULL || !isstrcmp2(c,node[i]))
			{
				printf("error ²»Æ¥Åä%c\n", c);
				break;
			}
		}
		i++;
	}
	if (Stacklink_size(stacklink) == 0 && node[i] == '\0')
	{
		printf("ok\n");
	}
	else
	{
		printf("error");
		while (Stacklink_size(stacklink) > 0)
		{
			char p = *(char *)Stacklink_pop(stacklink);
			printf("%c   ", p);
		}
	}
	Stacklink_destory(stacklink);
}
void main1()
{
	char *node = "#include<stdio.h> void main({int a=0;int b[3],c[4];hello;}";
	search(node);
	system("pause");
}