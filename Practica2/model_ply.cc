#include "model_ply.h"



model_ply::model_ply(){
	
}

model_ply::model_ply(char *archivo){
	vector<float> vertices;
	vector<int> indices;

	_file_ply obj;


	obj.open(archivo);

	obj.read(vertices,indices);

	for(int k=0;k<vertices.size();k+=3){
		_vertex3f v;
		v.x=20*vertices[k];
		v.y=20*vertices[k+1];
		v.z=20*vertices[k+2];

		vertice.push_back(v);
		colors.push_back(_vertex3f(90,0,0));
		colors_2.push_back(_vertex3f(0,0,90));
	}

	for(int j=0;j<indices.size();j+=3){
		_vertex3i cara;
		cara._0=indices[j];
		cara._1=indices[j+1];
		cara._2=indices[j+2];

		indice.push_back(cara);

		if(j%2==0) ic.push_back(cara);
		else	ip.push_back(cara);
	}
	

	setIndiAlternas(indice);

	setColor();

	v=&vertice[0];
	i=&indice[0];
}