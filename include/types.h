#ifndef TYPES_H_
#define TYPES_H_

using Time = int;
using TimeOffset = int;
using ElementID = int;

class Package {
private:
	ElementID id;
	static ElementID packageCounter;
public:
	Package() {
		static ElementID packageCounter = 0;
		id = packageCounter++;
	}
	ElementID getId() { return id; }
}; // Package


enum class ReceiverType { WORKER, STOREHOUSE };
enum class QueueType { LIFO, FIFO };

#endif /* TYPES_H_ */
