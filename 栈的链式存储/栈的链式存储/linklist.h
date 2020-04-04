#ifndef _MYLINK_k
#define _MYLINK_k
typedef void Linklist;
typedef struct LinklistNode
{
	struct LinklistNode *next;
}LinklistNode;
Linklist * linklist_create();
void linlist_destory(Linklist *list);
void linlist_clear(Linklist *list);
int linlist_length(Linklist *list);
int linlist_insert(Linklist *list, LinklistNode *node, int pos);
LinklistNode * linklist_get(Linklist *list, int pos);
LinklistNode * linklist_delete(Linklist *list, int pos);
#endif // !_MYLINK_k

