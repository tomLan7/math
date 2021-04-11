#include "setTheory.h"


SetTheory::SetTheory()
{
}

int element::getID(){
	return (int)this;
}
bool element::equals(element* e)
{
	return getID()==e->getID();
}
SetTheory::~SetTheory()
{
}
bool SetTheory::isContain(element* e)
{
	return obj.find(e) != obj.end();
}
SetTheory& SetTheory::Union(SetTheory& fs){
	for(auto i:fs.obj){
		if (!isContain(i)) {
			obj.insert(i);
		}
	}
	return *this;
}
SetTheory& SetTheory::intersection(SetTheory& fs){
	for (auto i = obj.begin(); i != obj.end();) {
		if (!fs.isContain(*i)) {//如果不包含就删去
			i=obj.erase(i);
		}
		else {
			++i;
		}
	}
	return *this;
}
SetTheory& SetTheory::difference(SetTheory& fs)
{
	for (auto i = obj.begin(); i != obj.end();) {
		if (fs.isContain(*i)) {//如果不包含就删去
			i = obj.erase(i);
		}
		else {
			++i;
		}
	}
	return *this;
}

bool SetTheory::isEmpty()
{
	return obj.empty();
}

bool SetTheory::addElement(element* e)
{
	if (!isContain(e)) {
		obj.insert(e);
		return true;
	}else
	return false;
}
