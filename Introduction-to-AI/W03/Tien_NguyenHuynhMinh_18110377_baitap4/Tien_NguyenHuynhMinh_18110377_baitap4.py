import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

#Đọc file dữ liệu
data = pd.read_csv(r"Data\time_series_covid19_confirmed_global.csv")
'''
Mô tả: Dữ liệu về số người nhiễm covid-19 của các quốc gia và vùng lãnh thổ trên thế giới
Try cập: 21:00 PM (ICT), ngày 12/4/2020
Nguồn: https://data.humdata.org/dataset/novel-coronavirus-2019-ncov-cases
'''

fig = plt.figure()
ax = fig.add_subplot(111)
days = data.columns.tolist()
x = np.arange(0, len(days) - 4)
# Chọn các quốc gia để vẽ dữ liệu
# Vietnam, Thailand, Singapore, Indonesia, Philippine, Malaysia
row_id = [228, 209, 196, 132, 182, 153]

for i in row_id:
    #Lấy data mỗi quốc gia
    raw_content = data.iloc[i, :]
    y = raw_content[4:]
    #Draw
    plt.plot(x,y)

#Tiêu đề cho biểu đồ
plt.title("Biểu đồ số ca nhiễm COVID-19 ở một số nước Đông Nam Á")
#Chú thích số liệu
plt.legend(data.iloc[row_id, 1])
#Chú thích cho mỗi trục tọa độ
plt.xlabel("Ngày")
plt.ylabel("Người")

ax.set_xticks(x[::5])
ax.set_xticklabels(days[4::5])
plt.show()