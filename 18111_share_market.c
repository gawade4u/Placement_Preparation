//Name -Gawade Rishikesh Sharad
//Roll no-18111
//Subject: assignment 3- maximum profit assignment 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//for accepting the table values
typedef struct list
{
	int day,price,change;
	struct list *next;
}list;
list *s;
int day=0,price;
//for creating table and inserting values into table
list *insert(list *s,int day,int price,int change)
{
	list *temp,*temp1;
	temp=(list *)malloc(sizeof(list));
	temp->day=day;
	temp->price=price;
	temp->change=change;
	temp->next=NULL;
	if(!s)
	{
		s=temp1=temp;
	}
	else
	{
		temp1->next=temp;
		temp1=temp;
	}
	return s;
}
int subarray(list *head,int n,int k)
{
	int i,j,x;
	list *temp,*temp1;
	int sum=0,max=0,smax=0;
	
	for(temp=head,i=0;i<n-k+1;i++,temp=temp->next)
	{
		sum=0;
		printf("{");
		for(temp1=temp->next,j=i+1;j<k+i+1;j++,temp1=temp1->next)
		{
			printf("%d",temp1->change);
			if(!(j==k+i))
				printf(",");
			sum+=temp1->change;
			max=sum;
		}
		if(smax<max)
			{
				smax=max;
				x=j-k;
			}
		printf("}\n");
	
	}
	printf("\tyou got max profit when you invest on %dth day\t",x-1);
	for(temp=head,i=0;i<x-1;i++,temp=temp->next);
	printf("and  share price is:=%d ",temp->price);
	return smax;
}
int maxsubarray(list *head,int n,int k)
{
	int i,j,x;
	list *temp,*temp1;
	int sum=0,max=0,smax=0;	
	for(temp=head,i=0;i<n-k+1;i++,temp=temp->next)
	{
		sum=0;
		//printf("{");
		for(temp1=temp->next,j=i+1;j<k+i+1;j++,temp1=temp1->next)
		{
			//printf("%d",temp1->change);
			if(!(j==k+i))
				//printf(",");
			sum+=temp1->change;
			max=sum;
		}
		if(smax<max)
			{
				smax=max;
				x=j-k;
			}
	
	}
	printf("\n\nyou got max profit when you invest on %dth day\n",x-1);
	for(temp=head,i=0;i<x-1;i++,temp=temp->next);
	printf("share price is:=%d \n maximum profit chart is as follows:\nprice\tchange\n",temp->price);
	sum=0;
	printf("{");
	for(temp1=temp,j=i;j<k+i+1;j++,temp1=temp1->next)
	{
		printf("%d\t%d",temp1->price,temp1->change);
		if(!(j==k+i))
			printf(",\n");
	}
	printf("}\n");
	return smax;
}
//for printing the Table 
void print(list *n) 
{  
	list *temp=n;
	printf("day\t\tprice\t\tchange\n");
	while (temp!=NULL)
	{ 
		printf("%d\t\t%d\t\t%d\n",temp->day,temp->price,temp->change); 
		temp=temp->next; 
 	}
}

