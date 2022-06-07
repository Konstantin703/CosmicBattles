#ifndef BASE_OBSERVER_H
#define BASE_OBSERVER_H

#include "Entity.h"

class BaseObserver
{
public:
	virtual ~BaseObserver() = default;
	virtual void onNotify(const Entity& in_entity) = 0;
};

#endif
