#pragma once
#pragma once
namespace mhha
{
	class worker_pool_t
	{
		protected:
		std::vector<mhha::worker_pool_item_t> m_running;
		std::vector<mhha::worker_pool_item_t> m_idle;
		size_t m_max_processes         = 32 ;
		size_t m_min_idle_processes    = 2  ;
		size_t m_granularity           = 4  ;
		size_t m_peak                  = 0;
		bool   m_running = false;
		// -------------------------------------------------
		public:
		worker_pool_t();
		~worker_pool_t();
		// -------------------------------------------------
		bool start();
		void request_termination( std::function<void()> & action );
		bool is_runing();


	};

}