#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "figura.h"
#include "escena.h"
#include "model_ply.h"
#include "file_ply_stl.h"
#include "cubo.h"
#include "tetraedro.h"
#include "piramide.h"
#include "revolucion.h"
#include "peon.h"



class Escena {
private:
// tamaño de los ejes
#define AXIS_SIZE 5000
Ejes ejes;
int mode; //modo
int type; //figura
int tamanio;
bool tapas;
int segmentos = 20;
// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformación de cámara
	void change_projection();
	void change_observer();



public:

	//figura figu;
	//tetraedro tetra(tamanio);
	//cubo cu;
	//piramide pi;
	//peon p;
	//revolucion re = revolucion(p.getVertices(),segmentos,tapas);
	//model_ply ply = model_ply("beethoven.ply");
	
     Escena();
	void inicializar(int UI_window_width,int UI_window_height,int tam);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);

	//Modificadores de mode y type
	void setMode(int m);
	void setType(int t);
	void setTapas();
	int getMode();
	int getType();
	bool getTapas();
	int getSegmentos();
	void masSegmentos();
	void menosSegmentos();
	void setTamanio(int t);
	int getTamanio();

	
};
#endif
