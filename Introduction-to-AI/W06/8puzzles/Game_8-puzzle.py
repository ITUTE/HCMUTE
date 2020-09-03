import tkinter as tk
import time
import Problem 

def ShowInfo():
    #labelAct
    labelAct = tk.Label(window, bd = 2, text = "Actions: " + str(Actions))
    labelAct.place(x = 30, y = 340)
    #labelTime
    labelTime = tk.Label(window, text = "Total searching time: %f seconds" % (totalTime))
    labelTime.place(x = 30, y = 370)

def PrintPuzzle(index):
    label = []
    state = States[index]
    for i in range(0,9):
        txt = str(state[i])
        label.append(tk.Label(frame, height = 3, width = 6, bd = 2, bg = "Cyan", text = txt, relief = "solid", font = ("Arial Bold", 12)))
        label[i].grid(column = i%3, row = i//3)
    label[state.index(0)].config(bg = "White", text = "")

def Solution(event):
    global index 
    global Actions

    if index < len(States):
        PrintPuzzle(index)
        index += 1
        if index < len(States):
            button.config(text = Actions[index])
        else:
            button.config(text = "End")
    else:
        ShowInfo()

if __name__ == "__main__":

    #Main()
    initialState = [3,1,2,6,0,8,7,5,4]
    goalState = [0,1,2,3,4,5,6,7,8]
    problem = Problem.Problem(initialState, goalState)

    start = time.time()
    Actions, States = problem.Solve()
    totalTime = time.time() - start

    #window
    window = tk.Tk()
    window.title("8-PUZZLE")
    window.geometry("400x400")

    #labelTitle
    labelTitle = tk.Label(window, text = "8-PUZZLE", fg = "red", font = ("Arial Bold", 30))
    labelTitle.place(x = 100, y = 10)

    #frame 
    frame = tk.Frame(window, bd = 2, relief = "solid")
    frame.place(x = 100, y = 100)
        
    #Show Puzzle first
    index = 0
    PrintPuzzle(index)

    #button
    button = tk.Button(window, text = "Action", relief = "raised", width = 7)
    button.place(x = 160, y = 300)
    button.bind('<Button-1>', Solution) #Click event

    window.mainloop()
    