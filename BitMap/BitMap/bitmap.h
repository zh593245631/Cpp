#pragma once
#include<vector>

class Bitmap
{
public:
	Bitmap(size_t bitCount):_bit((bitCount>>5)+1),_bitCount(bitCount){}

	//���� 1
	void set(int num)
	{
		if (num > _bitCount)return;
		size_t index = num >> 5;
		int  pos = num % 32;
		_bit[index] |= (1 << pos);
	}

	//���� 0
	void reset(int num)
	{
		if (num > _bitCount)return;
		size_t index = num >> 5;
		int  pos = num % 32;
		_bit[index] &= (~(1 << pos));
	}

	//����Ƿ����
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

	//λͼ�б���λ1�ĸ���

private:
	std::vector<int> _bit;
	size_t _bitCount;
};
