# Solve N-queens problems using Simulated annealing algorithm
#  Tham khảo phần giao diện: https://youtu.be/7w8jk0r4lxA

import sys
from collections import deque
import numpy as np
import random
import itertools 
import math
import tkinter as tk 
import time 
from PIL import Image, ImageTk 

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
        ''' Các node con có thể sinh ra từ node hiện tại, ứng với action '''
        next_state = problem.result(self.state, action)
        #next_node = Node(next_state, self, action, problem.path_cost(self.path_cost, self.state, action, next_state))
        next_node = Node(next_state, self, action) #tạo mới một child_node 
        return next_node
# ______________________________________________________________________________

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
        if state[-1] is not -1: #Cột cuối cùng đã được đặt quân hậu 
            return []  # All columns filled; no successors
        else:
            col = state.index(-1)   #Tìm vị trí trái nhất, là cột chưa đặt quân hậu vào 
            #return [(col, row) for row in range(self.N)
            return [row for row in range(self.N)
                    if not self.conflicted(state, row, col)]

    def result(self, state, row):
        """
        Place the next queen at the given row.
        Đặt quân hậu tiếp theo vào hàng row, của cột trống trái nhất.
        """
        col = state.index(-1)
        new = list(state[:])
        new[col] = row
        return tuple(new)

    def conflicted(self, state, row, col):
        """Would placing a queen at (row, col) conflict with anything?"""
        return any(self.conflict(row, col, state[c], c)
                   for c in range(col))

    def conflict(self, row1, col1, row2, col2):
        """
        Would putting two queens in (row1, col1) and (row2, col2) conflict?
        Kiểm tra 2 quân hậu lần lượt tại các ô có vị trí (row1, col1) và (row2, col2) có ăn nhau được không?
        """
        return (row1 == row2 or  # same row
                col1 == col2 or  # same column
                row1 - col1 == row2 - col2 or  # same \ diagonal
                row1 + col1 == row2 + col2)  # same / diagonal

    def value(self, node): 
        """
        Return (-) number of conflicting queens for a given node
        Trả về 1 số nguyên âm, cho biết số quân hậu có thể ăn nhau.
        Dấu (-) để giúp thuật toán tìm kiếm global maximun. Khi đó, global maximum = 0.
        """
        num_conflicts = 0 #num_conflicts là số nguyên dương, cho biết số quân hậu có thể ăn nhau
        for (r1, c1) in enumerate(node.state):
            for (r2, c2) in enumerate(node.state):
                if (r1, c1) != (r2, c2):
                    num_conflicts += self.conflict(r1, c1, r2, c2)  #Nếu 2 quân hậu có thể ăn nhau, num_conflicts sẽ tăng 1 (True = 1).

        return -num_conflicts 

def schedule(t, k = 20, lam = 0.005, limit = 1000):
    """One possible schedule function for simulated annealing"""
    return (k * np.exp(-lam * t) if t < limit else 0) 

def simulated_annealing(problem):
    
    #Khởi tạo node hiện tại (current node) của problem 
    current = Node(problem.initial)

    #Vòng lặp 1 đến vô cùng 
    for t in itertools.count(start = 1):

        # Tính giá trị nhiệt độ T 
        T = schedule(t)

        # Nếu nhiệt độ T = 0, quá trình luyện kim (annealing) kết thúc 
        if T == 0:
            return current.state

        #Tìm các neighbors của current state 
        successors = current.expand(problem)
        
        # Nếu đi vào trạng thái đường cùng (local maximum) 
        # Không thể đặt thêm 1 quân hậu nào nữa 
        if len(successors) == 0:
            # Nhưng vẫn còn có cột cần phải đặt quân hậu 
            if current.state.count(-1) > 0:
                # Thì phải Random lại từ đầu, để có solution khác 
                current = Node(problem.initial)
        else:
            #chọn ngẫu nhiên 1 successor trong tập các successors được expend từ node hiện tại (current node)
            next = random.choice(successors)

            #Tính giá trị deltaE 
            deltaE = problem.value(next) - problem.value(current)

            #Nếu deltaE > 0, nghĩa là nếu chọn node là next, ta có giá trị tốt hơn giá trị của current 
            if deltaE > 0:
                current = next
            # Ngược lại, chọn với điều kiện xác suất e^(deltaE/T)
            elif random.uniform(0.0, 1.0) < math.exp(deltaE/T): 
                current = next 


def Solve():
    begin = time.time()
    result = simulated_annealing(problem)       
    totalTime = time.time() - begin 

    print(result)

    InitChessBoard(result)  #Thể hiện lên giao diện ChessBoard 
    labelTime.config(text = "Total time: " + str(totalTime) + " sec.") #cập nhật thông tin thực thi việc tìm kiếm solution 

def StateToBoard(state):
    '''Dùng để chuyển từ mảng 1 chiều state sang mảng 2 chiều, để dễ biểu diễn trên ChessBoard'''
    a = np.zeros((no_of_queens, no_of_queens))  #tạo mảng 2D có kích cỡ no_of_queens x no_of_queens, mặc định 15x15
    for i in range(no_of_queens):
        a[state[i], i] = -1         #Tại các hàng đặt quân hậu (state[i]) ứng với từng cột i, đánh dấu -1 để vẽ lên đồ họa 
    return a

def InitChessBoard(state):
    '''Dùng để tạo ra giao diện cho ChessBoard'''
    board = StateToBoard(state)
    global img
    for r in range(no_of_queens):
        for c in range(no_of_queens):
            label.append(tk.Label(frame, bd = 0.5, relief = "solid", width = 4, height = 2))
            color = "white"
            if r%2 == c%2:
                color = "gray"
            if board[r][c] == -1:
                color = "red"
            label[no_of_queens*r + c].grid(row = r, column = c)
            label[no_of_queens*r + c].config(bg = color)

def SolveEvent(event):
    ''' Event gán cho button. '''
    Solve()

if __name__ == '__main__':
    no_of_queens = 15;
    random.seed(1)
    problem = NQueensProblem(no_of_queens)
    
    ###################################################################
    
    #window
    window = tk.Tk()
    window.title("N - QUEENS")
    window.geometry("600x650+300+50")

    #frame
    frame = tk.Frame(window, bd = 0.5, relief = "solid")
    frame.place(x = 60, y = 60)

    #Chessboard
    label = []

    #pic = Image.open("queen.png")
    #pic = pic.resize((128,128), Image.ANTIALIAS)
    #img = ImageTk.PhotoImage(pic)

    #Button
    button = tk.Button(window, text = "SOLVE", bg = "gray", width = 8, relief = "raised", bd = 1)
    button.place(x = 60, y = 610)
    button.bind('<Button-1>', SolveEvent)

    #labelTime
    labelTime = tk.Label(window)
    labelTime.place(x = 160, y = 610)

    Solve() #Show lời giải ban đầu

    window.mainloop()