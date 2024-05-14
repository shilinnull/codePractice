#pragma once
#include "bitset.h"

struct BKDRHash
{
	size_t operator()(const string& key)
	{
		// BKDR
		size_t hash = 0;
		for (auto e : key)
		{
			hash *= 31;
			hash += e;
		}

		return hash;
	}
};

struct APHash
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (size_t i = 0; i < key.size(); i++)
		{
			char ch = key[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJBHash
{
	size_t operator()(const string& key)
	{
		size_t hash = 5381;
		for (auto ch : key)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};

//��¡������
template<size_t N, class K = string, class HashFunc1 = BKDRHash, class HashFunc2 = APHash, class HashFunc3 = DJBHash>
class BloomFilter
{
public:
	void Set(const K& key)
	{
		//�����key��Ӧ������λ
		size_t hash1 = HashFunc1()(key) % N;
		size_t hash2 = HashFunc2()(key) % N;
		size_t hash3 = HashFunc3()(key) % N;
		// ��λͼ�е�������λ���ó�1
		_bs.set(hash1);
		_bs.set(hash2);
		_bs.set(hash3);
	}

	bool Test(const T& key)
	{
		//�����ж�key��Ӧ������λ�Ƿ�����
		size_t hash1 = HashFunc1()(key) % N;
		if (_bs.test(hash1) == false)
			return false;

		size_t hash2 = HashFunc2()(key) % N;
		if (_bs.test(hash1) == false)
			return false;

		size_t hash3 = HashFunc3()(key) % N;
		if (_bs.test(hash1) == false)
			return false;

		return true; // ���ܴ��ڣ����ǿ��ܴ�������
	}
private:
	lsl::bitset<N> _bs;
};


