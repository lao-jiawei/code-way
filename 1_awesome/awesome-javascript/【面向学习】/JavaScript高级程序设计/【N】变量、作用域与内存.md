# 垃圾回收

## Q：是什么？

* A：把没用的内存回收，以便重新使用。

## Q：如何实现垃圾回收？

* A：

  * 方法一：标记清除

    ````javascript
    let a = { name: '张三' };
    let b = { name: '李四' };
    a.friend = b;
    b.friend = a;
    a = full;
    b = full;
    ````

  * 方法二：