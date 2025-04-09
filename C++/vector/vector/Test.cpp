#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>

#include"vector.h"

void TestVectorExpand()
{
	size_t sz;
	std::vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
void TestVector1() {
	lsl::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.insert(v1.begin(), 10);
	for (const auto& e : v1)
	{
		cout << e << " ";
	}

	cout << endl;
	v1.erase(v1.end() - 1);
	for (const auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}

void TestVector2() {
	lsl::vector<int> v1(3, 1);
	for (const auto& e : v1)
		cout << e << " ";
	cout << endl;

	lsl::vector<int> v2(v1);
	for (const auto& e : v2)
		cout << e << " ";
	cout << endl;

	lsl::vector<int> v3 = v2;
	for (const auto& e : v3)
		cout << e << " ";
	cout << endl;

	lsl::vector<int> v4 = {1,2,3,4};
	for (const auto& e : v4)
		cout << e << " ";
	cout << endl;
}
void TestVector3() {
	std::vector<int> v{ 1,2,3,4,5,6 };
	auto it = v.begin();

	// ����ЧԪ�ظ������ӵ�100���������λ��ʹ��8��䣬�����ڼ�ײ������
	v.resize(100, 8);
	// reserve�����þ��Ǹı����ݴ�С�����ı���ЧԪ�ظ����������ڼ���ܻ�����ײ������ı�
	v.reserve(100);
	// ����Ԫ���ڼ䣬���ܻ��������ݣ�������ԭ�ռ䱻�ͷ�
	v.insert(v.begin(), 0);
	v.push_back(8);
	// ��vector���¸�ֵ�����ܻ�����ײ������ı�
	v.assign(100, 8);
	
	/*
	����ԭ�����ϲ��������п��ܻᵼ��vector���ݣ�Ҳ����˵vector�ײ�ԭ��ɿռ䱻��
	�ŵ������ڴ�ӡʱ��it��ʹ�õ����ͷ�֮��ľɿռ䣬�ڶ�it����������ʱ��ʵ�ʲ�������һ��
	�Ѿ����ͷŵĿռ䣬�������������ʱ������
	�����ʽ�������ϲ������֮�������Ҫ����ͨ������������vector�е�Ԫ�أ�ֻ���
	it���¸�ֵ���ɡ�
	*/
	
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestVector4() {

	int a[] = { 1, 2, 3, 4 };
	std::vector<int> v(a, a + sizeof(a) / sizeof(int));
	// ʹ��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
	v.erase(pos);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
}

void TestVector5() {
	vector<int> v{ 1, 2, 3, 4 };
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			v.erase(it);
		++it;
	}
}
void TestVector6() {
	vector<int> v{ 1, 2, 3, 4 };
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
}


void TestVector7() {
	lsl::vector<string> v;
	v.push_back("1111");
	v.push_back("2222");
	v.push_back("3333");
	v.push_back("4444");
	v.push_back("5555");
}

int main()
{
	//TestVectorExpand();
	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestVector4();
	//TestVector5();
	//TestVector6();
	TestVector7();


	return 0;
}




//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	for (size_t i = 0; i < v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//	auto it = v.begin();
//	cout << "����֮ǰ��vector������Ϊ: " << v.capacity() << endl;
//	// ͨ��reserve���ײ�ռ�����Ϊ100��Ŀ����Ϊ����vector�ĵ�����ʧЧ
//	v.reserve(100);
//	cout << "����֮��vector������Ϊ: " << v.capacity() << endl;
//	// ��������reserve֮��it�������϶���ʧЧ����vs�³����ֱ�ӱ����ˣ�����linux�²���
//	// ��Ȼ�������У���������Ľ���ǲ��Ե�
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	vector<int>::iterator it = find(v.begin(), v.end(), 3);
//	v.erase(it);
//	cout << *it << endl;
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	//vector<int> v{1,2,3,4,5,6};
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			v.erase(it);
//		++it;
//	}
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}

//int main() {
//	string s("hello");
//	auto it = s.begin();
//	// �ſ�֮�������������Ϊresize��20��string���������
//	// ����֮��itָ��֮ǰ�ɿռ��Ѿ����ͷ��ˣ��õ�������ʧЧ��
//	// �����ӡʱ���ٷ���itָ��Ŀռ����ͻ����
//	// s.resize(20, '!');
//	while (it != s.end())
//	{
//		cout << *it;
//		++it;
//	}
//	cout << endl;
//	it = s.begin();
//	while (it != s.end())
//	{
//		it = s.erase(it);
//		// �������淽ʽд������ʱ������������Ϊerase(it)֮��
//		// itλ�õĵ�������ʧЧ��
//		// s.erase(it);
//		++it;
//	}
//}


