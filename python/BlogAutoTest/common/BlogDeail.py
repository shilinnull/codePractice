from selenium.webdriver.common.by import By

from common.Utils import BlogDriver
#测试博客详情页
class BlogDeail:
    url = ""
    driver = ""
    def __init__(self):
        self.url = "file:///F:/code_practice/Python/BlogAutoTest/%E5%8D%9A%E5%AE%A2%E7%B3%BB%E7%BB%9F/blog_detail.html6"
        self.driver = BlogDriver.driver
        self.driver.get(self.url)

    #登陆状态下博客详情页的测试
    def DetailTestByLogin(self):
        #检查标题
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div > h3")
        #检查时间
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div > div.date")
        #检查内容
        self.driver.find_element(By.CSS_SELECTOR,"#content > p")
        #屏幕截图
        BlogDriver.getScreeShot()