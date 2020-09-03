
# Solve N-queens problem using Min-conflicts algorithm
'''
YOUR TASKS:
1. Read to understand the following code 
2. Give comments on the min_conflicts() function to show your comprehensive understanding of the code
3. (Optional) Add GUI, animation...
'''

import random
import time 

#%% Utilities:
def argmin_random_tie(seq, key=lambda x: x):
    """Return a minimum element of seq; break ties at random."""
    items = list(seq)
    random.shuffle(items) #Randomly shuffle a copy of seq.
    return min(items, key=key)

class UniversalDict:
    """A universal dict maps any key to the same value. We use it here
    as the domains dict for CSPs in which all variables have the same domain.
    >>> d = UniversalDict(42)
    >>> d['life']
    42
    """      
    def __init__(self, value): self.value = value

    def __getitem__(self, key): return self.value

    def __repr__(self): return '{{Any: {0!r}}}'.format(self.value)


#%% CSP
class CSP():
    """This class describes finite-domain Constraint Satisfaction Problems.
    A CSP is specified by the following inputs:
        variables   A list of variables; each is atomic (e.g. int or string).
        domains     A dict of {var:[possible_value, ...]} entries.
        neighbors   A dict of {var:[var,...]} that for each variable lists
                    the other variables that participate in constraints.
        constraints A function f(A, a, B, b) that returns true if neighbors
                    A, B satisfy the constraint when they have values A=a, B=b
    """

    def __init__(self, variables, domains, neighbors, constraints):
        """Construct a CSP problem. If variables is empty, it becomes domains.keys()."""
        #super().__init__(())
        variables = variables or list(domains.keys())
        self.variables = variables
        self.domains = domains
        self.neighbors = neighbors
        self.constraints = constraints
        self.curr_domains = None
        self.nassigns = 0

    def assign(self, var, val, assignment):
        """
        Add {var: val} to assignment; Discard the old value if any.
        Thêm vào dictionary *assignment* một cặp {key : value} tương ứng là {var : val}, 
        thay thế giá trị value *val* cũ nếu đã tồn tại key là var trong dict.
        """
        assignment[var] = val
        self.nassigns += 1

    def unassign(self, var, assignment):
        """Remove {var: val} from assignment.
        DO NOT call this if you are changing a variable to a new value;
        just call assign for that."""
        if var in assignment:
            del assignment[var]

    def nconflicts(self, var, val, assignment):
        """Return the number of conflicts var=val has with other variables."""

        # Subclasses may implement this more efficiently
        def conflict(var2):
            return var2 in assignment and not self.constraints(var, val, var2, assignment[var2])

        return count(conflict(v) for v in self.neighbors[var])

    # This is for min_conflicts search  
    def conflicted_vars(self, current):
        """Return a list of variables in current assignment that are in conflict"""
        return [var for var in self.variables
                if self.nconflicts(var, current[var], current) > 0]


#%% N-queens problem
def queen_constraint(A, a, B, b):
    """Constraint is satisfied (true) if A, B are really the same variable,
    or if they are not in the same row, down diagonal, or up diagonal.
    
    Điều kiện ràng buộc constraint cho csp """
    return A == B or (a != b and A + a != B + b and A - a != B - b)

