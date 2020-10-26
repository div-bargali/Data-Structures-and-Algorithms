# Implementing a queue using two stacks

class queue:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    
    # push element into the queue
    def push(self, x):
        self.stack1.append(x)

    # pop element form the queue
    def pop_op(self):
        
        # if both the stacks are empty
        if len(self.stack1) == 0 and len(self.stack2) == 0:
            print("Queue is empty.")
            return
        
        # if stack2 is empty and stack1 does contain elements
        elif len(self.stack1) > 0 and len(self.stack2) == 0:
            while len(self.stack1):
                temp = self.stack1.pop()
                self.stack2.append(temp)
            return self.stack2.pop()

        # else
        else:
            return self.stack2.pop()

# driver code
if __name__ == "__main__":
    q = queue()
    q.push(1)
    q.push(4)
    q.push(9)
    q.push(16)
    q.push(25)
    q.push(36)
    q.push(49)
    q.push(64)
    q.push(81)
    q.push(100)

    print(q.pop_op())
    print(q.pop_op())
    print(q.pop_op())
    print(q.pop_op())
    print(q.pop_op())
    print(q.pop_op())
    print(q.pop_op())
    print(q.pop_op())
    print(q.pop_op())
    print(q.pop_op())
