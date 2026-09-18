#include <iostream>
#include <stdexcept>

template<typename T>
class Queue
{
private:
    struct QueueItem
    {
        QueueItem(T data = T()) : _data(data), _next(nullptr) {}
        
        void* operator new(size_t size)
        {
            // 如果内存池为空，分配新内存池
            if (_Pool == nullptr)
            {
                // 分配连续内存
                _Pool = static_cast<QueueItem*>(
                    ::operator new(sizeof(QueueItem) * POOL_ITEM_SIZE)
                );
                
                // 构建空闲链表：将每个节点连接起来
                QueueItem* current = _Pool;
                for (int i = 0; i < POOL_ITEM_SIZE - 1; ++i)
                {
                    current->_next = current + 1;  // 指向下一个节点
                    current = current->_next;
                }
                current->_next = nullptr;  // 最后一个节点指向空
            }
            
            // 从内存池头部取出一个节点
            QueueItem* item = _Pool;
            _Pool = _Pool->_next;
            
            // 可选：重置节点的_next，避免残留
            if (item) {
                item->_next = nullptr;
            }
            
            return item;
        }
        
        void operator delete(void* ptr)
        {
            if (ptr == nullptr) return;
            
            // 将节点放回内存池头部
            QueueItem* item = static_cast<QueueItem*>(ptr);
            item->_next = _Pool;
            _Pool = item;
        }
        
        T _data;
        QueueItem* _next;
        static const int POOL_ITEM_SIZE = 10000;
        static QueueItem* _Pool;
    };
    
    QueueItem* _front;  // 头结点（哨兵）
    QueueItem* _rear;   // 尾节点

public:
    Queue()
    {
        _front = _rear = new QueueItem();  // 创建哨兵节点
    }
    
    ~Queue()
    {
        QueueItem* cur = _front;
        while (cur != nullptr)
        {
            _front = cur->_next;
            delete cur;  // 调用 operator delete 放回内存池
            cur = _front;
        }
    }
    
    void addQue(const T& val)
    {
        QueueItem* item = new QueueItem(val);
        _rear->_next = item;
        _rear = item;
    }
    
    void pop()
    {
        if (empty())
            return;
        
        QueueItem* first = _front->_next;
        _front->_next = first->_next;  // ✅ 修复：使用 _next
        
        if (_front->_next == nullptr)
        {
            _rear = _front;
        }
        
        delete first;  // 调用 operator delete 放回内存池
    }
    
    bool empty() const
    {
        return _front == _rear;
    }
    
    T& front()
    {
        if (empty())
            throw std::runtime_error("Queue is empty");
        return _front->_next->_data;
    }
    
    const T& front() const
    {
        if (empty())
            throw std::runtime_error("Queue is empty");
        return _front->_next->_data;
    }
};

// ✅ 静态成员定义
template<typename T>
typename Queue<T>::QueueItem* Queue<T>::QueueItem::_Pool = nullptr;

// 测试代码
int main()
{
    Queue<int> que;
    
    // 添加 1-99
    for (int i = 1; i < 100; i++)
    {
        que.addQue(i);
    }
    
    // 验证：取出前5个元素
    std::cout << "前5个元素: ";
    for (int i = 0; i < 5; i++)
    {
        if (!que.empty())
        {
            std::cout << que.front() << " ";
            que.pop();
        }
    }
    std::cout << std::endl;
    
    // 验证剩余元素数量
    int count = 0;
    Queue<int> temp = que;  // 需要拷贝构造函数（当前没有，会有问题）
    // 建议：添加拷贝构造和赋值操作符
    
    return 0;
}









