# 闭包

## Q：是什么？

* A：
  * 够读取其他函数内部变量的函数，是将函数内部和函数外部连接起来的一座桥梁。——by：阮一峰
  * 词法表示包括不被计算的变量的函数。——by：W3school
  * 函数以及其捆绑的周边环境状态[（**lexical environment**，**词法环境**）](https://github.com/lao-jiawei/code-way/blob/main/1_awesome/awesome-javascript/【面向学习】/【N】执行上下文.md)的引用的组合。——by：MDN


## Q：能干什么？

* A：

  * 可以从内部函数访问外部函数的作用域，允许将函数与其所操作的某些数据（环境）关联起来。

    ````javascript
     //示例
    function makeAdder(x) {
      return function (y) {
        return x + y;
      };
    }
    
    //此时传入makeAdder中的x
    var add5 = makeAdder(5);
    var add10 = makeAdder(10);
    
    //此时传入makeAdder中的y，但是函数会记住之前传的x
    console.log(add5(2)); // 7
    console.log(add10(2)); // 12
    ````
  * 模拟私有方法，闭包可以访问私有函数和变量。

    ````javascript
    var Counter = (function () {
      var privateCounter = 0;
      function changeBy(val) {
        privateCounter += val;
      }
      return {
        increment: function () {
          changeBy(1);
        },
        decrement: function () {
          changeBy(-1);
        },
        value: function () {
          return privateCounter;
        },
      };
    })();
    
    console.log(Counter.value()); /* logs 0 */
    Counter.increment();
    Counter.increment();
    console.log(Counter.value()); /* logs 2 */
    Counter.decrement();
    console.log(Counter.value()); /* logs 1 */
    ````
    
  * 让变量的值始终保持在内存中。
## Q：什么时候被创建？

* A：随着函数的创建而被同时创建。

## Q：闭包的缺点是什么？

* A：在处理速度和内存消耗方面对脚本性能具有负面影响
