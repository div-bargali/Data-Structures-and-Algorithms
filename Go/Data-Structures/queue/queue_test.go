package main

import "testing"

func TestQueueShouldInitialiseEmpty(t *testing.T) {
    var q queue
    if q.isEmpty() != true {
        t.Errorf("Queue failed to initialise with no values")
    }
}

func TestQueueShouldDequeValuesInOrderTheyWereAdded(t *testing.T) {
    var q queue
    var value int
    var valid bool
    q.enqueue(5)
    q.enqueue(4)
    q.enqueue(3)
    value, valid = q.dequeue()

    if value != 5 || valid != true {
        t.Errorf("Expected value %d, %t to be returned, received: %d, %t", 5, true, value, valid)
    }

    value, valid = q.dequeue()
    if value != 4 || valid != true {
        t.Errorf("Expected value %d, %t to be returned, received: %d, %t", 4, true, value, valid)
    }

    value, valid = q.dequeue()
    if value != 3 || valid != true {
        t.Errorf("Expected value %d, %t to be returned, received: %d, %t", 3, true, value, valid)
    }
}

func TestQueueShouldNotBeEmptyWhenValuesAreAdded(t *testing.T) {
    var q queue
    q.enqueue(5)
    q.enqueue(4)
    q.enqueue(3)
    if q.isEmpty() != false {
        t.Errorf("Expected queue to not be empty")
    }
}

func TestQueueShouldBeEmptyAfterAllValuesAreDequeued(t *testing.T) {
    var q queue
    q.enqueue(5)
    q.enqueue(4)
    q.enqueue(3)

    q.dequeue()
    q.dequeue()
    q.dequeue()
    if q.isEmpty() != true {
        t.Errorf("Expected queue to be empty")
    }
}

func TestQueueShouldReturn0FalseWhenDequeueIsCalledOnAnEmptyQueue(t *testing.T){
    var q queue
    value, valid := q.dequeue()
    if value != 0 || valid != false {
        t.Errorf("Expected values from empty queue: %d, %t - Received: %d, %t", 0, false, value, valid)
    }
}