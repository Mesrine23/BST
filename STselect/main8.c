#include <stdio.h>
#include <stdlib.h>
#include "mods8.h"
#include "Item.h"


int main(int argc, char* argv[])
{
  int *N;
  int i,k;

  N = malloc((argc-1)*sizeof(int));

  for(i=0 ; i<argc-1 ; ++i)
  {
    N[i] = atoi(argv[i+1]);
    printf("%d ",N[i]);
  }
  printf("\n\n");

  printf("Give *k* for smallest k-th item\n");
  scanf("%d",&k);
  printf("\n");
  if(k>argc-1)
    printf("Tree has less nodes than %d\n\n",k);
  else
    printf("The needed key is %d\n\n",Fselect(N,argc-1,k-1));

}
