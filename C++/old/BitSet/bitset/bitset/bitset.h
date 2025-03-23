#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace lsl
{
	template<size_t N>
	class bitset
	{
	public:
		// ����
		bitset()
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


	template<size_t N>
	class twobitset
	{
	public:
		void set(size_t x)
		{
			if (_bs1.test(x) == false && _bs2.test(x) == false) // 00
			{
				_bs2.set(x); // _bs1����Ҫ�� _ba2���ó�1
			}
			else if (_bs1.test(x) == false && _bs2.test(x) == true) // 01
			{
				_bs1.set(x); // 1
				_bs2.reset(x); // 0
			}
			else if (_bs1.test(x) == true && _bs2.test(x) == false) // 10
			{
				_bs1.set(x); // 1
				_bs2.set(x); // 1
			}
		}

		void Print()
		{
			for (size_t i = 0; i < N; i++)
			{
				if (_bs1.test(i) == false && _bs2.test(i) == true) // 01 -->����һ��
				{
					cout << "1->" << i << endl;
				}
				else if (_bs1.test(i) == true && _bs2.test(i) == false) //10 -->��������
				{
					cout << "2->" << i << endl;
				}
			}
			cout << endl;
		}

	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};
}