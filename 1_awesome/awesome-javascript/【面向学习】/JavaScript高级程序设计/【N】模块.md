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

  

