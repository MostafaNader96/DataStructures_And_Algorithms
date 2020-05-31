#include <stdio.h>
#include <conio.h>

void selectionsort(int *arr,int N);
void bubblesort(int *arr,int N);
void mergesort(int *arr,int N);
void merge(int *arr, int *l,int lcount, int *r, int rcount);
void swap(int *a, int *b);

void main()
{
 int select,i;
 int arr[10]={5,9,3,2,1,7,9,6,3,4};
 clrscr();
 printf("\nPress 1 for selection sorting: \nPress 2 for bubble sorting: \nPress 3 for merge sorting: \nYour selection: ");
 scanf("%d",&select);
 while(1)
 {
  if(select==1)
  {
  selectionsort(arr,10);
  break;
  }
  if(select==2)
  {
  bubblesort(arr,10);
  break;
  }
  if(select==3)
  mergesort(arr,10);
  break;
 }

  for(i=0;i<10;i++)
  {
  printf("Element %d = %d\n",i+1,arr[i]);
  }
  getch();

}

void selectionsort(int *arr, int N)
{
 int i,j,index;
 for(i=0;i<(N-1);i++)
 {
 index=i;
 for(j=i+1;j<N;j++)
 {
 if(arr[j]<arr[index])
 index=j;
 }
 swap(&arr[i],&arr[index]);
}
}

void bubblesort(int *arr, int N)
{
  int i,j,sorted=0;
  for(i=0;i<N-1 && !sorted; i++)
  {
  sorted=1;
  for(j=N-1;j>i;j--)
  {
  if(arr[j]<arr[j-1])
  {
  swap(&arr[j],&arr[j-1]);
  sorted=0;
  }
  }
  }
}

void mergesort(int *arr, int N)
{
int mid,i,*l,*r;
if(N<2) return;
mid=N/2;

l=(int *)malloc(mid*sizeof(int));
r=(int *)malloc((N-mid)*sizeof(int));

for(i=0;i<mid;i++)
{
l[i]=arr[i];
}

for(i=mid;i<N;i++)
{
r[i-mid]=arr[i];
}

mergesort(l,mid);
mergesort(r,(N-mid));
merge(arr,l,mid,r,(N-mid));
free(l);
free(r);
}

void merge(int *arr, int *l,int lcount, int *r, int rcount)
{
int i=0,j=0,k=0;
while(i<lcount && j<rcount)
{
if(l[i]<r[j])
{
arr[k]=l[i];
i++;
k++;
}
else
{
arr[k]=r[j];
j++;
k++;
}
}

while(i<lcount)
{
arr[k]=l[i];
k++;
i++;
}

while(j<rcount)
{
arr[k]=r[j];
k++;
j++;
}
}

void swap(int *a,int *b)
{
 int temp;
 temp=*a;
 *a=*b;
 *b=temp;
}
