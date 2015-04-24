#include<stdio.h>
 
template <typename T, const int max>
class Stack
{
  private:
    int numItems;
    T itemList[max];
 
  public:
    Stack():numItems(0) {}
 
    void push(T val) {
      if (numItems >= max) return;
      itemList[numItems++] = val;
    }
 
    T pop() {
      if (numItems <= 0) return itemList[0];
      T temp = itemList[--numItems];
      return temp;
    }
 
    bool isEmpty() {
      if (numItems <= 0) return true;
      return false;
    }
 
    void display() {
      for (int i = 0; i < numItems; ++i) {
        printf("%d ", itemList[i]);
      }
      printf("\n");
    }
 
    int size() {
      return numItems;
    }
 
    void clear() {
      numItems = 0;
    }
};
 
template < template<typename , const int > class TemplateType, class TY,const int ma >
void copyStack(TemplateType<TY,ma> &source, TemplateType<TY,ma> &target)
{
  if (source.isEmpty()) return;
  TY v = source.pop();
  copyStack(source, target);
  target.push(v);
}
 
template < template<typename , const int > class TemplateType, class TY,const int ma >
void reverseStack(TemplateType<TY,ma> & s, TemplateType<TY,ma> & t)
{
  TY v;
  while(!t.isEmpty()) {
    v = t.pop();
    s.push(v);
  }
}
 
int main()
{
  Stack<int, 10> s;
  Stack<int, 10> t;
  
	for(int i = 0; i < 5; ++i) {
    s.push(i + 1);
  }

  s.display();
  copyStack(s, t);
  reverseStack(s, t);
  s.display();
  return 0;
}
