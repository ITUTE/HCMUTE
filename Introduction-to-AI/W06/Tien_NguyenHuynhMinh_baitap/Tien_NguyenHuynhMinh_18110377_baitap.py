'''
Reference: Bài làm có tham khảo cách phân chia class và các hàm trong class từ nguồn 
https://www.studocu.com/en-us/document/university-of-northern-iowa/communication-theories/other/iddfs-8-puzzle-iteratively-deepening-depth-first-search-code-for-8-puzzle-problem/4456870/view
Các thuật toán tham khảo từ slide bài giảng của giáo viên 
Các thao tác lập trình GUI bằng tkinter có tham khảo từ https://phocode.com/python/tkinter/tkinter-quan-ly-layout/
'''


import tkinter as tk 
import Problem 
import time 

def PrintPuzzle(index):
    '''Dùng để hiển thị puzzle lên giao diện '''
    global states 
    label = []
    currentState = states[index]
    for i in range(0,9):
        txt = str(currentState[i])
        label.append(tk.Label(frame, height = 3, width = 6, text = txt, bd = 2, bg = "cyan", relief = "solid", font = ("Arial Bold", 12)))
        label[i].grid(row = i//3, column = i%3)
    label[currentState.index(0)].config(text = "", bg = "White")

def ShowInfo():
    '''Hiển thị thông tin khi solve problem '''
    labelActions = tk.Label(window, text = "Actions = " + str(actions), bd = 0, relief = "solid")
    labelActions.place(x = 30, y = 350)

    labelTime = tk.Label(window, text = "Total time: " + str(totalTime) + " seconds.", bd = 0, relief = "solid")
    labelTime.place(x = 30, y = 380)

def PrintState(event):
    '''Hiển thị lần lượt các state trong quá trình giải. '''
    global index 
    if (index) < len(states):
        PrintPuzzle(index)
        index += 1
        if (index < len(states)):
            button.config(text = str(actions[index - 1]))
        else:
            button.config(text = "End")
    else:
        ShowInfo()

if __name__ == "__main__":

    initalState = [3,1,2,6,0,8,7,5,4]
    goalState = [0,1,2,3,4,5,6,7,8]
    problem = Problem.Problem(initalState, goalState)

    start = time.time()
    actions, states = problem.Solve() 
    totalTime = time.time() - start

    #window
    window = tk.Tk()
    window.title("8 - PUZZLE")
    window.geometry("400x400+200+200")

    #labelTitle
    labelTitle = tk.Label(window, text = "8 - PUZZLE", fg = "Red", font = ("Arial Bold", 30))
    labelTitle.place(x = 90, y = 10)

    #frame
    frame = tk.Frame(window, bd = 2, relief = "solid")
    frame.place(x = 105, y = 100)

    #Puzzle
    PrintPuzzle(0)

    index = 1
    #button
    button = tk.Button(window, text = "Solve", width = 8)
    button.place(x = 160, y = 300)
    button.bind("<Button-1>", PrintState)

    window.mainloop()