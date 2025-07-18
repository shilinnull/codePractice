import datetime
import time

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from webdriver_manager.chrome import ChromeDriverManager

ChromeIns=ChromeDriverManager().install()
driver=webdriver.Chrome(service=Service(ChromeIns))
driver.get("https://www.baidu.com")

driver.find_element(By.CSS_SELECTOR, "#hotsearch-content-wrapper > li:nth-child(2) > a > span.title-content-title").click()

time.sleep(1)
# curWindow = driver.current_window_handle
# allWindow = driver.window_handles
#
# for window in allWindow:
#     if window != curWindow:
#         driver.switch_to.window(window)
#
# driver.maximize_window()
# time.sleep(1)
# driver.minimize_window()
# time.sleep(1)
# driver.fullscreen_window()
# time.sleep(1)
# driver.set_window_size(1024, 999)

# driver.save_screenshot("image.png");

time.sleep(1)
filename = "autotest-" + datetime.datetime.now().strftime("%Y-%m-%d-%H%M%S") + ".png"
driver.save_screenshot('./images/' + filename)
time.sleep(1)
driver.close()

time.sleep(3)
driver.quit()


