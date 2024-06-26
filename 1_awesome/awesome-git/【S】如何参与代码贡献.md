1. fork项目

   * 进入项目页面, 点击右上角的Fork按钮

2. 克隆自己库中fork来的项目

   ````bash
   git clone git@github.com:{用户名}/{仓库名}.git 
   ````

3. 获取原项目代码

   1. 进入本地克隆项目文件夹, 添加项目的远程地址

      ````bash
      git remote add upstream {参与项目克隆地址}
      ````

   2. 获取项目最新源码

      ````bash
      git pull upstream {主分支名}
      ````

4. 参与贡献

   1. 按照原项目开发规则创建分支

      ````bash
      git checkout -b {分支名}
      ````

   2. 在分支进行开发、测试

   3. 按照开发规则提交commit

      ````bash
      git commit -m '{前缀标签} {提交描述}'
      ````

   4. 合并修改

      > 注意：合并前应该重新获取一次最新代码
      >
      > ````bash
      > git checkout master
      > git pull upstream master
      > ````

      1. 检查主分支是否已经为最新代码。

      2. 将主分支代码合并至自己分支上。

         ````bash
         ##注意当前在自己分支上
         git marge master
         ````

      3. 代码提交至自己分支

         ````bash
         git push origin {自己分支名}
         ````

   5. 提交合并请求
      1. 进入

   

   