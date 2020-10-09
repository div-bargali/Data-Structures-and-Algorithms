class CircQueue:
    """
    Implementation of circular, array-backed queue data structure
    """

    # circular queue keeps track of position of recently enqueued item and
    # position of next item to dequeue
    def __init__(self, limit=20):
        self.data = [None] * limit
        self.head = -1
        self.tail = -1

    # add item into the queue
    def enqueue(self, val):
        if (self.tail + 1) % len(self.data) == self.head:
            raise RuntimeError

        if self.head == self.tail == -1:
            self.tail = 0
            self.head = 0
        else:
            self.tail = (self.tail + 1) % len(self.data)

        self.data[self.tail] = val

    # remove and return the first item in the queue (first in first out)
    def dequeue(self):
        if self.head == -1:
            raise RuntimeError

        data = self.data[self.head]
        self.data[self.head] = None

        if self.head == self.tail:
            self.head = -1
            self.tail = -1
        else:
            self.head = (self.head + 1) % len(self.data)

        return data

    # resize data array to given size
    def resize(self, newsize):
        assert newsize > len(self.data)

        new_data = []
        for item in self:
            new_data.append(item)

        self.tail = len(new_data) - 1

        for _ in range(newsize - len(self.data)):
            new_data.append(None)

        self.data = new_data
        self.head = 0

    # return True if queue is empty, otherwise False
    def empty(self):
        for item in self.data:
            if item is not None:
                return False
        return True

    # return True if queue is not empty, otherwise False
    def __bool__(self):
        return not self.empty()

    # return all data in queue in a string
    def __str__(self):
        if not self:
            return ''
        return ', '.join(str(item) for item in self)

    # return all data in queue in a string
    def __repr__(self):
        return str(self)

    # iter through the queue
    def __iter__(self):
        idx = self.head
        while idx != self.tail:
            yield self.data[idx]
            idx = (idx + 1) % len(self.data)
        yield self.data[idx]


# print option menu and take user input
def option_menu():
    print("1. Enqueue")
    print("2. Dequeue")
    print("3. Resize Queue")
    print("4. Print Queue")
    print("5. Exit")

    try:
        option = int(input("Enter option: "))
        return option

    except Exception as e:
        print(f"ERROR: {e}\n")

# test function
def test():
    q = CircQueue()

    while True:
        option = option_menu()

        if option == 1:
            while True:
                try:
                    item = int(input("Enter value to enqueue (enter character to quit): "))
                    q.enqueue(item)
                except:
                    print()
                    break

        elif option == 2:
            print("Result of dequeue: ", q.dequeue(), "\n")

        elif option == 3:
            new_size = int(input("Enter new size: "))
            q.resize(new_size)

        elif option == 4:
            print("Current queue: ", q)
            print("Current queue data: ", q.data, "\n")

        elif option == 5:
            print("Exiting...")
            break

        else:
            print("Invalid option\n")

if __name__ == "__main__":
    test()
