/*
 * SortedMap.h
 *
 *  Created on: Apr 18, 2021
 *      Author: yoolatbec
 */

#ifndef TL_UTILS_SORTEDMAP_H_
#define TL_UTILS_SORTEDMAP_H_

#include <tl/utils/Map.h>

namespace tl {
namespace utils {

using lang::Reference;

class SortedMap: public virtual Map {
private:
	const static type_t CLASS_SERIAL = 1036;
protected:
	Reference mComparator;

	SortedMap(type_t, type_t, Reference);
public:
	virtual ~SortedMap();
	SortedMap(const SortedMap &other) = delete;
	SortedMap& operator=(const SortedMap &other) = delete;
	virtual Reference ceilingEntry(Reference) = 0;
	virtual Reference ceilingKey(Reference) = 0;
	virtual Reference firstEntry() = 0;
	virtual Reference firstKey() = 0;
	virtual Reference floorEntry(Reference) = 0;
	virtual Reference floorKey(Reference) = 0;
	Reference getComparator();
	virtual Reference higherEntry(Reference) = 0;
	virtual Reference higherKey(Reference) = 0;
	virtual Reference lastEntry() = 0;
	virtual Reference lastKey() = 0;
	virtual Reference lowerKey(Reference) = 0;
	virtual Reference lowerEntry(Reference) = 0;
	virtual Reference pollFirstEntry() = 0;
	virtual Reference pollLastEntry() = 0;
	virtual Reference sortedKeySet() = 0;
	static type_t type();
	bool instanceof(type_t);
};

} /* namespace utils */
} /* namespace tl */

#endif /* TL_UTILS_SORTEDMAP_H_ */
