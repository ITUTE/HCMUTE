import tkinter as tk
import time

class Node:
    '''
    
    '''

    def __init__(self, position, parent = None, f_value = 0, g_value = 0, h_value = 0):
        self.position = position
        self.parent = parent

        self.f = f_value
        self.g = g_value
        self.h = h_value

    def __eq__(self, other):
        return self.position == other.position

    def ChildNode(self):
        children = []
        for new_position in [(0, -1), (0, 1), (-1, 0), (1, 0), (-1, -1), (-1, 1), (1, -1), (1, 1)]: # Adjacent squares

            # Get node position
            node_position = (self.position[0] + new_position[0], self.position[1] + new_position[1])

            # Make sure within range
            if node_position[0] > (len(maze) - 1) or node_position[0] < 0 or node_position[1] > (len(maze[len(maze)-1]) -1) or node_position[1] < 0:
                continue

            # Make sure walkable terrain
            if maze[node_position[0]][node_position[1]] != 0:
                continue

            # Create new node
            new_node = Node(position = node_position, parent = self)

            # Append
            children.append(new_node)

        return children


def astar(maze, start, end):
    '''

    '''

    # Create start and end node
    start_node = Node(start)
    end_node = Node(end)

    # Initialize both open and closed list
    open_list = []    # frontier queue
    closed_list = []  # explored set

    # Add the start node
    open_list.append(start_node)

    # Loop until you find the end
    while len(open_list) > 0:

        # Get the current node
        current_node = open_list[0]
        current_index = 0
        #Tim index va gia tri cua ham f nho nhat cua node trong list
        for index, item in enumerate(open_list):
            if item.f < current_node.f:
                current_node = item
                current_index = index

        # Pop current off open list, add to closed list
        open_list.pop(current_index)
        closed_list.append(current_node)

        # Check if we found the goal
        if current_node == end_node:
            path = []
            current = current_node
            while current is not None:
                path.append(current.position)
                current = current.parent
            return path[::-1] # Return reversed path

        children = current_node.ChildNode()
        for child in children:
            # Create the f, g, and h values
            #http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html#diagonal-distance
            child.g = current_node.g + 1
            dx = abs(child.position[0] - end_node.position[0])
            dy = abs(child.position[1] - end_node.position[1])
            child.h = (dx + dy) - min(dx, dy)    #Chebyshev distance
            child.f = child.g + child.h

            if child not in open_list and child not in closed_list:
                open_list.append(child)
            elif child in open_list:
                Check(open_list, open_list, child)
            elif child in closed_list:
                Check(closed_list, open_list, child)
            else:
                continue      

def Check(list, open_list, child):
    for index, node in enumerate(list):
        if child == node and child.g < node.g:
            list.pop(index)
            open_list.append(child)
            return


if __name__ == '__main__':

    ''' CHANGE THE BELOW VARIABLE TO REFLECT TO THE MAZE MAP IN THE EXERCISE '''
    maze =     [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 
                [0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
                [0, 1, 0, 0, 0, 1, 1, 1, 1, 0],  # 1: obstacle position
                [0, 1, 0, 0, 0, 1, 0, 0, 0, 0],
                [0, 1, 1, 1, 1, 1, 0, 0, 0, 0],
                [0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
                [0, 0, 0, 1, 0, 0, 1, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 1, 0, 0, 0]]

    start = (0, 0)
    goal = (8, 9)

    startTime = time.time()
    path = astar(maze, start, goal)
    totalTime = time.time() - startTime

    print(path) 
    print(totalTime)



    #window
    window = tk.Tk()
    window.title("TÌM ĐƯỜNG TRONG MÊ CUNG")
    window.geometry("400x400+200+200")

    #labelTitle
    labelTitle = tk.Label(window, text = "MÊ CUNG", fg = "Red", font = ("Arial Bold", 30))
    labelTitle.place(x = 100, y = 10)

    #frame
    frame = tk.Frame(window, bd = 0.5, relief = "solid")
    frame.place(x = 85, y = 80)

    #Maze
    label = []
    for i in range(0,100):
        (x, y) = (i//10, i%10)
        color = "cyan"
        if maze[x][y] == 1:
            color = "black"
        label.append(tk.Label(frame, height = 1, width = 2, bd = 0.5, bg = color, relief = "solid", font = ("Arial Bold", 12)))
        label[i].grid(row = x, column = y)

    label[start[0]*10 + start[1]].config(bg = "Red")
    label[goal[0]*10 + goal[1]].config(bg = "Red")

    index = 0

    def PrintPath(event):
        global index 
        if (index == len(path)):
            #label info
            labelInfo = tk.Label(window, text = "Total time: " + str(totalTime) + " sec")
            labelInfo.place(x = 90, y = 360)
        else:
            (r, c) = path[index]
            label[10*r + c].config(bg = "Yellow")
            index += 1

    
    #button
    button = tk.Button(window, text = ">>>", width = 8)
    button.place(x = 160, y = 320)
    button.bind("<Button-1>", PrintPath)

    window.mainloop()