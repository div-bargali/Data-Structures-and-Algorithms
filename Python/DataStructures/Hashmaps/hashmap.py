class Node:
   def __init__(self, key, val):
      self.key = key
      self.val = val
      self.next = None

class linkedlist:
   def __init__(self):
      self.prehead = Node(None, None)

   def search(self, key):
      p = self.prehead.next
      while p:
         if p.key == key:
            return p
         p = p.next
      return None

   def add(self, key, val):
      p = self.search(key)
      if p:
         p.val = val
      else:
         node = Node(key, val)
         self.prehead.next, node.next = node, self.prehead.next

   def get(self, key):
      p = self.search(key)
      if p:
         return p.val
      else:
         return None

   def remove(self, key):
      prev = self.prehead
      cur = prev.next
      while cur:
         if cur.key == key:
            break
         prev, cur = cur, cur.next
      if cur:
         prev.next = cur.next

   def serialize(self):
      p = self.prehead.next
      ret = []
      while p:
         ret.append([p.key, p.val])
         p = p.next
      return ret

class hashmap:
   def __init__(self):
      self.size = 1033
      self.arr = [linkedlist() for _ in range(self.size)]

   def _hash(self, key):
      return key % self.size

   def put(self, key, value):
      h = self._hash(key)
      self.arr[h].add(key, value)

   def get(self, key):
      h = self._hash(key)
      ret = self.arr[h].get(key)
      if ret is not None:
         return ret
      else:
         print("Data not present")

   def remove(self, key):
      h = self._hash(key)
      self.arr[h].remove(key)

def menu():
	print("1: Put")
	print("2: Get")
	print("3: Remove")
	print("4: Exit")
	choice = int(input("Enter your choice.. "))

	while choice <1 or choice >4:
		print("\nEnter between 1 and 4 (inclusive)\n")
		choice = int(input("\nEnter your choice..\n "))

	return choice



def operation(choice, ob):
	if choice == 1:
		data1, data2 = input("\nEnter two values : ").split()

		try:
			objects.put(int(data1), int(data2))
		except Exception as e:
			print(e)


	elif choice == 2:
		data = int(input("\nEnter data to get : "))
		try:	
			print("\n Your Data is : ", objects.get(data), "\n")
		except Exception as e:
			print(e)

	elif choice == 3:
		data = int(input("\nEnter data to remove : "))
		try:
			objects.remove(data)
		except Exception as e:
			print(e)

	elif choice == 4:
		exit()

if __name__ == "__main__":

	objects = hashmap()
	choice = menu()

	while choice != 5:
		operation(choice, objects)
		choice = menu()
