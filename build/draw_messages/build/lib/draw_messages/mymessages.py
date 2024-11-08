import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

class SpeedVisualizer(Node):
    def __init__(self):
        super().__init__('speed_visualizer')
        self.subscription = self.create_subscription(Float32, '/speed_topic', self.speed_callback, 10)
        self.subscription2 = self.create_subscription(Float32, '/error_topic', self.error_callback, 10)

        self.speeds = []
        self.errors = []

        # 初始化图形
        self.fig, (self.ax_speed, self.ax_error) = plt.subplots(2, 1)
        
        self.line_speed, = self.ax_speed.plot(self.speeds, color='g', label='Speed')
        self.ax_speed.set_ylim(0, 100)  # 根据实际速度范围调整
        self.ax_speed.set_title("Speed Visualization(km/h)")
        self.ax_speed.legend()

        self.line_error, = self.ax_error.plot(self.errors, color='r', label='Error')
        self.ax_error.set_ylim(-2, 100)  # 根据实际误差范围调整
         # 设置 y 轴的次刻度为 0.1
        self.ax_error.yaxis.set_major_locator(ticker.MultipleLocator(20))
        self.ax_speed.yaxis.set_major_locator(ticker.MultipleLocator(2))
        
        self.ax_error.set_title("Error Visualization(cm)")
        self.ax_error.legend()
        # 添加文本框以显示最新数据
        self.text_speed = self.ax_speed.text(0.05, 0.95, '', transform=self.ax_speed.transAxes, fontsize=10)
        self.text_error = self.ax_error.text(0.05, 0.95, '', transform=self.ax_error.transAxes, fontsize=10)
        plt.ion()  # 开启交互模式
        plt.show()

        # 绑定关闭事件
        self.fig.canvas.mpl_connect('close_event', self.on_close)

    def speed_callback(self, msg):
        print(msg.data*3.6)
        self.speeds.append((msg.data * 3.6))
        # 更新速度线
        self.line_speed.set_ydata(self.speeds)
        self.line_speed.set_xdata(range(len(self.speeds)))
        # 更新Y轴范围
        self.ax_speed.set_ylim(0, max(max(self.speeds), 20))
        # 更新文本框显示最新速度
        self.text_speed.set_text(f'Latest Speed: {msg.data*3.6:.2f} km/h')

        self.ax_speed.relim()  # 重新计算坐标轴
        self.ax_speed.autoscale_view()  # 自动缩放
        plt.draw()
        plt.pause(0.01)  # 暂停以更新图形

    def error_callback(self, msg):
        self.errors.append(msg.data * 100)
        # 更新误差线
        self.line_error.set_ydata(self.errors)
        self.line_error.set_xdata(range(len(self.errors)))

        # 更新Y轴范围
        self.ax_error.set_ylim(min(min(self.errors, default=0), -200), max(max(self.errors, default=0), 200))
        # 更新文本框显示最新误差
        self.text_error.set_text(f'Latest Error: {msg.data*100:.2f} cm')

        self.ax_error.relim()  # 重新计算坐标轴
        self.ax_error.autoscale_view()  # 自动缩放
        plt.draw()
        plt.pause(0.01)  # 暂停以更新图形

    def on_close(self, event):
        self.get_logger().info('关闭图形窗口')
        rclpy.shutdown()  # 正常关闭 ROS2
        plt.close(self.fig)  # 关闭 Matplotlib 图形

def main(args = None):
    rclpy.init(args = args)
    visualizer = SpeedVisualizer()
    rclpy.spin(visualizer)
    visualizer.destroy_node()

if __name__ == '__main__':
    main()
