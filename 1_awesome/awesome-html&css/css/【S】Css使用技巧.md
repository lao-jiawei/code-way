## Q：如何对png进行换色处理？

* A：对目标png元素设置css样式

  ````css
  //其本质就是生成一个新的阴影，改变阴影的颜色，将阴影移到原png位置
  .img {
      transform: translateX(-100%);
    	filter: drop-shadow(120px 0 {想要换的颜色});
  }
  ````

* 参考：

  [【掘金】用CSS也可以任意改变PNG图标颜色？](https://juejin.cn/user/2013961033613694/posts)