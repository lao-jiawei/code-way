# 高价函数

## Q：是什么？

* A：一个函数可以接收另一个函数作为参数，这种函数就称之为高阶函数。

# map

## Q：有哪些特性？

````javascript
let array = [,1,,2,,3];
array = array.map((i) => ++i)
````

* `map()`可以产生新的数组。

* `map()`会跳过空位，但会保留值

  > PS：跳过空位的方法还有
  >
  > * forEach
  >
  >   ````javascript
  >   let array = [,1,,2,,3];
  >   array.forEach(function (i) {
  >       console.log(i);
  >   })
  >   ````

# reduce

## Q：能干嘛？

* A：
  1. 求和。
  2. 构建对象。

## Q：怎么用？

* A：

  ````javascript
  Array.reduce(callBack,initObj)
  ````

  * `callBack`：回调函数，有三个参数（从左到右依次），返回值一定是当前处理完的结果。
    * `result`：收集的结果
    * `element`：当前元素
    * `index`：索引
  * `initObj`：初始值。

# filter

## Q：能干嘛？

* A：用于把`Array`的某些元素过滤掉，然后返回剩下的元素。

## Q：怎么用？

* A：

  ````javascript
  Array.filter(callBack)
  ````

  * `callBack`：回调函数，返回boolean值

# forEach

## Q：能干嘛？

* A：遍历数组

## Q：如何跳出遍历？

* A：
  * 方法一：截断数组。
  * 方法二：抛出错误。

# every

## Q：能干嘛？

* A：检测数组中的每一项是否符合条件。

  > 注意：空数组会返回true

# some

## Q：能干嘛？

* A：检测数组是否有某些项符合条件