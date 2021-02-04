#### Git

​	[本文来自于廖雪峰Git系列文章总结](https://www.liaoxuefeng.com/wiki/896043488029600)

1. git config user.name git config user.email 查看当前用户名和邮箱

2. git config --global user.name "Your_username" git config --global user.email "Your_email" 设置新用户的用户名和邮箱

3. ssh-keygen -t rsa -C "youremail@example.com"  根据邮箱来生成SSH key,和github/gitlab链接身份对应起来

4. 如果git clone的下载代码的时候是连接的https://而不是git@git (ssh)的形式，当操作git pull/push到远程的时候，总是提示输入账号和密码才能操作成功，频繁的输入账号和密码会很麻烦，使用此命令会在本地生成文本记录账号和密码：git config --global credential.helper store

5. 创建文件夹，使用git init来初始化空仓库，此时git会为我们创建一个.git文件夹

6. git有三个概念：工作区，暂存区和分支。工作区就是自己电脑上开发的区域，工作区有个.git文件夹叫版本库，就是用来版本管理的文件夹，其不属于工作区，版本库包含暂存区和分支两个区域。

7. git init初始化时，git会自动为我们创建一个master分支，并使用HEAD指针指向此master分支

8. git status，查看仓库状态，Untracked files:表示git还没有跟踪的文件，可以使用git add来跟踪文件，将其从工作区添加到暂存区；Changes not staged for commit: 是已经跟踪的文件发生了修改，需要重新git add添加；Changes to be committed:是添加了的文件等待被提交到仓库，使用git commit -m "提交的原因或修改的内容"，来将git add后的修改提交到当前分支，HEAD也向前移动，指向当前最新的commid id处

9. 每次git commit都会有对应的commit id, 可以使用git log来查看历史提交，包括每次的commit id和提交的原因。git所有的提交使用链表来存储，HEAD指针总是指向当前的版本

10. 回退版本，可以通过git reset --hard HEAD～n，表示让HEAD指针往前移动n次，即回退到前n次提交,n=0表示最新的提交版本，～n等同于n个^；或者使用commit id，git reset --hard + commit id的前几位，即可回退到对应版本。 git reflog可以查看历史命令，可以使用commit id进行版本回退和版本前进

11. git reset +commit id回退，会避免hard回退时之后的本地修改不会在工作区存在的情况，其会恢复到制定版本，并保留恢复版本之后所有存在的本地的修改；此时可能恢复的版本直接让本地的版本直接和远程的分支不对应，需要删除分支时，git push origin + 分支名 + delete即可删除，然后重新git push origin + 分支名推送本分支即可

12. 修改之后没有add时，可以使用git diff + 对象文件名来查看该对象文件和上次相比修改了什么东西

13. 当你修改了工作区，但没有添加到暂存区时，可以使用git status提示的 git checkout -- file_name 来丢弃工作区的修改

14. 当你修改了工作区，并且添加到暂存区时，还没有提交到分支，可以使用 git reset HEAD file_name 就回到了场景8（修改没有add了，但修改还存在在工作区），根据需求继续操作

15. git log --pretty=oneline  

16. git blame + file_name 列出这个文件所有的由谁的改动

    

17. git查看本地和远程分支  git branch -a；查看本地分支  git branch；

18. 要想切换用户，往github或者gitlab上切换远程网站，仅仅根据上面的1\2\3步骤重新配置即可

19. 要关联一个远程仓库，git remote add origin "your_githuborlab.user.gitreposname"

20. 首次推送会将git在本地默认生成的分支master和远程默认分支matser关联起来，git push -u origin master，后面就无需-u 

21. 每个git仓库都会提供两个下载地址https的和使用ssh的git://的，https的不仅速度慢，每次推送还必须使用口令

22. 上面说了，每次commit其实就时增加每个分支的时间线，其实HEAD并不是直接指向这个时间线，而是HEAD指向分支指针，再有分支指针指向最新提交

23. 分支: git checkout -b newbranch_name，可以在当前所在分支上创建一个新的分支并切换过去，并指向当前分支最新的提交。git checkout + 分支名可以切换分支

24. 然后在此分支上提交时，HEAD就一直跟随新的分支往前走，当此分支开发完毕之后，就位于想合并到的分支上，git merge + 你开发完成的新分支即可，git branch -d + 分支名，可以删除分支；若一个分支没有合并却需要删除，例如新需求的功能又不需要了，则git branch -D + 分支名

25. 不同分支提交时，git log只能看到自己分支的commit历史

26. 当使用git merge合并分支时，如出现了冲突，就需要打开冲突文件，此时git已经完全帮你标注出了什么地方冲突了。<<<<和====之间是当前分支上的内容，======和>>>>>>之间的内容时想要合并的导进来的内容，你需要修改冲突后，重新add和commit

27. 此时合并成功后，主分支会将之前新分支的commit log也加载进来；删除原来的开发分支即可

28. 合并分支时，若想保留分支的信息，可以加上 --no-ff 禁用 FastForward 合并模式

29. bug分支：若当前开发的dev分支并不像提交，可以使用git stash来保存当前分支的工作现场，然后切换到master分支，创建bug分支完成修复提交，再用master分支合并bug分支，回到dev分支之后使用git stash list搭配git stash apply+git stash drop恢复现场，或者git stash pop直接恢复

30. master分支上的bug同样应该存在在dev分支上，可以使用 git cherry-pick bug_commit_id来完成合并，当然也可以手动在dev上修复bug

31. 本地提交要推送到远程仓库时，可以使用git remote来查看远程仓库的名称，git push origin + 分支，推送到特定分支，然后创建PR，邀请别人review，完成由别人完成最终merge

32. 不能跨分支pull或者push

33. 当多个人在修改了同一分支上的东西且在同一分支提交时，需要先pull解决冲突，再add commit，即可

34. git fetch origin 会更新origin远程仓库的所有远程分支的最新commit id到本地的.git/FETCH_HEAD文件中，更新本地的远程分支信息，使用git diff来查看，git  merge这个分支，git pull相当于自动merge

35. 在本地创建和远程分支对应的分支，使用git checkout -b branch-name origin/branch-name，本地和远程分支的名称最好一致

36. git tag + tag_name + [commit_id] 表示在commit_id对应的提交上打标签，默认打在HEAD的提交处，git tag可以查看所有标签

37. git tag -d + tag_name删除标签，提交到远程使用git push origin + tag_name

38. git clean时清除本地没有track的文件

39. [git merge和git rebase的区别](https://juejin.cn/post/6844903603694469134)

40. git revert + commid-id 本地和远程都回退到某个版本
