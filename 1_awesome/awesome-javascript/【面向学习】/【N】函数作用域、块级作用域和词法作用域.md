# 变量的作用域

## Q：变量作用域有哪些？

* A：

  * 全局变量：函数**内部**可以直接读取全局变量。

    ````javascript
    var n=999;
    
    function f1(){
      alert(n);
    }
    
    f1(); // 999
    ````

  * 局部变量：函数**外部**无法读取函数内的局部变量。

    ````javascript
    function f1(){
      var n=999;
    }
    
    alert(n); // error

## Q：若不使用var命令，会声明什么变量？

* A：全局变量

  ````javascript
  function f1(){
    n=999;
  }
  
  f1();
  
  alert(n); // 999

## Q：如何从外部读取局部变量？

* A：使用闭包——在函数的内部，再定义一个函数。

  ````javascript
  function f1(){
  
    var n=999;
  
    function f2(){
      alert(n); // 999
    }
  
  }
  ````

  