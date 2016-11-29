#ifndef _COLOR_H_
#define _COLOR_H_
#include <GL/glut.h>
#include <stdlib.h>
#include <vertex.h>
#include <vector>

struct color{
	float r,g,b,valor;
	vector<_vertex3f> vertice;
	vector<_vertex3i> indice;

	color();
	void colorear()const;
};

#endif