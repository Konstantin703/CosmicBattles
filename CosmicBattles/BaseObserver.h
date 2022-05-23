#ifndef BASE_OBSERVER_H
#define BASE_OBSERVER_H

#include "Entity.h"

class BaseObserver
{
public:
	virtual ~BaseObserver() = default;
	virtual void onNotify() = 0;
};

#endif
