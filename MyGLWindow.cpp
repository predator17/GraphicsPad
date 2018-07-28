#include <GL\glew.h>
#include "MyGLWindow.h"

void MyGLWindow::initializeGL()
{
	glewInit();

	//GLfloat verts[]
	//{
	//	 0.0f,  1.0f,
	//	-1.0f, -1.0f,
	//	 1.0f, -1.0f
	//};

	GLfloat verts[]
	{
		0.0f,  0.0f,
		1.0f, 0.0f, 0.0f,

		1.0f,  1.0f,
		0.0f, 1.0f, 0.0f,

	   -1.0f,  1.0f,
	    0.0f, 0.0f, 1.0f,

	   -1.0f, -1.0f,
	    0.0f, 0.0f, 0.0f,

        1.0f, -1.0f,
		0.0f, 0.0f, 0.0f
	};

	// specify the name of the buffer, id represents the buffer object 
	GLuint myBufferID;
	// generate 1 buffer and stores it inside the id, where id represent the buffer object
	glGenBuffers(1, &myBufferID); // "1" is the number of buffers to be generated 

	// OpenGL has many types of buffer objects and the buffer type of a vertex buffer object is GL_ARRAY_BUFFER.
	// can bind the newly created buffer (which is represented by "myBufferID") to the GL_ARRAY_BUFFER target with the glBindBuffer function
	glBindBuffer(GL_ARRAY_BUFFER, myBufferID);

	// From that point on any buffer calls we make (on the GL_ARRAY_BUFFER target) 
	// will be used to configure the currently bound buffer, which is myBufferID. 

	// Then we can make a call to glBufferData function, which really creates the buffer object 
	// that copies the previously defined vertex data into the buffer's memory
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	
	// glBufferData is a function specifically targeted to copy user-defined data into the currently bound buffer. 
	// Its first argument is the type of the buffer we want to copy data into: 
	//     the vertex buffer object currently bound to the GL_ARRAY_BUFFER target. 
	// The second argument specifies the size of the data (in bytes) we want to pass to the buffer; 
	//     a simple sizeof of the vertex data suffices. 
	// The third parameter is the actual data we want to send.

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*5, 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float)*2) );

	GLushort indices[] = { 0,1,2, 0,3,4};
	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}


void MyGLWindow::paintGL()
{
	//glClearColor(0, 1, 1, 1);
	//glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, width(), height());
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
}


