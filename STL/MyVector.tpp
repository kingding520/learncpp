#include "MyVector.h"

// ============ 私有：扩容 ============
template <typename T>
void MyVector<T>::reallocate(size_t newCap){
    T*newData=new T[newCap];
    for(size_t i=0;i<size_;++i)
    {
        newData[i]=std::move(data_[i]);
    }
    delete[] data_;
    data_=newData;
    capacity_=newCap;
}


template <typename T>
MyVector<T>::MyVector():data_(nullptr),size_(0),capacity_(0){}
//列表初始化要按声明顺序
template <typename T>
MyVector<T>::MyVector(size_t n):data_(nullptr),size_(0),capacity_(n){
    if (n>0){
    data_=new T[n];
    //new T[n]() 的 () 是值初始化，int 会变 0；而 std::vector(n) 是默认初始化，int 是不确定值。行为不同。
    size_=capacity_=n;
    }
    
}
template <typename T>
MyVector<T>::MyVector(size_t n,const T& value)
{
    data_=new T[n];
    size_=n;
    capacity_=n;
    for(size_t i=0;i<n;++i) data_[i]=value;
}
template <typename T>
MyVector<T>::MyVector(const MyVector& other):data_(nullptr),size_(0),capacity_(0){
    if (other.size_>0){
    T*newData=new T[other.size_];
        for (size_t i = 0; i < other.size_; ++i) newData[i] = other.data_[i];
        size_ = capacity_ = other.size_;
     
    data_=newData;
    newData=nullptr;
    }
}
template <typename T>
MyVector<T>::MyVector(MyVector&& other)noexcept:
    data_(other.data_), size_(other.size_), capacity_(other.capacity_){
    other.data_=nullptr;
    other.size_=other.capacity_=0;
}
//移动赋值：noexcept，承诺不抛出异常，防止异常后数据损坏。
template <typename T>
MyVector<T>::~MyVector() {
    delete[] data_;
    size_=capacity_=0;
    data_=nullptr;
}
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other){
    if (this == &other) return *this;       // 自赋值检查
    if(other.size_>0)
    {
        T*newData=new T[other.size_];
        for(size_t i=0;i<other.size_;++i) newData[i]=other.data_[i];
    
    delete[] data_;
    data_=newData;
    newData = nullptr;
    size_=capacity_=other.size;
    }
    return *this;
}
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept{
    if(this == &other) return *this;
    delete[] data_;
    data_=other.data_;
    size_=capacity_=other.size_;
    other.data_=nullptr;
    other.size_=other.capacity_=0;
    return *this;
}

template <typename T>
T& MyVector<T>::operator[](size_t index){return data_[index];}
template <typename T>
const T& MyVector<T>::operator[](size_t index)const {return data_[index];} 
template <typename T>
T& MyVector<T>:: at(size_t index)
{
    if(index>=size_)throw std::out_of_range("Myvector::at");
    return data_[index];
}
template <typename T>
const T& MyVector<T>:: at(size_t index)const
{
    if(index>=size_)throw std::out_of_range("Myvector::at");
    return data_[index];
}
template <typename T>
T& MyVector<T>::front() { return data_[0]; }
template <typename T>
const T& MyVector<T>::front() const { return data_[0]; }
template <typename T>
T& MyVector<T>::back() { return data_[size_ - 1]; }
template <typename T>
const T& MyVector<T>::back() const { return data_[size_ - 1]; }

template <typename T>
void MyVector<T>::reserve(size_t newCap)
{
    if(capacity_<newCap)reallocate(newCap);
}
template<typename T>
void MyVector<T>::resize(size_t newCap)
{
    if(newCap>capacity_)reallocate(newCap);
    if(newCap>size_){
        for (size_t i = size_; i < newCap; ++i) data_[i] = T();
    }
    size_ = newCap;
}
template <typename T>
void MyVector<T>::shrink_to_fit() {
    if (size_ < capacity_) reallocate(size_);
}

template <typename T>
void MyVector<T>::push_back(const T& value)
{
    if (size_ == capacity_) {
        size_t newCap = (capacity_ == 0) ? 1 : capacity_ * 2;
        reallocate(newCap);
    }
    data_[size_++]=value;
}
template <typename T>
void MyVector<T>::push_back(T&& value) {
    if (size_ == capacity_) {
        size_t newCap = (capacity_ == 0) ? 1 : capacity_ * 2;
        reallocate(newCap);
    }
    data_[size_++] = std::move(value);
}
template <typename T>
void MyVector<T>::pop_back(){
    if(size_==0)return;
    size_--;
}
template <typename T>
void MyVector<T>::clear() noexcept {
    size_ = 0;
}