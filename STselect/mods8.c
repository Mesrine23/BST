#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "mods8.h"

typedef struct STnode* link;
struct STnode
{
  Item item;
  link l, r;
  int N;
};

static link head, z;

////////////////////////////////////////////////////////////////////////////////
link NEW(Item item, link l, link r, int N)
{
  link x = malloc(sizeof *x);
  x->item = item;
  x->l = l;
  x->r = r;
  x->N = N;
  return x;
}


link insertR(link h, Item item)
{
  Key v = key(item), t = key(h->item);
  if (h == z) return NEW(item, z, z, 1);
  if less(v, t)
    h->l = insertR(h->l, item);
  else
    h->r = insertR(h->r, item);
  (h->N)++; return h;
}



void STinsert(Item item)
  { head = insertR(head, item); }



void STinit()
  { head = (z = NEW(NULLitem, NULL, NULL, 0)); }

////////////////////////////////////////////////////////////////////////////////


int Fselect(int *N, int n, int k)
{

  STinit();

  int t,i;
  link h;

  for(i=0 ; i<n ; ++i)
  {
    STinsert(N[i]);
  }

  t=head->N;
  h=head;

  while (t!=k)
  {
    if((h->l)==NULL)
      t=0;
    else
      t=h->l->N;

    if (t>k)
      h = h->l;
    else if (t<k)
    {
      h=h->r;
      k=k-t-1;
    }
  }
  //printf("The needed key is %d\n\n",h->item);
  return h->item;

}
