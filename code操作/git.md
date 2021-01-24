Git

一、将服务器clone下来然后push到自己的仓库

git clone xxxx.git

git add . 或者 git add root/  或者 git add test.cpp

若不想add某个东西了，git restore --staged 文件； git reset HEAD 后面跟文件撤销，若不带文件，则撤销上次add的所有；

git commit -m "xxx"   若不想commit某个东西了，git rm --cached 文件名 或者 git rm -r --cached 文件夹 或者 git reset --mixed HEAD^ 撤销commit和add

git reset --soft HEAD^ 撤销commit不撤销add  

git reset --hard HEAD^ 撤销commit和add和修改的工作空间代码

git push

git add是从工作区提交到暂存区，git diff 查看工作区和暂存区的区别；git commit 是从暂存区提交到仓库，git diff --cached 是查看暂存区和仓库的区别；git diff HEAD 查看工作区和仓库的差异

二、本地直接push到服务器的仓库

git init

git remote add origin https://xxxx.git

git branch -M main

git add

git commit

git push -u origin main

三、多人连同开发

在add commit之后，如果你本地的不是最新的代码（别人已经在你之前push了一次），则需要pull下来解决冲突，然后在add commit pull，如果没有冲突或者你的本来就是最新的代码，则直接Push

pull = fetch + merge
