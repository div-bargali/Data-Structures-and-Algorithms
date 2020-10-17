
# Node
class Node:
	def __init__(self,data=None):
		self.data = data
		self.next = None

#  linkedlist
class LinkedList:
	def __init__(self):
		self.head = None


	def insertData(self,newItem): # inserting data in the list
		newNode = Node(newItem) # creating a new node

		#  checking if the head node is none, make the new node the head node
		if self.head == None:
			self.head = newNode
			return

		ThisNode = self.head

		# if the new node data is less than the head node data, insert it to the left of head node and make the new node the head node
		if ThisNode.data > newItem:
			newNode.next = ThisNode
			self.head = newNode
			return

		# if head node points to nothing place the newnode to head node
		if ThisNode.next == None:
			ThisNode.next = newNode
			return

		#  place the node between nodes

		while  ThisNode:
			if newItem > ThisNode.data:
				prevNode = ThisNode

			ThisNode = ThisNode.next

		if prevNode.next == None:
			prevNode.next = newNode
		else:
			newNode.next = prevNode.next
			prevNode.next = newNode


	#  displaying all the elements of list
	def printAll(self):
		temp = self.head
		if temp == None:
			print("LinkedList is empty")
			return 

		while (temp):
			print(temp.data)
			temp = temp.next

	#  finding element from list
	def findElement(self, DataItem):
		ThisNode = self.head  # starting from head node
		startIndex = 0 # used to identify the index


		notFound = False

		# if the head node is none list is empty
		if ThisNode == None:
			print("LinkedList is empty")
			return

		# looping through the list to find data 
		while ThisNode:
			if ThisNode.data == DataItem:
				print("Data found at index " + str(startIndex))
				notFound = False
			else:
				notFound = True

			startIndex += 1
			ThisNode = ThisNode.next

		if notFound == True:
			print("Data not found ")
	#  deleting node
	def deleteNode(self, DataItem):
		ThisNode = self.head
		#  if node to delete is the head node
		if ThisNode is not None:
			if ThisNode.data == DataItem:
				self.head = ThisNode.next
				ThisNode = None

				return

		# looping through list to find the node to delete
		while ThisNode is not None:
			if ThisNode.data == DataItem:
				break

			prevNode = ThisNode
			ThisNode = ThisNode.next

		if ThisNode == None:
			return

		prevNode.next = ThisNode.next
		ThisNode = None



# menu created
def Menu():
	print("1: Add an Item")
	print("2: Find an Item")
	print("3: delete an Item")
	print("4: Display all elements")
	print("5: Exit")
	choice = int(input("Enter your choice.. "))

	while choice <1 or choice >5:
		print("")
		print("Enter between 1 and 5 (inclusive)")
		choice = int(input("Enter your choice.. "))
		print("")

	return choice


def operation(choice, myList):
	if choice == 1:
		print("")
		data = input("Enter data to insert.. ")

		try:
			data = int(data)
		except:
			pass
		myList.insertData(data)
		print("")


	elif choice == 2:
		print("")
		data = input("Enter data to find.. ")
		try:	
			data = int(data)
		except:
			pass
		myList.findElement(data)
		print("")

	elif choice == 3:
		print("")
		data = input("Enter data to delete.. ")
		try:
			data = int(data)
		except:
			pass
		myList.deleteNode(data)
		print("")

	elif choice == 4:
		print("")
		myList.printAll()
		print("")

if __name__ == "__main__":

	myList = LinkedList()
	choice = Menu()

	while choice != 5:
		operation(choice, myList)
		choice = Menu()
