#pragma once

#include <vector>

class UnionFindSet
{
public:
	// ��ʼʱ����������Ԫ��ȫ������Ϊ-1
	UnionFindSet(size_t size)
		:_ufs(size, -1)
	{}
	
	// ��һ��Ԫ�صı�ţ��ҵ���Ԫ�����ڼ��ϵ�����
	int FindRoot(int x)
	{
		int root = x;
		// ��������д洢���Ǹ������ҵ�������һֱ����
		while (_ufs[root] >= 0)
		{
			root = _ufs[root];
		}

		// ѹ��·��
		while (_ufs[x] >= 0)
		{
			int parent = _ufs[x];
			_ufs[x] = root;
			x = parent;
		}

		return root;
	}

	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		// x1�Ѿ���x2��ͬһ������
		if (root1 == root2)
			return false;

		// ��С�ĺϲ�
		if (abs(_ufs[root1]) < abs(_ufs[root2]))
			std::swap(root1, root2);
		
		// ������������Ԫ�غϲ�
		_ufs[root1] = _ufs[root2];
		// ������һ���������Ƹı������һ��
		_ufs[root2] = root1;
		return true;
	}

	// �����и����ĸ�������Ϊ���ϵĸ���
	size_t Count() const
	{
		size_t count = 0;
		for (auto e : _ufs)
		{
			if (e < 0)
				count++;
		}
		return count;
	}

private:
	std::vector<int> _ufs;
};

