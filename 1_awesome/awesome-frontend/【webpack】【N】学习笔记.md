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

## Q：如何使用Eslint插件？

* A：

  1. 下载包

     ````bash
     npm i eslint-webpack-plugin eslint -D
     ````

  2. 定义Eslint配置文件，在`.src`同级目录下创建`.eslintrc.js`文件

     ````javascript
     //.eslintrc.js
     module.exports = {
       // 继承 Eslint 规则
       extends: ["eslint:recommended"],
       env: {
         node: true, // 启用node中全局变量
         browser: true, // 启用浏览器中全局变量
       },
       parserOptions: {
         ecmaVersion: 6,
         sourceType: "module",
       },
       rules: {
         "no-var": 2, // 不能使用 var 定义变量
       },
     };
     ````

  3. 重新打包

  > 注意：如何让eslint忽略指定目录下的文件？
  >
  > * A：在`.src`同级目录下创建`.eslintignore`文件，里面输入需要忽略的文件路径。

## Q：如何使用babel？

* A：

  1. 在`src`目录同级中添加配置文件`babel.config.js`

     ````javascript
     module.exports = {
       // 预设
       presets: [],
     };
     ````

     * `presets 预设`：一组 Babel 插件, 扩展 Babel 功能

       * `@babel/preset-env`: 一个智能预设，允许您使用最新的 JavaScript。

         `@babel/preset-react`：一个用来编译 React jsx 语法的预设

         `@babel/preset-typescript`：一个用来编译 TypeScript 语法的预设。

  2. 设置`webpack.config.js`配置

     ````javascript
     module.exports = {
       entry: "./src/main.js",
       output: {
         path: path.resolve(__dirname, "dist"),
         filename: "static/js/main.js", // 将 js 文件输出到 static/js 目录中
         clean: true, // 自动将上次打包目录资源清空
       },
       module: {
         rules: [
           // 对js进行编译
           {
             test: /.js$/,
             exclude: /node_modules/, // 排除node_modules代码不编译
             loader: "babel-loader",
           },
         ],
       },
       plugins: [],
       mode: "development",
     };
     ````

## Q：如何配置css兼容性？

* A：

  1. 下载包

     ````bash
     npm i postcss-loader postcss postcss-preset-env -D
     ````

  2. 配置生产环境webpack配置

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
               MiniCssExtractPlugin.loader,
               "css-loader",
               {
                 loader: "postcss-loader",
                 options: {
                   postcssOptions: {
                     plugins: [
                       "postcss-preset-env", // 能解决大多数样式兼容性问题
                     ],
                   },
                 },
               },
             ],
           },
           {
             test: /.less$/,
             use: [
               MiniCssExtractPlugin.loader,
               "css-loader",
               {
                 loader: "postcss-loader",
                 options: {
                   postcssOptions: {
                     plugins: [
                       "postcss-preset-env", // 能解决大多数样式兼容性问题
                     ],
                   },
                 },
               },
               "less-loader",
             ],
           },
           {
             test: /.s[ac]ss$/,
             use: [
               MiniCssExtractPlugin.loader,
               "css-loader",
               {
                 loader: "postcss-loader",
                 options: {
                   postcssOptions: {
                     plugins: [
                       "postcss-preset-env", // 能解决大多数样式兼容性问题
                     ],
                   },
                 },
               },
               "sass-loader",
             ],
           },
           {
             test: /.styl$/,
             use: [
               MiniCssExtractPlugin.loader,
               "css-loader",
               {
                 loader: "postcss-loader",
                 options: {
                   postcssOptions: {
                     plugins: [
                       "postcss-preset-env", // 能解决大多数样式兼容性问题
                     ],
                   },
                 },
               },
               "stylus-loader",
             ],
           },
           ...,
         ],
       },
       plugins: [
         ...,
       ],
       mode: "production",
     };
     ````

  3. 处理兼容性控制

     ````json
     //在 package.json 文件中添加 browserslist 来控制样式的兼容性做到什么程度。
     {
       ...,
       "browserslist": ["last 2 version", "> 1%", "not dead"]
     }
     ````

## Q：如何处理耦合度高的代码？

