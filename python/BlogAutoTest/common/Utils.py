import datetime
import os.path
import sys

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager

class Driver:
    driver = ""

    def __init__(self):
        options = webdriver.ChromOptions()
        self.driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)
    def getScreenShot(self):
        dirname = datetime.datetime.now().strftime('%Y-%m-%d')
        if not os.path.exists("../images/" + dirname):
            os.mkdir("../images/" + dirname)
        filename = sys._getframe().f_back.f_code.co_name + " " + datetime.datetime.now().strftime('%Y-%m-%d-%H%M%S') + ".PNG"
        self.driver.save_screenshot(f'../images/{ dirname }/' + filename)

BlogDriver = Driver()