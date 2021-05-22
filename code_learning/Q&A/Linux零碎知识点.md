# 零碎知识点梳理

### 1 grep
    grep -irn “target” * 指令，使用很频繁
    * Grep “target” * // 搜索当前目录下的files是否含有target
    * -n 显示行位置      -c 统计出现次数
    * -r  循环递归当前路径下所有文件夹

### 2 locate 
    locate “target” 指令，使用很频繁
    * Locate “target” 查找所有满足该字段的文件路径
    * -c 统计出现次数 可以先统计数量再显示


### 3 diff
    * diff -Naur a b > result.patch //类似git
### 3-2 patch
    * patch a < result.patch // 将a改成b
    * patch -R b < result.patch // 将b改成a
### 4 find
    * find  /path  -name “*detail*” // 强调路径与name参数才可以查找


