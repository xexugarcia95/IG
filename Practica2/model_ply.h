#ifndef _MODEL_PLY_H_
#define _MODEL_PLY_H_

#include "figura.h"
#include "file_ply_stl.h"
#include <iostream>

using namespace std;

struct model_ply : public figura{


	model_ply();
	model_ply(char *archivo);
};

#endif