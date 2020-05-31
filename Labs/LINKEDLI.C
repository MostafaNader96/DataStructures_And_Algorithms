#include <stdio.h>
#include <conio.h>
#define up 72
#define down 80
#define enter 13
#define esc   27

typedef struct node
{
char name[20];
int id;
struct node *next;
struct node *prev;
}node;

typedef struct linkedlist
{
node *start;
node *end;
}linkedlist;



node* createnode(void);
void  datanode(node *nodee);
void addnode(linkedlist *l, node *newnode);
void insertnode(linkedlist *l,node *newnode);
node * searchnode(linkedlist *l, int flag);
int deletenode(linkedlist *l, int flag);

void main()
{
  int col=20,row=3;
  int i,pos=0;
  int flag,x;
  char key;
  char menu[6][10]={"ADD","Insert","Delete","Search","Display","Exit"};
  linkedlist *ll;
  node *temp;
  ll->start=NULL;
  ll->end=NULL;


	while(1)
  {					//start while(1)
  clrscr();
  textcolor(CYAN);
  gotoxy(col,row);
  printf("%c%c",45,62);
  textcolor(CYAN);
  cprintf("ADD");

  gotoxy(col,row+1);
  textcolor(BLUE);
  cprintf("%c%c",45,62);
  cprintf("Insert");

  gotoxy(col,row+2);
  textcolor(RED);
  cprintf("%c%c",45,62);
  cprintf("Delete");

  gotoxy(col,row+3);
  textcolor(WHITE);
  cprintf("%c%c",45,62);
  cprintf("Search");

  gotoxy(col,row+4);
  textcolor(CYAN);
  cprintf("%c%c",45,62);
  cprintf("Display");

  gotoxy(col,row+5);
  textcolor(BLUE);
  cprintf("%c%c",45,62);
  cprintf("Exit");

  row=3;
  for(i=0;i<6;i++)
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
  if(pos<0) pos=5;
  break;
  case down:
  pos++;
  if(pos>5) pos=0;
  break;
  }           //end of switch on 2nd key
  break;

  case enter:
  switch(pos)
  {
  case 0:
  clrscr();
  temp=createnode();
  datanode(temp);
  addnode(ll,temp);
  printf("\nNode added succsessfully!\n");
  getch();
  break;

  case 1:
  clrscr();
  temp=createnode();
  datanode(temp);
  insertnode(ll,temp);
  printf("\nNode inserted succesfully!!\n");
  getch();

  break;

  case 2:
  clrscr();
  printf("Enter the id of the node you want to delete: ");
  scanf("%d",&flag);
  x=deletenode(ll,flag);
  if(x==1)
  printf("\n\nSuccesfully deleted!!");
  if(x==0)
  printf("\n\nDeletion Failure!!");
  getch();
  break;

  case 3:
  clrscr();
  printf("Enter the id you want to search for: ");
  scanf("%d",&flag);
  temp=searchnode(ll,flag);
  printf("\nThe following data refers to the id you searched for\nName: %s\nID: %d",temp->name,temp->id);
  getch();
  break;

  case 4:
  clrscr();
  temp=ll->start;
  while(temp!=NULL)
  {
  printf("Name: %s\nID: %d\n",temp->name,temp->id);
  temp=temp->next;
  }
  getch();
  break;

  case 5:
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



node* createnode(void)
{
 return (node*)malloc(sizeof(node));
}

void  datanode(node *nodee)
{
printf("Enter the name: ");
scanf("%s",nodee->name);
printf("Enter the id : ");
scanf("%d",&(nodee->id));

}

void addnode(linkedlist *l, node *newnode)
{
if(l->start==NULL)
{
l->start=newnode;
l->end=newnode;
newnode->next=NULL;
newnode->prev=NULL;
}
else
{
newnode->prev=l->end;
newnode->next=NULL;
l->end->next=newnode;
l->end=newnode;
}

}

void insertnode(linkedlist *l,node *newnode)
{
node *temp;
temp=l->start;
if(l->start==NULL) addnode(l,newnode);
while(temp && temp->id<newnode->id)
temp=temp->next;
if(!temp) addnode(l,newnode);
else if(temp==l->start)
{
newnode->next=l->start;
l->start->prev=newnode;
l->start=newnode;
newnode->prev=NULL;
}
else
{
temp->prev->next=newnode;
newnode->prev=temp->prev;
newnode->next=temp;
temp->prev=newnode;
}
}

node * searchnode(linkedlist *l, int flag)
{
 node *temp;
 temp=l->start;

 if(l->start==NULL)
 {

 return NULL;
 }

 while(temp!=NULL && flag!=temp->id)
 {
 temp=temp->next;
 }
 return temp;

}

int deletenode(linkedlist *l, int flag)
{
 node *temp;
 temp=searchnode(l,flag);
 if(temp==NULL) return 0;
 else
 {
  if((temp==l->start) && (temp==l->end))
  {
  l->start=NULL;
  l->end=NULL;
  free(temp);
  }
  else if(temp==l->start)
  {
  l->start=l->start->next;
  l->start->prev=NULL;
  free(temp);
  }
  else if(temp==l->end)
  {
  l->end=l->end->prev;
  l->end->next=NULL;
  free(temp);
  }
  else
  {
  temp->prev->next=temp->next;
  temp->next->prev=temp->prev;
  free(temp);
  }
  return 1;

 }


}

