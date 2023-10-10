#pragma once
#include <stdint.h>
#include <string>

#include "../Share/StdUtils.hpp"
#include "../Includes/FasterDefs.h"

NS_WTP_BEGIN
class WtUftEngine;
NS_WTP_END
USING_NS_WTP;

class ShareManager
{
private:
	ShareManager():_inited(false), _stopped(false), _engine(nullptr), _sync("sync"){}
	~ShareManager()
	{
		_stopped = true;
		if (_worker)
			_worker->join();
	}

public:
	static ShareManager& self()
	{
		static ShareManager inst;
		return inst;
	}

	void	set_engine(WtUftEngine* engine) { _engine = engine; }

	bool	initialize(const char* module);

	bool	start_watching(uint32_t microsecs);

	bool	init_domain(const char* id);

	bool	commit_param_watcher(const char* section);

	bool	set_value(const char* section, const char* key, const char* val);

	bool	set_value(const char* section, const char* key, int32_t val);

	bool	set_value(const char* section, const char* key, int64_t val);

	bool	set_value(const char* section, const char* key, uint32_t val);

	bool	set_value(const char* section, const char* key, uint64_t val);

	bool	set_value(const char* section, const char* key, double val);

	const char*	get_value(const char* section, const char* key, const char* defVal = "");

	int32_t		get_value(const char* section, const char* key, int32_t defVal = 0);

	int64_t		get_value(const char* section, const char* key, int64_t defVal = 0);

	uint32_t	get_value(const char* section, const char* key, uint32_t defVal = 0);

	uint64_t	get_value(const char* section, const char* key, uint64_t defVal = 0);

	double		get_value(const char* section, const char* key, double defVal = 0);

	/*
	 *	�ڵ���ͬ���������ֶ�
	 */
	const char*	allocate_value(const char* section, const char* key, const char* initVal = "");
	int32_t*	allocate_value(const char* section, const char* key, int32_t initVal = 0);
	int64_t*	allocate_value(const char* section, const char* key, int64_t initVal = 0);
	uint32_t*	allocate_value(const char* section, const char* key, uint32_t initVal = 0);
	uint64_t*	allocate_value(const char* section, const char* key, uint64_t initVal = 0);
	double*		allocate_value(const char* section, const char* key, double initVal = 0);

private:
	bool			_inited;
	std::string		_exchg;	//������
	std::string		_sync;
	wt_hashmap<std::string, uint64_t>	_secnames;

	bool			_stopped;
	StdThreadPtr	_worker;
	WtUftEngine*	_engine;
};

