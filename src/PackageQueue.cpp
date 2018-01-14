// PackageQueue.cpp

PackageQueue::PackageQueue(QueueType type)
{
	PackageQueueType = type;
	//ustawic std::function 
}

void PackageQueue::push(Package package_)
{
	deque.push_back(package_);
}

Package PackageQueue::pop()
{
	//?
}

Package* PackageQueue::view()
{
	//?
}

QueueType PackageQueue::getQueueType()
{
	return PackageQueueType;
}

bool PackageQueue::isEmpty()
{
	return deque.empty();
}

int PackageQueue::size()
{
	return deque.size();
}
