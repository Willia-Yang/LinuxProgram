#include "ch13.h"
pthread_rwlock_t rw=PTHREAD_RWLOCK_INITIALIZER;
struct list { 
   struct list *next;
   struct list *prev;
   int id;
};
struct list *list_head = NULL;
void list_add(struct list *add)
{
   struct list *curr, *prev;
   int rv;
   rv = pthread_rwlock_wrlock(&rw);   // 加新项将更新表，因此以写方式申请读写锁 
   check_error(rv, "add: write lock");
   if (list_head == (struct list *)NULL){ // 空表，插入第一项
      list_head = add;
      add->prev = add->next = NULL;
   } else {
      for (curr=list_head; curr !=NULL; curr=curr->next){ // 找出插入点 
         if (curr->id > add->id) 
            break;
         prev = curr;
      }
      if (curr == NULL){ //插入位置在表尾
         add->next = NULL;
         add->prev = prev;
         prev->next = add;
      } else {           //插入位置在表中间
         add->next = curr;
         add->prev = prev;
         prev->next = add;
         curr->prev = add;
      }
   }
   rv = pthread_rwlock_unlock(&rw);   /* 释放读写锁 */
   check_error(rv, "add: write unlock");
}
struct list * list_lookup(int lookup_id)
{
   struct list *curr;
   int rv;
   rv=pthread_rwlock_rdlock(&rw);   // 只读表，因此以读方式申请读写锁 
   check_error(rv, "lookup: read lock");
   for (curr=list_head; curr !=NULL; curr=curr->next) // 查找表项位置 
         if (curr->id >= lookup_id) 
            break;
   if (curr != NULL && curr->id != lookup_id)
      curr = (struct list *)NULL;    // 没有找到
   rv = pthread_rwlock_unlock(&rw);   // 释放读写锁 
   check_error(rv, "add: write unlock");
   return (curr);
}
