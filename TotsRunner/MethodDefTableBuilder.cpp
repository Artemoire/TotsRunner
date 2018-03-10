#include "MethodDefTableBuilder.h"

void MethodDefTableBuilder::add(MethodDef * def)
{
	defs.push_back(def);
}

starray<MethodDef*>* MethodDefTableBuilder::build()
{
	starray<MethodDef*> * defs = new starray<MethodDef*>(this->defs.size());
	for (int i = 0; i < this->defs.size(); i++)
		defs->values[i] = this->defs[i];
	this->defs.clear();
	return defs;
}
