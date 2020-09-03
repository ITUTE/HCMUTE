class Node:
    ''' 
    Dùng để định nghĩa 1 node
        State: là 1 mảng 1 chiều dùng để chứa puzzle 3x3 
        Parent: là node cha sinh ra node hiện tại 
    '''

    def __init__(self, state, parent = None):
        self.State = state
        self.Parent = parent

    def ChildNode(seft, action):
        newState = seft.State[:]        #Tạo một bản copy của State hiện tại 
        zeroPos = newState.index(0)     #Tìm vị trí ô trống 
        newState[zeroPos], newState[zeroPos + action] = newState[zeroPos + action], newState[zeroPos] #swap
        return Node(newState, parent = seft)
