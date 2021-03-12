/*
 * SortedMap.h
 *
 *  Created on: 4 Feb 2021
 *      Author: yoolatbec
 */

#ifndef INCLUDE_UTILS_SORTEDMAP_H_
#define INCLUDE_UTILS_SORTEDMAP_H_

#include <tl/utils/Map.h>

namespace tl {
namespace utils {

class SortedMap: public Map {
private:
	const static type_t CLASS_SERIAL = 43;
public:
	SortedMap(type_t, type_t);
	virtual ~SortedMap();
	SortedMap(const SortedMap &other) = delete;
	SortedMap& operator=(const SortedMap &other) = delete;
	virtual Reference keySet() = 0;
	virtual Reference values() = 0;
	virtual Reference firstKey() = 0;
	virtual Reference lastKey() = 0;
	virtual Reference entrySet() = 0;
//	virtual Reference subMap(Reference, bool, Reference, bool) = 0;
//	virtual Reference subMap(Reference, Reference) = 0;
//	virtual Reference tailMap(Reference) = 0;
//	virtual Reference headMap(Reference) = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* INCLUDE_UTILS_SORTEDMAP_H_ */
