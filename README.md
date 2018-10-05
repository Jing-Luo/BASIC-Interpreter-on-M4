# BASIC Interpreter on M4

It's an embedded system project based on Cortex M4, in which I implement a BASIC interpreter. 

### Project outcome

**The analysis and interpretation of BASIC statements**: input BASIC statements through the virtual serial, and the M4 board will return results.

**Instructions expansion**: we include the HIGH, LOW, DELAY statement to control the levels of pins.
LCD display: use 12864B LCD to display instructions and running results.

### Showcase

* Sample Input
![](/Demo/Demo1.png)

* Error Report
![](/Demo/Demo.png)


# 嵌入式系统项目：基于M4板的BASIC解释器的实现

嵌入式课程的开放式课题，在TI公司的EK-TM4C1294XL开发板上实现BASIC语言解析的功能。项目文件详见目录中的项目报告，KEIL代码见KeilSourceCode文件夹。

### 项目成果

- 实现BASIC语句的解析：通过虚拟串口输入BASIC语句，经M4板处理后返回语句执行结果。
- 指令体系的扩展：加入HIGH、LOW、DELAY语句，控制开发板的引脚的高低电平。
- 加入LCD显示功能：引入12864B型LCD，显示指令及运行结果。

### BASIC解析器的实现细节

- 表达式树的建立与运算

- 指令的储存和运行

### 代码的完备性和健壮性

- 对Basic程序语句和控制指令的支持和扩展

- 允许乱序输入行号

- Error Report机制
