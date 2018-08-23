import tensorflow as tf

#Feed
#创建占位符
input1 = tf.placeholder(tf.float32)
input2 = tf.placeholder(tf.float32)
output = tf.multiply(input1, input2)


with tf.Session() as sess:
    #第一个参数op。第二个参数是feed需要的字典，也就是对应的变量和值
    #也就是说feed的参数是可变的，可以等到run的时候在确定下来
    print(sess.run(output, feed_dict={input1:[7,], input2:[2,]}))
