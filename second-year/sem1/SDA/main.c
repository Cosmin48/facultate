#include  "timer.h"
#include <stdio.h>
#include <stdlib.h>

int a[2000000],n;
void citire()
{
   FILE *f=fopen("numere.txt","r");
   int i;
   n=10000;
   for(i=0;i<n;i++)
        fscanf(f,"%d",&a[i]);
}

void shakersort()
{
    int j,ultim,sus,jos;
    int temp;
    sus= 1; jos= n-1; ultim= n-1;
    do {
      for( j= jos; j >= sus; j --)
     {
         if (a[j-1]>a[j])
        {
          temp= a[j-1]; a[j-1]= a[j]; a[j]= temp;
          ultim= j;
        }
      }
      sus= ultim+1;
      for( j=sus; j <= jos; j ++)
     {
      if (a[j-1]>a[j])
        {
          temp=a[j-1]; a[j-1]=a[j]; a[j]=temp;
          ultim=j;
        }
      }
    jos=ultim-1;
  } while (!(sus>jos));
}




int main()
{ float timp;
FILE *fout;
fout=fopen("afisare_numere.txt","w");
if(!fout)
    exit(EXIT_FAILURE);
int i;
for( i=1;i<=10;i++)
{
n=1000*i;
citire();
starton();
shakersort();
timp=startoff();
fprintf(fout,"BS,%d,%f\n",n,timp);
}
return 0;
}
