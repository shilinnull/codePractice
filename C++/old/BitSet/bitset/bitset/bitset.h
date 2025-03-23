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
		// 构造
		bitset()
		{
			// _bits.resize((N >> 5) + 1, 0); // 可以这样写，但是要注意优先级
			_bits.resize(N / 32 + 1, 0);
		}

		// 将x比特位置1
		void set(size_t x)
		{
			// 计算第几个整形
			// size_t i = x >> 5; // 也可以这样写
			size_t i = x / 32;
			// 计算第几个位
			size_t j = x % 32;
			// 将第j位处理成1其他位不变
			_bits[i] |= (1 << j);
		}

		// 将x比特位置0
		void reset(size_t x)
		{
			// 计算第几个整形
			size_t i = x / 32;
			// 计算第几个位
			size_t j = x % 32;
			// 将第j位处理成0其他位不变
			_bits[i] &= ~(1 << j);
		}

		// 检测位图中x是否为1
		bool test(size_t x)
		{
			// 计算第几个整形
			size_t i = x / 32;
			// 计算第几个位
			size_t j = x % 32;
			// 检测第j位是否为1
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
				_bs2.set(x); // _bs1不需要动 _ba2设置成1
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
				if (_bs1.test(i) == false && _bs2.test(i) == true) // 01 -->出现一次
				{
					cout << "1->" << i << endl;
				}
				else if (_bs1.test(i) == true && _bs2.test(i) == false) //10 -->出现两次
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