#include "GunBase.h"
#include <iostream>

GunBase::GunBase()
{
	for (size_t i = 0; i < BULLET_CAPACITY; ++i)
	{
		/*BulletBase* bullet = new BulletBase;
		m_bullets_pool.push_back(std::move(bullet));	*/

	}
}

void GunBase::releaseBullet()
{
	std::cout << "void GunBase::releaseBullet()" << std::endl;
	std::cout << "Bullets available: " << m_bullets_pool.size() << std::endl;
}
