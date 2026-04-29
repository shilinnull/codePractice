# 导入OpenCV库
import cv2

# 读取图像：彩色模式（默认，flags=1可省略）、灰度模式（flags=0）
img_color = cv2.imread("1.jpg", flags=1)  # 彩色模式
img_gray = cv2.imread("1.jpg", flags=0)  # 灰度模式

# 分别显示两个窗口，窗口名称区分明确
cv2.imshow("彩色原图", img_color)
cv2.imshow("灰度图", img_gray)

# 等待键盘输入，关闭所有窗口
cv2.waitKey(0)
cv2.destroyAllWindows()