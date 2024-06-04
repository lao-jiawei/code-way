# 第3章 语言基础

【本章内容】

- [ ] 语法
- [ ] 数据类型
- [ ] 流控制语句
- [ ] 理解函数

## 语法

### var关键字

* var声明的变量后续不仅可以改变保存的值，还可以改变数据类型

  ````javascript
  var massage='hi';
  massage=1;//合法但不推荐
  ````

  * 声明的变量会成为window对象的属性

    ````javascript
    //	还是上述案例
    console.log(window.massage)//1
    ````

* 声明作用域：**函数**作用域

  ````javascript
  function test(){
    var massage='hi';
  }
  test();
  console.log(message)//报错
  /*
  【原因】
  var声明的变量随着函数的销毁，而销毁。
  */
  ````

* 【不推荐】在函数中定义变量时省略var，会创建一个全局变量

  ````javascript
  function test(){
    message='hi';//全局变量
  }
  test();
  console.log(message) // 'hi'
  ````

* 可以通过`,`分隔一次声明多个变量

* 声明提升——把所有声明的变量都自动拉到最前

  ````javascript
  function foo(){
    console.log(age);
    var age=22;
  }
  foo()//'undefined'
  //因为声明提升，所以相当于
  function foo(){
    var age;
    console.log(age); //这时候age变量还没赋值，所以为undefined,详情请前往undefined类型查看
    arg=22;
  }
  foo()//'undefined';
  ````

* 反复多次使用var声明同一个变量也没问题

  ````javascript
  function foo(){
    var age=12;
    var age=22;
    var age=32
    console.log(age);
  }
  foo();//32;
  ````

  * for循环中的var声明

    ````javascript
    // 使用var声明for循环
    for(var i=0;i<5;i++){
      setTimeout(()=>{console.log(i)},0);
    }
    // 5、5、5、5、5
    /*
    【原因】
    因为var可以冗余声明，所以所有的i都是同一个变量
    */
    ````

### **let 声明**

* 声明作用域：块作用域（是函数作用域的子集，即：函数作用域>块作用域）

  ````javascript
  if(true){
    let age=22;
    console.log(age)//22
  }
  console.log(age)//ReferenceError:age
  /*
  【原因】
  let 定义的变量只在块作用域内生效
  */
  ````

  * for 循环中的let声明

    ````javascript
    // 使用let声明for循环
    for(let i=0;i<5;i++){
      setTimeout(()=>{console.log(i)},0);
    }
    // 0、1、2、3、4
    /*
    【原因】
    每次迭代都会声明一个新的迭代变量
    每次引用的都是不同的变量
    */
    ````

* 不允许冗余声明（即：不允许重复声明同一个变量名）

  ````javascript
  let age;
  var age; //SyntaxError
  ````

* let 声明的变量不会在作用域中被提升。（即：不能在声明前调用变量）

  ````javascript
  console.log(name)//ReferenceError:age
  let age=22;
  ````

  * 暂时性死区：在let 声明前的执行瞬间
    * 在此阶段引用任何后面才声明的变量都会抛出`ReferenceError`

* let 在全局作用域中声明的变量不会成为window对象的属性。

  ````javascript
  // 还是上述例子
  console.log(window.age)//undefined
  ````

### const 声明

* 与let行为基本相同，但是声明时必须有初始值

  * 不允许修改值类型
  * 但是可以修改引用类型。

  ````javascript
  const res=1;resObj={};
  res=2; //TypeError: 给常量赋值
  resObj.number=2;
  console.log(resObj.number)//2
  ````

* 不允许冗余声明（即：不允许重复声明同一个变量名）

  ````javascript
  const age=22;
  const age=23; //SyntaxError
  ````

* 声明作用域：块级作用域

* 不能用const来声明迭代变量

  ````javascript
  for(const i=0;i<10;i++){}//TypeError:给常量赋值
  ````

  * 但是可以用了声明不会被修改的循环变量

    ````javascript
    // for...in
    for(const key if {a:1,b:2}){
      console.log(key);
    }
    //a,b
    
    //for...of
    for(const value of [1,3,4]){
      console.log(value);
    }
    //1,3,4
    ````

## 数据类型

### typeof

* 用来确定任意变量的数据类型。
* 返回是一个字符串
* 是一个操作符而不是一个函数所以不需要用参数
* 注意：使用typeof来辨别null或object会无法区分
  * 【因为】null被认为是一个空对象，从而返回"object"字符串

### **Undefined 类型**

* 只有一个值

  * 当var或let声明了变量但没有初始化时，相当于赋值undefined。
  * 永远不需要显式各某个变量设置undefined值。

* 包含undefined值的变量和未定义变量不是一样的

  ````javascript
  let message;
  
  //let age 没有定义的变量
  console.log(message) //'undefined'
  console.log(age) //报错
  ````

