#include "piramide.h"

piramide::piramide(){
	

}

piramide::piramide(float t ){
	vertice.push_back(_vertex3f(-t,-t,-t));
	vertice.push_back(_vertex3f(-t,-t,t));
	vertice.push_back(_vertex3f(t,-t,t));
	vertice.push_back(_vertex3f(t,-t,-t));
	vertice.push_back(_vertex3f(0.0f,t,0.0f));
	
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


	setIndiAlternas(indice);

	setColor();

	v=&vertice[0];
	i=&indice[0];

}