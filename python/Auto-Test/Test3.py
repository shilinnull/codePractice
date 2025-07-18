import datetime
import time

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.ie.webdriver import WebDriver
from selenium.webdriver.support.wait import WebDriverWait
from webdriver_manager.chrome import ChromeDriverManager


ChromeIns=ChromeDriverManager().install()
driver=webdriver.Chrome(service=Service(ChromeIns))
# driver.get("C:/Users/shilinnull/Desktop/selenium-html/alert.html")
driver.get("file:///C:/Users/shilinnull/Desktop/selenium-html/Prompt.html")
driver.find_element(By.CSS_SELECTOR, 'body > input[type=button]').click()

# driver.implicitly_wait(3)



time.sleep(2)
alert = driver.switch_to.alert
time.sleep(1)
# alert.accept()
# alert.dismiss()
alert.send_keys("蔡徐坤")
time.sleep(2)
alert.accept()
time.sleep(3)


driver.quit()