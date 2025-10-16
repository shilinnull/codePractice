#include <iostream>

using namespace std;

// 在多个翻译单元(.cpp文件)中包含此头文件会导致链接错误
// int bufferSize = 1024;		// 链接报错
const int bufferSize = 1024;	// 每个.cpp文件都会有自己的bufferSize副本，这不是我们想要的
const int cacheSize = 4 * 1024;

void func();