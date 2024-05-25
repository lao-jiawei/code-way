# 基本知识

## Q：是什么？

* A：可组装的 JavaScript 和 JSX 检查工具。

## Q：能干啥？

* A：用来检测 js 和 jsx 语法的工具，可以配置各项功能。

## Q：如何添加配置？

* A：

  * 方法一：.eslintrc.*：新建文件，位于项目根目录

    * `.eslintrc`
    * `.eslintrc.js`
    * `.eslintrc.json`

    > 区别在于配置格式不一样

  * 方法二：`package.json` 中 `eslintConfig`：不需要创建文件，在原有文件基础上写

## Q：配置文件内容含义？

* A：

  ````javascript
  module.exports = {
    // 解析选项
    parserOptions: {},
    // 具体检查规则
    rules: {},
    // 继承其他规则
    extends: [],
    // ...
    // 其他规则详见：https://eslint.bootcss.com/docs/user-guide/configuring
  };
  ````

  * parserOptions 解析选项

    ````javascript
    parserOptions: {
      ecmaVersion: 6, // ES 语法版本
      sourceType: "module", // ES 模块化
      ecmaFeatures: { // ES 其他特性
        jsx: true // 如果是 React 项目，就需要开启 jsx 语法
      }
    }
    ````

  * rules 具体规则