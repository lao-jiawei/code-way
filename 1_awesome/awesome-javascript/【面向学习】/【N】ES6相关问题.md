# 模版字符串

## Q：将模版字符串作为参数传递，参数分别是啥？

* A：第一个参数的值总是包含字符串的数组。其余的参数获取的是传递的表达式的值

  `````javascript
  function getPersonInfo(one, two, three) {
    //["", " is ", " years old"]
  	console.log(one)
    //'Lydia'
  	console.log(two)
    //21
  	console.log(three)
  }
  
  const person = 'Lydia'
  const age = 21
  
  getPersonInfo`${person} is ${age} years old`
  `````

  