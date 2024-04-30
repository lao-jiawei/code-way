#   构造函数

## Q：是什么？

* A：专门用来生成实例对象的函数。
  * JavaScript 语言使用构造函数（constructor）作为对象的模板。

## Q：特点是什么？

* A：
  * 函数体内部使用了`this`关键字，代表了所要生成的对象实例。
  * 生成对象的时候，必须使用`new`命令。

## Q：构造函数如何实现继承？

* A：

  * 方法一：构造函数绑定

    * 使用call或apply方法，将父对象的构造函数绑定在子对象上

      ````javascript
      function Animal(){
        this.species = "动物";
      }
      function Cat(name,color){
        //继承Animal
        Animal.apply(this, arguments);
        this.name = name;
        this.color = color;
      }
      
      var cat1 = new Cat("大毛","黄色");
      alert(cat1.species); // 动物
      ````

  * 方法二： prototype模式（常见）

    * 若子类的prototype对象，指向一个父类的实例，那么所有子类的实例，就能继承父类了。

      ````javascript
      //将子类的prototype对象，指向一个父类的实例
      //它相当于完全删除了prototype 对象原先的值，然后赋予一个新值。
      Cat.prototype = new Animal();
      
      //任何一个prototype对象都有一个constructor属性，指向它的构造函数。
      //若没有这行，Cat.prototype.constructor指向Animal。
      Cat.prototype.constructor = Cat;
      
      var cat1 = new Cat("大毛","黄色");
      
      alert(cat1.species); // 动物
      ````

      

# new命令

## Q：new使用时发生了什么？

* A：执行构造函数，返回一个实例对象。相当于使用一个立即函数。每当用 `new` 调用函数时，JavaScript 解释器都会在底层创建一个全新的对象并把这个对象当做 `this`。

  ````javascript
  function person(name) {
    this.name = name;
  }
  var foo = new person("deen");
  //通过new创建了一个对象
  //new是一种语法糖，new person等价于
  var bar = (function(name) {
    var _newObj = {
      constructor : person,
      __proto__ : person.prototype,
    };
    _newObj.constructor(name); // _newObj.constructor.call(_newObj, name)
    return _newObj;
  })();
  ````

## Q：如果忘了使用`new`命令，直接调用构造函数会发生什么事？

* A：构造函数就变成了普通函数，并不会生成实例对象。`this`这时代表全局对象。

  ````javascript
  var Vehicle = function (){
    this.price = 1000;
  };
  
  var v = Vehicle();
  
  v // undefined
  //price属性变成了全局变
  price // 1000
  ````

## Q：构造函数内部有return语句会发生什么？

* A：

  * 若return对象，则返回return指定的对象

    ````javascript
    var Vehicle = function (){
      this.price = 1000;
      return { price: 2000 };
    };
    
    (new Vehicle()).price
    // 2000
    ````

    > 注意：
    >
    > * 如果`return`语句返回的是一个跟`this`无关的新对象，`new`命令会返回这个新对象，而不是`this`对象。

  * 否则，就会不管`return`语句，返回`this`对象。

    ````javascript
    var Vehicle = function () {
      this.price = 1000;
      return 1000;
    };
    
    (new Vehicle()) === 1000
    // false
    ````

## Q：构造函数内部如何知道是否使用new指令？

* A：可以使用`new.target`属性。

  * 如果当前函数是`new`命令调用，`new.target`指向当前函数
  * 否则为`undefined`。

  ````javascript
  function f() {
    console.log(new.target === f);
  }
  
  f() // false
  new f() // true
  ````

  

# 对象

## Q：是什么？

* A：每一个对象都是功能中心，具有明确分工，可以完成接受信息、处理数据、发出信息等任务。
  * 对象是单个实物的抽象。
  * 对象是一个容器，封装了属性（property）和方法（method）。

## Q：有什么特征？

* A：可以复用，通过继承机制还可以定制。