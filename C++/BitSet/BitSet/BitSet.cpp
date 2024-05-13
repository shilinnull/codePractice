#include"BitSet.h"

//int main()
//{
//	lsl::bitset<100> bs;
//	bs.set(40);
//	bs.set(39);
//	cout << bs.test(40) << endl;
//	cout << bs.test(39) << endl;
//	cout << bs.test(41) << endl;
//	cout << bs.test(42) << endl << endl;
//
//	bs.reset(40);
//	cout << bs.test(40) << endl;
//	cout << bs.test(39) << endl;
//	cout << bs.test(41) << endl;
//	cout << bs.test(42) << endl << endl;
//	return 0;
//}

//#include<bitset>
//
//int main()
//{
//	try
//	{
//		std::bitset<100> bs;
//		bs.set(40);
//		bs.set(39);
//
//		cout << bs.test(38) << endl;
//		cout << bs.test(39) << endl;
//		cout << bs.test(40) << endl;
//		cout << bs.test(41) << endl;
//		cout << bs.test(42) << endl << endl;
//
//		cout << bs.to_string() << endl;
//
//		bs.reset(40);
//
//		cout << bs.test(38) << endl;
//		cout << bs.test(39) << endl;
//		cout << bs.test(40) << endl;
//		cout << bs.test(41) << endl;
//		cout << bs.test(42) << endl << endl;
//
//
//		// std::bitset<0xffffffff> bigbs1; // ±¨´í
//		// std::bitset<-1> bigbs2;		// ±¨´í
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

int main()
{

	int a[] = { 1, 4, 7, 9, 44, 88, 1, 4, 88, 99, 78, 5, 7, 7, 7, 7 };
	lsl::twobitset<100> bs;
	for (auto e : a)
	{
		bs.set(e);
	}
	bs.Print();

	return 0;
}