class NQueensCSP(CSP):
    """
    Make a CSP for the nQueens problem for search with min_conflicts.
    Suitable for large n, it uses only data structures of size O(n).
    Think of placing queens one per column, from left to right.
    That means position (x, y) represents (var, val) in the CSP.
    The main structures are three arrays to count queens that could conflict:
        rows[i]      Number of queens in the ith row (i.e. val == i)
        downs[i]     Number of queens in the \ diagonal
                     such that their (x, y) coordinates sum to i
        ups[i]       Number of queens in the / diagonal
                     such that their (x, y) coordinates have x-y+n-1 = i
    """

    def __init__(self, n):
        """Initialize data structures for n Queens."""
        
        CSP.__init__(self, 
                     variables = list(range(n)), 
                     domains = UniversalDict(list(range(n))),
                     neighbors = UniversalDict(list(range(n))), 
                     constraints = queen_constraint)

        self.rows = [0] * n
        self.ups = [0] * (2 * n - 1)
        self.downs = [0] * (2 * n - 1)

    def nconflicts(self, var, val, assignment):
        """The number of conflicts, as recorded with each assignment.
        Count conflicts in row and in up, down diagonals. If there
        is a queen there, it can't conflict with itself, so subtract 3."""
        n = len(self.variables)
        c = self.rows[val] + self.downs[var + val] + self.ups[var - val + n - 1]
        if assignment.get(var, None) == val:
            c -= 3
        return c

    def assign(self, var, val, assignment):
        """Assign var, and keep track of conflicts."""
        old_val = assignment.get(var, None)
        if val != old_val:
            if old_val is not None:  # Remove old val if there was one
                self.record_conflict(assignment, var, old_val, -1)
            self.record_conflict(assignment, var, val, +1)
            CSP.assign(self, var, val, assignment)

    def unassign(self, var, assignment):
        """Remove var from assignment (if it is there) and track conflicts."""
        if var in assignment:
            self.record_conflict(assignment, var, assignment[var], -1)
        CSP.unassign(self, var, assignment)

    def record_conflict(self, assignment, var, val, delta):
        """Record conflicts caused by addition or deletion of a Queen."""
        n = len(self.variables)
        self.rows[val] += delta
        self.downs[var + val] += delta
        self.ups[var - val + n - 1] += delta


#%% Min-conflicts for CSPs
''' READ AND COMMENT to show your comprehensive understanding of the following function '''
def min_conflicts(csp, max_steps=100000):
    """
    csp: a constraint satisfaction problem, (X, D, C)
    max_steps: số lần thử tối đa cho phép trước khi thông báo Failure 
    """

    csp.current = current = {} # an initial complete assignment for csp
    # Gán mỗi var của tập variables một giá trị (chính là giá trị số cặp conflicts là nhỏ nhất, 
    # nếu có nhiều giá trị min như vậy thì chọn random từ các vị trí min)
    for var in csp.variables:

        val = min_conflicts_value(csp, var, current)
        '''Thêm vào dictionary *assignment* một cặp {key : value} tương ứng là {var : val}, 
        thay thế giá trị value *val* cũ nếu đã tồn tại key là var trong dict.'''
        csp.assign(var, val, current)

    
    # Thực hiện một vòng lặp với số step tối đa được xác định trước 
    for i in range(max_steps):
        # Xác định xem có conflicted không.
        conflicted = csp.conflicted_vars(current)

        # if current is a solution for csp (not conflicted)
        # Nếu không conflicted, thì đó chính là solution của csp luôn 
        if not conflicted:
            return current

        # Chọn ngẫu nhiên một biến bị conflicted trong tập VARIABLES vẫn còn vi phạm ràng buộc 
        var = random.choice(conflicted) # a randomly chosen conflicted variable from csp.VARIABLES

        # Tính giá trị value cho biến var tương ứng, là giá trị conflicts nhỏ nhất hoặc random (nếu nó có nhiều giá trị min).
        val = min_conflicts_value(csp, var, current)

        # Gán giá trị var = val cho trạng thái current 
        csp.assign(var, val, current) # Thêm giá trị {var : val} vào dict current, thay thế giá trị val cũ nếu đã tồn tại var 

    # Sau khi thực hiện lặp với số lần là max_steps mà vẫn chưa tìm ra lời giải
    return None

def min_conflicts_value(csp, var, current):
    """Return the value that will give var the least number of conflicts.
    If there is a tie, choose at random."""
    return argmin_random_tie(csp.domains[var], key=lambda val: csp.nconflicts(var, val, current))


#%% main
if __name__ == '__main__':      
    problem = NQueensCSP(n=100)
    t = time.time()
    min_conflicts(problem, max_steps=100000); 
    total = time.time() - t
    print(problem.current);
    print("\n\n Time:", total)
    