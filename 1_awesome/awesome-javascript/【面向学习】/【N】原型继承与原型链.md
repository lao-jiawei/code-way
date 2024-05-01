# 原型

## Q：是什么？

* A：函数的**prototype属性**（也称为原型对象）。构造函数在创建的过程中，系统自动创建出来与构造函数相关联的一个空的对象。

## Q：怎么访问到？

* A：由构造函数`.prototype`来访问到。

  ````javascript
  Person.prototype
  ````

## Q：可以做什么？

* 放一些属性和方法，共享给实例对象使用。
* 可以做继承。

# 原型链

## Q：是什么？

* 由一个一个对象，一层一层`_proto_`属性形成的链式结构成为原型链

  * 如下图最底下连成的线为原型链。

    ![](https://imgconvert.csdnimg.cn/aHR0cDovL3Jlc291cmNlLm11eWl5LmNuL2ltYWdlLzIwMTktMDctMjQtMDYwMzE5LmpwZw?x-oss-process=image/format,png)

    对象的`_proto_`属性，这个属性也指向他的原型对象，原型对象也是对象，也有`_proto_`属性，指向原型对象的原型对象，以此类推直到指到最顶层找不到则返回null。

## Q：原型连的最末端指向的是什么？

* A：
