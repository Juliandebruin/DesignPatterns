#pragma once
#include "LanguageLib.h"
#include "ENLib.h"
#include "NLLib.h"

class FactoryLangLib
{
public:
	FactoryLangLib() {
		libs = { {"en", new ENLib()}, {"nl", new NLLib()} };
	}
	virtual ~FactoryLangLib() {}
	
	LanguageLib* CreatePrototype(string type) {
		return libs[type]->Clone();
	}
private:
	map< string, LanguageLib*> libs;
	
};

