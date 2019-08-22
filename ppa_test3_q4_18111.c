#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int data;
	struct stack *next;
}stack;
stack *Input,*Output;
stack *push(stack *Input,int data)
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	temp->data=data;
	temp->next=NULL;
	if(!Input)
	{
		Input=temp;
	}
	else
	{
		temp->next=Input;
		Input=temp;
	}
	return Input;
}
stack *pop(stack *Input)
{
	if(!Input)
	{
		printf("\n\nwarning: Empty stack...\n");
		return Input;
	}
	else
	{ 
		int data=Input->data;
		if(!Input->next)
		{
			printf("%d is poped successfully...\n",data);
			return NULL;
		}
		else
		{
			printf("%d is poped successfully...\n",data);
			Input=Input->next;
			return Input;
		}
	}
}

stack *insertOutput(stack *head,int data)
{
	stack *temp,*temp1=head;
	temp=(stack *)malloc(sizeof(stack));
	temp->data=data;
	temp->next==NULL;
	if(!head)
	{
		head=temp1=temp;
	}
	else
	{
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=temp;
		temp1=temp;
	}
	return head;
}
void print(stack *Input) 
{ 
	stack *temp;
	temp=Input;
	if(!Input)
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
	int i,ip,n,data,choice,inc;
	Input=NULL;
	Output=NULL;
	printf("Enter how many number of Trolly's you have:");
	scanf("%d",&n);
	ip=1;
	while(1)
	{	
		if(!Input)	
		{
			printf("\n\nwarning: Empty stack...\n");
			if(ip<=n)
			printf("\n1:move Trolly %d into stack",ip);
		}
		else if(Input && ip<=n)
			printf("\n1:move Trolly %d into stack\n2:move Trolly %d into Output stack",ip,Input->data);
		else //if(!Input->next)
			printf("\n2:move Trolly %d into Output stack\n",Input->data);
		printf("\n3:print Input\n4:print output\n0:exit\nEnter the operation number:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	//for push an Trolly into stack
				if(ip>n)
					printf("Not allowed...\n");
				else
					Input=push(Input,ip++);
				break;
			case 2:	//for pop an Trolly from stack
				if(!Input)
					printf("Not allowed...\n");
				else	
				{
					data=Input->data;
					if(!Input->next)
						Input=NULL;
					else 
						Input=pop(Input);
					Output=insertOutput(Output,data);
				}
				break;
			case 3: //printing stack of Trolly's
				print(Input);
				break;
			case 4: //printing stack of Trolly's
				print(Output);
				break;
			case 0:exit(0);
				break;
			default :break;
		}
	
	}	
	return 0;
}
/*OUTPUT:

rishi@pucsd:~$ gcc q4.c
rishi@pucsd:~$ ./a.out
Enter how many number of Trolly's you have:4


warning: Empty stack...

1:move Trolly 1 into stack
3:print Input
4:print output
0:exit
Enter the operation number:1

1:move Trolly 2 into stack
2:move Trolly 1 into Output stack
3:print Input
4:print output
0:exit
Enter the operation number:1

1:move Trolly 3 into stack
2:move Trolly 2 into Output stack
3:print Input
4:print output
0:exit
Enter the operation number:2
2 is poped successfully...

1:move Trolly 3 into stack
2:move Trolly 1 into Output stack
3:print Input
4:print output
0:exit
Enter the operation number:1

1:move Trolly 4 into stack
2:move Trolly 3 into Output stack
3:print Input
4:print output
0:exit
Enter the operation number:2
3 is poped successfully...

1:move Trolly 4 into stack
2:move Trolly 1 into Output stack
3:print Input
4:print output
0:exit
Enter the operation number:1

2:move Trolly 4 into Output stack

3:print Input
4:print output
0:exit
Enter the operation number:2
4 is poped successfully...

2:move Trolly 1 into Output stack

3:print Input
4:print output
0:exit
Enter the operation number:2


warning: Empty stack...

3:print Input
4:print output
0:exit
Enter the operation number:4
2	3	4	1	

warning: Empty stack...

3:print Input
4:print output
0:exit
Enter the operation number:3


warning: Empty stack...


warning: Empty stack...

3:print Input
4:print output
0:exit
Enter the operation number:0
rishi@pucsd:~$ */
