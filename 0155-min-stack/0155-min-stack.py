class MinStack:

    def __init__(self):
        self.stk=[]
        self.minstk=[]
    
    def push(self, value: int) -> None:
        self.stk.append(value)

        if(len(self.minstk)==0 or value<=self.minstk[-1]):
            self.minstk.append(value)
    
    def pop(self) -> None:
        if(self.stk[-1]==self.minstk[-1]):
            self.minstk.pop()

        self.stk.pop()
    
    def top(self) -> int:
        return self.stk[-1]
    
    def getMin(self) -> int:
        return self.minstk[-1]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()