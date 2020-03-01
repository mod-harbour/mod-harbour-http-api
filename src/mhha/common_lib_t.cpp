#include "pch.h"
#include <assert.h>
// ---------------------------------------------------------------------------------------------------------------------------------------
static mhha::common_lib_t * s_common_lib = 0;
// ---------------------------------------------------------------------------------------------------------------------------------------
mhha::common_lib_t* mhha::common_lib_t::get(void)
{
	return s_common_lib;
}
// ---------------------------------------------------------------------------------------------------------------------------------------
void mhha::common_lib_t::init_library(HMODULE hMhha)
{
	assert(!s_common_lib);
	if (!s_common_lib)
	{
		s_common_lib = new common_lib_t(hMhha);
	}
}
// ---------------------------------------------------------------------------------------------------------------------------------------
mhha::common_lib_t::common_lib_t(HMODULE hMhha)
{
	init_mhha_dll_folder(hMhha);
	
}
// ---------------------------------------------------------------------------------------------------------------------------------------
mhha::common_lib_t::~common_lib_t()
{
}
// ---------------------------------------------------------------------------------------------------------------------------------------
void mhha::common_lib_t::init_mhha_dll_folder(HMODULE hMhha)
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

