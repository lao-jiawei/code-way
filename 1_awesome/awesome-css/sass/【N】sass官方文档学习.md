# Sass特点

1. 使用变量：
   * 可以把反复使用的`css`属性值 定义成变量，然后通过变量名来引用它们，而无需重复书写这一属性值。
   * 对于仅使用过一 次的属性值，你可以赋予其一个易懂的变量名，让人一眼就知道这个属性值的用途。

# 1. 使用变量

## Q：为什么要在sass中引入变量？

* A：只需修改一处，其他引用的值随之改变。
  * css若需要一个不同的值，只需要改变这个变量的值，则所有引用此变量的地方生成的值都会随之改变。

## Q：如何声明变量？

* A：使用`$`符号来标识变量(老版本的`´sass`使用`!`来标识变量）

  ````scss
  //标识变量nav-color
  $nav-color: #F90;
  nav {
    //标识变量width
    $width: 100px;
    //使用变量width
    width: $width;
    //变量使用nav-color
    color: $nav-color;
  }
  
  //编译后
  
  nav {
    width: 100px;
    color: #F90;
  }
  ````

## Q：sass使用范围？

* A：任何可以用作`css`属性值的赋值都 可以用作`sass`的变量值，甚至是以空格分割的多个属性值

## Q：如何分格多个属性值？

* A：

  ````scss
  //方法一：空格分割
  $basic-border: 1px solid black;
  
  //方法二：逗号分割
  $plain-font: "Myriad Pro"、Myriad、"Helvetica Neue"、Helvetica、"Liberation Sans"、Arial和sans-serif; sans-serif;
  ````

## Q：变量使用范围？

* A：

  * 变量可以在`css`规则块定义之外存在。

    ````scss
    $nav-color: #F90;
    nav {
      color: $nav-color;
    }
    ````

  * 当变量定义在`css`规则块内，那么该变量只能在此规则块内使用。

    ````scss
    nav {
      $width: 100px;
      width: $width;
    }
    ````

## Q：如何引用变量？

* A：

  * 单层引用

    ````scss
    $highlight-color: #F90;
    .selected {
      border: 1px solid $highlight-color;
    }
    
    //编译后
    
    .selected {
      border: 1px solid #F90;
    }
    ````

  * 多层嵌套引用

    ````scss
    $highlight-color: #F90;
    $highlight-border: 1px solid $highlight-color;
    .selected {
      border: $highlight-border;
    }
    
    //编译后
    
    .selected {
      border: 1px solid #F90;
    }
    ````

## Q：如何给变量命名？

* A：使用中划线的方式更为普遍。`sass`的变量名可以与`css`中的属性名和选择器名称相同，包括中划线和下划线。

  * scss做了兼容，用中划线声明的变量可以使用下划线的方式引用，反之亦然。

    ````scss
    $link-color: blue;
    a {
      color: $link_color;
    }
    
    //编译后
    
    a {
      color: blue;
    }
    ````

## Q：为什么用中划线声明的变量可以使用下划线的方式引用？

* A：中划线和下划线的变量，其实指向的是同一个变量。
  * 在`sass`的大 多数地方，中划线命名的内容和下划线命名的内容是互通的，除了变量，也包括对混合器和Sass函数的命名。
  * 但是在`sass`中纯`css`部分不互通，比如类名、ID或属性名。

# 2.嵌套CSS 规则

