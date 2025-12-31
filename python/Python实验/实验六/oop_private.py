class BankAccount:
    """银行账户类， 封装账户信息， 私有成员保护余额"""
    def __init__(self, account_id, name, initial_balance=0):
        self.account_id = account_id
        self.name = name
        self.__balance = initial_balance
    def get_balance(self):
        print(f"{self.name}的账户余额： {self.__balance}元")
        return self.__balance
    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount
            print(f"存款成功！ 存入{amount}元， 当前余额： {self.__balance}元")
        else:
            print("存款金额无效！ 需大于0")
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
    def __check_balance(self):
        """私有方法： 检查余额是否低于100元， 低于则提示"""
        if self.__balance < 100:
            print(f"警告： {self.name}的账户余额低于100元， 请及时充值！ ")
acc1 = BankAccount("6666666666", "乔乾峰", 1000)
print(f"账户账号： {acc1.account_id}")
acc1.get_balance()
acc1.deposit(400)
acc1.withdraw(300)
acc1.withdraw(700)
acc1.withdraw(550)