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
/* ------------------------ */


/* insertion operation */
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
/* ------------------- */


/* -------------- */
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
/* -------------- */


/* select operation */
Item selectR(link h, int k)
  {
    int t;
    if (h == z) return NULLitem;
    t = (h->l == z) ? 0 : h->l->N;
    if (t > k) return selectR(h->l, k);
    if (t < k) return selectR(h->r, k-t-1);
    return h->item;
  }

Item STselect(int k)
  { return selectR(head, k); }
/* ---------------- */

/* FREQUENCY FUNCTION */
void KeyFrequency(int n)
{
  int i,k=0,test;
  int **p; // 2d board

  p = malloc(n*sizeof(int *));
  if (p==NULL)
  {
  	printf ("ERROR: Malloc returned NULL");
  	return;
  }

  for (i=0 ; i<n ; ++i)
  {
  	p[i] = malloc(2*sizeof(int));
  	if (p[i]==NULL)
  	{
  		printf ("ERROR: Malloc returned NULL");
  		return;
	   }
  }



  k=0;
  p[0][0] = STselect(0);
  p[0][1] = 1;
  for(i=1 ; i<n ; ++i)
  {

    test = STselect(i);

    if(test == (p[k][0]))
      { ++p[k][1]; }
    else
    {
      ++k;
      p[k][0] = test;
      p[k][1] = 1;
    }

  }


  for(i=0 ; i<=k ; ++i)
  {
    printf("%d -> %d\n",p[i][0],p[i][1]);
  }
  printf("\n");


}

/* ------------------ */
