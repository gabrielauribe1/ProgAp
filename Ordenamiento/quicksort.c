// quicksort
#include<stdio.h>
#include<string.h>

void quicks(int a[], int left, int right);
int partition(int a[], int left, int right);

int main (void)
{
  int m[]={25, 2, 7, 3, 67, 43, 1, 15, 9, 32};
  int i;

  printf("Arreglo original\n");
  for(i=0; i<10; i++)
    printf("%d\n", m[i]);
  printf("Arreglo ordenado\n");
  quicks(m, 0, 9);
  for(i=0; i<10; i++)
    printf("%d\n", m[i]);
}
void quicks(int a[], int left, int right)
{
  int j;

  if(left<right)
    {
      j=partition(a, left, right);
      quicks(a, left, j-1);
      quicks(a, j+1, right);
    }
}
int partition(int a[], int left, int right)
{
  int pivot, i, j, t;

  pivot = a[left];
  i=left;
  j=right+1;

  while(1)
    {
      do
	++i;
      while ((a[i] <= pivot) && (i<=right));
      do
	--j;
      while(a[j]>pivot);
      if(i >= j)
	break;
      t=a[i];
      a[i]=a[j];
      a[j]=t;
    }
  t=a[left];
  a[left]=a[j];
  a[j]=t;
  return j;
}
