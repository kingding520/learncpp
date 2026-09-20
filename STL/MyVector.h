#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <cstddef>  //size_t
#include <stdexcept>//std::out_of_range
#include <utility>  //std::move
#include <algorithm>//std::copy

template <typename T>
class MyVector
{
    public:
   // ============ 构造 / 析构 ============
    MyVector();
    explicit MyVector(size_t n);                 // 构造 n 个默认元素
    MyVector(size_t n, const T& value);          // 构造 n 个 value
    MyVector(const MyVector& other);             // 拷贝构造
    MyVector(MyVector&& other) noexcept;         // 移动构造
    ~MyVector();

    // ============ 赋值运算符 ============
    MyVector& operator=(const MyVector& other);  // 拷贝赋值
    MyVector& operator=(MyVector&& other) noexcept; // 移动赋值

    // ============ 元素访问 ============
    T&       operator[](size_t index);
    const T& operator[](size_t index) const;

    T&       at(size_t index);
    const T& at(size_t index) const;

    T&       front();
    const T& front() const;

    T&       back();
    const T& back() const;

    // ============ 容量相关 ============
    size_t size()     const noexcept { return size_; }
    size_t capacity() const noexcept { return capacity_; }
    bool   empty()    const noexcept { return size_ == 0; }

    void reserve(size_t newCap);
    void resize(size_t newSize);
    void shrink_to_fit();

    // ============ 修改操作 ============
    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    void clear() noexcept;

    // ============ 迭代器 ============
    T*       begin()  noexcept { return data_; }
    T*       end()    noexcept { return data_ + size_; }
    const T* begin()  const noexcept { return data_; }
    const T* end()    const noexcept { return data_ + size_; }

private:
    T*     data_;       // 数据缓冲区
    size_t size_;       // 当前元素个数
    size_t capacity_;   // 当前容量

    void reallocate(size_t newCap);   // 扩容并搬运元素

};
#include "MyVector.tpp" 
#endif