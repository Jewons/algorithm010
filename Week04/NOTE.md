学习笔记

1.深度遍历与广度遍历，dfs和bfs，两种常见的遍历方式，主要用于二叉树和图。
顺手默写一下 dfs C++模板
void dfs(TreeNode* node)
{
	if(node == NULL)
		return;
	for(int i = 0; i < node->child.size();i++){
		dfs(node->child[i]);
	}
}
2.贪心算法，就是用当前最优解来获取全局最优解，但是局限性较大，容易找不到最优解。
	理解上来讲，贪心算法属于那种不撤回的回溯。

3.二分查找，常见的查找方式，主要用于数据有序的情况。