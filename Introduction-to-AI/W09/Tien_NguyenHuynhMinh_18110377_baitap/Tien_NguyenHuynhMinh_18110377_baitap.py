# Solve N-queens problems using AND-OR search algorithm

from collections import deque
import tkinter as tk 
import numpy as np
import time 

class Node:
    def __init__(self, state, parent=None, action=None, path_cost=0):
        """Create a search tree Node, derived from a parent by an action."""
        self.state = state
        self.parent = parent
        self.action = action
        self.path_cost = path_cost
        self.depth = 0
        if parent:
            self.depth = parent.depth + 1

    def expand(self, problem):
        """List the nodes reachable in one step from this node."""
        return [self.child_node(problem, action)
                for action in problem.actions(self.state)]

    def child_node(self, problem, action):
        next_state = problem.result(self.state, action)
        #next_node = Node(next_state, self, action, problem.path_cost(self.path_cost, self.state, action, next_state))
        next_node = Node(next_state, self, action)
        return next_node


class NQueensProblem:
    """The problem of placing N queens on an NxN board with none attacking each other. 
    A state is represented as an N-element array, where a value of r in the c-th entry means there is a queen at column c,
    row r, and a value of -1 means that the c-th column has not been filled in yet. We fill in columns left to right.
    
    Sample code: iterative_deepening_search(NQueensProblem(8))
    Result: <Node (0, 4, 7, 5, 2, 6, 1, 3)>
    """

    def __init__(self, N):
        #self.initial = initial 
        self.initial = tuple([-1]*no_of_queens)  # -1: no queen in that column
        self.N = N

    def actions(self, state):
        """In the leftmost empty column, try all non-conflicting rows."""
        if state[-1] is not -1:
            return []  # All columns filled; no successors
        else:
            col = state.index(-1)
            #return [(col, row) for row in range(self.N)
            return [row for row in range(self.N)
                    if not self.conflicted(state, row, col)]

    def goal_test(self, state):
        """Check if all columns filled, no conflicts."""
        if state[-1] is -1:
            return False
        return not any(self.conflicted(state, state[col], col)
                       for col in range(len(state)))

    def result(self, state, row):
        """Place the next queen at the given row."""
        col = state.index(-1)
        new = list(state[:])
        new[col] = row
        return tuple(new)

    def conflicted(self, state, row, col):
        """Would placing a queen at (row, col) conflict with anything?"""
        return any(self.conflict(row, col, state[c], c)
                   for c in range(col))

    def conflict(self, row1, col1, row2, col2):
        """Would putting two queens in (row1, col1) and (row2, col2) conflict?"""
        return (row1 == row2 or  # same row
                col1 == col2 or  # same column
                row1 - col1 == row2 - col2 or  # same \ diagonal
                row1 + col1 == row2 + col2)  # same / diagonal

    def value(self, node): 
        """Return (-) number of conflicting queens for a given node"""
        num_conflicts = 0
        for (r1, c1) in enumerate(node.state):
            for (r2, c2) in enumerate(node.state):
                if (r1, c1) != (r2, c2):
                    num_conflicts += self.conflict(r1, c1, r2, c2)

        return -num_conflicts 

def StateToBoard(state):
    '''Dùng để chuyển từ mảng 1 chiều state sang mảng 2 chiều, để dễ biểu diễn trên ChessBoard'''
    a = np.zeros((no_of_queens, no_of_queens))  #tạo mảng 2D có kích cỡ no_of_queens x no_of_queens, mặc định 15x15
    for i in range(no_of_queens):
        a[state[i], i] = -1         #Tại các hàng đặt quân hậu (state[i]) ứng với từng cột i, đánh dấu -1 để vẽ lên đồ họa 
    return a


