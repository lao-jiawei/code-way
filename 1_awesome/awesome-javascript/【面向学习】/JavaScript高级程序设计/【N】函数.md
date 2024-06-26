# 函数声明

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

# 函数表达式

【格式】

````javascript
const funcName=function (arg1,arg2,...args){
  /* 函数内容 */
};
````

* 与函数声明等价
* function关键字后没有名称，这个函数可以通过变量funcName来引用。
* 【规范】末尾是有`;`

# 箭头函数

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


# 默认参数值

## Q：函数设置默认参数值时发生了什么？

* A：若参数指定对象作为默认参数值时。会以默认参数值为模版，创建一个新的对象。

  ````javascript
  const person = {
    name: "Lydia",
    age: 21
  }
  
  const changeAge = (x = { ...person }) => x.age += 1
  const changeAgeAndName = (x = { ...person }) => {
    x.age += 1
    x.name = "Sarah"
  }
  
  changeAge(person)
  changeAgeAndName()//该调用中的参数x就以person为模版new一个新对象
  ````


# 私有变量

## Q：如何在类中声明一个私有变量？

* A：使用`#`为前缀声明私有变量（ES2020）

  ````javascript
  class Counter {
    #number = 10
  
    increment() {
      this.#number++
    }
  
    getNum() {
      return this.#number
    }
  }
  
  const counter = new Counter()
  counter.increment()
  //外部无法访问私有变量
  console.log(counter.#number)
  ````

  