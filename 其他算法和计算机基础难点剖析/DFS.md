DFS

1. 单词搜索 LeetCode 79.

   给定一个二维网格和一个单词，找出该单词是否存在于网格中。

   单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

   来源：力扣（LeetCode）
   链接：https://leetcode-cn.com/problems/word-search

   ```c++
   class Solution {
   public:
       // DFS回溯
       bool exist(vector<vector<char>>& board, string word) {
           int w = board.size(), h = board[0].size();
           for(int i = 0; i < w; i++) {
               for(int j = 0; j < h; j++) {
                   if(dfs(board, word, i, j, 0))
                       return true;
               }
           }
           return false;
       }
   
       bool dfs(vector<vector<char>>& board, string word, int i, int j, int index) {
           // 结束条件
           if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
               return false;
           if(index == word.size()-1)
               return true;
           char tmp = board[i][j];
           board[i][j] = '.';
           //每个位置找四个方向
           bool res = dfs(board, word, i, j+1, index+1) || dfs(board, word, i+1, j, index+1) 
               || dfs(board, word, i, j-1, index+1) || dfs(board, word, i-1, j, index+1);
           board[i][j] = tmp;
           return res;
       }
   
       
   };
   ```

   

2. 岛屿的最大面积 LeetCode 695.

   给定一个包含了一些 0 和 1 的非空二维数组 grid 。

   一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

   找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

   来源：力扣（LeetCode）
   链接：https://leetcode-cn.com/problems/max-area-of-island

   ```c++
   class Solution {
   public:
       vector<vector<int>> dirs{{0,1}, {1,0}, {0,-1}, {-1,0}};
       int maxAreaOfIsland(vector<vector<int>>& grid) {
           int w = grid.size(), h = grid[0].size();
           int maxLen = 0;
           for(int i = 0; i < w; i++) {
               for(int j = 0; j < h; j++) {
                   if(grid[i][j] == 1) {
                       int cur = dfs(grid, i, j);
                       maxLen = max(maxLen, cur);
                   }  
               }
           }
           return maxLen;
       }
   
       int dfs(vector<vector<int>>& grid, int i, int j) {
           if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
               return 0;
   
           int tmp = grid[i][j];
           grid[i][j] = 0;
           int res = 1;
           for(auto dir : dirs)
               res += dfs(grid, i+dir[0], j+dir[1]);
           //grid[i][j] = tmp;
           return res;
       }
   };
   ```

   3.不同路径 LeetCode 62.

   一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

   机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

   问总共有多少条不同的路径？

   来源：力扣（LeetCode）
   链接：https://leetcode-cn.com/problems/unique-paths

   ```c++
   /*class Solution {
   public:
       // DP
       int uniquePaths(int m, int n) {
           vector<vector<int> > dp(m, vector<int>(n, 0));
           dp[0][0] = 1;
           for(int i = 1; i < m; i++){
               dp[i][0] = 1;
           }
           for(int i = 1; i < n; i++){
               dp[0][i] = 1;
           }
   
           for(int i = 1; i < m; i++){
               for(int j = 1; j < n; j++){
                   dp[i][j] = dp[i][j-1] + dp[i-1][j];
               }
           }
   
           return dp[m-1][n-1];
       }
   };*/
   
   // DFS回溯
   class Solution {
   public:
       int uniquePaths(int m, int n) {
           return dfs(1, 1, m, n);
       }
   
       int dfs(int bgi, int bgj, int edi, int edj) {
           if(bgi > edi || bgj > edj)
               return 0;
           if(bgi == edi && bgj == edj)
               return 1;
           int res = 0;
           res += dfs(bgi + 0, bgj + 1, edi, edj);
           res += dfs(bgi + 1, bgj + 0, edi, edj);
           return res;
       }
   };
   ```

   4. 全排列 LeetCode 46.

      给定一个 **没有重复** 数字的序列，返回其所有可能的全排列

      ```c++
      class Solution {
      public:
          vector<vector<int>> permute(vector<int>& nums) {
              vector<vector<int>> res;
              vector<int> item;
              vector<int> used(nums.size(), 0);
              dfs(nums, res, item, used, 0);
              return res;
          }
      
          void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& item, vector<int>& used, int depth) {
              if(depth == nums.size()) {
                  res.push_back(item);
                  return;
              }
      
              for(int i = 0; i < nums.size(); i++) {
                  if(used[i]) continue;
                  item.push_back(nums[i]);
                  used[i] = 1;
                  dfs(nums, res, item, used, depth + 1);
                  item.pop_back();
                  used[i] = 0;
              }
          }
      };
      ```

      5. 组合 LeetCode 77.

         给定两个整数 *n* 和 *k*，返回 1 ... *n* 中所有可能的 *k* 个数的组合。

         ```c++
         class Solution {
         public:
             vector<vector<int>> combine(int n, int k) {
                 vector<vector<int>> res;
                 
                 vector<int> item;
                 vector<int> used(n+1, 0);
                 dfs(n, res, item, used, 0, k);
                 return res;
             }
         
             void dfs(int n, vector<vector<int>>& res, vector<int>& item, vector<int>& used, int depth, int k) {
                 if(depth == k) {
                     res.push_back(item);
                     return;
                 }
         
                 for(int i = 1; i <= n; i++) {
                     if(used[i]) continue;
                     if(!item.empty() && item[item.size()-1] > i) continue;
                     item.push_back(i);
                     used[i] = 1;
                     dfs(n, res, item, used, depth + 1, k);
                     item.pop_back();
                     used[i] = 0;
                 }
             }
         };
         ```

         