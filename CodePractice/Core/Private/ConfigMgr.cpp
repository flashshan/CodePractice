#include <iostream>

#include "ThirdLibrary/tinyxml2/tinyxml2.h"
#include "Core/ConfigMgr.h"

using namespace tinyxml2;


void ConfigMgr::LoadConfigFromXml()
{
	XMLDocument *doc = new XMLDocument();
	const char* xmlFilePath = "ProblemCfg.xml";

	doc->LoadFile(xmlFilePath);
	if (doc->ErrorID() != 0)
	{
		cout << "Open file " << xmlFilePath << " failed" << endl;
		return;
	}

	for (XMLElement* ele = doc->FirstChildElement("Collection")->FirstChildElement(); ele; ele = ele->NextSiblingElement())
	{
		if (strcmp(ele->Value(),"Class") != 0)
			continue;

		ProblemClassConfig *tempTypeConfig = new ProblemClassConfig();
		const char *enableValue;
		ele->QueryStringAttribute("Enable", &enableValue);
		tempTypeConfig->Enable = (strcmp(enableValue,"True") == 0);

		const char *nameValue;
		ele->QueryStringAttribute("Name", &nameValue);
		ConfigMap.insert(pair<string, ProblemClassConfig*>(string(nameValue), tempTypeConfig));

		if (tempTypeConfig->Enable)
		{
			for (XMLElement *problemEle = ele->FirstChildElement(); problemEle; problemEle = problemEle->NextSiblingElement())
			{
				if (strcmp(problemEle->Value(), "Problem") != 0)
					continue;

				const char *enableValueStr;
				problemEle->QueryStringAttribute("Enable", &enableValueStr);
				if (strcmp(enableValueStr, "True") == 0)
				{
					const char *nameValueStr;
					problemEle->QueryStringAttribute("Name", &nameValueStr);
					tempTypeConfig->ProblemSet.insert(string(nameValueStr));
				}
			}
		}
	}

	delete doc;
}

void ConfigMgr::ClearConfig()
{
	for (auto it = ConfigMap.begin(); it != ConfigMap.end(); ++it)
	{
		delete it->second;
	}
}

ProblemClassConfig* ConfigMgr::GetTypeConfig(string classStr) const
{
	auto it = ConfigMap.find(classStr);
	if (it == ConfigMap.end())
	{
		cout << "Error: 找不到对应的Class: " << classStr << endl;
		return nullptr;
	}
	return it->second;
}