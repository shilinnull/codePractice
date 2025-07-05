import datetime
import time
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
from webdriver_manager.chrome import ChromeDriverManager

#编写自动化脚本，具体步骤
#1.打开浏览器----驱动管理
ChromeIns=ChromeDriverManager().install()
###创建谷歌浏览器驱动对象
driver=webdriver.Chrome(service=Service(ChromeIns))
time.sleep(2)
driver.get("https://www.baidu.com")
time.sleep(2)
#3.找到百度输入框，输入关键词“迪丽热巴”
driver.find_element(By.CSS_SELECTOR,"#kw").send_keys("蔡徐坤")
time.sleep(2)
#4.点击“百度一下”按钮
driver.find_element(By.CSS_SELECTOR,"#su").click()
time.sleep(2)
#5.关闭浏览器
driver.quit()







