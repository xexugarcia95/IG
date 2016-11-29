#ifndef _FIGURA_H_
#define _FIGURA_H_

#include <GL/glut.h>
#include <stdlib.h>
#include <vertex.h>

#include <vector>


struct figura{

	vector<_vertex3f> vertice; //vector de vertices
	vector<_vertex3i> indice; //vector de aristas
	//vector<_vertex3f> vertice_normal;
	//vector<_vertex3i> indice_normal;
	vector<_vertex3f> colors; //vector 1º de vertices de colores
	vector<_vertex3f> colors_2; //vector 2º de vertices de colores
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


	void dibuja(int m);
	void setVertices(vector<_vertex3f> vertices);
	void setIndices(vector<_vertex3i> indices);
	void setIndiAlternas(vector<_vertex3i> alterna);
	vector<_vertex3f> getVertices();
	void setColor();
	GLenum getModo(int mode);
};

#endif