* A：封装处理

  ````javascript
  // 获取处理样式的Loaders
  const getStyleLoaders = (preProcessor) => {
    return [
      MiniCssExtractPlugin.loader,
      "css-loader",
      {
        loader: "postcss-loader",
        options: {
          postcssOptions: {
            plugins: [
              "postcss-preset-env", // 能解决大多数样式兼容性问题
            ],
          },
        },
      },
      preProcessor,
    ].filter(Boolean);
  };
  
  module.exports = {
    ...,
    module: {
      rules: [
        {
          // 用来匹配 .css 结尾的文件
          test: /.css$/,
          // use 数组里面 Loader 执行顺序是从右到左
          use: getStyleLoaders(),
        },
        {
          test: /.less$/,
          use: getStyleLoaders("less-loader"),
        },
        {
          test: /.s[ac]ss$/,
          use: getStyleLoaders("sass-loader"),
        },
        {
          test: /.styl$/,
          use: getStyleLoaders("stylus-loader"),
        },
        ...,
      ],
    },
    plugins: [...],
    mode: "production",
  };
  ````

  



# Plugins

## Q：如何处理HTML资源？

* A：

  1. 下载插件

     ````bash
     npm i html-webpack-plugin -D
     ````

  2. 设置`webpack.config.js`

     ````javascript
     const path = require("path");
     const ESLintWebpackPlugin = require("eslint-webpack-plugin");
     const HtmlWebpackPlugin = require("html-webpack-plugin");
     
     module.exports = {
       ...,
       plugins: [
         new ESLintWebpackPlugin({
           // 指定检查文件的根目录
           context: path.resolve(__dirname, "src"),
         }),
         new HtmlWebpackPlugin({
           // 以 public/index.html 为模板创建文件
           // 新的html文件有两个特点：1. 内容和源文件一致 2. 自动引入打包生成的js等资源
           template: path.resolve(__dirname, "public/index.html"),
         }),
       ],
       mode: "development",
     };
     ````

  3. 重新打包

## Q：如何单独打包css文件？

