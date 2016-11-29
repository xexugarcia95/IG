#include "modelo_jerarquico.h"



modelo_jerarquico::modelo_jerarquico(){	
	
}

//----------------ESTRUCTURA PRINCIPAL----------------

void modelo_jerarquico::pared_trasera(int modo){
	glPushMatrix();
	glTranslatef(5,0,-120);
	glScalef(3.5,2.0,0.1);
	cu.dibuja(modo);
	glPopMatrix();

}

void modelo_jerarquico::pared_lateral_izq(int modo){
	glPushMatrix();
	glTranslatef(5,0,0);
	glScalef(0.1,2.0,2.5);
	cu.dibuja(modo);
	glPopMatrix();
}

void modelo_jerarquico::pared_lateral_der(int modo){
	glPushMatrix();
	glTranslatef(180,0,0);
	glScalef(0.1,2.0,2.5);
	cu.dibuja(modo);
	glPopMatrix();
}

void modelo_jerarquico::suelo(int modo){
	glPushMatrix();
	glTranslatef(10,0,0);
	glScalef(3.4,0.1,2.5);
	cu.dibuja(modo);
	glPopMatrix();
}

void modelo_jerarquico::suelo2(int modo){
	glPushMatrix();
	glTranslatef(10,40,0);
	glScalef(3.4,0.1,2.4);
	cu.dibuja(modo);
	glPopMatrix();
}

void modelo_jerarquico::techo(int modo){
	glPushMatrix();
	glTranslatef(5,100,0);
	glScalef(3.6,0.1,2.5);
	cu.dibuja(modo);
	glPopMatrix();
}

void modelo_jerarquico::separador(int modo){
	glPushMatrix();
	glTranslatef(95,5,0);
	glScalef(0.2,0.7,2.5);
	cu.dibuja(modo);
	glPopMatrix();
}

void modelo_jerarquico::estructura(int modo){

	pared_lateral_izq(modo);

	pared_trasera(modo);

	pared_lateral_der(modo);

	suelo(modo);

	techo(modo);

	suelo2(modo);

	separador(modo);
}

//----------------CAJAS--------------------------

void modelo_jerarquico::cajon(int modo,float mov){
	glPushMatrix();
	glTranslatef(-110,48,mov);
	glScalef(0.55,0.34,1.2);
	glRotatef(270,1,0,0);
	pared_lateral_izq(modo);
	pared_trasera(modo);
	pared_lateral_der(modo);
	suelo(modo);
	techo(modo);
	glPopMatrix();
}

void modelo_jerarquico::cajon2(int modo,float mov){
	glPushMatrix();
	glTranslatef(5,48,mov);
	glScalef(0.5,0.34,1.2);
	glRotatef(270,1,0,0);
	pared_lateral_izq(modo);
	pared_trasera(modo);
	pared_lateral_der(modo);
	suelo(modo);
	techo(modo);
	
	glPopMatrix();
}



void modelo_jerarquico::cajones(int modo,float mov,float mov2){

	cajon(modo,mov);
	cajon2(modo,mov2);
}

//----------PUERTA------------------------

void modelo_jerarquico::puerta(int modo,float rotacion,float variable){
	
	glPushMatrix();
	
	glTranslatef(-110,50,0);
	glRotatef(rotacion,1,0,0);
	glScalef(4.1,variable,0.1);
	cu.dibuja(modo);
	glPopMatrix();
}

void modelo_jerarquico::dibujar_modelo(int modo,float r,float mov,float mov2,float variable){
	
	glPushMatrix();
	//Puerta
	puerta(modo,r,variable);
	//Cajas
	glPushMatrix();
	cajones(modo,mov,mov2);
	glPopMatrix();
	//Estructura
	glPushMatrix();
	glTranslatef(-120,0,0);
	glScalef(1.2,1.2,1);
	estructura(modo);
	glPopMatrix();
	glPopMatrix();
	
}

