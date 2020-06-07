#ifndef DSA_SINGLELIST_H
#define DSA_SINGLELIST_H

#include <exception>

namespace dsa
{
  template <typename T>
  class SingleList
  {
  public:
    SingleList() : head_(new Node()), size_(0) {}

    SingleList(const SingleList &singleList)
    {
      construct(singleList.head_, singleList.size_);
    }

    SingleList &operator=(const SingleList &rhs)
    {
      if (this == &rhs)
        return *this;
      destroy();
      construct(rhs.head_, rhs.size_);
    }

    ~SingleList()
    {
      destroy();
    }

    int size() const { return size_; }

    bool empty() const { return !size_; }

    T get(int index) const
    {
      Node *cur = findByIndex(index, "get");
      return cur->data;
    }

    T getFirst() const
    {
      return get(0);
    }

    T getLast() const
    {
      return get(size_ - 1);
    }

    void set(int index, const T &e)
    {
      Node *cur = findByIndex(index, "set");
      cur->data = e;
    }
    //插入到index节点前面
    void add(int index, const T &e)
    {
      if (index < 0 || index > size_)
        throw std::invalid_argument("Add failed. Illegal index.");
      Node *prev = head_;
      for (int i = 0; i < index; ++i)
        prev = prev->next;
      prev->next = new Node(e, prev->next);
      size_++;
    }

    void addFirst(const T &e)
    {
      add(0, e);
    }

    void addLast(const T &e)
    {
      add(size_, e);
    }

    bool contains(const T &e) const
    {
      Node *cur = head_->next;
      while (cur != nullptr)
      {
        if (cur->data == e)
          return true;
        cur = cur->next;
      }
      return false;
    }

    T remove(int index)
    {
      if (index < 0 || index >= size_)
        throw std::invalid_argument("Remove failed. Illegal index.");
      Node *prev = head_;
      for (int i = 0; i < index; ++i)
      {
        prev = prev->next;
      }

      Node *delNode = prev->next;
      prev->next = delNode->next;
      delNode->next = nullptr;
      size_--;
      T ret = delNode->data;
      delete delNode;
      return ret;
    }

    T removeFirst()
    {
      return remove(0);
    }

    T removeLast()
    {
      return remove(size_ - 1);
    }

    void removeElement(const T &e)
    {
      Node *prev = head_;
      while (prev != nullptr)
      {
        if (prev->next->data == e)
          break;
        prev = prev->next;
      }
      if (prev->next != nullptr) //尾节点特殊处理
      {
        Node *delNode = prev->next;
        prev->next = delNode->next;
        delNode->next = nullptr;
        delete delNode;
        size_--;
      }
    }

    void print()
    {
      Node *cur = head_->next;
      while (cur != nullptr)
      {
        std::cout << cur->data << "->";
        cur = cur->next;
      }
      std::cout << "NULL" << std::endl;
    }

  private:
    struct Node
    {
      Node() = default;
      Node(const T &e) : data(e), next(nullptr) {}
      Node(const T &e, Node *next) : data(e), next(next) {}
      T data;
      Node *next;
    };

    Node *head_;
    int size_;

    void construct(Node *srcHead, int count)
    {
      head_ = new Node();
      size_ = count;
      Node *prev = head_;
      Node *p = srcHead->next; //指向要复制的节点
      for (int i = 0; i < count; ++i)
      {
        prev->next = new Node(p->data, nullptr);
        prev = prev->next;
        p = p->next;
      }
    }

    void destroy()
    {
      Node *p = head_;
      while (p != nullptr)
      {
        Node *delNode = p;
        p = delNode->next;
        delete delNode;
      }
    }

    //返回指向index节点的指针
    Node *findByIndex(int index, const std::string &functionName) const
    {
      if (index < 0 || index >= size_)
        throw std::invalid_argument(functionName + " failed. Illegal index.");
      Node *p = head_->next;
      for (int i = 0; i < index; ++i)
        p = p->next;
      return p;
    }
  };

} //namespace dsa

#endif //DSA_SINGLELIST_H
