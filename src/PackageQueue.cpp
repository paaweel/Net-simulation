// PackageQueue.cpp


#include "types.h"
#include "PackageQueue.h"

//workaround, we should be able to think of something else
//overloading deque class is one option
Package popAndReturnValueFIFO(std::deque<Package> &deque) {
    Package p = deque.front();
    deque.pop_front();
    return p;
}

Package popAndReturnValueLIFO(std::deque<Package> &deque) {
    Package p = deque.back();
    deque.pop_back();
    return p;
}

PackageQueue::PackageQueue(QueueType type)
{
	PackageQueueType = type;
    switch(type) {
        case QueueType::FIFO:
            _popFunction = popAndReturnValueFIFO;
            break;
        case QueueType::LIFO:
            _popFunction = popAndReturnValueLIFO;
            break;
    //exception if none matched?
    }
}

void PackageQueue::push(Package package_)
{
	deque.push_back(package_);
}

Package PackageQueue::pop()
{
	return _popFunction(deque);
}

Package* PackageQueue::view()
{
    //DOES NOT WORK
    //ONLY FOR DEBUGGING
	Package * p = new Package;
    return p;
}

QueueType PackageQueue::getQueueType()
{
	return PackageQueueType;
}

bool PackageQueue::empty()
{
	return deque.empty();
}

int PackageQueue::size()
{
	return deque.size();
}
