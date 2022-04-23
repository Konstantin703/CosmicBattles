#ifndef GUN_BASE_H
#define GUN_BASE_H

#include "BulletBase.h"
#include <deque>
#include <memory>

class GunBase
{
public:
	GunBase();

	void releaseBullet();

private:
	const size_t BULLET_CAPACITY= 3;
	std::deque<BulletBase*> m_bullets_pool;
};

#endif
