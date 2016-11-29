#include "cubo.h"

cubo::cubo(){
	vertice.push_back(_vertex3f(50.0f,50.0f,0.0f));
	vertice.push_back(_vertex3f(0.0f,50.0f,0.0f));
	vertice.push_back(_vertex3f(0.0f,0.0f,0.0f));
	vertice.push_back(_vertex3f(50.0f,0.0f,0.0f));
	vertice.push_back(_vertex3f(50.0f,0.0f,-50.0f));	
	vertice.push_back(_vertex3f(50.0f,50.0f,-50.0f));
	vertice.push_back(_vertex3f(0.0f,50.0f,-50.0f));
	vertice.push_back(_vertex3f(0.0f,0.0f,-50.0f)); 
	

	indice.push_back(_vertex3i(0,1,2));
	indice.push_back(_vertex3i(2,3,0));
	indice.push_back(_vertex3i(0,3,4));
	indice.push_back(_vertex3i(4,5,0));
	indice.push_back(_vertex3i(4,5,6));
	indice.push_back(_vertex3i(6,7,4));
	indice.push_back(_vertex3i(6,1,2));
	indice.push_back(_vertex3i(2,7,6));
	indice.push_back(_vertex3i(0,5,6));
	indice.push_back(_vertex3i(6,1,0));
	indice.push_back(_vertex3i(2,3,4));
	indice.push_back(_vertex3i(4,7,2));


	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	
	colors_2.push_back(_vertex3f(0,0,90));
	colors_2.push_back(_vertex3f(0,0,90));
	colors_2.push_back(_vertex3f(0,0,90));
	colors_2.push_back(_vertex3f(0,0,90));
	colors_2.push_back(_vertex3f(0,0,90));
	colors_2.push_back(_vertex3f(0,0,90));
	colors_2.push_back(_vertex3f(0,0,90));
	colors_2.push_back(_vertex3f(0,0,90));

	ip.push_back(_vertex3i(0,1,2));
	ic.push_back(_vertex3i(2,3,0));
	ip.push_back(_vertex3i(0,3,4));
	ic.push_back(_vertex3i(4,5,0));
	ip.push_back(_vertex3i(4,5,6));
	ic.push_back(_vertex3i(6,7,4));
	ip.push_back(_vertex3i(6,1,2));
	ic.push_back(_vertex3i(2,7,6));
	ip.push_back(_vertex3i(0,5,6));
	ic.push_back(_vertex3i(6,1,0));
	ip.push_back(_vertex3i(2,3,4));
	ic.push_back(_vertex3i(4,7,2));

	v=&vertice[0];
	i=&indice[0];

	ver=8;
	tri=12;

	c=&colors[0];
	c2=&colors_2[0];

	impar=&ic[0];
	par=&ip[0];

}