/* This code is from "Algorithms in C, Third Edition, by Robert Sedgewick, Addison-Wesley, 1998. */

#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

typedef struct STnode* link;
struct STnode
{
  Item item;
  link l, r;
  int N;
};

static link head, z;

link NEW(Item item, link l, link r, int N)
  { link x = malloc(sizeof *x);
    x->item = item; x->l = l; x->r = r; x->N = N;
    return x;
  }

/* initialization operation */
void STinit()
  { head = (z = NEW(NULLitem, NULL, NULL, 0)); }


/* search operation */
Item searchR(link h, Key v)
  { Key t = key(h->item);
    if (h == z) return NULLitem;
    if eq(v, t) return h->item;
    if less(v, t) return searchR(h->l, v);
             else return searchR(h->r, v);
  }

Item STsearch(Key v)
  { return searchR(head, v); }

/* recursive insert operation */
link insertR(link h, Item item)
  { Key v = key(item), t = key(h->item);
    if (h == z) return NEW(item, z, z, 1);
    if less(v, t)
         h->l = insertR(h->l, item);
    else h->r = insertR(h->r, item);
    (h->N)++; return h;
  }

void STinsert(Item item)
  { head = insertR(head, item); }


/* rotation auxiliary functions */
link rotR(link h)
  { link x = h->l; h->l = x->r; x->r = h;
    return x; }

link rotL(link h)
  { link x = h->r; h->r = x->l; x->l = h;
    return x; }


/* sort operation */
void sortR(link h, void (*visit)(Item))
  {
    if (h == z) return;
    sortR(h->l, visit);
    visit(h->item);
    sortR(h->r, visit);
  }

void STsort(void (*visit)(Item))
  { sortR(head, visit); }


/* partition auxiliary function */
link partR(link h, int k)
  { int t = h->l->N;
    if (t > k )
      { h->l = partR(h->l, k); h = rotR(h); }
    if (t < k )
      { h->r = partR(h->r, k-t-1); h = rotL(h); }
    return h;
  }

/* recursive deletion operation */
link joinLR(link a, link b)
  {
    if (b == z) return a;
    b = partR(b, 0); b->l = a;
    return b;
  }


 void STdelete(Key v)
 {
   link *h=&head,x;
   Key t;
   while(1)
   {
     t=key((*h)->item);
     if (less(v, t))
       h = &((*h)->l);
     else if (less(t, v))
       h = &((*h)->r);
     else
     {
       x = *h;
       *h = joinLR((*h)->l, (*h)->r);
       //printf("\n");
       //STsort(ITEMshow);
       free(x);
       break;
     }
   }
 }
