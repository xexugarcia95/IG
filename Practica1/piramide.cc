#include "piramide.h"

piramide::piramide(){
	vertice.push_back(_vertex3f(-50.0f,-50.0f,-50.0f));
	vertice.push_back(_vertex3f(-50.0f,-50.0f,50.0f));
	vertice.push_back(_vertex3f(50.0f,-50.0f,50.0f));
	vertice.push_back(_vertex3f(50.0f,-50.0f,-50.0f));
	vertice.push_back(_vertex3f(0.0f,50.0f,0.0f));
	
	indice.push_back(_vertex3i(0,3,4));
	indice.push_back(_vertex3i(0,1,4));
	indice.push_back(_vertex3i(1,2,4));
	indice.push_back(_vertex3i(2,3,4));
	indice.push_back(_vertex3i(1,2,0));
	indice.push_back(_vertex3i(2,3,0));

	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	colors.push_back(_vertex3f(90,0,0));
	
	colors_2.push_back(_vertex3f(0,0,85));
	colors_2.push_back(_vertex3f(0,0,85));
	colors_2.push_back(_vertex3f(0,0,85));
	colors_2.push_back(_vertex3f(0,0,85));
	colors_2.push_back(_vertex3f(0,0,85));

	ip.push_back(_vertex3i(0,3,4));
	ic.push_back(_vertex3i(0,1,4));
	ip.push_back(_vertex3i(1,2,4));
	ic.push_back(_vertex3i(2,3,4));
	ip.push_back(_vertex3i(1,2,0));
	ic.push_back(_vertex3i(2,3,0));


	v=&vertice[0];
	i=&indice[0];

	ver=5;
	tri=6;

	c=&colors[0];
	c2=&colors_2[0];

	impar=&ic[0];
	par=&ip[0];


}