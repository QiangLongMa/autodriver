import matplotlib.pyplot as plt

# 读取文件
with open('path1.txt', 'r') as file:
    lines = file.readlines()

x_values = []
y_values = []
index_values = []
index_valuesss=[]
# 解析每一行数据
for line in lines:
    data = line.split()
    x_values.append(float(data[0]))
    y_values.append(float(data[1]))
    index_values.append(float(data[2]))
    # index_valuesss.append(float(data[3]))


# 绘制数据
plt.subplot(1, 2, 1)
plt.plot(x_values)
plt.title('u+')

# 绘制第二张图片
plt.subplot(1, 2, 2)
plt.plot(y_values)
plt.title('u')
plt.show()


plt.subplot(1,2,3)
plt.plot(index_values)
plt.title('kl')
plt.show()

