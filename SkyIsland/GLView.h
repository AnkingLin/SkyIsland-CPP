#pragma once
#include "stdinc.h"
namespace SIE {
	class GLView
	{
	public:
		GLFWwindow *win;

		GLView(std::string viewName, int w, int h, bool initGLFW);

		void setViewport();

		virtual void destroyWindow();
		virtual void beginGL();
		virtual void endGL();
		virtual void error_callback(int error, const char* description);
	};
}

