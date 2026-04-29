# 导入OpenCV库
import cv2

# 读取本地彩色图像（请补充正确的图像路径）
img = cv2.imread("1.jpg")

# 显示图像，请补充窗口名称
cv2.imshow("窗口名称", img)

# 添加等待键盘输入
cv2.waitKey(0)

# 关闭所有显示窗口（可选，建议添加）
cv2.destroyAllWindows()