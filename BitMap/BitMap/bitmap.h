#pragma once
#include<vector>

class Bitmap
{
public:
	Bitmap(size_t bitCount):_bit((bitCount>>5)+1),_bitCount(bitCount){}

	//设置 1
	void set(int num)
	{
		if (num > _bitCount)return;
		size_t index = num >> 5;
		int  pos = num % 32;
		_bit[index] |= (1 << pos);
	}

	//设置 0
	void reset(int num)
	{
		if (num > _bitCount)return;
		size_t index = num >> 5;
		int  pos = num % 32;
		_bit[index] &= (~(1 << pos));
	}

	//检测是否存在
	bool Test(int num)
	{
		if (num > _bitCount)return false;
		size_t index = num >> 5;
		int  pos = num % 32;

		return _bit[index] & (1 << pos);
	}

	size_t Count()const
	{
		return _bitCount;
	}

	//位图中比特位1的个数

private:
	std::vector<int> _bit;
	size_t _bitCount;
};
