import matplotlib.pyplot as plt
import numpy as np

# 读取数据文件
def write(filename, index):
    x_values = []
    y_values = []
    curvature_values = []
    heading_values = []
    
    with open(filename, 'r') as file:
        for line in file:
            # 分割每一行的数据，并将其转换为浮点数
            data = line.strip().split()
            
            if len(data) >= 5:  # 确保数据行中有足够的元素
                x = float(data[0])  # 第一个数据为 x
                y = float(data[1])  # 第二个数据为 y
                curvature = float(data[4])  # 第五个数据为曲率
                heading = float(data[3])  # 第四个数据为航向角
                
                # 将 x, y 和曲率添加到列表中
                x_values.append(x)
                y_values.append(y)
                curvature_values.append(curvature)
                heading_values.append(heading)

    # 创建两个子图
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 12))

    # 绘制 x, y 的散点图
    scatter = ax1.scatter(x_values, y_values, c=curvature_values, cmap='viridis', marker='o')
    cbar = plt.colorbar(scatter, ax=ax1)
    cbar.set_label('Curvature')  # 添加颜色条表示曲率
    ax1.set_title(f'2D Plot of (x, y) with Curvature (File {index})')  # 显示文件索引
    ax1.set_xlabel('X')
    ax1.set_ylabel('Y')
    ax1.grid()

    # 绘制航向角曲线 , linestyle=''
    ax2.plot(heading_values, color='blue', label='Heading Angle')
    ax2.set_title('Heading Angle vs. X')
    ax2.set_xlabel('X')
    ax2.set_ylabel('Heading Angle (degrees)')
    ax2.grid()
    ax2.legend()  # 添加图例
# 反转 x 轴
    ax2.invert_xaxis()
    plt.tight_layout()  # 自动调整子图间距
    plt.show()

# 读取多个文件
for i in range(1, 165):
    file1 = f'/home/mm/longshan11_6/local/{i}.txt'
    write(file1, i)  # 将文件索引传递给函数
