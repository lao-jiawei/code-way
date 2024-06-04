# 虚拟dom

## Q：是什么？

* A：一个数据结构——js树，用于表示真实DOM的状态。

## Q：能干嘛？

* A：
  * 减少对真实dom的操作
    * 当数据发生变化时，首先会在虚拟DOM上执行DOM更新，而不是直接操作真实DOM。然后，通过比较前后两个虚拟DOM的差异，最小化真实DOM的操作，从而减少页面重绘的次数，提高性能。

## Q：如何构建虚拟dom

* A：使用JSX（JavaScript XML）语法来描述虚拟DOM的结构

  ````jsx
  ReactDOM.render (
    <div>
      <h1>Hello, Virtual DOM!</h1>
    </div>
  )
  ````

  * 会被解析为虚拟dom对象

    ````javascript
    {
      type: 'div',
      children: [
        {
          type: 'h1',
          props: {},
          children: 'Hello, Virtual DOM!' 
        }
      ]
    }
