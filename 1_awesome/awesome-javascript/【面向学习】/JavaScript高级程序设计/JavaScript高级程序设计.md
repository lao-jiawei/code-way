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

## 流控制语句

### 语句

#### for-in

* 严格的迭代语句，用于枚举对象中的非符号属性

  ````javascript
  for(const propName in window){
    document.write(propName)
  }
  ````

  * 每次执行循环，都会给变量赋值。

* 遍历对象时

  * 不能保证返回对象的属性的顺序
  * null或undefined不执行循环体
  * 会遍历整个对象甚至原型中的属性


#### for-of

* 严格的迭代语句，用于遍历可迭代的对象元素

  ````javascript
  for(const num of [1,2,3,4]){
    console.log(num);
  }
  ````

  *  循环会按照可迭代对象的 next()方法产生值的顺序迭代元素

# 第6章 集合引用类型

【本章内容】

- [ ] 对象
- [ ] 数组与定型数组
- [ ] Map、WeakMap、Set以及WeakSet类型

## 数组与定型数组

### Array

* 检测数组
  * 方法一：instanceof
  * 方法二：Array.isArray(tagetValue);

## Map

* 【ES6】新的集合类型

* 基本API

  | Api                 | 描述                            |
  | ------------------- | ------------------------------- |
  | new Map()           | 创建一个空映射                  |
  | .set("key","value") | 添加键/值对                     |
  | .get("key")         | 获取key的值                     |
  | .has("key")         | 查询是否存在key                 |
  | .size()             | 获取映射中的键/值对的数量       |
  | .delete("key")      | 删除改key的键/值对              |
  | .clear()            | 清除这个映射实例中的所有键/值对 |

* Map可以使用任何数据类型作为键

* Map实例会维护键值对的插入顺序。

  * 映射实例可以提供一个迭代器

    ````javascript
    const m=new Map([
      ["key1","val1"],
      ["key2","val2"],
      ["key3","val3"],
    ])
    
    console.log(m.entries===m[Symbol.iterator])//true;
    ````

  * Map对象转数组

    ````javascript
    console.log([...m])//[[key1,val1],[key2,val2],[key3,val3]]
    ````

  * 遍历Map对象与遍历Object对象一致

    ````javascript
    for(let key of m.keys()){
      console.log(key);
    }
    //key1
    //key2
    //key3
    
    for(let val of m.values()){
      console.log(val);
    }
    //value1
    //value2
    //value3
    ````

  * 键和值在迭代器遍历时是可以修改的，但映射内部的引用无法修改。

    

## Set

* 基本API

  | api       | 描述                   |
  | --------- | ---------------------- |
  | new Set() | 创建set对象            |
  | .size     | 获取元素数量           |
  | .add()    | 增加值                 |
  | .has()    | 查询值                 |
  | delete()  | 删除元素               |
  | .clear()  | 销毁集合实例中所有的值 |

* set可以包含任何数据类型的值。

* set支持顺序迭代

  * 集合实例可以提供一个迭代器

    ````javascript
    const s=new Set(['val1','val2','val3']);
    console.log(s.values===s[Symbol.iterator])//true;
    console.log(s.keys===s[Symbol.iterator])//true;
    ````

  * Set集合转数组

    ````javascript
    const s=new Set(['val1','val2','val3']);
    console.log([...s]);
    ````

  * 遍历set对象

    ````javascript
    //以上述案例
    for(let [key,value] of s.entries()){
      console.log(key,value);
    }
    // val1,val1
    // val2,val2
    // val3,val3
    s.forEach((key,value)=>console.log(key,value))//输出同上
    ````

  * 在遍历中修改set对象的值

    ````javascript
    const s1 = new Set(["val1"]);
    
    for(let val of s1.values()){
      val='newVal';
      console.log(val);//newVal
      console.log(s1.has('val1'))//true;
    }
    //set元素为数组时，无法修改其值
    
    const valObj={id:1}
    const s2 = new Set([valObj]);
    for(let val of s2.values()){
      val.id='newVal';
      console.log(val);//{id:'newVal'}
      console.log(s1.has(valObj))//true;
    }
    console.log(valObj);//{id:'newVal'}
    //set元素为Object时，可以修改其中的值。
    ````

    



# 第10章 函数

【本章内容】

- [x] 函数表达式、函数声明及箭头函数
- [ ] 默认参数及扩展操作符
- [ ] 使用函数实现递归
- [ ] 使用闭包实现私有变量

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

