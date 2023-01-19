# 5th Assignment 

In this assignment we had to implement a collection class called a priority queue, which stores its elements in an order determined by a numeric priority value. Lower numeric values correspond to higher levels of urgency, so that a task with priority 1 comes before a task with priority 2. The methods that PriorityQueue will use are:

* enqueue (value,priority), adds value at the appropriate position in the queue as determined by the numeric value priority.
* dequeue(), removes the balue at the head of the queue and returns it to the caller.
* peek(), returns the value of the most urgent item in the queue without removing it.
* peepPriority(), returns the priority of the most urgent item in the queue without removing it.
* clear(), removes all elements from queue.
* size(), returns size of queue.
* isEmpty(), returns true if the queue is empty.

<br>
Implementation of this PriorityQueue project had to be done using three different underlying representations:
1. A dynamic array that stores the elements in priority order. Methods enqueue and dequeue operate in O(N) time.
2. A linked list that stores the elements in prioority order. Methods enqueue requires linear time but dequeue runs in O(1).
3. A data structure called a heap that stores the elements in a way that guarantees that the fundamental queue operations run in O(log N) time (enqueue and dequeue).
