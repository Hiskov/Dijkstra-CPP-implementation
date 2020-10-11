#include "PriorityQueue.h"

/*--------------------------------------------------------
     Adds the element with the following priority
----------------------------------------------------------*/
void PriorityQueue::addWithPriority(int elem, int priority)
{
    Q.push(make_pair(elem, priority));
}


/*--------------------------------------------------------
    Extracts the element with the smallest priority (top)
----------------------------------------------------------*/
int PriorityQueue::extractMin()
{
    int extract_elem = Q.top().first;   //first of the pair ==> the element
    Q.pop();
    return extract_elem;
}


/*--------------------------------------------------------
            Gives the element a new priority
----------------------------------------------------------*/
void PriorityQueue::decreasePriority(int elem, int new_priority)
{
    Q.push(make_pair(elem, new_priority)); //lazy deletion ==> add a copy of the elem with a better priority
}



bool PriorityQueue::isEmpty()
{
    return Q.empty();
}

