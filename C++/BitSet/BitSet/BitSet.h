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
		// 构造
		BitSet()
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
}