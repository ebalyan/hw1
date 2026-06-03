#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}
std::string const & ULListStr::front() const
{
  return head_->val[tail_->first];

}

void ULListStr::push_back(const std::string& val)
{
  if empty()){
    Item* item = new Item;
    item->val[0] = val;
    item->first = 0;
    item->last = 1;
    head_ = item;
    tail_ = item;
  }
  else if(tail_->last < ARRSIZE){
    Item* item = new Item;
    item->val[0] = val;
    item->first = 0;
    item->last = 1;
    item->prev = tail_;
    tail_->next = item;
    tail_ = item;
  }
size++;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
