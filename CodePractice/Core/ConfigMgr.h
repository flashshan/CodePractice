#pragma once

#include <map>
#include <set>
#include <string>

using namespace std;


struct ProblemClassConfig
{
public:
	bool Enable = false;
	set<string> ProblemSet;
};


class ConfigMgr
{
public:
	void LoadConfigFromXml();	
	ProblemClassConfig* GetTypeConfig(string classStr) const;
	void ClearConfig();

private:
	map<string, ProblemClassConfig *> ConfigMap;

};
