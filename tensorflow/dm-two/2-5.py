#hello

# File Name: 2-5.py
# Author: 刘傲天
# mail: 1151172004@qq.com
# Created Time: 2018-07-11
import tensorflow as tf
import numpy as np

#使用numpy生成100个随机点
x_data = np.random.rand(100)
y_data = x_data*0.1 + 0.2

#构造一个线性模型
b = tf.Variable(0.)
k = tf.Variable(0.)
y = k*x_data + b

#二次代价函数
#tf.square 是一个求平方的方法
#tf.reduce_mean是一个求平均值的方法
loss = tf.reduce_mean(tf.square(y_data-y))
#定义一个梯度下降来进行训练的优化器
optimizer = tf.train.GradientDescentOptimizer(0.2)
#最小化代价函数 定义一个训练
train = optimizer.minimize(loss)

init = tf.global_variables_initializer()

with tf.Session() as sess:
    sess.run(init)
    for step in range(201):
        sess.run(train)
        if step % 20 == 0:
            print(step, sess.run([k, b]))
