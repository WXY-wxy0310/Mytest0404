#include"linkstack.h"
#include"linklist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct TLinkstack
{
	LinklistNode node;
	void *item;
}TLinkstack;
Stacklink* Stacklink_create()
{
	return linklist_create();
}
void Stacklink_destory(Stacklink *stacklink)
{
	Stacklink_clear(stacklink);
	linlist_destory(stacklink);
	return;
}
void Stacklink_clear(Stacklink *stacklink)
{
	if (stacklink == NULL)
	{
		return;
	}
	while (Stacklink_size(stacklink) > 0)
	{
		Stacklink_pop(stacklink);
	}
	return;
}
int Stacklink_insert(Stacklink *stacklink, void *item)
{
	TLinkstack *tmp = NULL;
	tmp = (TLinkstack *)malloc(sizeof(TLinkstack));
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0, sizeof(TLinkstack));
	tmp->item = item;
	//int linlist_insert(Linklist *list, LinklistNode *node, int pos);
	int ret = linlist_insert(stacklink, tmp, 0);
	if (ret != 0)
	{
		ret = -3;
		if (tmp != NULL)
		{
			free(tmp);
		}
		return ret;
	}
	return ret;
}
void *Stacklink_pop(Stacklink *stacklink)
{
	TLinkstack *tmp = NULL;
	tmp = linklist_delete(stacklink, 0);
	if (tmp == NULL)
	{
		return -1;
	}
	void *item = NULL;
	item = tmp->item;
	free(tmp);

	return item;
}
void * Stacklink_top(Stacklink *stacklink)
{
	TLinkstack *tmp = NULL;
	tmp = linklist_get(stacklink, 0);
	if (tmp == NULL)
	{
		return -1;
	}

	return tmp->item;
}
int Stacklink_size(Stacklink *stacklink)
{
	
	return linlist_length(stacklink);
}
