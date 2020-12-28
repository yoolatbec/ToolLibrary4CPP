/*
 * ArrayList.h
 *
 *  Created on: Nov 8, 2020
 *      Author: yoolatbec
 */

#ifndef SRC_UTILS_ARRAYLIST_H_
#define SRC_UTILS_ARRAYLIST_H_

#include "List.h"
#include "../lang/Integer.h"

namespace tl {
namespace utils {

using lang::Reference;

class ArrayList: virtual public List{
private:
	const static type_t CLASS_SERIAL = 13;
	Reference *mElements;

	class ArrayListIterator: public ListIterator {
	private:
		const static type_t CLASS_SERIAL = 14;
		ArrayList *const mList;
		tlint mCurrent;
	public:
		ArrayListIterator(ArrayList*);
		static hash_t getType();
		bool instanceof(type_t);
		bool hasNext();
		Reference next();
		bool hasPrevious();
		Reference previous();
		bool remove();
		bool insert(Reference);
		static type_t type();
	};

	friend class ArrayListIterator;

	void expand();
public:
	const static tlint MAX_CAPACITY = lang::Integer::MAX_VALUE;
	explicit ArrayList(type_t);
	ArrayList(type_t, tlint);
	~ArrayList();
	ArrayList(const ArrayList &other) = delete;
	ArrayList& operator=(const ArrayList&) = delete;
	bool add(Reference);
	bool addAll(Reference);
	bool contains(Reference);
	bool containsAll(Reference);
	tlint indexOf(Reference);
	bool insert(Reference, tlint position);
	bool insertAll(Reference, tlint);
	bool remove(tlint);
	bool remove(Reference);
	bool removeAll(Reference);
	Reference toArray();
	Reference sublist(tlint, tlint);
	void clear();
	Reference get(tlint);
	bool set(tlint, Reference);
	Reference iterator();
	virtual bool instanceof(type_t);
	static type_t type();
};

} /* namespace utils */
} /* namespace tl */

#endif /* SRC_UTILS_ARRAYLIST_H_ */
