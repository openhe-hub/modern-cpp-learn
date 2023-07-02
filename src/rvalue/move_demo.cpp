#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// 传统cpp中，拷贝对象先复制再析构
// 使用std::move，将左值转为右值，直接完成移动

int main(int argc, char** argv)
{
    std::string str = "Hello world";
    std::vector<std::string> vec;
    vec.push_back(str);
    std::cout<<str<<std::endl; // "Hello world"

    vec.push_back(std::move(str));
    std::cout<<str<<std::endl; // ""

    return 0;
}