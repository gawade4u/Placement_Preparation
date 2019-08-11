//Name-Gawade Rishikesh sharad
//Roll No-18111
//Q-1- Implement queue using doubly link list
#include<stdio.h>
#include<stdlib.h>
//Queue data structure
typedef struct queue
{
	int data;
	struct queue *next,*prev;
}Queue;
Queue *head;
//to insert into the queue
Queue *enQueue(Queue *head,int data)
{
	Queue *temp,*temp1=head;
	temp=(Queue *)malloc(sizeof(Queue));
	temp->data=data;
	temp->next=temp->prev=NULL;
	if(!head)
	{
		head=temp1=temp;
	}
	else
	{
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=temp;
		temp->prev=temp1;
		temp1=temp;
	}
	return head;
}
//for deleting from a queue
Queue *dequeue(Queue *head)
{
	int data=head->data;
	if(!head->next)
	{
		printf("Element %d deleted successfully...\n",data);
		return NULL;
	}
	else
	{
		head=head->next;
		head->prev=NULL;
		printf("Element %d deleted successfully...\n",data);
		return head;
	}
}
int peek(Queue *head)
{
	
	if(!head)
		return -1;
	else 
		return head->data;
}
//to display the elements from queue
void print(Queue *head)
{
	Queue *temp;
	if(!head)//if Queue is empty
		printf("Queue is empty....\n");
	else
	{
		printf("Your Queue is as Follows:\n");
		for(temp=head;temp!=NULL;temp=temp->next)
		printf("%d\t",temp->data);
	}
}

//starting of main function
int main( void)
{
	head=NULL;
	int i,n,data,choice;
	while(1)
	{
		//to accept input from user
		printf("\nwhat do you want:\n1:insert\n2:delete\n3:peek\n4:print Queue\n0:exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: //for exit from program
				exit(0);
				break;
			case 1: //for inserting into queue
				printf("\nHow many nodes you want to insert:");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("Enter the data:");
					scanf("%d",&data);	
					head=enQueue(head,data);
				}
				break;
			case 2:	//for deleting a number
				if(!head)
					printf("\nsorry\n...Queue is empty...\n");
				else
					head=dequeue(head);//for pop 1st element from queue
				break;
			case 3://peek current element
				data=peek(head);
				if(data==-1)
					printf("Queue is empty....\n");
				else
					printf("current element in a queue is %d\n",data);
				break;
			case 4://for printing elements of Queue
				print(head);
				break;
			default: break;
		
		}
	}
	return 0;
}

/*
OUTPUT:
rishi@pucsd:~$ gcc queue.c
rishi@pucsd:~$ ./a.out
what do you want:
1:insert
2:delete
3:peek
4:print Queue
0:exit
1
How many nodes you want to insert:5
Enter the data:1
Enter the data:2
Enter the data:3
Enter the data:4
Enter the data:5
what do you want:
1:insert
2:delete
3:peek
4:print Queue
0:exit
3
current element in a queue is 1
what do you want:
1:insert
2:delete
3:peek
4:print Queue
0:exit
4
Your Queue is as Follows:
1	2	3	4	5	
what do you want:
1:insert
2:delete
3:peek
4:print Queue
0:exit
2
Element 1 deleted successfully...
what do you want:
1:insert
2:delete
3:peek
4:print Queue
0:exit
2
Element 2 deleted successfully...
what do you want:
1:insert
2:delete
3:peek
4:print Queue
0:exit
2
Element 3 deleted successfully...
what do you want:
1:insert
2:delete
3:peek
4:print Queue
0:exit
2
Element 4 deleted successfully...
what do you want:
1:insert
2:delete
3:peek
4:print Queue
0:exit
2
Element 5 deleted successfully...
what do you want:
1:insert
2:delete
3:peek
4:print Queue
0:exit
2
sorry
...Queue is empty...
what do you want:
1:insert
2:delete
3:peek
4:print Queue
0:exit
2
sorry
...Queue is empty...
what do you want:
1:insert
2:delete
3:peek
4:print Queue
0:exit
3
Queue is empty....
what do you want:
1:insert
2:delete
3:peek
4:print Queue
0:exit
0
rishi@pucsd:~$ 
*/
