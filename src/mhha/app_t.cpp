#include "pch.h"
#include <assert.h>
// ---------------------------------------------------------------------------------------------------------------------------------------
static mhha::app_t * s_app = 0;
// ---------------------------------------------------------------------------------------------------------------------------------------
mhha::app_t* app(void)
{
	return s_app;
}
// ---------------------------------------------------------------------------------------------------------------------------------------
void mhha::app_t::init_library(HMODULE hMhha)
{
	assert(!s_app);
	if (!s_app)
	{
		s_app = new app_t(hMhha);
	}
}
// ---------------------------------------------------------------------------------------------------------------------------------------
mhha::app_t::app_t(HMODULE hMhha)
{
	init_mhha_dll_folder(hMhha);
	
}
// ---------------------------------------------------------------------------------------------------------------------------------------
mhha::app_t::~app_t()
{
}
// ---------------------------------------------------------------------------------------------------------------------------------------
void mhha::app_t::init_mhha_dll_folder(HMODULE hMhha)
{
   
	std::wstring buffer;
	buffer.reserve(MAX_PATH+1);
	ZeroMemory(buffer.c_str, buffer.capacity);
	GetModuleFileNameW(hMhha, buffer.c_str, buffer.capacity - 1);
	m_mhha_folder = buffer.c_str;
	ZeroMemory(buffer.c_str, buffer.capacity);
	GetModuleFileNameW(0, buffer.c_str, buffer.capacity - 1);
	m_app_folder = buffer.c_str;
}
// ---------------------------------------------------------------------------------------------------------------------------------------

app_t* mhha::app(void)
{
	return nullptr;
}
