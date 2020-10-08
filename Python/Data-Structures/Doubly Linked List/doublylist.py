class Node:
    def __init__(self, data=None, prev=None, next=None):
        self.data = data
        self.prev = prev
        self.next = next


class Doublylist:
    def __init__(self):
        self.head = None

    def insertatbeginning(self, data):
        if self.head is None:
            node = Node(data)
            self.head = node
        else:
            self.head = Node(data, next=self.head)

    def length(self):
        itr = self.head
        count = 0
        while itr:
            count += 1
            itr = itr.next
        return count

    def insertatend(self, data):
        if self.head is None:
            self.insertatbeginning(data)
        else:
            itr = self.head
            while itr.next:
                itr = itr.next
            itr.next = Node(data, prev=itr)

    def print(self):
        itr = self.head
        istr = ''
        while itr:
            istr += str(itr.data) + '-->'
            itr = itr.next
        print(istr)

    def insertat(self, data, at):
        if at == 0:
            self.insertatbeginning(data)
        elif at == self.length() - 1:
            self.insertatend(data)
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

    def removeval(self,val):
        if self.head is None:
            raise Exception("invalid list")
        if self.head.data is val:
            self.head = None
        itr1=self.head
        itr2=self.head
        while itr1.next:
            itr1=itr1.next
            if itr1.data == val:
                itr2.next=itr1.next
                itr1.next.prev=itr2
            itr2=itr2.next

    def insertval(self,datalist):
        for i in datalist:
            d.insertatend(i)
        return



if __name__ == "__main__":
    d = Doublylist()
    d.insertatbeginning(5)
    d.print()
    d.insertatbeginning(6)
    d.print()
    print(d.length())
    d.insertatend(20)
    d.print()
    d.insertat(4, 1)
    d.removeval(6)
    d.print()
    d.removeval(4)
    d.print()