def ShowSolution(state, is_init):
    '''Dùng để tạo ra giao diện cho ChessBoard'''
    board = StateToBoard(state)
    for r in range(no_of_queens):
        for c in range(no_of_queens):
            if is_init:
                label.append(tk.Label(frame, bd = 0.5, relief = "solid", width = 4, height = 2))

            color = "white"
            if r%2 == c%2:
                color = "gray"
            if board[r][c] == -1:
                color = "red"
            label[no_of_queens*r + c].grid(row = r, column = c)
            label[no_of_queens*r + c].config(bg = color)


def and_or_graph_search(problem):
    '''
    Thuật toán AND-OR SEARCH (AO*) dùng để tìm lời giải cho bài toán N quân hậu.
    Hàm and_or_graph_search() sử dụng đệ quy tương hỗ, dựa trên Depth-First Search để tìm goal state.
    Sử dụng 2 hàm con, gọi đệ quy lẫn nhau là or_search() và and_search().
    '''

    def or_search(state, problem, path):
        '''
        Return None nếu Failure.
        state: state hiện tại, là một tuple chứa trạng thái của các quân hậu trên bàn cờ.
        problem: là thể hiện (instance) của NQUEENSPROBLEM.
        path: 
        '''

        if problem.goal_test(state):
            print(state)
            ShowSolution(state, False)
            window.update()
            return []

        if state in path:
            return None
        actions = problem.actions(state)

        plans = []
        for action in actions:
            plan = and_search([problem.result(state, action)], problem, [state] + path)
            
            #Nếu tìm thấy goal state, mỗi action chỉ ứng với 1 goal state (NQueens) nên có thể return luôn 
            if plan is not None:
                plans.append((action, plan))

        if len(plans) > 0:
            return plans
        return None


    def and_search(states, problem, path):
        '''
        Return dictionary là plans nếu có thể tìm thấy ít nhất một goal state ứng với state s_i. Ngược lại, return None.
        states: list các states (chính là các successors của state hiện tại ở or_search()).
        problem: là thể hiện (instance) của NQUEENSPROBLEM.
        path:
        '''

        plans = {}  #plan là mọt dictionary, có key là 1 state cụ thể, mỗi key ứng với một value là kết quả trả về của hàm or_search().

        #Thêm các phần tử vào plan 
        for state in states:
            plan = or_search(state, problem, path)
            if plan is None:
                continue
            else:
                plans[state] = plan
        
        '''Có thể sau khi chuẩn hóa dictionary plans thì không còn phần tử nào.
        Nghĩa là từ state ở or_search(), sinh ra các successors, không một successor nào đi đến được goal state.'''
        if len(plans) > 0:
            return plans
        else:
            return None



    state = problem.initial
    plans = {}
    plans[state] = or_search(state, problem, [])
    return plans


def ListGoalTest(dictionary):
    for key in dictionary:
        array = dictionary.get(key)
        if array == []:
            goalStates.append(key)
        else:
            for item in dictionary.get(key):
                action, plan = item
                ListGoalTest(plan)


if __name__ == '__main__':


    no_of_queens = 4

    problem1 = NQueensProblem(no_of_queens)

    ###################################################################

    window = tk.Tk()
    window.title("N - QUEENS")
    window.geometry("600x650+500+50")

    #frame
    frame = tk.Frame(window, bd = 0.5, relief = "solid")
    frame.place(x = 60, y = 60)
     
    #Chessboard
    label = []

    ShowSolution(problem1.initial, True)

    window.update()

    ####################################################################
    start = time.time()
    result2 = and_or_graph_search(problem1)
    total = time.time() - start
    print(result2)

    goalStates = deque()
    if (result2 is not None) and (not any(result2.get(key) == None for key in result2)):
        ListGoalTest(result2)

    print("\nNo. goal states: ", len(goalStates))
    print("\nTime: ", total, end="\n\n")
    #print(goalStates)

    with open("output.txt", "w") as f:
        print(len(goalStates), file = f, end = '\n\n')
        print("Time: ", total, file = f, end="\n\n")
        print(result2, file = f, end = '\n\n\n')
        for goal in goalStates:
            print(goal, file = f)
        
    f.close()
    window.mainloop()