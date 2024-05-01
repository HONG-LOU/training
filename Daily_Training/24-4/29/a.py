import mysql.connector

# 创建数据库连接
db = mysql.connector.connect(
    host="localhost",  # MySQL服务器地址
    user="username",   # 用户名
    password="password",  # 密码
    database="mydatabase"  # 数据库名称
)

# 创建游标对象，用于执行SQL查询
cursor = db.cursor()

