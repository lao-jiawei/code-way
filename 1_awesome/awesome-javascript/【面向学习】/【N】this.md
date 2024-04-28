# this

## Q：是什么？

* A：JavaScript 语言的一个关键字。

## Q：什么时候产生？

* A：函数运行时，在函数体内部自动生成的一个对象。

## Q：使用范围？

* A：只能在函数体内部使用。

## Q：值是什么？

* A：函数的不同使用场合，`this`有不同的值。总的来说，`this`就是函数运行时所在的环境对象。

## Q：this的用法有哪些？

* A：

  1. 纯粹的函数调用

     * 全局性调用，因此`this`就代表全局对象

     ````javascript
     var x = 1;
     function test() {
        console.log(this.x);
     }
     test();  // 1
     ````

  2. 作为对象方法的调用

     * 这时`this`就指这个上级对象

     ````javascript
     function test() {
       //上级对象为obj
       console.log(this.x);
     }
     
     var obj = {};
     obj.x = 1;
     obj.m = test;
     
     //作为对象方法调用
     obj.m(); // 1
     ````

  3.  作为构造函数调用
  
     * `this`指这个构造函数生成的新对象
  
       ````javascript
       function test() {
       　//this为构造函数生成的对象
         this.x = 1;
       }
       
       //构造函数
       var obj = new test();
       obj.x // 1
       ````
  
  4. apply调用
  
     ````javascript
     var x = 0;
     function test() {
     　console.log(this.x);
     }
     
     var obj = {};
     obj.x = 1;
     //此时this为obj对象
     obj.m = test;
     //通过apply调用后，由于没有参数，默认this指向全局对象
     obj.m.apply() // 0

# apply

## Q：是什么？

* A：是函数的一个方法，作用是改变函数的调用对象。

## Q：怎么用？

* A：它的第一个参数就表示改变后的调用这个函数的对象。
  * 参数为空时，默认调用全局对象。

# call

## Q：是什么？

* A：

## Q：能干什么？

* A：通过call方法，可以改变函数执行时的this指向

## Q：执行全局函数时发生了什么？

* A：

  ````javascript
  function say(word) {
    console.log(world);
  }
  say("Hello world");
  
  //js执行函数时会默认完成以下的步骤
  say.call(window, "Hello world");
  ````

  1.  把第二个到最后一个参数作为函数执行时要传入的参数
  2.  把函数执行时的this指向第一个参数
  3. 在上面这个特殊的上下文中执行函数