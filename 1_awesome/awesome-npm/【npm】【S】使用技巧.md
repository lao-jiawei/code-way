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
