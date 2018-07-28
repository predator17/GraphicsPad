#pragma once

#include <QtOpenGL\qgl.h>

class MyGLWindow : public QGLWidget 
{
protected:
	void initializeGL();
	void paintGL();
};

