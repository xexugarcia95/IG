#include "figura.h"

figura::figura(){


}


GLenum figura::getModo(int mode){
	GLenum m;
	switch(mode){
		case 1:
			m=GL_POINT;
		break;
		case 2:
			m=GL_LINE;
		break;
		default:
			m=GL_FILL;
	}
	return m;
}


void figura::dibuja(int m){
	GLenum modo=getModo(m);
	switch(m){
		case 1: //puntos
			modo=GL_POINT;
			break;
		case 2: //alambre
			modo=GL_LINE;
			break;
		default: //resto 
			modo=GL_FILL;
			break;
	}


	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glPointSize(3);
	//glEnable(GL_CULL_FACE);
	glVertexPointer(3,GL_FLOAT,0,v);
	if(m==5){
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glColorPointer(3,GL_FLOAT,0,v);
		glDrawElements(GL_TRIANGLES,3*indice.size(),GL_UNSIGNED_INT,i);
	}
	glPolygonMode(GL_FRONT_AND_BACK,modo);
	//glNormalPointer(3,GL_FLOAT,v);
	
	if(m==4){
		

		glColorPointer(3,GL_FLOAT,0,c);
		glDrawElements(GL_TRIANGLES,(3*indice.size())/2,GL_UNSIGNED_INT,impar);
		glColorPointer(3,GL_FLOAT,0,c2);
		glDrawElements(GL_TRIANGLES,(3*indice.size())/2,GL_UNSIGNED_INT,par);
	}else{
		glColorPointer(3,GL_FLOAT,0,c);
		glDrawElements(GL_TRIANGLES,3*indice.size(),GL_UNSIGNED_INT,i);	
	}
	
	
		

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);	
}


	void figura::setVertices(vector<_vertex3f> vertices){
		vertice=vertices;
		v=&vertice[0];
	}

	void figura::setIndices(vector<_vertex3i> indices){
		indice=indices;
		i=&indice[0];
	}

	vector<_vertex3f> figura::getVertices(){
		return vertice;
	}

	void figura::setIndiAlternas(vector<_vertex3i> alterna){
		for(int i=0;i<indice.size();i++){
			ip.push_back(indice[i]);
			i++;
			ic.push_back(indice[i]);
		}
		par=&ip[0];
		impar=&ic[0];
	}

	void figura::setColor(float numero){
		
		for(int i=0;i<vertice.size();i++){
			colors.push_back(_vertex3f(numero,0.0f,0.0f));
			colors_2.push_back(_vertex3f(0.0f,0.0f,numero));
		}
		c=&colors[0];
		c2=&colors_2[0];
	}


