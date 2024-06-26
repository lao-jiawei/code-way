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
           //...,
         ],
       },
       plugins: [
         //...,
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

### Q：如何让文件匹配上一个loader，剩下的rule就不匹配了？

* A：使用`Oneof`

  ````javascript
  module.exports = {
    //...,
    module: {
      rules: [
        {
          oneOf: [
            {
              // 用来匹配 .css 结尾的文件
              test: /.css$/,
              // use 数组里面 Loader 执行顺序是从右到左
              use: ["style-loader", "css-loader"],
            },
            //...各种rule配置,
          ],
        },
      ],
    },
    plugins: [//...
    ],
    //...,
    mode: "development",
    //...,
  };
  ````

  * 优化原理：
    * 优化前：一个文件通过rules会全部遍历去匹配
    * 优化后：匹配中其中一个，就不匹配后续rule

### Q：如何排除指定文件打包编译？

* A：使用`include/exclude`

  * `include`：包含，只处理 xxx 文件
  * `exclude`：排除，除了 xxx 文件以外其他文件都处理

  ````javascript
  module.exports = {
    //...,
    module: {
        rules: [
            {
                oneOf: [
                    ...,
                    {
                        test: /.js$/,
                        // exclude: /node_modules/, // 排除node_modules代码不编译
                        include: path.resolve(__dirname, "../src"), // 也可以用包含
                        loader: "babel-loader",
                    },
                ],
            },
        ],
    },
    // ....
  };
  ````

  > 注意：`include/exclude`只能二选一，不能同时存在。
  >
  > *  开发时需要使用第三方的库或插件，所有文件都下载到 node_modules 中了。而这些文件是不需要编译可以直接使用的。所以在对 js 文件处理时，要排除 node_modules 下面的文件。

### Q：如何让第二次打包，只对修改的文件进行slint 检查 和 Babel 编译？

* A：使用`cache`

  ````javascript
  module.exports = {
    //...,
    module: {
      rules: [
        {
          oneOf: [
            // ...
            {
                test: /.js$/,
                // exclude: /node_modules/, // 排除node_modules代码不编译
                include: path.resolve(__dirname, "../src"), // 也可以用包含
                loader: "babel-loader",
                options: {
                  cacheDirectory: true, // 开启babel编译缓存
                  cacheCompression: false, // 缓存文件不要压缩
                },
            },
          ],
        },
      ],
    },
    plugins: [
      new ESLintWebpackPlugin({
        // 指定检查文件的根目录
        context: path.resolve(__dirname, "../src"),
        exclude: "node_modules", // 默认值
        cache: true, // 开启缓存
        // 缓存目录
        cacheLocation: path.resolve(
            __dirname,
            "../node_modules/.cache/.eslintcache"
        ),
      }),
      // ... 
    ],
    // ...
  };
  ````

  * 发生了什么？：每次打包时，没有修改的文件可以缓存之前的 Eslint 检查 和 Babel 编译结果，这样第二次打包时速度就会更快了。

### Q：如何开启多线程进行打包？

* A：使用`thead`

  * 如何使用？

    1. 下载包

       ````bash
       npm i thread-loader -D
       ````

    2. 修改webpack配置文件

       ````javascript
       const os = require("os"); // 添加此代码
       //...,
       const TerserPlugin = require("terser-webpack-plugin");
       
       // cpu核数
       const threads = os.cpus().length; // 添加此代码
       
       module.exports = {
         //...,
         module: {...},
         plugins: [
           new ESLintWebpackPlugin({
             // 指定检查文件的根目录
             context: path.resolve(__dirname, "../src"),
             exclude: "node_modules", // 默认值
             cache: true, // 开启缓存
             // 缓存目录
             cacheLocation: path.resolve(
                 __dirname,
                 "../node_modules/.cache/.eslintcache"
             ),
             // 添加此代码 ESlint
             threads, // 开启多进程
           }),
         ],
         // CSS压缩也可以开启多进程
         optimization: {
           minimize: true,
           minimizer: [
             // css压缩也可以写到optimization.minimizer里面，效果一样的
             new CssMinimizerPlugin(),
             // 当生产模式会默认开启TerserPlugin，但是我们需要进行其他配置，就要重新写了
             new TerserPlugin({
                 parallel: threads // 开启多进程
             })
           ],
         },
         // ...
       };
       ````

  

## 减少代码体积

### Q：如何实现使用什么库，打包什么库？

* A：使用`TreeShaking`
  * 如何使用？：检查是否使用`ES Module`，Webpack 已经默认开启了这个功能，无需其他配置。

### Q：如何处理babel为编译的每个文件都插入了辅助代码，导致打包代码体积过大？

* A：使用`@babel/plugin-transform-runtime`

  * Q：为什么babel会导致代码提交过大？

    * A：Babel 对一些公共方法使用了非常小的辅助代码，比如 `_extend`。默认情况下会被添加到每一个需要它的文件中。

  * Q：能干嘛？

    * A：禁用了 Babel 自动对每个文件的 runtime 注入，而是引入 `@babel/plugin-transform-runtime` 并且使所有辅助代码从这里引用。

  * Q：如何使用？

    1. 下载包

       ````bash
       npm i @babel/plugin-transform-runtime -D
       ````

    2. 设置（开发｜生产）配置文件

       ````json
       //rule设置项
       {
         test: /.js$/,
             // exclude: /node_modules/, // 排除node_modules代码不编译
             include: path.resolve(__dirname, "../src"), // 也可以用包含
                 use: [
                     {
                         loader: "thread-loader", // 开启多进程
                         options: {
                             workers: threads, // 数量
                         },
                     },
                     {
                         loader: "babel-loader",
                         options: {
                             cacheDirectory: true, // 开启babel编译缓存
                             cacheCompression: false, // 缓存文件不要压缩
                             plugins: ["@babel/plugin-transform-runtime"], // 减少代码体积
                         },
                     },
                 ],
       }
       ````

### Q：如何对静态图片进行压缩处理？

* A：使用`image-minimizer-webpack-plugin`插件

  1. 下载包

     ````bash
     npm i image-minimizer-webpack-plugin imagemin -D
     ````

     * 模式选择

       * 无损压缩

         ````bash
         npm install imagemin-gifsicle imagemin-jpegtran imagemin-optipng imagemin-svgo -D
         ````

       * 有损压缩

         ````bash
         npm install imagemin-gifsicle imagemin-mozjpeg imagemin-pngquant imagemin-svgo -D
         ````

  2. 设置webpack配置

     ````javascript
     const ImageMinimizerPlugin = require("image-minimizer-webpack-plugin");
     
     optimization: {
       minimizer: [
         // 压缩图片
         new ImageMinimizerPlugin({
           minimizer: {
             implementation: ImageMinimizerPlugin.imageminGenerate,
             options: {
               plugins: [
                   ["gifsicle", { interlaced: true }],
                   ["jpegtran", { progressive: true }],
                   ["optipng", { optimizationLevel: 5 }],
                   [                            "svgo",                            {                                plugins: [                                    "preset-default",                                    "prefixIds",                                    {                                        name: "sortAttrs",                                        params: {                                            xmlnsOrder: "alphabetical",                                        },                                    },                                ],
                       },
                   ],
                 ],
             },
           },
         }),
       ],
     },
     ````


### Q：如何忽略源码中的注释、日志进行打包？

* A：使用`TerserPlugin`插件

  1. 下载包

     ````bash
     npm install terser-webpack-plugin -D
     ````

  2. 设置配置

     ````javascript
     const TerserPlugin = require("terser-webpack-plugin");
     
     module.exports = {
       // ... 其他配置 ...
       optimization: {
         minimize: true,
         minimizer: [
           new TerserPlugin({
             parallel: true,
             terserOptions: {
               compress: {
                 drop_console: true, // 移除所有console相关代码
                 drop_debugger: true, // 移除自动断点功能
                 pure_funcs: ["console.log", "console.error"], // 配置移除指定的指令，如console.log, alert等
               },
               format: {
                 comments: false, // 移除注释
               },
             },
             extractComments: false, // 不提取注释到单独文件
           })
         ],
       },
       // ... 其他配置 ...
     };
     ````

     

  

## 优化代码运行性能

### Q：如何实现代码按需加载打包？

* A：代码分割（Code Split）处理。

  * Q：是什么？

    * A：
      * 分割文件：将打包生成的文件进行分割，生成多个 js 文件。
      * 按需加载：需要哪个文件就加载哪个文件。

  * Q：怎么做？

    * 方法一：使用多入口分割打包文件

      ````javascript
      module.exports = {
        // 单入口
        // entry: './src/main.js',
        // 多入口
        entry: {
          main: "./src/main.js",
          app: "./src/app.js",
          //...
          //[打包名]:[目标文件路径]
        },
        output: {
          path: path.resolve(__dirname, "./dist"),
          // [name]是webpack命名规则，使用chunk的name作为输出的文件名。
          // 什么是chunk？打包的资源就是chunk，输出出去叫bundle。
          // chunk的name是啥呢？ 比如： entry中xxx: "./src/xxx.js", name就是xxx。注意是前面的xxx，和文件名无关。
          // 为什么需要这样命名呢？如果还是之前写法main.js，那么打包生成两个js文件都会叫做main.js会发生覆盖。(实际上会直接报错的)
          filename: "js/[name].js",
          clear: true,
        },
        plugins: [
          new HtmlWebpackPlugin({
            template: "./public/index.html",
          }),
        ],
        mode: "production",
      };
      ````

### Q：多入口打包时，如何处理公共模块？

* A：设置代码分割配置

  ````javascript
  // webpack.config.js
  
  module.exports = {
      // 单入口
      // entry: './src/main.js',
      // 多入口
      entry: {
          main: "./src/main.js",
          app: "./src/app.js",
      },
      output: {
          path: path.resolve(__dirname, "./dist"),
          filename: "js/[name].js",
          clean: true,
      },
      plugins: [
        //...
      ],
      mode: "production",
      // ==========以下为新增代码=============
      optimization: {
          // 代码分割配置
          splitChunks: {
              chunks: "all", // 对所有模块都进行分割
              // 以下是默认值
              // minSize: 20000, // 分割代码最小的大小
              // minRemainingSize: 0, // 类似于minSize，最后确保提取的文件大小不能为0
              // minChunks: 1, // 至少被引用的次数，满足条件才会代码分割
              // maxAsyncRequests: 30, // 按需加载时并行加载的文件的最大数量
              // maxInitialRequests: 30, // 入口js文件最大并行请求数量
              // enforceSizeThreshold: 50000, // 超过50kb一定会单独打包（此时会忽略minRemainingSize、maxAsyncRequests、maxInitialRequests）
              // cacheGroups: { // 组，哪些模块要打包到一个组
              //   defaultVendors: { // 组名
              //     test: /[\/]node_modules[\/]/, // 需要打包到一起的模块
              //     priority: -10, // 权重（越大越高）
              //     reuseExistingChunk: true, // 如果当前 chunk 包含已从主 bundle 中拆分出的模块，则它将被重用，而不是生成新的模块
              //   },
              //   default: { // 其他没有写的配置会使用上面的默认值
              //     minChunks: 2, // 这里的minChunks权重更大
              //     priority: -20,
              //     reuseExistingChunk: true,
              //   },
              // },
              // 修改配置
              cacheGroups: {
                  // 组，哪些模块要打包到一个组
                  // defaultVendors: { // 组名
                  //   test: /[\/]node_modules[\/]/, // 需要打包到一起的模块
                  //   priority: -10, // 权重（越大越高）
                  //   reuseExistingChunk: true, // 如果当前 chunk 包含已从主 bundle 中拆分出的模块，则它将被重用，而不是生成新的模块
                  // },
                  default: {
                      // 其他没有写的配置会使用上面的默认值
                      minSize: 0, // 我们定义的文件体积太小了，所以要改打包的最小文件体积
                      minChunks: 2,
                      priority: -20,
                      reuseExistingChunk: true,
                  },
              },
          },
  
      },
  };
  ````

  > Q：为什么要处理公共模块？
  >
  > * A：若不处理，每一个打包文件都会对公共模块进行重复打包，导致代码体积变大。

### Q：多入口打包，如何对js文件进行按需加载？

* A：对js文件使用动态导入

  ````javascript
  document.getElementById("btn").onclick = function () {
    // 动态导入 --> 实现按需加载
    // 即使只被引用了一次，也会代码分割
    import("{js文件路径}").then(({ func }) => {
      func();
    });
  };
  ````

### Q：单入口打包，如何对js文件进行按需加载？

* A：

  1. 设置webpack文件

     ````javascript
     const path = require("path");
     const HtmlWebpackPlugin = require("html-webpack-plugin");
     module.exports = {
       entry: "./src/main.js",
       output: {
         path: path.resolve(__dirname, "./dist"),
         filename: "js/[name].js",
         clean: true,
       },
       plugins: [
         new HtmlWebpackPlugin({
           template: "./public/index.html",
         }),
       ],
       mode: "production",
       optimization: {
         // 代码分割配置
         splitChunks: {
           chunks: "all", // 对所有模块都进行分割
       },
     };
     ````

  2. 引入`eslint`动态导入

     ````bash
     npm i eslint-plugin-import -D
     ````

  3. 配置`.eslintrc.js`文件，添加`import`插件

     ````javascript
     // .eslintrc.js
     module.exports = {
       // 继承 Eslint 规则
       extends: ["eslint:recommended"],
       env: {
         node: true, // 启用node中全局变量
         browser: true, // 启用浏览器中全局变量
       },
       plugins: ["import"], // 解决动态导入import语法报错问题 --> 实际使用eslint-plugin-import的规则解决的
       parserOptions: {
         ecmaVersion: 6,
         sourceType: "module",
       },
       rules: {
         "no-var": 2, // 不能使用 var 定义变量
       },
     };
     ````

  4. 将js改为动态引入

     ````javascript
     document.getElementById("btn").onclick = function () {
       // 动态导入 --> 实现按需加载
       // 即使只被引用了一次，也会代码分割
       import("{js文件路径}").then(({ func }) => {
         func();
       });
     };
     ````

### Q：如何处理代码分割导致模块名不统一问题？

* A：

  1. 对js文件中使用动导入位置追加魔法命名

     ````javascript
     document.getElementById("btn").onclick = function () {
       // 动态导入 --> 实现按需加载
       // 即使只被引用了一次，也会代码分割
       import(/*webpackChunkName:"{指定的打包文件}"*/"{js文件路径}").then(({ func }) => {
         func();
       });
     };
     ````

  2. 修改webpack配置，添加`chunkFilename`、`assetModuleFilename`配置

     ````javascript
     //webpack.config.js
     const path = require("path");
     const HtmlWebpackPlugin = require("html-webpack-plugin");
     module.exports = {
       entry: "./src/main.js",
       output: {
         path: path.resolve(__dirname, "./dist"),
         filename: "js/[name].js",
         chunkFilename: "static/js/[name].chunk.js", // 动态导入输出资源命名方式
         assetModuleFilename: "static/media/[name].[hash][ext]", // 图片、字体等资源命名方式（注意用hash）
         clean: true,
       },
       plugins: [
         new HtmlWebpackPlugin({
           template: "./public/index.html",
         }),
       ],
       mode: "production",
       optimization: {
         // 代码分割配置
         splitChunks: {
           chunks: "all", // 对所有模块都进行分割
       },
     };
     ````

### Q：如何实现在浏览器空闲时间，加载后续需要使用的资源？

* A：使用`Preload / Prefetch`技术

  > Q：相同点？
  >
  > * A：
  >   * 都只会加载资源，并不执行。
  >   * 都有缓存。
  >
  > Q：区别是什么？
  >
  > * A：
  >
  >   |            | Preload                        | Prefeth                                                    |
  >   | ---------- | ------------------------------ | ---------------------------------------------------------- |
  >   | 是什么？   | 告诉浏览器立即加载资源。       | 告诉浏览器在空闲时才开始加载资源。                         |
  >   | 加载优先级 | 高                             | 低                                                         |
  >   | 加载资源   | 只能加载当前页面需要使用的资源 | 可以加载当前页面资源，也可以加载下一个页面需要使用的资源。 |
  >
  > Q：缺点是啥？
  >
  > * A：兼容性较差。

  1. 下载包

     ````bash
     npm i @vue/preload-webpack-plugin -D
     ````

  2. 设置webpack文件

     ````javascript
     const PreloadWebpackPlugin = require("@vue/preload-webpack-plugin");
     {
       plugins: [
         new PreloadWebpackPlugin({
           rel: "preload", // preload兼容性更好
           as: "script",
           // rel: 'prefetch' // prefetch兼容性更差
         }),
       ]
     }
     ````

     





### 



