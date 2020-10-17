import random
class Node():

      
    # Intilizing Nodes
    
    
    def __init__(self,date):
        self.date=date
        self.next=None
class LinkNode():
    def __init__(self,node=None):
        self.__head=node
        if node:
            node.next=self.__head #Establish a loop head node
    def is_empty(self):
        """Judging whether the list is empty"""
        return self.__head==None

    def length(self):
        """
            //Finding the Length of Chain List
        """
        if self.is_empty():
            return 0
        
        count=1
        cur=self.__head
        while cur.next!=self.__head:
            count+=1
            cur=cur.next
        return count

    def travel(self):
        """Traversing the entire list"""
        if self.is_empty():
            return
        #Creating a cursor equals the starting node
        cur = self.__head
        while cur.next != self.__head:
            print(cur.date,end=" ")
            cur = cur.next
        print(cur.date,end="\n")
    def HeadInsert(self,num):
        """
            //Head insertion node
        """
        node=Node(num)
        if self.is_empty():
            self.__head=node
            node.next=node
        else:
            cur=self.__head
            while cur.next!=self.__head:
                cur=cur.next
            node.next=self.__head
            self.__head=node
            cur.next=self.__head
    def TailInsert(self,num):
        """
            //Tail insertion node
        """
        node=Node(num)
        if self.is_empty():
            self.__head=node
            node.next=self.__head
        else:
            cur=self.__head
            while cur.next!=self.__head:
                cur=cur.next
            cur.next=node   
            node.next=self.__head

            
    def NodeInsert(self,index,num):
        """Adding elements at specified locations"""
        #Point to the address of self. head, which is not a header element
        # For the next element, so Preis the next element
        if index <= 0:
            #Think of it as head insertion.
            self.HeadInsert(num)
        elif index > (self.length()-1):
            self.TailInsert(num)
        else:
            pre_cur = self.__head
            count = 0
            while count < (index-1):
                count+=1
                pre_cur = pre_cur.next
            node = Node(num)
            node.next = pre_cur.next
            pre_cur.next = node

a=LinkNode()
for i in range(6):
    a.TailInsert(random.randint(0,10))#Random insertion of six numbers
a.travel()
a.NodeInsert(5,100)
a.travel()
