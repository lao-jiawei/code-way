# 生成器

## Q：能干啥？

* A：拥有在一个函数块内暂停和恢复代码执行的能力

## Q：怎么用？

* A：

  ````javascript
  // 生成器函数声明
  function* generatorFn() {}
  // 生成器函数表达式
  let generatorFn = function* () {}
  // 作为对象字面量方法的生成器函é数 
  let foo = {
    * generatorFn() {}
  }
  // 作为类实例方法的生成器函数 
  class Foo {
    * generatorFn() {}
  }
  // 作为类静态方法的生成器函数 
  class Bar {
    static * generatorFn() {}
  }
  ````

  > 注意：箭头函数不能用来定义生成器函数。

## Q：生成器函数执行流程？

* A：
  * 遇到`yield`就停下，生成yield值并输出但是不返回（即：不return）。
  * 当再次执行next()方法时，会从之前停止的位置继续向下执行，至下一个`yield`停下。

## Q：如何提前终止生成器？

* A：return()和 throw()方法都可以用于强制生成器进入关闭状态。
  * 方法一：return()
  * 方法二：throw()

