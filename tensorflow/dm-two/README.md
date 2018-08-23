# 第一天学到的英文

subtract        减法<br>
Variable        变量<br>
constant        常量<br>
add             加法<br>
multiply        乘法<br>
global          全局<br>
initializer     初始化<br>
global_variables_initializer 全局变量初始化<br>
Session         会话<br>
run()是非常重要的，也要搭配with来使用<br>
Fetch是run的一种使用方法，可以以列表的形式传入run的参数，就可以达到一次运行多个op的效果<br>
Feed也是run的一种使用方法，意味创建一个或多个占位符，先占着变量的位置，可以等到调用run的时候通过feed_dict传入一个字典的形式，传入这个参数<br>
通过tensorflow的placeholder函数创建,有一个参数就是创建占位符的类型<br>
