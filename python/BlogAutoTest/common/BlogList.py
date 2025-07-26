from selenium.webdriver.common.by import By

from common.Utils import BlogDriver


class BlogList:
    url = ""
    driver = ""
    def __init__(self):
        self.driver = BlogDriver.driver
        self.url = "file:///F:/code_practice/Python/BlogAutoTest/%E5%8D%9A%E5%AE%A2%E7%B3%BB%E7%BB%9F/blog_list.html"
        self.driver.get(self.url)
    def ListTest(self):
        #测试博客标题是否存在
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div:nth-child(1) > div.title")
        #测试博客内容是否存在
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div:nth-child(1) > div.desc")
        #测试按钮是否存在
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div:nth-child(1) > a")
        #个人信息-检查昵称是否存在
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.left > div > h3")
        #添加屏幕截图
        BlogDriver.getScreeShot()

