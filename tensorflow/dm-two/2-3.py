import tensorflow as tf

#Fetch
#Fetch就是可以在一个会话运行多个Op
#创建san个常量
input1 = tf.constant(3.0)
input2 = tf.constant(2.0)
input3 = tf.constant(5.0)

#创建一个加法操作
add = tf.add(input2, input3)


#创建一个乘法操作
mul = tf.multiply(input1, add)

with tf.Session() as sess:
    #Fetch 同时运行mul和add
    result = sess.run([mul,add])
    print(result)

