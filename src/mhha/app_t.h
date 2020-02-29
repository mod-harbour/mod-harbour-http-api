#pragma once
namespace mhha
{
	
	class app_t
	{
		private :
		std::filesystem::path m_mhha_folder  = L"";
		std::filesystem::path m_app_folder   = L"";


		// --------------------------------------------------------------------
		public:
		static void init_library(HMODULE hMhha);
		// --------------------------------------------------------------------
		private:
		app_t(HMODULE hMhha );
		~app_t();
		// --------------------------------------------------------------------
		void init_mhha_dll_folder(HMODULE hMhha);

	};
	app_t* app(void);
}