#include <stdio.h>
#include <stdlib.h>
#include "mods10.h"
#include "Item.h"


void main(int argc, char *argv[])
{

  STinit();

  int i,prob;

  for(i=1 ; i<argc ; ++i)
  {
    STinsert(atoi(argv[i]));
    //printf("%d ",atoi(argv[i]));
  }
  printf("\n\n");

  printf("The keys in sorted order are: ");
  STsort(ITEMshow);
  printf("\n\n");

  printf("Frequency of each Key in the BST:\n\n");
  KeyFrequency(argc-1);

}
