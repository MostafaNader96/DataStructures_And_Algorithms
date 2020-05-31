#include <stdio.h>
#include <conio.h>


void main()
{
int S=0,L=14;
int se,i,r;
int flag=0;
int M=((S+L)/2);
int arr[15];
clrscr();
for(i=0;i<15;i++)
{
printf("Enter Element %d in the array: ",i);
scanf("%d",&arr[i]);
}
printf("Enter the value that u want to search for: ");
scanf("%d",&se);

for(i=0;i<(15/2);i++)
{
if(se>arr[M])
{
 S=M;
 M=((M+L)/2);

}
else if(se<arr[M])
{
 L=M;
 M=((M+S)/2);

}
else
{
flag=1;
r=M;
}

}

if(flag==1)
{
printf("Value found in index %d",r);
}
else
printf("Not found");
getch();
}
