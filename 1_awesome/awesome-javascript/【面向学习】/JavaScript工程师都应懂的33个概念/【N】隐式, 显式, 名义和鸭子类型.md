# 隐式转换

## Q：boolean相关的隐式转换有哪些？

* A：

  * 转成false的值：

    | 所属类型 | 值              |
    | -------- | --------------- |
    |          | undefined、null |
    | Boolean  | false           |
    | Number   | -0、+0、NaN     |
    | String   | ''              |
    
  * 转成true的值
  
    * 构造函数

## Q：隐式转为number类型的例子有哪些？

* A：

  * 一元操作符加号尝试将 bool 转为 number。

    ````javascript
    +true//1
    ````

## Q：隐式转为string类型的例子有哪些？

* A：

  * {String}+{Number}

    ````javascript
    let a='5'+1 //51
    ````

  * Obj[obj]
  
    ````javascript
    const a = {}
    const b = { key: 'b' }
    const c = { key: 'c' }
    
    //b被转换成"[object Object]"
    a[b] = 123
    //c也被转换成"[object Object]"
    a[c] = 456
    
    //相当于a["[object Object]"]
    console.log(a[b])//456
    ````
  
    

