import itertools 
import NodePuzzle as Node 

def IDDFS(problem): 
        ''' Iterative Deepening Depth First Search '''

        def Recursive_DLS(node, problem, limit):
            ''' Recursive Depth Limited Search '''
            if problem.GoalTest(node):
                return problem.Solution(node)   #Success 
            if limit == 0:
                return 0                #Cutoff 
            
            cutoff_occurred = False
            for action in problem.Actions(node):
                child = node.ChildNode(action)      #Tạo 1 node mới từ node hiện tại 
                problem.actions.queue.append(action)
                problem.savedStates.queue.append(child.State)
                result = Recursive_DLS(child, problem, limit - 1) #Gọi đệ quy 
                if result == 0: #Cutoff
                    cutoff_occurred = True
                    problem.actions.queue.pop()
                    problem.savedStates.queue.pop()
                elif result != -1:  #Success
                    return result

            if cutoff_occurred:
                return 0
            else:
                return -1

        for depth in itertools.count(): #vòng lặp từ 0 .. inf 
            rootNode = Node.Node(problem.InitialState)          
            result = Recursive_DLS(rootNode, problem, depth)
            if result != -1 and result != 0:
                return problem.actions.queue[:], problem.savedStates.queue[:]

