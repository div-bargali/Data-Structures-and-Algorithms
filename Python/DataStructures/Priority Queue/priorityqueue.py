#Dilip Jain
class PriorityQueue(object):
    '''
    Implementing Priority Queue using Python.
    Priority Queue is a special type of data structure in which items can be inserted or deleted based on the priority.
    '''
    def __init__(self):
        self.queue = []

    def __str__(self):
        return ' '.join([str(i) for i in self.queue])

    #for checking if the queue is empty (UnderFlow Condition)
    def isEmpty(self):
        return len(self.queue) == 0


    #for insertion
    def insert(self, data):
        self.queue.append(data)


    #for deletion
    def delete(self):
        try:
            max = 0
            for i in range(len(self.queue)):
                if self.queue[i] > self.queue[max]:
                    max = i
            item = self.queue[max]
            del self.queue[max]
            return item
        except IndexError:
            print()
            exit()


def test():
    cond = True
    while cond:
        option = int(input('Select options:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n'))
        if(option == 1):
            value = int(input('Enter the value: '))
            myQueue.insert(value)
        elif(option == 2):
            while not myQueue.isEmpty():
                print(myQueue.delete())
        elif(option == 3):
            print(myQueue)
        elif(option == 4):
            print('Thank You')
            exit()
        else:
            print('Please Try Again')


if __name__=='__main__':
    myQueue = PriorityQueue()
    test()
            
                
