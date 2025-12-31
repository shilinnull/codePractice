class Book:
    """图书类， 封装图书信息与借阅状态"""
    def __init__(self, title, author, isbn):
        self.title = title
        self.author = author
        self.isbn = isbn
        self.__is_borrowed = False
    def borrow(self):
        """借出图书： 未借出则修改状态为已借出， 返回True； 已借出返回False"""
        if not self.__is_borrowed:
            self.__is_borrowed = True
            print(f"《{self.title}》 （ISBN： {self.isbn}） 借出成功！ ")
            return True
        else:
            print(f"《{self.title}》 （ISBN： {self.isbn}） 已被借出， 无法重复借出！ ")
            return False
    def return_book(self):
        """归还图书： 已借出则修改状态为未借出， 返回True； 未借出返回False"""
        if self.__is_borrowed:
            self.__is_borrowed = False
            print(f"《{self.title}》 （ISBN： {self.isbn}） 归还成功！ ")
            return True
        else:
            print(f"《{self.title}》 （ISBN： {self.isbn}） 未被借出， 无需归还！ ")
            return False
    def __str__(self):
        """返回图书的友好字符串表示（包含借出状态） """
        borrow_status = "已借出" if self.__is_borrowed else "未借出"
        return f"书名： 《{self.title}》 ， 作者： {self.author}， ISBN： {self.isbn}， 状态：{borrow_status}"
class Library:
    def __init__(self, name):
        self.name = name
        self.__books = []
    def add_book(self, book):
        """添加图书： 验证是否为Book对象， 且ISBN未重复， 添加到列表"""
        if not isinstance(book, Book):
            print("添加失败！ 只能添加Book对象")
            return False
        for existing_book in self.__books:
            if existing_book.isbn == book.isbn:
                print(f"添加失败！ ISBN： {book.isbn}已存在， 不可重复添加")
                return False
        self.__books.append(book)
        print(f"成功添加图书： {book}")
        return True
    def show_all_books(self):
        """显示所有图书： 遍历图书列表， 打印每本图书信息"""
        print(f"\n===== {self.name} 所有图书 =====")
        if not self.__books:
            print("当前暂无图书")
            return
        for idx, book in enumerate(self.__books, start=1):
            print(f"{idx}. {book}")
    def search_book(self, title_keyword):
        """按书名关键词搜索图书： 返回包含关键词的图书列表"""
        results = [book for book in self.__books if title_keyword in book.title]
        print(f"\n===== 搜索'{title_keyword}'的结果 =====")
        if not results:
            print(f"未找到包含'{title_keyword}'的图书")
            return []
        for idx, book in enumerate(results, start=1):
            print(f"{idx}. {book}")
        return results
    def borrow_book(self, isbn):
        """根据ISBN借出图书： 找到图书则调用其borrow()方法"""
        for book in self.__books:
            if book.isbn == isbn:
                return book.borrow()
        print(f"未找到ISBN为{isbn}的图书， 借出失败！ ")
        return False
    def return_book(self, isbn):
        for book in self.__books:
            if book.isbn == isbn:
                return book.return_book()
        print(f"未找到ISBN为{isbn}的图书， 归还失败！ ")
        return False
if __name__ == "__main__":
    lib = Library("学校图书馆")
    print("=== 步骤1： 添加图书 ===")
    book1 = Book("计算机组成原理", "唐朔飞", "97870405545180")
    book2 = Book("计算机网络", "谢希仁", "9787121302954")
    book3 = Book("软件工程", "李爱萍", "9787115340795")
    lib.add_book(book1)
    lib.add_book(book2)
    lib.add_book(book3)
    book4 = Book("计组重复图书", "测试作者", "97870405545180") # ISBN与book1相同
    lib.add_book(book4)
    print("\n=== 步骤2： 显示所有图书 ===")
    lib.show_all_books()
    print("\n=== 步骤3： 搜索图书 ===")
    lib.search_book("软件")
    print("\n=== 步骤4： 借出图书 ===")
    lib.borrow_book("9787121302954")
    lib.borrow_book("9787121302954")
    print("\n=== 步骤5： 归还图书 ===")
    lib.return_book("9787121302954")
    lib.return_book("9787121302954")
    print("\n=== 步骤6： 显示更新后的图书 ===")
    lib.show_all_books()