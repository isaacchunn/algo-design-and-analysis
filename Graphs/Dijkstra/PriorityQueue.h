#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

//https://stackoverflow.com/questions/19467485/how-to-remove-element-not-at-top-from-priority-queue
#include <queue>
#include <vector>

template<typename T>
class PriorityQueue : public std::priority_queue<T, std::vector<T>>
{
  public:

      bool remove(const T& value) {
          auto it = std::find(this->c.begin(), this->c.end(), value);
       
          if (it == this->c.end()) {
              return false;
          }
          if (it == this->c.begin()) {
              // deque the top element
              this->pop();
          }
          else {
              // remove element and re-heap
              this->c.erase(it);
              std::make_heap(this->c.begin(), this->c.end(), this->comp);
         }
         return true;
     }
};

#endif
