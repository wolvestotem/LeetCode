## Permutation

大致两种思路：
最简洁的是用swap(nums[curr],nums[i])，在数组内动态调整，缺点是要打乱顺序
还可以用visited记录已访问和未访问列表，每次按顺序遍历未访问数字
duplicate问题：
if(i>0 && nums[i]==nums[i-1])--dupciate经典写法
思路是保持相同数字稳定，不交换顺序,访问时候按顺序访问
if(i>0 && nums[i]==nums[i-1] && !visited[i-1])

## Combination

39,40,77

39--distinct number with a target
77 distinct number with limit k use
216--combination of 39 & 77
本质一样，都是经典bakctrack，加以index约束选择列表和结束条件

40--duplicate
需要用一个vector记录每个数出现次数（可选用次数），转换后就与经典问题一致了

需要注意：
index还是i递增
主函数return 结果
