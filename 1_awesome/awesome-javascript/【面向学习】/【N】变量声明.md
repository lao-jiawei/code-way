# 变量声明

## Q：声明分类有哪几种？

* A：var声明、let与const声明和函数声明。

## Q：变量声明与函数声明变量名相同，谁会生效？

* A：函数声明高于一切

  ````javascript
  foo();
  
  function foo() {
    console.log('foo');//foo
  }
  var foo = 2;
  ````

## Q：多个函数声明同一个变量名，谁会生效？

* A：有多个函数声明的时候，是由最后面的函数声明来替代前面的

  ````javascript
  foo();
  
  function foo() {
    console.log('1');
  }
  
  function foo() {
    console.log('2');//输出
  }
  ````

## Q：声明变量时发生了什么？

* A：干了两件事

  1. 编译器在当前作用域中声明一个变量`xxx`
  2. 运行时引擎在作用域中查找该变量，找到了`xxx`变量并为其赋值

  `````javascript
  var name = 'iceman'
  //实际上发生了两件事
  var name=undefinded;
  name='iceman';
  `````

  