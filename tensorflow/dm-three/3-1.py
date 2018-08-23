
# Author: 刘傲天
# mail: 1151172004@qq.com
# Created Time: 2018-07-11
# File Name: 3-1.py

import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt

#使用numpy来生成200个随机点
#linspace函数说明:从参数1到参数2的范围之间生成200个随机数
#[:,np.newaxis] 增加一个纬度，变成二维
x_data = np.linspace(-0.5, 0.5, 200)[:,np.newaxis]
noise = np.random.normal(0, 0.02, x_data.shape)
y_data = np.square(x_data) + noise

#定义两个placeholder  占位符
x = tf.placeholder(tf.float32, [None,1])
y = tf.placeholder(tf.float32, [None,1])

#定义神经网络中间层
Weights_L1 = tf.Variable(tf.random.normal[1, 10])
biases_L1 = tf.Variable(tf.zeros[1, 10])
Wx_plus_L1 = tf.matmul(x, Weights) + biases_L1
L1 = tf.nn.tanh(Wx_plus_L1)


#定义神经网络输出层
Weights_L2 = tf.Variable(tf.random_normal([10, 1]))
biases_L2 = tf.Variable(tf.zeros[1, 1])
#暂时搁置，教程看不懂

