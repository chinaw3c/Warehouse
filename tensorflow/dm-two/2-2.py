#hello

# File Name: 2-2.py
# Author: 刘傲天
# mail: 1151172004@qq.com
# Created Time: 2018-07-10
import tensorflow as tf

#创建一个变量 变量可以取一个名字
x = tf.Variable([1,2], name='wa')
#创建一个常量
a = tf.constant([3,3])
#增加一个减法op
sub = tf.subtract(x, a)
#增加一个加法op
add = tf.add(x, sub)

#初始化一个变量0
state = tf.Variable(0)

#创建一个变量等于state + 1的结果
new_value = tf.add(state, 1)

#赋值操作必须调用tensorflow.assign(要被赋值的变量,变量)
#把第二个变量赋值给第一个
update = tf.assign(state, new_value)

#初始化变量
init = tf.global_variables_initializer()

with tf.Session() as sess:
    #先进行初始化
    sess.run(init)
    print(sess.run(state))
    for _ in range(5):
        sess.run(update)
        print(sess.run(state))
