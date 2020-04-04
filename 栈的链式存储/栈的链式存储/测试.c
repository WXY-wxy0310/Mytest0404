#include"linkstack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main00()
{
	Stacklink *stacklink = NULL;
	stacklink = Stacklink_create();
	int a[10];
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		Stacklink_insert(stacklink, &a[i]);
	}
	printf("%d\n", Stacklink_size(stacklink));
	printf("%d\n", *(int *)Stacklink_top(stacklink));
	while (Stacklink_size(stacklink) > 0)
	{
		int p = *(int *)Stacklink_pop(stacklink);
		printf("%d   ", p);
	}
	Stacklink_destory(stacklink);
	system("pause");
}