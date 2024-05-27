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

## Q：Object.freeze是什么？怎么用？

* A：`Object.freeze`使得无法添加、删除或修改对象的属性（除非属性的值是另一个对象）。

  ````javascript
  Object.freeze(targetObj)
  ````

## Q：如何判断一个对象是否被冻结？

* A：使用`Object.isFrozen`检查
