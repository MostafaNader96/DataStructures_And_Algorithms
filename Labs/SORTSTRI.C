#include <stdio.h>
#include <conio.h>
#define N 5




void main()
{
  char arr[5][20]={"waleed","ali","yousef","beshoy","ahmed"};
  char temp[1][20];
  int x,i,j,index;
  clrscr();
  for(i=0;i<(N-1);i++)
  {
  index=i;
  for(j=i+1;j<N;j++)
  {
  x=strcmp(arr[j],arr[index]);
  if(x<0)
  index=j;
  }

  strcpy(temp,arr[i]);
  strcpy(arr[i],arr[index]);
  strcpy(arr[index],temp);
  }

  for(i=0;i<N;i++)
  {
  printf("%s\n",arr[i]);
  }

  getch();




}