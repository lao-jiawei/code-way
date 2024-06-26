# 使用ES6模块

## Q：可以修改引入模块的值吗？

* A：不能，引入的模块是只读的。只有导出他们的模块才能修改其值。

  ````javascript
  // counter.js
  let counter = 10;
  export default counter;
  ````

  ````javascript
  // index.js
  import myCounter from "./counter";
  
  myCounter += 1;
  
  console.log(myCounter);//Eorror
  ````


## Q：使用import和使用require模块加载顺序有何不同？

* A：

  * `import`命令是编译阶段执行的，在代码运行之前。因此这意味着被导入的模块会先运行，而导入模块的文件会后执行。

    ````javascript
    // index.js
    console.log('running index.js');
    import { sum } from './sum.js';
    console.log(sum(1, 2));
    
    // sum.js
    console.log('running sum.js');
    export const sum = (a, b) => a + b;
    
    //输出
    //'running sum.js'
    //'running index.js'
    //3
    ````

  * 使用`require()`，可以在运行代码时根据需要加载依赖项。

    ````javascript
    // index.js
    console.log('running index.js');
    const { sum } =require( './sum.js');
    console.log(sum(1, 2));
    
    // sum.js
    console.log('running sum.js');
    export const sum = (a, b) => a + b;
    //输出
    //'running index.js'
    //'running sum.js'
    //3
    ````


## Q：export const 和export default有何不同？

* A：

  ````javascript
  // info.js
  export const name = "Lydia";
  export const age = 21;
  export default "I love JavaScript";
  
  // index.js
  import * as info from "./info";
  console.log(info);
  //{
  //  default: "I love JavaScript",
  //  name: "Lydia",
  //  age: 21
  //}
  ````

  

