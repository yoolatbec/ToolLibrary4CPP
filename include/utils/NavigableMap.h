/*
 * NavigableMap.h
 *
 *  Created on: 4 Feb 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_NAVIGABLEMAP_H_
#define INCLUDE_UTILS_NAVIGABLEMAP_H_

#include <utils/SortedMap.h>

namespace tl {
namespace utils {

class NavigableMap: public SortedMap {
private:
	const static type_t CLASS_SERIAL = 35;
public:
	NavigableMap(type_t, type_t);
	virtual ~NavigableMap();
	NavigableMap(const NavigableMap &other) = delete;
	NavigableMap& operator=(const NavigableMap &other) = delete;
	virtual Reference ceilingEntry(Reference) = 0;
	virtual Reference ceilingKey(Reference) = 0;
//	virtual Reference descendingKeySet() = 0;
//	virtual Reference descendingMap() = 0;
	virtual Reference firstEntry() = 0;
	virtual Reference floorEntry(Reference) = 0;
	virtual Reference floorKey(Reference) = 0;
	virtual Reference higherKey(Reference) = 0;
	virtual Reference higherEntry(Reference) = 0;
	virtual Reference lastEntry() = 0;
	virtual Reference lastKey() = 0;
	virtual Reference lowerEntry(Reference) = 0;
	virtual Reference lowerKey(Reference) = 0;
	virtual Reference pollFirstEntry() = 0;
	virtual Reference pollLastEntry() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_NAVIGABLEMAP_H_ */
