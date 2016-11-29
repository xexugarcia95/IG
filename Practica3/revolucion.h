#ifndef _REVOLUCION_H_
#define _REVOLUCION_H_

#include "figura.h"

struct revolucion : public figura{
	vector<_vertex3f> vertices_normales;
	vector<_vertex3i> indices_normales;
	//bool tapas;
	revolucion(vector<_vertex3f> perfil,int steps,bool tapas,float an);
	void dibujar(int modo);
	void key(unsigned char boton);
	void dibujarNormales()const;
	void setIndicesNormales(vector<_vertex3i> indice);
	void setVerticesNormales(vector<_vertex3f> vertice);
	float gradosRadianes(float valor);
	_vertex3f rotarX(_vertex3f v,float angulo);
	_vertex3f rotarY(_vertex3f v,float angulo);
	_vertex3f rotarZ(_vertex3f v,float angulo);
	void liberar();
	void reservar(int vertices,int indices);
	
	//vector<_vertex3f> getVertices();
	
	void generaPerfil(vector<_vertex3f> perfil,int steps,bool tapas,float an);
	void generaNormales();
	void generaNormalesIndices();
	void generaNormalesVertices();
};

#endif