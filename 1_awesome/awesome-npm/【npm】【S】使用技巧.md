# 指令相关

## Q：如何添加依赖至开发环境？

* A：

  ````shell
  npm install {包名} -D
  ````

# 访问依赖库相关

## Q：如何查看依赖库相关信息？

* A：访问对应地址：

  ````bash
  https://registry.npmjs.org/-/package/{库名}/dist-tags
  
  //示例
  https://registry.npmjs.org/-/package/create-react-app/dist-tags
  ````

  * 访问结果

    | 字段   | 描述     |
    | ------ | -------- |
    | next   |          |
    | latest | 最新版本 |
    | canary |          |

## Q：如何清除项目中的node_modules

* A：

  ````shell
  rm -rf node_modules
  ````

## Q：npm和npx有何不同？

* A：
  * npm：用来下载包
  * npx：会将node_modules中的`.bin`文件临时添加为环境变量
    * 就可以访问环境变量中的应用程序
