# 前言

【适合人群】

* 对React有一定了解

【学习资源】

* 【视频资源】[【2022最新】4小时带你快速入门React全家桶](https://www.bilibili.com/video/BV1tY411G7UP/?spm_id_from=trigger_reload&vd_source=2f682a60feabf0f730ad09e0f980ce83)

<br>

---

<br>

# React初识

## 创建第一个React项目

1. 在目标路径下打开`cmd`搭建react项目

   ````shell
   npx create-react-app 项目名称
   ````

   【==注意==】

   * 打开`cmd`需要用管理员模式开启
   * 使用`npx`而不是`npm`搭建项目
     * 【原因】使用`npx`会临时的把React脚手架下载下来。创建结束后会把脚手架自动删掉
       * 不会占用电脑的内存空间
       * 可以实时的和官网最新的脚手架保持一致

2. 项目创建完之后，进入项目内

   ````shell
   cd 项目名
   ````

3. 用vscode打开

   ````shell
   code .
   ````

4. 把项目跑起来

   ````shell
   npm run start
   ````

   【==注意==】

   * 【报错】**react项目启动报错Plugin “react“ was conflicted**

     * 【解决办法】

       1. 在package.json删除

       ```json
       "eslintConfig": {
           "extends": [
               "react-app",
               "react-app/jest"
           ]
       },
       ```

       [了解更多](https://blog.csdn.net/weixin_51277037/article/details/122531372)

