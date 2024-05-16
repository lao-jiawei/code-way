# 第4章	变量、作业域和内存问题

## 1、基本类型和引用类型的值

**啥是基本类型？**

* *简单的数据段*
* **有哪些？**【巧记】USBN
  * U：`undefined`
  * S：`string`
  * B：`boolean`
  * N：`null`、`number`
* 按值访问的
  * 可以操作保存在变量中的实际的值

<br>

**啥是引用类型？**

* *可能由多个值构成的对象*
* **有哪些？**
  * O：`object`
* 值保存在内存中
  * 【所以】不能直接操作对象的内存空间
    * 【因此】操作对象时，实际是在操作对象的引用而不是实际的对象。

<br>

### 1.1	动态属性

**啥是动态属性？**

* *对于**引用类型**的值，可以为其添加属性和方法，也可以改变和删除其属性和方法*

  【示例】*对引用类型添加属性*

  ````javascript
  var person = new Object();
  person.name='Lao'	//可以添加属性,并赋值
  alert(person.name)	//输出lao	
  ````

  【示例】对基本类型添加属性

  ````javascript
  var name='lao';
  name.age = 21;	//试图添加age属性
  alert(name.age);	//输出undefined
  ````

  * 【说明】**只能给引用类型添加动态属性**

<br>

### 1.2	复制变量值

> 复制**基本类型**的值

【示例】

````javascript
var num1 = 5;
var num2 - num1;
````

【过程】

1. 在变量对象上创建一个新值

   ![1655047273035](D:\Data\9_Typora图片缓存\1655047273035.png)

2. 把该值复制到新变量分配的位置上

   ![1655047291804](D:\Data\9_Typora图片缓存\1655047291804.png)

【==注意==】

* 两个变量可以参与任何操作而不会互相影响

<br>

> 复制**引用类型**的值

【示例】

````javascript
var obj1 =new Object();
var obj2 = obj1;
obj1.name = 'lao'
alert(obj2.name);	//输出'lao'
````

![1655047524385](D:\Data\9_Typora图片缓存\1655047524385.png)

<br>

### 1.3	传递参数

* 所有函数的参数都是按值传递的（相当与复制变量值）

<br>



# 第7章	函数表达式

## 2、闭包



<br>

# 第10章	DOM

## 1、节点层次

**文档节点**

* 每个文档的根节点。
* 只有一个子结点（**文档元素**，即`<html>`元素）
  * 文档元素是文档的最外层元素。
  * 每个文档只能有一个

<br>

### Node类型

<br>

### Document类型

* 表示文档（整个HTML页面）

#### 操作页面

> 文档的子节点

**【格式】获取文档子节点**

````javascript
var name = documentElement;
````

<br>

> 文档信息

|      |      |      |
| ---- | ---- | ---- |
|      |      |      |
|      |      |      |
|      |      |      |

**【格式】获取文档标题**

````html
var name = document.title;
````

**【格式】设置文档标题**

````javascript
document.title='新标题内容';
````



<br>

# 第11章	DOM扩展

## 1、选择符API

### querySelector()方法

* 用来获取DOM结点元素。

> 格式

````javascript
var name = document.querySelector("cssSelector")
````

* `name`：接收名
* 查找范围：
  * `document`：在文档元素的范围内查找
  * `element`：只会在该元素后代范围内查找

* `cssSelector`：（Css选择器）
  * 标签
  * `#`：id选择器
  * `.`：类选择器

**返回值：**

* 匹配到：匹配的**第一个**元素
* 没有匹配到：`null`

<br>

### querySelectorAll()方法

> 格式

````javascript
var name = document.querySelectorAll("cssSelector")
````

* 和`querySelector()`方法的用法一样。

**返回值：**（NodeList对象）

* 匹配到：**所有**匹配的元素
* 匹配不到：NodeList是空的。

