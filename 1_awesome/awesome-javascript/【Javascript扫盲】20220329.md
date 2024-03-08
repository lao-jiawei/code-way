# Array.prototype.map()

````javascript
let array = [,1,,2,,3];
array = array.map((i) => ++i)
````

* `map()`可以产生新的数组。
* `map()`会跳过空位，但会保留值

<br>

## 跳过空位的方法还有

> forEach()

````javascript
let array = [,1,,2,,3];
array.forEach(function (i) {
    console.log(i);
})
````

*控制台输出：*

![1648518607001](D:\Data\9_Typora图片缓存\1648518607001.png)

<br>

> filter()

[JavaScript Array filter() 方法](https://www.runoob.com/jsref/jsref-filter.html)



> reduce()

> every()

> some()