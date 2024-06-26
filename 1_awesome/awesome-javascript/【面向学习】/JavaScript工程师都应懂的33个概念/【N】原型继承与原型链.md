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

## Q：原型如何实现继承？

* A：只需要将子级的原型对象设置为父级的一个实例，加入到原型链中即可。

## Q：原型的属性类型有哪些？

* A：

  | 字段         | 描述                                                         |
  | ------------ | ------------------------------------------------------------ |
  | configurable | 表示该属性是否能被delete删除。<br />当其值为false时，其他的特性也不能被改变。<br />默认值为true |
  | enumerable   | 是否能枚举。默认值为true                                     |
  | writable     | 是否能修改值。默认为true                                     |
  | value        | 该属性的具体值是多少。默认为undefined                        |
  | get          | 可以自定义返回的具体值是多少。get默认值为undefined           |
  | set          | 可以自定义设置值的具体方式。set默认值为undefined             |

  > 注意：不能同时设置value、writable 与 get、set的值。

## Q：如何修改属性类型？

* A：通过`Object.defineProperty`修改。

## Q：所有对象都有原型？

* A：错，除了基本对象（base object），所有对象都有原型。
  * 基本对象可以访问一些方法和属性，比如 `.toString`。

# 原型链

## Q：是什么？

* 由一个一个对象，一层一层`_proto_`属性形成的链式结构成为原型链

  * 如下图最底下连成的线为原型链。

    ![](https://imgconvert.csdnimg.cn/aHR0cDovL3Jlc291cmNlLm11eWl5LmNuL2ltYWdlLzIwMTktMDctMjQtMDYwMzE5LmpwZw?x-oss-process=image/format,png)

    对象的`_proto_`属性，这个属性也指向他的原型对象，原型对象也是对象，也有`_proto_`属性，指向原型对象的原型对象，以此类推直到指到最顶层找不到则返回null。

## Q：原型链的最末端指向的是什么？

* A：
