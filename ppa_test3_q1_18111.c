#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int data;
	struct stack *next;
}stack;
stack *s;
stack *push(stack *s,int data)
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	temp->data=data;
	temp->next=NULL;
	if(!s)
	{
		s=temp;
	}
	else
	{
		temp->next=s;
		s=temp;
	}
	return s;
}
stack *pop(stack *s)
{
	if(!s)
	{
		printf("\n\nwarning: Empty stack...\n");
		return s;
	}
	else
	{ 
		int data=s->data;
		if(!s->next)
		{
			printf("%d is poped successfully...\n",data);
			return NULL;
		}
		else
		{
			printf("%d is poped successfully...\n",data);
			s=s->next;
			return s;
		}
	}
}
int findmiddle(stack *s)
{
	stack *temp=s,*middle=s;
	int flag=0,count=1;
	if(!s)
	{
		return -1;
	}
	while(temp)
	{
		if(flag==2)
		{
			flag=1;
			count++;
			middle=middle->next;
		}
		else 
		{
			flag++;
		}
		temp=temp->next;	
	}
	printf("middle element is %d and is at %d th possition\n",middle->data,count);
	return count;
}
stack *deletemiddle(stack *s)
{
	stack *temp=s;
	int middle,i=0;
	middle=findmiddle(s);
	if(!temp->next)
	{
		printf("\n\t\tmiddle(first) element is deleted succesfully...\n");
		printf("\n\nwarning: Empty stack...\n");
		return NULL;
	}
	else if(!temp->next->next)
	{
		printf("\n\t\tmiddle(first) element is deleted succesfully...\n");
		return s->next;
	}
	else
	{
		while(i!=middle-2)
		{
			i++;
			temp=temp->next;	
		}
		temp->next=temp->next->next;
	}
	printf("\n\t\tmiddle element is deleted succesfully...\n");
	return s;
}
void print(stack *s) 
{ 
	stack *temp;
	temp=s;
	if(!s)
		printf("\n\nwarning: Empty stack...\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d\t",temp->data); 
			temp=temp->next; 
		}
	}
}
int main()
{
	int i,n,data,choice;
	s=NULL;
	printf("Enter how many numbers you have:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the node data:");
		scanf("%d",&data);
		s=push(s,data);
	}
	while(1)
	{
		printf("\n1:push\n2:pop\n3:find Middle\n4:delete Middle\n5:print \n0:exit\nEnter the operation number:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	//for push an element into stack
				printf("Enter the node data:");
				scanf("%d",&data);
				s=push(s,data);
				break;
			case 2:	//for pop an element from stack
				s=pop(s);
				break;
			case 3://for finding middle element of stack
				data=findmiddle(s);
				if(data==-1)
					printf("\n\nwarning: Empty stack...\n");
				break;
			case 4://for deleting middle element of stack
				if(!s)
					printf("\n\nwarning: Empty stack...\n");
				else
					s=deletemiddle(s);
				break;
			case 5: //printing stack elements
				print(s);
				break;
			case 0:exit(0);
				break;
			default :break;
		}
	
	}	
	return 0;
}
/*
OUTPUT:
rishi@pucsd:~$ gcc stack.c
rishi@pucsd:~$ ./a.out
Enter how many numbers you have:4
Enter the node data:1
Enter the node data:2
Enter the node data:3
Enter the node data:4

1:push
2:pop
3:find Middle
4:delete Middle
5:print 
0:exit
Enter the operation number:3
middle element is 3 and is at 2 th possition

1:push
2:pop
3:find Middle
4:delete Middle
5:print 
0:exit
Enter the operation number:4
middle element is 3 and is at 2 th possition

		middle element is deleted succesfully...

1:push
2:pop
3:find Middle
4:delete Middle
5:print 
0:exit
Enter the operation number:4
middle element is 2 and is at 2 th possition

		middle element is deleted succesfully...

1:push
2:pop
3:find Middle
4:delete Middle
5:print 
0:exit
Enter the operation number:4
middle element is 4 and is at 1 th possition

		middle(first) element is deleted succesfully...

1:push
2:pop
3:find Middle
4:delete Middle
5:print 
0:exit
Enter the operation number:4
middle element is 1 and is at 1 th possition

		middle(first) element is deleted succesfully...


warning: Empty stack...

1:push
2:pop
3:find Middle
4:delete Middle
5:print 
0:exit
Enter the operation number:0
rishi@pucsd:~$ 
*/
