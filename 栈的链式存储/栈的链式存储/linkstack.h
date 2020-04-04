#ifndef _STACKLINK_
#define _STACKLINK_
typedef void Stacklink;

Stacklink* Stacklink_create();
void Stacklink_destory(Stacklink *stacklink);
void Stacklink_clear(Stacklink *stacklink);
int Stacklink_insert(Stacklink *stacklink, void *item);
void *Stacklink_pop(Stacklink *stacklink);
void * Stacklink_top(Stacklink *stacklink);
int Stacklink_size(Stacklink *stacklink);
#endif // !_STACKLINK_
