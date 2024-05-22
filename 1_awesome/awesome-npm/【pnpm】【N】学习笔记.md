# pnpm

## Q：解决了什么问题？

* A：
  * 更快
  * 使用非扁平目录，避免幽灵依赖

## Q：什么是幽灵依赖？

* A：依赖内部使用的依赖，被当前项目引用。

## Q：为什么使用非扁平化目录？

* A：防止依赖包内部引用包找不到了

## Q：如何从老项目中安全过渡？

* A：

  1. 复制原项目文件做备份

  2. 删除文件中`node_modules`文件

     ````bash
     rm -rf node_modules
     ````

  3. 使用原`xxx-lock.xxx`文件生成`pnpm-lock.yaml`文件

     ````bash
     pnpm import
     ````

     > 该指令作用：[通过其他软件包管理器的 lockfile 文件生成 `pnpm-lock.yaml`](https://www.pnpm.cn/cli/import)

  4. 检查是否有使用内部源，若有使用则切换源地址

     ````bash
     pnpm config set registry {源地址}
     ````

  5. 安装依赖

     ````bash
     pnpm i
     ````

  6. 处理报错

     ````bash
     pnpm add {缺失包} -{mode}
     ````

     > 注意：根据包对项目的影响决定添加包至不同的模式
     >
     > `mode`：
     >
     > * d：生产环境依赖
     > * D：开发环境依赖

## Q：如何查看当前镜像源？

* A：

  ````bash
  pnpm config get registry
  ````

## Q：为什么修改镜像源失败？

* A：
  * 检查项目中`.npmrc`文件中`registry=`的值
