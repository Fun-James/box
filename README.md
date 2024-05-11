# box
 高级语言程序设计大作业实验报告（NKU）


[![Video Title](https://i0.hdslb.com/bfs/archive/YOUR_COVER_IMAGE.jpg)](https://www.bilibili.com/video/BV1MM4m1o7fo)
目录

[高级语言程序设计大作业实验报告](#_toc166187112)

[**一.**	**作业题目**](#_toc166187113)

[**二.**	**开发软件**	](#_toc166187114)

[**三.**	**课题要求**	](#_toc166187115)

[**四.**	**主要流程**	](#_toc166187116)

[**1.**	**整体流程**	](#_toc166187117)

[**2.**	**算法或公式**](#_toc166187118)

[**（1） Qt的信号和信号槽机制**2](#_toc166187119)

[**（2） 随机数的生成与存储**	](#_toc166187120)

[**（3） box和figure对应的判断**	](#_toc166187121)

[**五.**	**测试**	](#_toc166187122)

[测试结果	](#_toc166187123)

[**六.**	**收获**	](#_toc166187124)

[**1.**	**加深对类的实现和类之间的交互的理解**	](#_toc166187125)

[**2.**	**类的封装性有效减少重复的代码**	](#_toc166187126)

[**3.**	**信号和信号槽的松耦合**	](#_toc166187127)



<a name="_toc166187112"></a>高级语言程序设计大作业实验报告


1  <a name="_toc166187113"></a>**作业题目**

   小游戏：取件码识别与配对

1  <a name="_toc166187114"></a>**开发软件**

   Qt Creator

1  <a name="_toc166187115"></a>**课题要求**
1) 面向对象。
1) 模型部分
1) 验证

1  <a name="_toc166187116"></a>**主要流程**
   1. <a name="_toc166187117"></a>**整体流程**

实现思路：

定义Box类和Figure类作为“快递件”和取件人，利用随机生成的8位取件码来判定，定义Login类为程序登录的窗口，定义三种难度窗口：Easy、Middle和Hard，其中Easy为9个配对，Middle为16个配对，Hard在Middle的基础上，让随机数变得相似，从而变相增加难度，最后定义Score窗口来显示耗时和成绩。

1. <a name="_toc166187118"></a>**算法或公式**
   1. <a name="_toc166187119"></a>**Qt的信号和信号槽机制**

      信号（Signal）：信号是由对象在特定事件发生时发出的通知。当一个对象的状态发生改变或者发生了某个事件时，它会发出相应的信号。

      槽（Slot）：槽是一个响应信号的函数或方法。当一个信号被发出时，与之相连的槽函数会被自动调用。

      连接（Connection）：通过使用connect() 函数，可以将信号与槽进行连接。一个信号可以连接到多个槽，一个槽也可以接收多个信号。

      比如上面的代码就将ui中的pushbutton和Push\_on\_Go()函数链接，实现了点击pushbutton调用Push\_on\_Go()的功能。

   1. <a name="_toc166187120"></a>**随机数的生成与存储**

      `	`在本程序中较为关键的一步是给每一个box生成随机的8位取件码，并且和唯一的一个figure对应起来。在Qt中其实有已经写好的随机数生成器QRandomGenerator，要生成8位的随机数只需要生成0到9×107 的随机数，然后都加上108，就可以生成任意8位随机数。

      `	`除此之外，为了能够让figure也能随机的与box对应，因此在用vector<int>存储box的取件码之后，调用了C++标准库中的随机数库来打乱vector中数的顺序。创建一个 std::random\_device 对象 rd，用于生成随机种子。使用 rd 生成的随机种子初始化一个 std::mt19937 随机数引擎 rng。使用 std::shuffle 算法，并传递 boxNumbers 容器的迭代器范围和 rng 随机数生成器，随机打乱 boxNumbers 容器中元素的顺序。这种方式可以确保每次运行程序时，boxNumbers 容器中的元素都会以不同的随机顺序排列，提供了良好的随机性。


   1. <a name="_toc166187121"></a>**box和figure对应的判断**

      程序要让用户拖动box到figure之后立刻判断取件码是否对应，如果对应则两个都消失。重写了mouseReleaseEvent函数，在松开时立刻判定。

   1. **box的动态变化**

在程序中，为了避免僵硬，给box以动态变化，具体表现为box不会直接从关闭状态到打开状态，而是会后一个半开合的过程，利用QTimer计时器来触发连续的动态变化。



1  <a name="_toc166187122"></a>**测试**
   ### <a name="_toc15356"></a><a name="_toc166187123"></a>**测试结果**
   Login界面可以正常跳转三个模式。

   Easy模式可以正常配对，并跳转至成绩页面。

   Middle模式同上。

   Hard模式的随机数符合预期的目标。

1  <a name="_toc166187124"></a>**收获**
   1. <a name="_toc166187125"></a>**加深对类的实现和类之间的交互的理解**
   1. <a name="_toc166187126"></a>**类的封装性有效减少重复的代码**

在这个小游戏中设置了相当多的“对象”，分为Box类和Figure类，之后在创建内容是可以轻松对这些对象进行统一的操作，十分方便。

1. <a name="_toc166187127"></a>**信号和信号槽的松耦合**

Qt的一大优点就是信号与信号槽机制，这是一种高效的事件处理系统，使得对象可以发出信号以表示某种状态的改变或事件的发生，并且可以连接到一个或多个槽函数上，这些槽函数定义了对这些信号的响应。这种设计可以简化对象间的通信，易于扩展和修改，能自动管理连接，让每一部分更安全，极大地增强了软件的可维护性和扩展性。





