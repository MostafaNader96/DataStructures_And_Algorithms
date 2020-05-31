#include <stdio.h>
#include <conio.h>
#define N 5

struct employee
{
 int id;
 char name[20];
 char address[20];
};

void swap(int *a,int *b);

void main()
{ char namee[20];
  int x,idser;
  struct employee emp[5];
  int temp;
  char tempp[20];
  char temppp[20];
  int i,j,sel,sorted=0;
  clrscr();

  for(i=0;i<5;i++)
  {
  printf("Enter employee number %d name: ",i+1);
  scanf("%s",emp[i].name);
  printf("Enter employee number %d id: ",i+1);
  scanf("%d",&emp[i].id);
  printf("Enter employee number %d address: ",i+1);
  scanf("%s",emp[i].address);
  }


  for(i=0;i<N-1 && !sorted;i++)
  {
  sorted=1;
  for(j=N-1;j>i;j--)
  {
  if(emp[j].id<emp[j-1].id);
  {
 // swap(&emp[j].id,&emp[j-1].id);
  temp=emp[j].id;
  emp[j].id=emp[j-1].id;
  emp[j-1].id=temp;


  strcpy(tempp,emp[j].name);
  strcpy(emp[j].name,emp[j-1].name);
  strcpy(emp[j-1].name,tempp);

  strcpy(temppp,emp[j].address);
  strcpy(emp[j].address,emp[j-1].address);
  strcpy(emp[j-1].address,temppp);


  sorted=0;
  }
  }
  }

   printf("\n\nname            id            address\n");
  for(i=0;i<5;i++)
  {

  printf(" %s             %d                  %s\n",emp[i].name,emp[i].id,emp[i].address);

  }
  getch();




}


void swap(int *a,int *b)
{
 int temp;
 temp=*a;
 *a=*b;
 *b=temp;
}
