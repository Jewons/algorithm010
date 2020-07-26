学习笔记

//总结双向BFS模板 C++
strcut Node
{
	int val;
	vector<Node*> next;
}

void double_direction_BFS(Node* begin,Node* end)
{
	std::queue<Node*> qBegin;
	std::queue<Node*> qEnd;
	
	qBegin.push(begin);
	qEnd.push(end);
	
	while(!qBegin.empty() && !qEnd.empty())
	{
		//置换成小的队列
		if(qBegin.size() > qEnd.size())
		{
			std::queue<Node*> q;
			q = qBegin();
			qBegin = qEnd;
			qEnd = q;
		}
		//取出第一个节点
		Node* tmp = qBegin.front();
		qBegin.pop();
		
		//处理第一个节点
		process(tmp);
		
		//将下一层的节点加入到队列里
		for(int i = 0; i < tmp->next.size();i++)
		{
			qBegin.push(tmp->next[i]);
		}
	}
}

1.字典树：
	字典树可以解决一些字符串搜索的问题，时间复杂度较低，但空间复杂度较高，可以使用动态字典树（带有insert接口的）来规避这个问题。
2.高级搜索
	相对于朴素搜索（傻搜）来讲的有点有
	a.通过剪枝，来减少遍历的点的个数，提高代码的运行效率。
	b.双向BFS搜索，多数情况下比传统BFS可以减少一半的时间。
	c.启发式搜索，也就是记录搜索的过程，按照优先级来搜索。
