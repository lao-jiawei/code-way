# 数据类型

## Number类型

### Q：数值转换的方法有哪些？

* A：
  * 用于所有类型转换：Number()
  * 用于字符串转数值：parseInt()、parseFloat()；

### Q：parseInt如何使用？

* A：

  ````javascript
  parseInt(string,format)
  ````

  * `string`：字符串（最前面的空格会被忽略，即从第一个非空格字符开始转换）。

  > 返回值出错场景
  >
  > 1. 返回NaN：
  >    * 原因一：`string`参数不是数值字符、加号或减号。（`string`为空字符）

### Q：parseInt匹配流程是什么？

* A：从第一个字符是数值字符、加号或减号，依次检测每个字符，直到字符串末尾，或碰到非数值字符。

  ````javascript
  parseInt('1234blue')//1234
  
  //小数点不是有效的整数字符
  parseInt('22.5')//22
  ````

  

# 操作符

## 一元操作符

### Q：如何区分先增（减）还是后增（减）？

* A：看符号位置，在前则先，在后则过后再处理

  ````javascript
  let number = 0			 // 输出		number
  console.log(number++)//	 0				1
  console.log(++number)//	 2				2
  ````


# 运算符

## Q：运算符优先级是什么？

* A：从右到左还是从左往右。

# 语句

## for-in语句

### Q：能干嘛？

* A：用于枚举对象中的非符号（Symbol）键的属性

  > 注意：需要枚举的对象是null或undefined，则不执行循环体。