* undefined检验——不能单纯依赖typeof来判断，而是通过字面量来检测

  ````javascript
  // 上述案例
  cosole.log(typeof message)// 'undefined'
  cosole.log(typeof age) //'undefined'
  //对于没有声明的变量通过typeof校验也是undefined
  //所以无法通过typeof 来区分undefined类型
  ````

### **Null 类型**

* 只有一个值——表示一个空对象指针实际上是赋值`{}`。

  ````javascript
  let car=null;
  console.log(typeof car)//'object';
  ````

* undefined是由null派生而来的

  ````javascript
  console.log(undefined==null)//true;
  ````

* 用途：变量将来要保存对象值时，需要显式赋值

* 检测：用字面量检测



# 第10章 函数

【本章内容】

- [x] 函数表达式、函数声明及箭头函数
- [ ] 默认参数及扩展操作符
- [ ] 使用函数实现递归
- [ ] 使用闭包实现私有变量

## 函数声明

【格式】

````javascript
function fucName(arg1,arg2,...args){
  /* 函数内容 */
}
````

* 每个函数都是Function类型的实例。

* 函数是对象，也有属性和方法。

* 函数名就是指向函数对象的指针。

  > 函数名：指向函数对象的指针
  >
  > * 一个函数可以有多个名称
  >
  >   ````javascript
  >   function sum(a+b){
  >     return a+b;
  >   }
  >   console.log(sum(1,1))//2
  >   
  >   //不带括号的函数名会访问函数指针，而不会执行函数
  >   //两个函数名指向同一个函数地址
  >   const anotherSum=sum;
  >   //切断其中一个指针指向，并不会影响另一个指针指向
  >   sum=null
  >   console.log(anotherSum(1,2))//3
  >   ````
  >
  > * ES6中获取函数名
  >
  >   ````javascript
  >   //已上述为例
  >   console.log(sum.name)//'sum'
  >   //若函数没有名称，返回空字符串
  >   console.log((()=>{}).name)//''
  >   //若是Function函数构建，则会返回‘anonymous’
  >   console.log((new Function()).name)//'anonymous'
  >   ````

* 【规范】函数声明结尾可以不加`;`

* `arguments`——类数组对象（包含调用函数时传入的参数）

  * 只有以`function`关键字定义的函数（还有箭头函数）时才会有

  * 内包含`cellee`属性——指向arguments对象所在函数的指针。

    ````javascript
    function factorial(num){
      if(num<=1){
        return 1;
      }else{
        //待优化点：若修改函数名，此处还需要修改。
        return num*factorial(num-1);
      }
    }
    
    function factorial(num){
      if(num<=1){
        return 1;
      }else{
        //使用arguments.callee可以让函数逻辑与函数名结偶
        //（即：无论函数名修改什么，都可以引用正确的函数）
        return num*arguments.callee(num-1);
      }
    }
    ````

    

* `this`指向：方法调用的上下文对象。

  ````javascript
  window.color='red';
  let o={
    color:'blue'
  };
  
  function sayColor(){
    console.log(this.color);
  }
  sayColor();//'red'——这里调用方法的上下文对象为window
  
  o.sayColor=sayColor;//把sayColor赋值给o后
  o.sayColor();//'blue'——sayColor中的this.color相当于o.color;
  ````

* `caller`——【ES5】用于调用当前函数的函数。（即返回引用该函数的函数）

  ````javascript
  function outer(){
    inner();
  }
  
  function inner(){
    console.log(inner.caller);//显示outer()函数的代码
    //若要降低耦合度可写成
    console.log(arguments.callee.caller);
    //严格模式下arguments.callee会报错，且不能给caller赋值。
  }
  outer();
  ````

## 函数表达式

【格式】

````javascript
const funcName=function (arg1,arg2,...args){
  /* 函数内容 */
};
````

* 与函数声明等价
* function关键字后没有名称，这个函数可以通过变量funcName来引用。
* 【规范】末尾是有`;`

## 箭头函数

【格式】

````javascript
const arrFunc=(arg1,arg2,...args)=>{
  /* 函数内容*/
};
````

* 任何可以使用函数表达式的地方都可以使用箭头函数

* 使用场景：

  * 嵌入函数的场景

    ````javascript
    let ints=[1,2,3];
    ints.map((i)=>{return i+1});
    ````

* 如果只有一个参数，可以不用括号。

* 如果没有参数或有多个参数才需要括号。

* 不能使用`arguments`、`super`和`new.target`属性，不能用做构造函数。

* this指向：箭头函数的上下文。(箭头函数中的this会保留定义该函数时的上下文)

  ````javascript
  function King(){
    this.royaltyName='Henry';
    //this 引用King的实例
    setTimeout(()=>console.log(this.royaltyName),1000);
  }
  
  function Queen(){
    this.royaltyName='Elizabeth';
    //this 引用window对象
    setTimeout(function(){console.log(this.royaltyName)},1000);
  }
  
  new King();//'Henry'
  new Queen();//undefined
  ````

  

