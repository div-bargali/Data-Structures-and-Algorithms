class Node:
    def __init__(self, data=None, prev=None, next=None):
        self.data = data
        self.prev = prev
        self.next = next


class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        if self.head is None:
            node = Node(data)
            self.head = node
        else:
            new_head = Node(data, next=self.head)
            self.head.prev = new_head
            self.head = new_head

    def length(self):
        itr = self.head
        count = 0
        while itr:
            count += 1
            itr = itr.next
        return count

    def insert_at_end(self, data):
        if self.head is None:
            self.insert_at_beginning(data)
        else:
            itr = self.head
            while itr.next:
                itr = itr.next
            itr.next = Node(data, prev=itr)

    def insert_at(self, data, at):
        if at == 0:
            self.insert_at_beginning(data)
        elif at == self.length() - 1 and self.length() > 2:
            self.insert_at_end(data)
        else:
            itr = self.head
            count = 0
            while itr:
                if count != at - 1:
                    count += 1
                    itr = itr.next
                else:
                    break
            itr.next = Node(data, itr, itr.next)

    def remove_val(self, val):
        while self.head and self.head.data is val:
            self.head = self.head.next
        if self.head is None:
            return

        current = self.head
        while current:
            if current.data == val:
                if current == self.head:
                    self.head = current.next
                    self.head.prev = None
                if current.next is None:
                    current.prev.next = None
                    return
                else:
                    current.next.prev = current.prev
                    current.prev.next = current.next
            current = current.next

    def __str__(self):
        current = self.head
        as_string = ''
        while current:
            as_string += str(current.data)
            if current.next:
                as_string += ' --> '
            current = current.next
        return as_string
