import itertools 
import Node 

def IDS(problem):
    '''
    Iteractive Deepening Search
    '''
    def Recursive_DLS(node, problem, limit):
        if problem.GoalTest(node):
            return problem.Solution()
        elif limit == 0:            #cutoff
            return 0 
        else:
            cutoff_occurred = False
            for action in problem.Action(node):
                child = node.ChildNode(action)
                problem.Actions.queue.append(action)
                problem.SavedStates.queue.append(child.State)
                result = Recursive_DLS(child, problem, limit - 1)
                if result == 0:     #cutoff
                    cutoff_occurred = True 
                    problem.Actions.queue.pop()
                    problem.SavedStates.queue.pop()
                elif result != -1:  #-1 = failure
                    return result
            if cutoff_occurred:
                return 0
            else:
                return -1 


    for depth in itertools.count():
        rootNode = Node.Node(problem.InitialState)
        result = Recursive_DLS(rootNode, problem, depth)
        if result != 0:
            return result
            #return problem.Actions.queue[:], problem.SavedStates.queue[:]