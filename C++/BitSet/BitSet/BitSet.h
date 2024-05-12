#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace lsl
{
	template<size_t N>
	class BitSet
	{
	public:
		// ����
		BitSet()
		{
			// _bits.resize((N >> 5) + 1, 0); // ��������д������Ҫע�����ȼ�
			_bits.resize(N / 32 + 1, 0);
		}

		// ��x����λ��1
		void set(size_t x)
		{
			// ����ڼ�������
			// size_t i = x >> 5; // Ҳ��������д
			size_t i = x / 32;
			// ����ڼ���λ
			size_t j = x % 32;
			// ����jλ�����1����λ����
			_bits[i] |= (1 << j);
		}

		// ��x����λ��0
		void reset(size_t x)
		{
			// ����ڼ�������
			size_t i = x / 32;
			// ����ڼ���λ
			size_t j = x % 32;
			// ����jλ�����0����λ����
			_bits[i] &= ~(1 << j);
		}

		// ���λͼ��x�Ƿ�Ϊ1
		bool test(size_t x)
		{
			// ����ڼ�������
			size_t i = x / 32;
			// ����ڼ���λ
			size_t j = x % 32;
			// ����jλ�Ƿ�Ϊ1
			return _bits[i] & (1 << j);
		}

	private:
		vector<int> _bits;
	};
}