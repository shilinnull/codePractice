from selenium.webdriver.common.by import By

from common.Utils import BlogDriver


class BlogLogin:
    url = " "
    driver = ""

    def __init__(self):
        self.url = "file:///F:/code_practice/Python/BlogAutoTest/%E5%8D%9A%E5%AE%A2%E7%B3%BB%E7%BB%9F/blog_login.html"
        self.driver = BlogDriver.driver
        self.driver.get(self.url)

    def loginSucTest(self):
        self.driver.find_element(By.CSS_SELECTOR, "#username").clear()
        self.driver.find_element(By.CSS_SELECTOR, "#password").clear()
        self.driver.find_element(By.CSS_SELECTOR, "#username").send_keys("admin")
        self.driver.find_element(By.CSS_SELECTOR, "#password").send_keys("123")
        self.driver.find_element(By.CSS_SELECTOR, "#submit").click()
        self.driver.find_element(By.CSS_SELECTOR, "body > div.container > div.left > div > img")
        BlogDriver.getScreenShot()
        self.driver.back()

    def loginFailTest(self):
        self.driver.find_element(By.CSS_SELECTOR, "#username").clear()
        self.driver.find_element(By.CSS_SELECTOR, "#password").clear()
        self.driver.find_element(By.CSS_SELECTOR, "#username").send_keys("admin")
        self.driver.find_element(By.CSS_SELECTOR, "#password").send_keys("123")
        self.driver.find_element(By.CSS_SELECTOR, "#submit").click()
        actual = self.driver.find_element(By.CSS_SELECTOR, "body").text
        print(actual)
        BlogDriver.getScreenShot()
        self.driver.back()