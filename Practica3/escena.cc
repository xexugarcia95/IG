#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"



Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);
    setType(3);
    setMode(3);
   
   
}

void Escena::inicializar(int UI_window_width,int UI_window_height,int tam) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);
	tamanio=tam;

}

//***************************************************************************
// Modificadores
//***************************************************************************
void Escena::setMode(int m){
	mode=m;
}
void Escena::setType(int t){
	type=t;
}
int Escena::getMode(){
	return mode;
}
int Escena::getType(){
	return type;
}
void Escena::setTamanio(int t){
	tamanio=t;
}
int Escena::getTamanio(){
	return tamanio;
}

void Escena::setTapas(){
	tapas=!tapas;
}

bool Escena::getTapas(){
	return tapas;
}

void Escena::masSegmentos(){
	segmentos++;
}

int Escena::getSegmentos(){
	return segmentos;
}

void Escena::menosSegmentos(){
	segmentos--;
}

void Escena::rotacion_inversa(){
	if(rotate>0.0)
		rotate-=1.0;
}


void Escena::rotacion(){
	if(rotate<90.0)
		rotate+=1.0;
}

float Escena::getRotacion(){
	return rotate;
}

void Escena::moverA(){
	if(movimientoA<100.0)
		movimientoA+=1.0;
}

void Escena::retrocesoA(){
	if(movimientoA>0.0)
		movimientoA-=1.0;
}

float Escena::getA(){
	return movimientoA;
}

void Escena::moverB(){
	if(movimientoB<100.0)
		movimientoB+=1.0;
}

void Escena::retrocesoB(){
	if(movimientoB>0.0)
		movimientoB-=1.0;
}

float Escena::getB(){
	return movimientoB;
}

void Escena::masPuerta(){
	if(puerta<1.4)
		puerta+=0.1;
}

void Escena::menosPuerta(){
	if(puerta>0)
		puerta-=0.1;
}
	
float Escena::getPuerta(){
	return puerta;
}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {

	model_ply ply = model_ply("beethoven.ply");
	peon p;
	revolucion re(p.getVertices(),getSegmentos(),getTapas(),360);
	modelo_jerarquico modelo;
	cubo cu(getTamanio());

	if(getType()==1){
		
		ply.dibuja(getMode());
	}else if(getType()==2){
		
		re.dibuja(getMode());
	}else if(getType()==3){
		
		modelo.dibujar_modelo(getMode(),getRotacion(),getA(),getB(),getPuerta());
	}else if(getType()==4){
		cu.dibuja(getMode());
	}

}
	
		



void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
	glutSwapBuffers();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

    std::cout << "Tecla" << Tecla1<< std::endl;
	if (toupper(Tecla1)=='Q') return 1;
	else return 0;
	
		
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}




