#ifndef _CUBO_H_
#define _CUBO_H_

#include "figura.h"

struct cubo : public figura{
	cubo();
	cubo(float t);
	cubo(float t,float color);
};

#endif