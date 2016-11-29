#ifndef _MODELO_JERARQUICO_H_
#define _MODELO_JERARQUICO_H_

#include <GL/glut.h>
#include <stdlib.h>
#include <vertex.h>
#include <vector>
#include "revolucion.h"
#include "model_ply.h"
#include "figura.h"
#include "cubo.h"

struct modelo_jerarquico : public figura
{

	cubo cu=cubo(50);
	


	modelo_jerarquico();
	

	void dibujar_modelo(int modo,float r,float mov,float mov2,float variable);
	void estructura(int modo);
	void pared_trasera(int modo);
	void pared_lateral_izq(int modo);
	void pared_lateral_der(int modo);
	void techo(int modo);
	void suelo(int modo);
	void suelo2(int modo);
	void cajon(int modo,float mov);
	void cajon2(int modo,float mov);
	void separador(int modo);
	void cajones(int modo,float mov,float mov2);
	void puerta(int modo,float rotacion,float variable);
};

#endif