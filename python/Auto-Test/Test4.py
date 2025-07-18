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
driver.get("https://tool.lu/")
driver.implicitly_wait(3)
driver.find_element(By.CSS_SELECTOR, "#page > div:nth-child(1) > div.item-list > div.item.tool-cutout > div.item-inner > div.item-hd > div > h3 > a").click()

time.sleep(1)
driver.back()

time.sleep(1)
driver.forward()

time.sleep(1)
driver.refresh()

time.sleep(1)
driver.quit()