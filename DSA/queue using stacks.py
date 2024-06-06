class Queue:
    def __init__(self):cccccccccccccccccc
        self.stack1 = []
        self.stack2 = []

    def enqueue(self, item):
        self.stack1.append(item)

    def dequeue(self):
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        if self.stack2:
            return self.stack2.pop()
        else:
            raise IndexError("Queue is empty")

    def is_empty(self):
        return len(self.stack1) == 0 and len(self.stack2) == 0

    def size(self):
        return len(self.stack1) + len(self.stack2) 