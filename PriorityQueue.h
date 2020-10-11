/*--------------------------------------------------------------------------
     PriorityQueue is a more understandable priority queue implemented
                 with the one of the standard library
--------------------------------------------------------------------------*/

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <queue>    //contain the standard priority queue implementation
using namespace std;

typedef pair<int,int> intPair; //couple of integer

class PriorityQueue
{
    private:

        /*------------------------------------------------------------------------------
                          Template parameters for the priority queue:

        intPair: it's a queue of couple of integer (<element, priority>)

        vector<intPair>: the container use to store the elements is a vector of pair

        greater<intPair>: the comparator. Here the element with the smallest
                          priority will appear at the top of the queue
        ------------------------------------------------------------------------------*/
        priority_queue< intPair, vector<intPair> , greater<intPair> > Q;

    public:
        void addWithPriority(int elem, int priority);
        int extractMin();
        void decreasePriority(int elem, int new_priority);
        bool isEmpty();
};

#endif // PRIORITYQUEUE_H
