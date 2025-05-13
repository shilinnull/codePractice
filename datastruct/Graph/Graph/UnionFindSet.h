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
	int FindRoot(int index)
	{
		// ��������д洢���Ǹ������ҵ�������һֱ����
		while (_ufs[index] >= 0)
		{
			index = _ufs[index];
		}
		return index;
	}

	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		// x1�Ѿ���x2��ͬһ������
		if (root1 == root2)
			return false;

		if (root2 < root1)
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

