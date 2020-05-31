#include <stdio.h>
#include <conio.h>
#define up 72
#define down 80
#define enter 13
#define esc   27


/*typedef struct employee
{
 char name[20];
 int id;
}employee;*/

typedef struct stack
{
int tos,size;
int *stk;
}stack;



int initstack(stack *s,int size);
int isemptystack(stack *s);
int isfullstack(stack *s);
int push(stack *s,int data);
int pop(stack *s,int *data);


void main()
{
  int col=20,row=3;
  int i,pos=0;
  int flag,x,y;
  int pushf,popf;
  char key;
  stack *s;
  //stack *temp;

  char menu[3][10]={"ADD","Delete","Exit"};
  initstack(s,4);


	while(1)
  {					//start while(1)
  clrscr();
  textcolor(CYAN);
  gotoxy(col,row);
  printf("%c%c",45,62);
  textcolor(CYAN);
  cprintf("ADD");


  gotoxy(col,row+1);
  textcolor(RED);
  cprintf("%c%c",45,62);
  cprintf("Delete");


  gotoxy(col,row+2);
  textcolor(BLUE);
  cprintf("%c%c",45,62);
  cprintf("Exit");

  row=3;
  for(i=0;i<3;i++)
  {
  if(i==pos)
  {
  gotoxy(col,row+i);
  textattr(0x70);
  cprintf("%c%c",45,62);
  cprintf("%s",menu[i]);
  textattr(0x07);
  }
  }
   flushall();

  key=getch();
  switch(key)
  {            //start of switch on first key
  case NULL:
  key=getch();
  switch(key)
  {			   //start of swicth on 2nd key
  case up:
  pos--;
  if(pos<0) pos=2;
  break;
  case down:
  pos++;
  if(pos>2) pos=0;
  break;
  }           //end of switch on 2nd key
  break;

  case enter:
  switch(pos)
  {
  case 0:
  clrscr();
  printf("Enter an integer to push!");
  scanf("%d",&x);
  pushf=push(s,x);
  if(pushf==1)
  printf("\n\nPushed successfully :)");
  if(pushf==0)
  printf("\n\nSTACK FULL! ");
 // printf("\ added succsessfully!\n");
  getch();
  break;

  /*case 1:
  clrscr();
  temp=createnode();
  datanode(temp);
  insertnode(ll,temp);
  printf("\nNode inserted succesfully!!\n");
  getch();

  break;*/

  case 1:
  clrscr();
  popf=pop(s,&y);
  if(popf==1)
  printf("\nPOPPED!");
  if(popf==0)
  printf("\nStack Empty!");
  getch();
  break;

  /*case 3:
  clrscr();
  temp=s
  for(i=0;i<(s->tos);i++)
  {
  printf("%s\n%d",temp->stk->name,temp->stk->id);
  }
  getch();
  break;*/

  /*case 4:
  clrscr();
  temp=ll->start;
  while(temp!=NULL)
  {
  printf("Name: %s\nID: %d\n",temp->name,temp->id);
  temp=temp->next;
  }
  getch();
  break;*/

  case 2:
  clrscr();
  printf("Exit mode! Press any key to terminate ");
  getch();
  exit();
  break;
  }
  break;

  case esc:
  exit();
  break;

  }           //end of switch on first key

  }				// end while(1)



}

int initstack(stack *s,int size)
{
if(s->stk=(int *)malloc(size*sizeof(int)))
{
s->size=size;
s->tos=0;
//gets(s->stk->name);
//scanf("%d",&(s->stk->id));
return 1;
}

return 0;
}

int isemptystack(stack *s)
{
if(s->tos==0)
return 1;
return 0;
}

int isfullstack(stack *s)
{
return (s->tos==s->size);
}

int push(stack *s,int data)
{
if(!isfullstack(s))
{
//strcpy(s->stk[s->tos].name,data.name);
s->stk[s->tos]=data;
s->tos ++;
return 1;
}
return 0;
}

int pop(stack *s,int *data)
{
if(!isemptystack(s))
{
s->tos--;
*data=s->stk[s->tos];
printf("%d",*data);
return 1;
}
return 0;
}






