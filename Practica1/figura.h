#ifndef _FIGURA_H_
#define _FIGURA_H_

#include <GL/glut.h>
#include <stdlib.h>
#include <vertex.h>

#include <vector>

//#include <color.h>

struct figura{

	vector<_vertex3f> vertice; //vector de vertices
	vector<_vertex3i> indice; //vector de aristas
	vector<_vertex3f> colors;
	vector<_vertex3f> colors_2;
	vector<_vertex3i> ic;
	vector<_vertex3i> ip;
	//color col; //vector de colores
	int ver; //numero de vertices
	int tri; //numero de triangulos
	_vertex3i *i;
	_vertex3f *v;
	_vertex3f *c;
	_vertex3f *c2;
	_vertex3i *impar;
	_vertex3i *par;

	

	figura();

	

	enum modo{
		PUNTOS,ALAMBRE,SOLIDO,AJEDREZ
	};




	void dibuja(modo m=SOLIDO)const;
};

#endif
