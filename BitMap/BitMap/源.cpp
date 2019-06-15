#include<iostream>
#include"bitmap.h"
using namespace std;

int main()
{
	Bitmap c(1000);

	c.set(1);
	c.set(34);
	c.set(2);
	c.reset(1);
	cout << c.Test(1) << endl;
	cout << c.Test(2) << endl;
	return 0;
}