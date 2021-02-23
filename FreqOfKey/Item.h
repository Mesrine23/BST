/* This code is from "Algorithms in C, Third Edition, by Robert Sedgewick, Addison-Wesley, 1998. */

typedef int Item;
typedef int Key;

#define NULLitem -1 /* NULLitem is a constant */
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))

Item ITEMrand(void);
int ITEMscan(Item *);
void ITEMshow(Item);
