#include "figura.h"

figura::figura(){


}



void figura::dibuja(figura::modo m)const{
	GLenum modo;
	switch(m){
		case figura::PUNTOS:
			modo=GL_POINT;
			glPointSize(3);
			break;
		case figura::ALAMBRE:
			modo=GL_LINE;
			break;
		default:
			modo=GL_FILL;
			break;
	}


	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	//glEnable(GL_CULL_FACE);
	glVertexPointer(3,GL_FLOAT,0,v);
	glPolygonMode(GL_FRONT_AND_BACK,modo);
	//glNormalPointer(3,GL_FLOAT,v);
	
	if(m==AJEDREZ){
		

		glColorPointer(3,GL_FLOAT,0,c);
		glDrawElements(GL_TRIANGLES,(3*tri)/2,GL_UNSIGNED_INT,par);
		glColorPointer(3,GL_FLOAT,0,c2);
		glDrawElements(GL_TRIANGLES,(3*tri)/2,GL_UNSIGNED_INT,impar);
	}else{
		glColorPointer(3,GL_FLOAT,0,c);
		glDrawElements(GL_TRIANGLES,3*tri,GL_UNSIGNED_INT,i);	
	}
	
	
		

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	
	
}