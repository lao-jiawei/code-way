# webpack5介绍与基本使用

## Q：webpack是什么？

* A：静态资源打包工具

## Q：能干啥？

* A：将浏览器不能识别的语法打包成浏览器可以识别的语法。

## Q：webpack有哪几种模式？

* A：
  * 开发模式：编译JS中模块化语法
  * 生产模式：编译JS中模块化语法、压缩JS代码

## Q：如何使用？

* A：

  1. 生成包描述文件`package.json`

     ````shell
     npm init -y
     ````

  2. 下载webpack相关依赖

     ````shell
     npm i webpack webpack-cli -d
     ````

  3. 执行webpack指令

     ````shell
     npx webpack {入口路径} --mode={development|production}
     ````

     * `入口路径`：项目开始进入的路径。
     * `{development|production}`：开发模式

  4. 检查是否打包成功

     * 成功标志：是否有succeeful

# 基本配置

| 关键词           | 描述                                                         |
| ---------------- | ------------------------------------------------------------ |
| entry（入口）    | 指示webpack从哪个文件开始打包                                |
| output（输出）   | 指示 Webpack 打包完的文件输出到哪里去，如何命名等            |
| loader（加载器） | webpack 本身只能处理 js、json 等资源，其他资源需要借助 loader，Webpack 才能解析 |
| plugins（插件）  | 扩展 Webpack 的功能                                          |

## Q：如何添加配置文件？

* A：

  1. 在项目文件与`src`文件同级下创建`webpack.config.js`文件

     ````shell
     -
     |--src
     |--webpack.config.js
     ````

  2. 初始化文件内容

     ````javascript
     module.exports = {
       // 入口
       entry: "",
       // 输出
       output: {},
       // 加载器
       module: {
         rules: [],
       },
       // 插件
       plugins: [],
       // 模式
       mode: "",
     };
     ````

  3. 执行配置文件

     ````bash
     npx webpack
     ````

# 开发模式

## Q：开发模式能干什么？

* A：
  * 编译代码，使浏览器能识别运行
  * 代码质量检查，树立代码规范

# Loader

## Q：能干什么？

* A：Webpack 本身是不能识别样式资源的，需要借助 Loader 来帮助 Webpack 解析样式资源

## Q：如何处理Css资源？

* A：

  1. 下载包

     ````bash
     npm i css-loader style-loader -D
     ````

  2. 设置配置文件

     ````javascript
     module.exports = {
       ...,
       module: {
         rules: [
           {
             // 用来匹配 .css 结尾的文件
             test: /.css$/,
             // use 数组里面 Loader 执行顺序是从右到左
             use: [
               "style-loader", // 将js中css通过创建 style 标签添加 html 文件中生效
               "css-loader", // 将css资源编译成 commonjs 的模块到js中
             ],
           },
         ],
       },
       ...,
     };
     ````

  3. 重新打包

## Q：如何处理less资源？

* A：

  1. 下载包

     ````bash
     npm i less-loader less -D
     ````

  2. 设置配置文件

     ````javascript
     module.exports = {
       ...,
       module: {
         rules: [	
       			...,
           {
             test: /.less$/,
             // loader: 'xxx', 只能使用一个loader
             // use可以使用多个 loader
             use: ["style-loader", "css-loader", "less-loader"],
           },
         ],
       },
       ...,
       plugins: [],
       mode: "development",
     };
     ````

  3. 重新打包

## Q：如何处理sass资源？

* A：

  1. 下载包

     ```` bash
     npm i sass-loader less -D
     ````

  2. 设置配置文件

     ````javascript
     module.exports = {
       ...,
       module: {
         rules: [	
       			...,
           {
             test: /\.s[ac]ss$/,
             // loader: 'xxx', 只能使用一个loader
             // use可以使用多个 loader
             use: ["style-loader", "css-loader", "sass-loader"],
           },
         ],
       },
       ...,
       plugins: [],
       mode: "development",
     };
     ````

  3. 重新打包

## Q：如何处理stylus资源？

* A：
  1. 下载包
  
     ```` bash
     npm i stylus-loader less -D
     ````
  
  2. 设置配置文件
  
     ````javascript
     module.exports = {
       ...,
       module: {
         rules: [	
       			...,
           {
             test: /.styl$/,
             use: ["style-loader", "css-loader", "stylus-loader"],
           },
         ],
       },
       ...,
       plugins: [],
       mode: "development",
     };
     ````
  
  3. 重新打包

## Q：如何处理图片资源？

* A：

  1. 直接使用，只需设置配置文件

     ````javascript
     module.exports = {
       ...,
       module: {
         rules: [
           // 图片配置
           {
             test: /.(png|jpe?g|gif|webp)$/,
             type: "asset",
           },
         ],
       },
       plugins: [],
       mode: "development",
     };
     ````

  2. 删除dist中的文件

  3. 重新打包

## Q：如何指定打包文件路径？

* A：

  1. 修改配置文件

     ````javascript
     module.exports = {
       entry: "./src/main.js",
       output: {
         path: path.resolve(__dirname, "dist"),
         // 将 js 文件输出到 static/js 目录中
         filename: "static/js/main.js", 
       },
       ...,
     };
     ````

  2. 重新打包

## Q：如何设置图片打包配置？

* A：

  1. 修改配置文件
  
     ````javascript
     module.exports = {
       ...,
       module: {
         rules: [
     	  //	...
           {
             test: /.(png|jpe?g|gif|webp)$/,
             type: "asset",
             parser: {
               dataUrlCondition: {
                 maxSize: 10 * 1024, // 小于10kb的图片会被base64处理
               },
             },
             generator: {
               // 将图片文件输出到 static/imgs 目录中
               // 将图片文件命名 [hash:8][ext][query]
               // [hash:8]: hash值取8位
               // [ext]: 使用之前的文件扩展名
               // [query]: 添加之前的query参数
               filename: "static/imgs/[hash:8][ext][query]",
             },
           },
         ],
       },
       plugins: [],
       mode: "development",
     };
     ````
  
  2. 重新打包

## Q：如何自动清空上次打包资源？

* A：设置`output.clean`

  ````javascript
  module.exports = {
    entry: "./src/main.js",
    output: {
      path: path.resolve(__dirname, "dist"),
      filename: "static/js/main.js",
      clean: true, // 自动将上次打包目录资源清空
    },
    ...,
  };
  ````

  * 原理：在打包前，将path整个目录内容清空，再进行打包。

## Q：如何处理音频资源？

* A：

  1. 设置配置文件

     ````javascript
     module.exports = {
       ...,
       module: {
         rules: [
           // 添加此处配置
           {
             test: /.(ttf|woff2?|map4|map3|avi)$/,
             type: "asset/resource",
             generator: {
               filename: "static/media/[hash:8][ext][query]",
             },
           },
         ],
       },
       plugins: [],
       mode: "development",
     };
     ````

  2. 重新打包



