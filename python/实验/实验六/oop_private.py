# 任务3： 私有成员（用双下划线__开头， 仅类内部可访问， 外部不可直接访问）
class BankAccount:
    """银行账户类， 封装账户信息， 私有成员保护余额"""
    def __init__(self, account_id, name, initial_balance=0):
        self.account_id = account_id # 公开属性： 账号（外部可访问）
        self.name = name # 公开属性： 户主姓名
        self.__balance = initial_balance # 私有属性： 余额（仅内部可访问）
    # 公开方法（接口） ： 查询余额（外部通过方法访问私有属性）
    def get_balance(self):
        print(f"{self.name}的账户余额： {self.__balance}元")
        return self.__balance
    # 公开方法（接口） ： 存款（验证金额合法性， 修改私有属性）
    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount
            print(f"存款成功！ 存入{amount}元， 当前余额： {self.__balance}元")
        else:
            print("存款金额无效！ 需大于0")

    # 公开方法（接口） ： 取款（验证金额合法性与余额充足性）
    def withdraw(self, amount):
        if amount <= 0:
            print("取款金额无效！ 需大于0")
            return False
        elif amount > self.__balance:
            print("余额不足！ 无法取款")
            return False
        else:
            self.__balance -= amount
            print(f"取款成功！ 取出{amount}元， 当前余额： {self.__balance}元")
        return True

    # 私有方法（仅类内部可调用， 外部不可访问）
    def __check_balance(self):
        """私有方法： 检查余额是否低于100元， 低于则提示"""
        if self.__balance < 100:
            print(f"警告： {self.name}的账户余额低于100元， 请及时充值！ ")
# 私有成员测试
print("=== 私有成员与封装测试 ===")
# 创建银行账户对象
acc1 = BankAccount("6222081234567890", "张三", 500)
# 访问公开属性
print(f"账户账号： {acc1.account_id}")  # 正常访问
acc1.get_balance()  # 预期500元
acc1.deposit(300)  # 存款300， 余额800
acc1.withdraw(200)  # 取款200， 余额600
acc1.withdraw(700)  # 余额不足， 取款失败
print("\n测试私有方法调用： ")
acc1.withdraw(550)  # 取款550， 余额50， 触发私有方法__check_balance的警告