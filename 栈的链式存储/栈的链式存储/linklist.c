#include"linklist.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct Tlinklist
{
	LinklistNode phead;
	int len;
}Tlinklist;
Linklist * linklist_create()
{
	Tlinklist *tlist = NULL;
	tlist = (Tlinklist *)malloc(sizeof(Tlinklist));
	memset(tlist, 0, sizeof(Tlinklist));
	tlist->len = 0;
	tlist->phead.next = NULL;
	return tlist;
}
void linlist_destory(Linklist *list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
}
void linlist_clear(Linklist *list)
{
	Tlinklist *tlist = NULL;
	if (list == NULL)
	{
		printf("linlist_clear error");
	}
	tlist = (Tlinklist *)list;
	tlist->len = 0;
	tlist->phead.next = NULL;
}
int linlist_length(Linklist *list)
{
	Tlinklist *tlist = NULL;
	if (list == NULL)
	{
		printf("linlist_clear error");
	}
	tlist = (Tlinklist *)list;
	return tlist->len;
}
int linlist_insert(Linklist *list, LinklistNode *node, int pos)
{
	Tlinklist *tlist = NULL;
	if (list == NULL)
	{
		printf("linlist_clear error");
		return -1;
	}
	tlist = (Tlinklist *)list;
	LinklistNode *cur = NULL;
	cur = &(tlist->phead);
	int i = 0;
	for (i = 0; i < pos&&(cur->next!=NULL); i++)
	{
		cur = cur->next;
	}
	node->next = cur->next;
	cur->next = node;
	tlist->len++;
	return 0;
}
LinklistNode * linklist_get(Linklist *list, int pos)
{
	Tlinklist *tlist = NULL;
	if (list == NULL)
	{
		printf("linlist_clear error");
		return NULL;
	}
	tlist = (Tlinklist *)list;
	LinklistNode *cur = NULL;
	cur = &(tlist->phead);
	int i = 0;
	for (i = 0; i < pos && (cur->next != NULL); i++)
	{
		cur = cur->next;
	}
	return cur->next;
}
LinklistNode * linklist_delete(Linklist *list, int pos)
{
	Tlinklist *tlist = NULL;
	if (list == NULL)
	{
		printf("linlist_clear error");
		return NULL;
	}
	tlist = (Tlinklist *)list;
	LinklistNode *cur = NULL;
	LinklistNode * tmp = NULL;
	cur = &(tlist->phead);
	int i = 0;
	for (i = 0; i < pos && (cur->next != NULL); i++)
	{
		cur = cur->next;
	}
	tmp = cur->next;
	cur->next = tmp->next;
	tlist->len--;
	return tmp;
}