# 第11章 期约与异步函数

【本章内容】

- [ ] 异步编程
- [ ] 期约
- [ ] 异步函数

## 异步函数（async/await）

* 异步函数——ES6在ECMAScript函数中应用。

* async/await——ES8规范新增。（让以同步方式写的代码能够异步执行）

  * > async

    * 用于声明异步函数——可以让函数具有异步特征。

      ````javascript
      //用在：函数声明
      async function foo(){}
      //用在：函数表达式
      let bar=async function(){};
      //用在：箭头函数
      let baz=async ()=>{};
      //用在：方法
      class Qux(){
        async qux(){}
      }
      ````

  * > await

    * 用于暂停异步函数代码的执行，等待期约解决
      * await关键词会暂停执行异步函数后面的代码，让出JavaScript运行时的执行线程。
        1. 尝试解包
        2. 将这个值传给表达式
        3. 异步恢复异步函数的执行
    * 使用方法
      * 可以单独使用
      * 可以在表达式中使用

* 异步函数仍然具有普通JS函数的正常行为，但是如果使用return关键字返回值（没有return则返回undefined）

  * 这个值会被Promise.resolve()包装成一个期约对象。（始终返回期约对象）

    ````javascript
    //异步函数返回值
    async function foo(){
      console.log(1);
      return 3;
    }
    foo().then(console.log);
    console.log(2);
    
    //1
    //2
    //3
    
    //异步函数直接返回期约对象
    async function foo(){
      console.log(1);
      return Promise.resolve(3);
    }
    foo().then(console.log);
    console.log(2);
    
    //1
    //2
    //3
    ````


* 异步函数返回值处理
  * 判断是否是实现thenable的对象
    * 是：返回值提供给then()的处理程序进行“解包”
    
      ````javascript
      //返回一个原始值
      async function foo(){
        return 'foo';
      }
      foo().then(console.log);//foo;
      
      // 返回一个实现了thenable接口的非期约对象
      async function baz(){
        const thenable={
          then(callback){callback('baz');}
        };
        return thenable;
      }
      baz().then(console.log);//baz
      
      //返回一个七月
      async function qux(){
        return Promise.resolve('qux';)
      }
      qux().then(console.log);//qux;
      ````
    
    * 否：返回值当作已经解决的期约
    
      ````javascript
      //返回一个没有实现thenalbe接口的对象
      async function bar(){
        return ['bar'];
      }
      bar().then(cosole.log);//['bar']
      ````
  
* 在异步函数中抛出错误会返回拒绝的期约；
  
  ````javascript
  async function foo(){
    console.log(1);
    throw 3;
  }
  foo().catch(console.log);
  console.log(2);
  //1
  //2
  //3
  ````
  
  * 拒绝的期约的错误不会被异步函数捕捉
  
    ````javascript
    async function foo(){
      console.log(1);
      Promise.reject(3);
    }
    foo().catch(console.log);
    console.log(2);
    //1
    //2
    //Uncaught(in promise):3
    ````



# 第17章 事件

【本章内容】

- [x] 理解事件流
- [ ] 使用事件处理程序
- [ ] 了解不同类型的事件

## 事件流

* 事件流——描述页面接收事件的顺序。

  ![](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/abf749d3c7a941e3aa1ff33dc33a3439~tplv-k3u1fbpfcp-jj-mark:3024:0:0:0:q75.awebp)

  * 事件冒泡
    * 从最底部一直向上触发，一直冒泡到window对象。
  * 事件捕获
    * 先由document元素捕获，然后沿着DOM树依次向下传播，直到到达实际的目标元素。
    * 所有浏览器都是从window对象开始捕获事件，而DOM2 Events规定从document开始。

* DOM事件流

  * 事件流分三阶段
    1. 事件捕获——最先发生，为提前拦截事件提供可能
    2. 到达目标
    3. 事件冒泡——最后阶段，最迟要在这个阶段响应事件。

### 事件委托【项目优化】

* 利用事件冒泡，将子元素的处理事件委托给父元素，可以实现只使用一个事件处理来管理一种类型的事件。

* 实现优化：

  * document对象随时可用。（即：可以动态添加 `DOM` 元素）

    * 任何时候都可以给它添加事件处理程序(不用等待 DOMContentLoaded 或 load 事件)。

      （即只要页面渲染出可点击的元素，就可以无延迟地起作用。）

  * 节省页面事件处理程序的时间。

    （代码不会导致先期延迟，因为只访问了一个DOM元素和添加了一个事件处理程序。）

    * 【原因】只指定一个事件处理程序，既节省DOM引用，也节省时间。

  * 占用内存更少。

* 可优化位置：
  1. 所有使用按钮事件的位置。

