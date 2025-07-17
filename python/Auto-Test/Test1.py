import time

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from webdriver_manager.chrome import ChromeDriverManager

ChromeIns=ChromeDriverManager().install()
driver=webdriver.Chrome(service=Service(ChromeIns))
driver.get("https://www.baidu.com")
# time.sleep(1)
# # driver.find_element(By.CSS_SELECTOR, "#su").click()
# driver.find_element(By.CSS_SELECTOR, "#kw").send_keys("蔡徐坤")
# time.sleep(1)
# driver.find_element(By.CSS_SELECTOR, "#su").click()
# time.sleep(1)
# driver.find_element(By.CSS_SELECTOR, "#kw").clear()
# time.sleep(1)
# driver.find_element(By.CSS_SELECTOR, "#kw").send_keys("你干嘛")
# time.sleep(1)
# driver.find_element(By.CSS_SELECTOR, "#su").click()

# 获取文本信息
# text = driver.find_element(By.XPATH, '//*[@id="hotsearch-content-wrapper"]/li[2]/a/span[2]').text
#
# print(text)

# 获取标题
# title = driver.title
# print(title)
# assert title == "百度一下，你就知道"
#
# url = driver.current_url
# print(url)

# 获取属性
attribute = driver.find_element(By.CSS_SELECTOR, '#su').get_attribute('value')
print(attribute)
assert attribute == '百度一下'

time.sleep(5)

driver.quit()
