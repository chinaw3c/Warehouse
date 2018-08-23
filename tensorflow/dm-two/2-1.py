#hello

# File Name: 2-1.py
# Author: 刘傲天
# mail: 1151172004@qq.com
# Created Time: 2018-07-10
import tensorflow as tf
#创建常量m1和m2 constant:常量
m1 = tf.constant([[3, 3]])
m2 = tf.constant([[2], [3]])
#创建一个矩阵乘法, m1和m2作为参数传入
product = tf.matmul(m1, m2)
print(product)
#定义一个绘画，启动默认的图
sess = tf.Session()

result = sess.run(product)
print(result)
sess.close()