//starting of main function
int main()
{
	int i,change,n,choice,Day;
	s=NULL;
	printf("Enter how many records you have:");
	scanf("%d",&n);
	printf("Enter the starting price:");
	scanf("%d",&price);
	s=insert(s,day++,price,0);
	for(i=0;i<n;i++)
	{
		printf("Enter the change in price:");
		scanf("%d",&change);
		price=price+change;
		s=insert(s,day++,price,change);
	}
	print(s);
	printf("\n");
	printf("calculations By Subarray:\n");
	int sum=0,max[20],maximum=0;
	printf("\n");
	for(i=1;i<n;i++)
	{
		max[i]=subarray(s,n,i);
		
		if(max[i]>maximum)
		{
			maximum=max[i];
			choice=i;
		}
		if(max[i]<=0)
		{
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b...hence, you are in Loss and dont invest your money\n");
		}
		else
			printf("\tand max profit is:%d\n",max[i]);
	}	
	max[i]=maxsubarray(s,n,choice);
	printf("\nmaximum profit is:%d\n",max[choice]);
	return 0;
}
/*
OUTPUT...:
rishi@pucsd:~$ gcc 18111_share_market.c 
rishi@pucsd:~$ ./a.out
Enter how many records you have:16
100
13
-3
-25
20
-3
-16
-23
18
20
-7
12
-5
-22
15
-4
7Enter the starting price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:Enter the change in price:
day		price		change
0		100		0
1		113		13
2		110		-3
3		85		-25
4		105		20
5		102		-3
6		86		-16
7		63		-23
8		81		18
9		101		20
10		94		-7
11		106		12
12		101		-5
13		79		-22
14		94		15
15		90		-4
16		97		7

calculations By Subarray:

{13}
{-3}
{-25}
{20}
{-3}
{-16}
{-23}
{18}
{20}
{-7}
{12}
{-5}
{-22}
{15}
{-4}
{7}
	you got max profit when you invest on 3th day	and  share price is:=85 and max profit is:20
{13,-3}
{-3,-25}
{-25,20}
{20,-3}
{-3,-16}
{-16,-23}
{-23,18}
{18,20}
{20,-7}
{-7,12}
{12,-5}
{-5,-22}
{-22,15}
{15,-4}
{-4,7}
	you got max profit when you invest on 7th day	and  share price is:=63 and max profit is:38
{13,-3,-25}
{-3,-25,20}
{-25,20,-3}
{20,-3,-16}
{-3,-16,-23}
{-16,-23,18}
{-23,18,20}
{18,20,-7}
{20,-7,12}
{-7,12,-5}
{12,-5,-22}
{-5,-22,15}
{-22,15,-4}
{15,-4,7}
	you got max profit when you invest on 7th day	and  share price is:=63 and max profit is:31
{13,-3,-25,20}
{-3,-25,20,-3}
{-25,20,-3,-16}
{20,-3,-16,-23}
{-3,-16,-23,18}
{-16,-23,18,20}
{-23,18,20,-7}
{18,20,-7,12}
{20,-7,12,-5}
{-7,12,-5,-22}
{12,-5,-22,15}
{-5,-22,15,-4}
{-22,15,-4,7}
	you got max profit when you invest on 7th day	and  share price is:=63 and max profit is:43
{13,-3,-25,20,-3}
{-3,-25,20,-3,-16}
{-25,20,-3,-16,-23}
{20,-3,-16,-23,18}
{-3,-16,-23,18,20}
{-16,-23,18,20,-7}
{-23,18,20,-7,12}
{18,20,-7,12,-5}
{20,-7,12,-5,-22}
{-7,12,-5,-22,15}
{12,-5,-22,15,-4}
{-5,-22,15,-4,7}
	you got max profit when you invest on 7th day	and  share price is:=63 and max profit is:38
{13,-3,-25,20,-3,-16}
{-3,-25,20,-3,-16,-23}
{-25,20,-3,-16,-23,18}
{20,-3,-16,-23,18,20}
{-3,-16,-23,18,20,-7}
{-16,-23,18,20,-7,12}
{-23,18,20,-7,12,-5}
{18,20,-7,12,-5,-22}
{20,-7,12,-5,-22,15}
{-7,12,-5,-22,15,-4}
{12,-5,-22,15,-4,7}
	you got max profit when you invest on 3th day	and  share price is:=85 and max profit is:16
{13,-3,-25,20,-3,-16,-23}
{-3,-25,20,-3,-16,-23,18}
{-25,20,-3,-16,-23,18,20}
{20,-3,-16,-23,18,20,-7}
{-3,-16,-23,18,20,-7,12}
{-16,-23,18,20,-7,12,-5}
{-23,18,20,-7,12,-5,-22}
{18,20,-7,12,-5,-22,15}
{20,-7,12,-5,-22,15,-4}
{-7,12,-5,-22,15,-4,7}
	you got max profit when you invest on 7th day	and  share price is:=63 and max profit is:31
{13,-3,-25,20,-3,-16,-23,18}
{-3,-25,20,-3,-16,-23,18,20}
{-25,20,-3,-16,-23,18,20,-7}
{20,-3,-16,-23,18,20,-7,12}
{-3,-16,-23,18,20,-7,12,-5}
{-16,-23,18,20,-7,12,-5,-22}
{-23,18,20,-7,12,-5,-22,15}
{18,20,-7,12,-5,-22,15,-4}
{20,-7,12,-5,-22,15,-4,7}
	you got max profit when you invest on 7th day	and  share price is:=63 and max profit is:27
{13,-3,-25,20,-3,-16,-23,18,20}
{-3,-25,20,-3,-16,-23,18,20,-7}
{-25,20,-3,-16,-23,18,20,-7,12}
{20,-3,-16,-23,18,20,-7,12,-5}
{-3,-16,-23,18,20,-7,12,-5,-22}
{-16,-23,18,20,-7,12,-5,-22,15}
{-23,18,20,-7,12,-5,-22,15,-4}
{18,20,-7,12,-5,-22,15,-4,7}
	you got max profit when you invest on 7th day	and  share price is:=63 and max profit is:34
{13,-3,-25,20,-3,-16,-23,18,20,-7}
{-3,-25,20,-3,-16,-23,18,20,-7,12}
{-25,20,-3,-16,-23,18,20,-7,12,-5}
{20,-3,-16,-23,18,20,-7,12,-5,-22}
{-3,-16,-23,18,20,-7,12,-5,-22,15}
{-16,-23,18,20,-7,12,-5,-22,15,-4}
{-23,18,20,-7,12,-5,-22,15,-4,7}
	you got max profit when you invest on 6th day	and  share price is:=86 and max profit is:11
{13,-3,-25,20,-3,-16,-23,18,20,-7,12}
{-3,-25,20,-3,-16,-23,18,20,-7,12,-5}
{-25,20,-3,-16,-23,18,20,-7,12,-5,-22}
{20,-3,-16,-23,18,20,-7,12,-5,-22,15}
{-3,-16,-23,18,20,-7,12,-5,-22,15,-4}
{-16,-23,18,20,-7,12,-5,-22,15,-4,7}
	you got max profit when you invest on 3th day	and  share price is:=85 and max profit is:9
{13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5}
{-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22}
{-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15}
{20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4}
{-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7}
	you got max profit when you invest on 3th day	and  share price is:=85 and max profit is:5
{13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22}
{-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15}
{-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4}
{20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7}
	you got max profit when you invest on 3th day	and  share price is:=85 and max profit is:12
{13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15}
{-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4}
{-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7}
      ...hence, you are in Loss and dont invest your moneyd  share price is:=85 
{13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4}
{-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7}
	you got max profit when you invest on -1th day	and  share price is:=100...hence, you are in Loss and dont invest your money


you got max profit when you invest on 7th day
share price is:=63 
 maximum profit chart is as follows:
price	change
{63	-23,
81	18,
101	20,
94	-7,
106	12}

maximum profit is:43
rishi@pucsd:~$ 
*/
