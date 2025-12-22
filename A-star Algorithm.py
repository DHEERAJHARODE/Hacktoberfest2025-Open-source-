from queue import *
class State(object):
    def __init__(self,value, parent, start=0,goal=0,solver=0):
        self.children = []
        self.parent = parent
        self.value = value
        self.dist = 0
        if parent:
            self.path = parent.path[:]
            self.path.append(value)
            self.start = parent.start
            self.goal = parent.goal
            self.solver = parent.solver
        else:
            self.path = [value]
            self.start = start
            self.goal = goal
            self.solver = solver

    def GetDist(self):
        pass
    def CreateChildren(self):
        pass


class State_String(State):
    def __init__(self, value, parent, start=0, goal=0, solver=0):
        super(State_String,self).__init__(value, parent, start, goal, solver)
        self.dist =self.GetDist()
    def GetDist(self):
        if self.value == self.goal:
            return 0
        dist = 0
        for i in range(len(self.goal)):
            letter = self.goal[i]
            dist += abs(i - self.value.index(letter))
        return dist
    def CreateChildren(self):
        if not self.children:
            for i in range(len(self.goal)-1):
                val = self.value
                val = val[:i]+val[i+1]+val[i]+val[i+2]
                child = State_String(val,self)
                self.children.append(child)

class Astar_Solver:
    def __init__(self,start,goal):
        self.path = []
        self.visitedQueue = []
        self.priorityQueue = PriorityQueue()
        self.start = start
        self.goal = goal

    def Solver(self):
        startState = State_String(self.start,0,self.start,self.goal,self)
        count = 0
        self.priorityQueue.put((0,count,startState))
        while(not self.path and self.priorityQueue.qsize()):
            closestChild = self.priorityQueue.get()[2]
            closestChild.CreateChildren()
            self.visitedQueue.append(closestChild.value)
            for child in closestChild:
                if child.value not in  self.visitedQueue:
                    count += 1

                    if not child.dist:
                        self.path = child.path
                        break
                    self.priorityQueue.put((child.dist,count,child))

        if not self.path:
            print("Goal"+self.goal+"is not possible")
        return self.path

        if __name__ == "__main__":
            start1 = "cdabfe"
            goal1 = "abcdef"
            print("Starting")
            a = Astar_Solver(start1,goal1)
            a.Solve()
            for i in xrange(len(a.path)):
                print("%d" %i + a.path[i])