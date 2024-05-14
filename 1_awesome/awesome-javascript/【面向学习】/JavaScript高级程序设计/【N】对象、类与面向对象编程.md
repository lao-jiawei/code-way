# 对象

## Q：delete如何使用？

* A：

  ````javascript
  const obj={name:'test',age:12}
  const res=delete obj.name;
  console.log(res)//true;
  ````

  * 返回值：boolean类型，true——删除成功，false——失败。

  > 注意：无法删除值类型。

