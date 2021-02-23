#include <stdio.h>
#include <stdlib.h>
#include "mods9.h"
#include "Item.h"


void main(int argc, char *argv[])
{

  STinit();

  int i,k;

  for(i=1 ; i<argc ; ++i)
  {
    STinsert(atoi(argv[i]));
    //printf("%d ",atoi(argv[i]));
  }
  printf("\n\n");

  printf("The keys in sorted order are: ");
  STsort(ITEMshow);
  printf("\n\n");

  printf("Give the key you want to delete\n");
  scanf("%d",&k);
  printf("\n");

  if(STsearch(k)==NULLitem)
  {
    printf("This node does not exist in the BST\n\n");
  }
  else
  {
    STdelete(k);
    printf("The keys  in sorted order AFTER DELETION are: ");
    STsort(ITEMshow);
    printf("\n\n");
  }

}
