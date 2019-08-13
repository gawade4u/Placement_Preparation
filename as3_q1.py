class node:
	def __init__(self,data=None):
		self.data=data
		self.next=None

class queue:
	def __init__(self):
		self.head=None
		
	def enqueue(self,data=None):
		temp1=self.head
		temp=node(data)
		if(self.head.data is None):
			self.head=temp1=temp
		else:
			while(temp1.next is not None):
				temp1=temp1.next
			temp1.next=temp
		temp1=temp1.next
		return self.head
		
	def reverse(self,k):
		temp1=self.head
		for i in range(0,k):
			data=temp1.data
			temp1=temp1.next
			list1.head=list1.enstack(data)
		temp2=list1.head
		while(temp2.next is not None):
			temp2=temp2.next
		temp2.next=temp1
		return list1.head
	
	def Print(self):
		print("Queue Elements are as follows:")
		temp=self.head
		while(temp is not None):
			print(temp.data)
			temp=temp.next
			
class stack:
	def __init__(self):
		self.head=None
	def enstack(self,data=None):
		temp1=self.head
		temp=node(data)
		if(self.head.data is None):
			self.head=temp1=temp
		else:
			temp.next=temp1
		return temp
	def Print(self):
		print("stack Elements are as follows:")
		temp=self.head
		while(temp is not None):
			print(temp.data)
			temp=temp.next
	
			

n=int(input("Enter the value for n:"))
list=queue()
list1=stack()
list1.head=node()
list.head=node()
for i in range(0,n):
	data=int(input("Enter the data:"))
	list.head=list.enqueue(data)
list.Print()
k=int(input("Enter the value for k:"))
list.head=list.reverse(k)
print("After applying operations on queue:")
list.Print()


"""OUTPUT
rishi@pucsd:~$ python3 as3_q1.py 
Enter the value for n:10
Enter the data:10
Enter the data:20
Enter the data:30
Enter the data:40
Enter the data:50
Enter the data:60
Enter the data:70
Enter the data:80
Enter the data:90
Enter the data:100
Queue Elements are as follows:
10
20
30
40
50
60
70
80
90
100
Enter the value for k:5
After applying operations on queue:

Queue Elements are as follows:
50
40
30
20
10
60
70
80
90
100
rishi@pucsd:~$ """
