#ifndef __ASK3_H__
#define __ASK3_H__

#include "std_lib_facilities.h"
#include <assert.h>


using namespace std;

class Rectangle {
private:
	float len,wid;
public:
	Rectangle(int _len, int _wid) : len(_len), wid(_wid) {};
	void setL(int _len) { assert(_len >= 0 && _len <= 20.0); len = _len; };
	void setW(int _wid) { assert(_wid >= 0 && _wid <= 20.0); wid = _wid; };
	float getL() { return len; };
	float getW() { return wid; };
};


#endif