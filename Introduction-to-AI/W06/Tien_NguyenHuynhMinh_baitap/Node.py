class Node:
    '''
    Node dùng để chứa thông tin của một node trong Tree Search
    State: lưu trạng thái hiện tại của puzzle
    Parent: cho biết node cha của node hiện tại 
    '''

    def __init__(self, state, parent = None):
        self.State = state
        self.Parent = parent 

    def ChildNode(self, action):
        '''Tạo ra các node con tùy vào action cụ thể. Tương tự hàm Result(state s, action a).'''
        newState = self.State[:]
        indexZero = newState.index(0)
        newState[indexZero], newState[indexZero + action] = newState[indexZero + action], newState[indexZero]
        return Node(newState, parent = self)
