#include <bits/stdc++.h>

using namespace std;

// Below is the interface for Iterator, which is already defined for you.
//   **DO NOT** modify the interface for Iterator.
class Iterator
{
public:
    struct Data;
    Data *data;
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};
class PeekingIterator : public Iterator
{
    int nextVal;
    bool iterHasNext;

public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        iterHasNext = Iterator::hasNext();
        if (iterHasNext)
            nextVal = Iterator::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        return nextVal;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        int curNext = nextVal;
        iterHasNext = Iterator::hasNext();
        if (iterHasNext)
            nextVal = Iterator::next();
        return curNext;
    }

    bool hasNext() const
    {
        return iterHasNext;
    }
};