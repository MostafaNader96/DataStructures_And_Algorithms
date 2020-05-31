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

typedef struct queue
{
int in,size;
int *que;
}queue;



int initqueue(queue *q,int size);
int isemptyqueue(queue *q);
int isfullqueue(queue *q);
int input(queue *q,int data);
int output(queue *q,int *data);


void main()
{
  int col=20,row=3;
  int i,pos=0;
  int flag,x,y;
  int inf,outf;
  char key;
  queue *q;
  //stack *temp;

  char menu[3][10]={"ADD","Delete","Exit"};
  initqueue(q,5);


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
  printf("Enter an integer to Enqueue!");
  scanf("%d",&x);
  inf=input(q,x);
  if(inf==1)
  printf("\n\nEnqueued successfully :)");
  if(inf==0)
  printf("\n\nQUEUE FULL! ");
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
  outf=output(q,&y);
  if(outf==1)
  printf("\nDEQUEUED!");
  if(outf==0)
  printf("\nQUEUE Empty!");
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

int initqueue(queue *q,int size)
{
if(!(q->que=(int *)malloc(size*sizeof(int))))
return 0;

q->size=size;
q->in=0;
return 1;

}

int isemptyqueue(queue *q)
{
   return !(q->in);
}

int isfullqueue(queue *q)
{
return (q->in==q->size);
}

int input(queue *q,int data)
{
if(!isfullqueue(q))
{
//strcpy(s->stk[s->tos].name,data.name);
q->que[q->in]=data;
q->in ++;
return 1;
}
return 0;
}

int output(queue *q,int *data)
{
int i;
if(isemptystack(q))
return 0;

*data=q->que[0];
for(i=0;i<q->in-1;i++)
{
q->que[i]=q->que[i+1];
}
return 1;

}
