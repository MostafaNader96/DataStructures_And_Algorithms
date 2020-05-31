#include <stdio.h>
#include <conio.h>

void main()
{
  int arr[15];
  int s,i,flag;
  clrscr();
  for(i=0;i<15;i++)
  {
  printf("Enter value #%d in the array",i);
  scanf("%d",&arr[i]);
  }
  printf("\n\nEnter the value that u want to search for: ");
  scanf("%d",&s);

  for(i=0;i<15;i++)
  {
  if(s==arr[i])
  {
   break;
  }
  else
  {
  if(i==14)
  {
  flag=0;
  }
  }
  }


  if(flag==0)
  printf("\nNot Found!");
  else
  printf("\nThe value is in index %d in the array ",i);


  getch();




}