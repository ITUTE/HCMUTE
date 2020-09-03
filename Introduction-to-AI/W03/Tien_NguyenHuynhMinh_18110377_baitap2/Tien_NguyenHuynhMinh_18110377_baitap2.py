import numpy as np

a = np.array([ [1,3,5,7], [4,5,2,1], [9,1,7,8], [4,1,7,3]])

#Tim gia tri lon nhat matrix
a.max()

#Tim cac phan tu lon nhat moi cot
#return list cacs phan tu lon nhat moi cot
a.max(0)

#Tim cac phan tu lon nhat moi dong
#return list cac phan tu lon nhat moi dong
a.max(1)

x=1