import Search 

class Problem:
    ''' Class Problem chứa các thông tin về Initial State, Goal State và hàm ACTIONS. Thông tin Solution lưu trong actions và savedState '''

    import queue 
    actions = queue.LifoQueue()        #Chứa các actions lần lượt của quá trình giải 
    savedStates = queue.LifoQueue()     #Chứa các State lần lượt duyệt qua trong quá trình giải 
    actionName = {-3:"UP", -1:"LEFT", 1:"RIGHT", 3:"DOWN"}

    def __init__(self, initialState, goalState=[0,1,2,3,4,5,6,7,8]):
        self.InitialState = initialState
        self.GoalState = goalState

    def Actions(self, node):
        Act = []
        index = node.State.index(0)
        if (index - 3 >= 0):
            Act.append(-3)
        if (index + 3 <= 8):
            Act.append(3)
        if (index - 1 >= 0 and (index//3 == (index - 1)//3)):
            Act.append(-1)
        if (index + 1 <= 8 and (index//3 == (index + 1)//3)):
            Act.append(1)
        return Act
    
    def GoalTest(seft, node):
        return node.State == seft.GoalState

    def Solution(self, node):
        return self.actions

    def Solve(self):
        result, states = Search.IDDFS(self)
        actions = [self.actionName[x] for x in result]
        return actions, states
