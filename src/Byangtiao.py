import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import make_interp_spline

# 生成一些具有曲率不连续的点
x = np.linspace(0, 10, 10)
y = np.sin(x) + np.random.normal(scale=0.3, size=x.shape)  # 添加噪声的正弦波

# 绘制原始点
plt.scatter(x, y, color='red', label='Original Points')

# 使用 make_interp_spline 进行插值
degree = 5  # 五次B样条
spline = make_interp_spline(x, y, k=degree)

# 生成平滑曲线
x_smooth = np.linspace(x.min(), x.max(), 100)
y_smooth = spline(x_smooth)

# 输出平滑后的点坐标
smooth_points = np.column_stack((x_smooth, y_smooth))
print("Smooth Points Coordinates:")
print(smooth_points)

# 绘制平滑后的B样条曲线
plt.plot(x_smooth, y_smooth, color='blue', label='B-Spline Curve (Degree 5)')

# 图形设置
plt.title('B-Spline Curve Smoothing (Degree 5)')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.legend()
plt.grid()
plt.show()