* A：

  1. 下载包

     ````bash
     npm i mini-css-extract-plugin -D
     ````

  2. 设置生产环境下的webpack配置

     1. 将所以`style-loader`替换成`MiniCssExtractPlugin`
     2. 插件字段中添加`MiniCssExtractPlugin`配置

     ````javascript
     const MiniCssExtractPlugin = require("mini-css-extract-plugin");
     
     module.exports = {
       ...,
       module: {
         rules: [
           {
             // 用来匹配 .css 结尾的文件
             test: /.css$/,
             // use 数组里面 Loader 执行顺序是从右到左
             use: [MiniCssExtractPlugin.loader, "css-loader"],
           },
           {
             test: /.less$/,
             use: [MiniCssExtractPlugin.loader, "css-loader", "less-loader"],
           },
           {
             test: /.s[ac]ss$/,
             use: [MiniCssExtractPlugin.loader, "css-loader", "sass-loader"],
           },
           {
             test: /.styl$/,
             use: [MiniCssExtractPlugin.loader, "css-loader", "stylus-loader"],
             ...,
         ],
       },
       plugins: [
         ...,
         // 提取css成单独文件
         new MiniCssExtractPlugin({
           // 定义输出文件名和目录
           filename: "static/css/main.css",
         }),
       ],
       mode: "production",
     };
     ````

## Q：为什么要对css单独打包？

* A：Css 文件被打包到 js 文件中，当 js 文件加载时，会创建一个 style 标签来生成样式，这样对于网站来说，会出现闪屏现象，用户体验不好

## Q：如何对css打包资源进行压缩？

* A：使用`css-minimizer-webpack-plugin`

  1. 下载包

     ````bash
     npm i css-minimizer-webpack-plugin -D
     ````

  2. 配置生产环境webpack配置

     ````javascript
     const CssMinimizerPlugin = require("css-minimizer-webpack-plugin");
     
     module.exports = {
       ...,
       module: {
         rules: [...],
       },
       plugins: [
         ...,
         // css压缩
         new CssMinimizerPlugin(),
       ],
       ...,
       mode: "production",
     };
     ````

## Q：如何对html或js打包资源进行压缩？

* A：默认生产模式已经开启了：html 压缩和 js 压缩。所以不需要额外进行配置

# devServer

## Q：如何开启服务器&自动化？

* A：

  1. 下载包

     ````bash
     npm i webpack-dev-server -D
     ````

  2. 配置`webpack.config.js`

     ```javascript
     module.exports = {
     	...,
       // 开发服务器
       devServer: {
           host: "localhost", // 启动服务器域名
           port: "3000", // 启动服务器端口号
           open: true, // 是否自动打开浏览器
       },
       mode: "development",
     };
     ```

  3. 运行开发服务

     ````bash
     npx webpack serve
     ````

     * 当使用开发服务器时，所有代码都会在内存中编译打包，并不会输出到 dist 目录下。

# 生产模式

## Q：优化内容有哪些？

* A：
  * 优化代码运行性能
  * 优化代码打包速度

## Q：如何配置项兼容开发与生产？

* A：

  1. 设置项目文件目录

     ````bash
     ├── (项目根目录)
         ├── config (Webpack配置文件目录)
         │    ├── webpack.dev.js(开发模式配置文件)
         │    └── webpack.prod.js(生产模式配置文件)
         ├── node_modules (下载包存放目录)
         ├── src (项目源码目录，除了html其他都在src里面)
         │    └── 略
         ├── public (项目html文件)
         │    └── index.html
         ├── .eslintrc.js(Eslint配置文件)
         ├── babel.config.js(Babel配置文件)
         └── package.json (包的依赖管理配置文件)
     ````

  2. 设置开发模式配置文件`webpack.dev.js`

     ````javascript
     module.exports = {
       entry: "./src/main.js",
       output: {
         path: undefined, // 开发模式没有输出，不需要指定输出目录
         filename: "static/js/main.js", // 将 js 文件输出到 static/js 目录中
         // clean: true, // 开发模式没有输出，不需要清空输出结果
       },
       module: {
         rules: [
           ...,
         ],
         plugins: [
           new ESLintWebpackPlugin({
             // 指定检查文件的根目录
             context: path.resolve(__dirname, "../src"),
           }),
           new HtmlWebpackPlugin({
             // 以 public/index.html 为模板创建文件
             // 新的html文件有两个特点：1. 内容和源文件一致 2. 自动引入打包生成的js等资源
             template: path.resolve(__dirname, "../public/index.html"),
           }),
         ],
     // 其他省略
       devServer: {
         host: "localhost", // 启动服务器域名
         port: "3000", // 启动服务器端口号
         open: true, // 是否自动打开浏览器
       },
       mode: "development",
     };
     ````

  3. 设置生产模式配置文件`webpack.prod.js`

     ````javascript
     module.exports = {
       entry: "./src/main.js",
       output: {
         path: path.resolve(__dirname, "../dist"), // 生产模式需要输出
         filename: "static/js/main.js", // 将 js 文件输出到 static/js 目录中
         clean: true,
       },
       module: {
         rules: [
           ...,
         ],
       },
       plugins: [
         ...,
       ],
       mode: "production",
     };
     ````

  4. 配置运行命令

     ````json
     // package.json
     {
       // 其他省略
       "scripts": {
         "start": "npm run dev",
         "dev": "npx webpack serve --config ./config/webpack.dev.js",
         "build": "npx webpack --config ./config/webpack.prod.js"
       }
     }
     ````

# 优化方向

## 提升开发体验

### Q：如何使打包后报错可映射源码报错位置？

* A：使用SourceMap工具

  - 开发模式：`cheap-module-source-map`
    - 优点：打包编译速度快，只包含行映射
    - 缺点：没有列映射

  ```javascript
  module.exports = {
    // 其他省略
    mode: "development",
    devtool: "cheap-module-source-map",
  };
  ```

  - 生产模式：`source-map`
    - 优点：包含行/列映射
    - 缺点：打包编译速度更慢

  ```javascript
  module.exports = {
    // 其他省略
    mode: "production",
    devtool: "source-map",
  };
  ```

## 提升代码构建速度

### Q：如何实现模块热替换？

* A：使用HotModuleReplacement（HMR/热模块替换）

  * 能干嘛？：在程序运行中，替换、添加或删除模块，而无需重新加载整个页面。

  * 怎么用？：

    ````javascript
    module.exports = {
      // 其他省略
      devServer: {
        host: "localhost", // 启动服务器域名
        port: "3000", // 启动服务器端口号
        open: true, // 是否自动打开浏览器
        hot: true, // 开启HMR功能（只能用于开发环境，生产环境不需要了）
      },
    };
    ````

    > 注意：JS默认不能热模块替换
    >
    > * 需要使用 module.hot.accept 使js开启热加载，但是需要先判断是否支持 module.hot
    >
    >   ````javascript
    >   // main.js
    >   
    >   // 判断是否支持HMR功能
    >   if (module.hot) {
    >     module.hot.accept("./js/count.js", function (count) {
    >         const result1 = count(2, 1);
    >         console.log(result1);
    >     });
    >     module.hot.accept("./js/sum.js", function (sum) {
    >         const result2 = sum(1, 2, 3, 4);
    >         console.log(result2);
    >     });
    >   }
    >   ````
    >
    > * 实际开发会使用其他 loader 来解决（比如：vue-loader，react-hot-loader。）加入以上loader自动配置js热加载。

## 减少代码体积

## 优化代码运行性能



