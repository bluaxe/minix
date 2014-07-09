操作系统课程设计 Project4
==================
CS356 SJTU 2014

Minix 3.1.8

1.  为Minix 增加新的系统调用
----------------
增加新的系统调用，接口为：

`
void yoursyscall(void);
`

新的系统调用由pm 服务器来处理，pm 在收到请求后输出一句话即可。

具体实现方式请看yoursyscall_void 分支。

2. 将yoursyscall 修改为带参数版本
----------------
在上一个的基础上，将yoursyscall 修改为：

`
void yoursyscall(int arg);
`

在用户端，将arg 参数写入消息，在pm 端提取arg 并输出。

具体实现方式请看yoursyscall_arg 分支。

3. 将pm 的printf 改为一个_taskcall
-----------------------

在上一个的基础上，假设pm 无法单独完成你的yoursyscall，他在收到请求
获得参数后，对yoursyscall 的处理方式就是调用_taskcall 函数，将请求发给sched
服务器，让sched 服务器完成你的调用。发给sched 服务器的信息中应该包含是
哪个用户进程发来的请求以及arg 值是多少。

具体实现方式请看yoursyscall_taskcall 分支。

4. 修改sched服务器
------------------

在第三步基础上，修改sched 对yoursyscall 的
处理，使得当一个进程调用yoursyscall 时，它比其他进程会获得更多的运行机会，
并且yoursyscall 中传入的数值越大，这个进程获得的机会就越多。

具体实现方式请看yoursyscall_sched 分支。

5. 增加deadline 功能
-------------
在上述功能的基础上，增加调用的参数个数：

`
void yoursyscall(int arg, int deadline);
`

增加的参数deadline 的意思是，在这么多秒后，如果这个调用yoursyscall
的进程还没有结束，那么就强制结束这个进程。

具体实现方式请看yoursyscall_deadline 分支。

6. 增加机会浮动功能
-----------------
在上述功能的基础上，增加机会浮动的功能，即程序越接近deadline，它会
获得更多的运行机会。

具体实现方式请看yoursyscall_dynamic 分支。