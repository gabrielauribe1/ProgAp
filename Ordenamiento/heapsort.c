//heapsort

#include<stdio.h>
#include<string.h>

void makeheap(int x[], int n);
void heapsort(int x[], int n);


 int main (void)
 {
   int m[]={25, 2, 7, 3, 67, 43, 1, 15, 9, 32};
   int i;

   makeheap(m, 10);
   printf("Arreglo original\n");
   for(i=0; i<10; i++)
     printf("%d\n", m[i]);

   heapsort(m, 10);
   printf("Arreglo ordenado\n");
   for(i=0; i<10; i++)
     printf("%d\n", m[i]);
 }

void makeheap(int x[], int n)
{
  int i, val, s, f;

  for(i=1; i<n; i++)
    {
      val = x[i];
      s = i;
      f = (s-1)/2;
      while(s>0 && x[f]<val)
	{
	  x[s] = x[f];
	  s = f;
	  f = (s-1)/2;
	}
      x[s]=val;
    }
}

void heapsort(int x[], int n)
{
  int i, s, f, ivalue;

  for(i=n-1; i>0; i--)
    {
      ivalue = x[i];
      x[i]=x[0];
      f=0;
      if(i == 1)
	s=-1;
      else
	s=1;
      if(i>2 && x[2] > x[1])
	s=2;
      while(s>=0 && ivalue < x[s])
	{
	  x[f]=x[s];
	  f=s;
	  s=2 * f + 1;
	  if(s+1<=i-1 && x[s]<x[s+1])
	    s++;
	  if(s > i-1)
	    s = -1;
	}
      x[f] = ivalue;
    }
}
