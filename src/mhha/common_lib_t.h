#pragma once
namespace mhha
{
	
	class common_lib_t
	{
		protected :
		std::filesystem::path m_mhha_folder  = L"";
		std::filesystem::path m_app_folder   = L"";
		// --------------------------------------------------------------------
		public:
		static void init_library(HMODULE hMhha);
		common_lib_t* get(void);
		// --------------------------------------------------------------------
		private:
		common_lib_t(HMODULE hMhha );
		~common_lib_t();
		// --------------------------------------------------------------------
		void init_mhha_dll_folder(HMODULE hMhha);

	};
	
}