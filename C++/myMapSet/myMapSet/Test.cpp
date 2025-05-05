#include "mymap.h"
#include "myset.h"


void Print(const lsl::set<int>& s)
{
	for (auto& e : s)
	{
		//e++;
		cout << e << " ";
	}
	cout << endl;
} 

void Print(const lsl::map<string, string>& s)
{
	for (auto& e : s)
	{
		//e.first += 'x';
		//e.second += 'x';
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;
}

void test_set()
{
	lsl::set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(3);
	s.insert(6);
	s.insert(16);
	s.insert(6);
	s.insert(36);
	s.insert(-6);
	s.insert(9);

	lsl::set<int>::iterator it  = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		//*it = 1;
		++it;
	}
	cout << endl;

	Print(s);

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	it = s.end();
	while (it != s.begin())
	{
		--it;
		cout << *it << " ";
	}
	cout << endl;
}

void test_map()
{
	lsl::map<string, string> dict;
	dict.insert({ "sort", "ÅÅĞò" });
	dict.insert({ "left", "×ó±ß" });
	dict.insert({ "right", "ÓÒ±ß" });

	lsl::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		//it->first += 'x';
		it->second += 'x';

		cout << it->first << "" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;
}

void test_map1()
{
	lsl::map<string, string> dict;
	dict.insert({ "sort", "ÅÅĞò" });
	dict.insert({ "left", "×ó±ß" });
	dict.insert({ "right", "ÓÒ±ß" });

	lsl::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		//it->first += 'x';
		it->second += 'x';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	dict["insert"];
	dict["left"] = "×ó±ß¡¢Ê£Óà";

	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;
}

int main()
{
	
	test_set();
	//test_map1();

	return 0;
}



