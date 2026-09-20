#include "MyVector.h"
#include <iostream>
#include <string>

int main() {
    MyVector<int> v;
    for (int i = 0; i < 5; ++i) v.push_back(i * 10);

    std::cout << "size=" << v.size()
              << " capacity=" << v.capacity() << "\n";

    // 范围 for
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";

    // 越界测试
    try {
        v.at(100);
    } catch (const std::out_of_range& e) {
        std::cout << "caught: " << e.what() << "\n";
    }

    // 拷贝 & 移动
    MyVector<int> v2 = v;             // 拷贝构造
    MyVector<int> v3 = std::move(v);  // 移动构造
    std::cout << "v2.back()=" << v2.back() << "\n";
    std::cout << "v.size()=" << v.size() << "\n";  // 应为 0（被移动走了）

    // 字符串测试
    MyVector<std::string> sv;
    sv.push_back("hello");
    sv.push_back("world");
    for (const auto& s : sv) std::cout << s << " ";
    std::cout << "\n";

    return 0;
}