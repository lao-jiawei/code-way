# 变量的作用域

## Q：什么是作用域？

* A：程序源代码中定义变量的区域。

## Q：有什么用？

* A：规定了如何查找变量，也就是确定当前执行代码对变量的访问权限。

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


## Q：var的作用域是什么？

* A：

  * 如果一个变量在函数体内部声明，则该变量的作用域为整个函数体，在函数体外不可引用该变量

    ````javascript
    'use strict';
    
    function foo() {
      //在函数体内部声明
      var x = 1;
      x = x + 1;
    }
    
    x = x + 2; // ReferenceError! 无法在函数体外引用变量x
    ````

  * 如果两个不同的函数各自申明了同一个变量，那么该变量只在各自的函数体内起作用。（即：不同函数内部的同名变量互相独立，互不影响）

    ````javascript
    'use strict';
    
    function foo() {
      var x = 1;
      x = x + 1;
    }
    
    function bar() {
      var x = 'A';
      x = x + 'B';
    }
    ````

# 函数作用域

## Q：哪些变量属于函数作用域？

* A：在某个函数内的变量即从属于当前函数作用域

## Q：特点是什么？

* A：内部函数可以访问外部函数定义的变量，反过来则不行

  ````javascript
  'use strict';
  
  function foo() {
    var x = 1;
    function bar() {
      // bar可以访问foo的变量x!
      var y = x + 1; 
    }
    // ReferenceError! foo不可以访问bar的变量y!
    var z = y + 1; 
  }
  ````

# 全局作用域

## Q：哪些变量具有全局作用域？

* A：不在任何函数内定义的变量就具有全局作用域。

## Q：全局作用域的变量在哪里可以访问到？

* A：window中。全局作用域的变量实际上被绑定到`window`的一个属性

## Q：全局作用域的特点是什么？

* A：
  * JavaScript实际上只有一个全局作用域。
  * 任何变量（函数也视为变量），如果没有在当前函数作用域中找到，就会继续往上查找，最后如果在全局作用域中也没有找到，则报`ReferenceError`错误。

# 块级作用域

## Q：如何使变量具有块级作用域？

* A：用`let`或`const`替代`var`可以申明一个块级作用域的变量

# 词法作用域（静态作用域）

## Q：是什么？

* A：一个符号参照到语境中符号名字出现的地方，局部变量缺省有着词法作用域。

## Q：采用静态作用域与动态作用域处理流程？

* A：

  【示例】

  ````javascript
  var value = 1;
  
  function foo() {
    console.log(value);
  }
  
  function bar() {
    var value = 2;
    foo();
  }
  
  bar();
  ````

  * 采用静态作用域时（按顺序而去获取）
    * 执行foo函数，先从foo函数内部查找是否有局部变量value，
      * 如果没有，就根据书写的位置，查找上面一层的代码，在这里是全局作用域，也就是value等于1，所以最后会打印1
  * 采用动态作用域时（随着函数调用而去获取）
    * 执行foo函数，依然是从foo函数内部查找是否有局部变量value。
      * 如果没有，就从调用函数的作用域，也就是bar函数内部查找value变量，所以最后会打印2

