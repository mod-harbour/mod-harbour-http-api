#include "pch.h"

mhha::worker_pool_t::worker_pool_t()
{
}

mhha::worker_pool_t::~worker_pool_t()
{
}

bool mhha::worker_pool_t::start()
{
	return false;
}

void mhha::worker_pool_t::request_termination(std::function<void()>& lambda)
{
	lambda();
}

bool mhha::worker_pool_t::is_runing()
{
	return m_running;
}
