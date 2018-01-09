#ifndef TYPES_H_
#define TYPES_H_

using Time = int;
using TimeOffset = int;
using ElementID = int;

class Package {
private:
	ElementID id;
	static int packageCounter = 0;
public:
	Package() { id = packageCounter++; }
	Package(ElementID number) : id(number) {packageCounter++;} // zakladamy ze numery ID w pliku sa unikalne
	ElementID getId() { return id; }
}; // Package

enum class ReceiverType { WORKER, STOREHOUSE };
enum class QueueType { LIFO, FIFO };

#endif /* TYPES_H_ */
