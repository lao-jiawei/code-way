# 前言

# 如何高效地寻找开源项目？

具体教程:[如何高效地在网上找开源项目做！在职程序员实际演示一波视频教程操作](https://www.bilibili.com/video/BV1yJ411S7Wu?spm_id_from=333.337.search-card.all.click)

**搜索栏搜索格式：**

|       搜索栏内容        |                  描述                   |
| :---------------------: | :-------------------------------------: |
|    in:name `关键词`     |       库名字包含关键词的开源项目        |
|      stars:>`数值`      | 收藏数大于`数值 `的开源项目（火热程度） |
|      fork:>`数值`       |       分支数大于`数值`的开源项目        |
|   in:readme `关键词`    |    readme文件中包含关键词的开源项目     |
| in:description `关键词` |     项目描述中包含关键词的开源项目      |
|     pushed:>`日期`      |       更新为指定`日期`的开源项目        |
|   language:`语言名称`   |         使用指定语言的开源项目          |

==注意：上述搜索约束条件都可以并行使用。==

<br>

# 单独下载库中单个文件或目录

> 下载单个文件



> 下载单个目录

````shell
git clone 克隆地址 "目标文件名"
````

<br>

# 如何提交本地文件到远程仓库？

【前提】

* 远程仓库已创建
* git已安装

<br>

1. **克隆远程仓库**

   ````shell  
   $ git clone
   ````

2. **拖动要上传的文件到克隆的远程仓库内**

3. **把文件夹所有文件添加到仓库**

   ````shell
   $ git add .
   ````

   【拓展】**add命令的使用**

   > 将修改的文件添加到缓存区

   ````shell
   git add 文件名
   ````

   >

4. **添加本次提交的说明**

   ````shell
   $ git commit -m " "
   ````

5. **把本地库的所有内容推送到远程库上**

   ````shell
   $ git push -u origin master
   ````


<br>

# 如何更改本地提交人？

1. 查看个人信息是否跟github设置里的一样

   ````bash
   git show
   ````

2. 修改邮箱

   ````shell
   git config --global user.email "youremail@email.com"
   ````

3. 再次确认

   ````shell
   git config --global user.email
   ````

<br>

# 如何将本地项目绑定远程仓库？

1. 在本地项目中`git bash`

   ````shell
   git remote
   ````

2. 复制远程仓库SSH

   ```shell
   git remote add origin 地址
   ```

3. 查看当前

   ````shell
   git remote
   ````

4. 将项目内容提交到远程仓库

   ````shell
   git push origin master
   ````

5. 创建开发分支

   ````shell
   git checkout -b dev
   ````

6. 提交开发分支

   ````shell
   git push origin dev
   ````

<br>

# 如何创建分支？

【格式】

````shell
git checkout -b 分支名
````

<br>

# 提交



# 结语

