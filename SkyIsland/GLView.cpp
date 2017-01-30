#include "GLView.h"

namespace SIE {
	GLView::GLView(string viewName, int w, int h, bool initGLFW)
	{
		if (initGLFW)
			if (!glfwInit())
				cerr << "GLFW Init Error" << endl;

		glfwSetErrorCallback(GLFWerrorfun(&[this](int error, const char* description) {
			this->error_callback(error, description);
		}));

		win = glfwCreateWindow(w, h, viewName.c_str(), nullptr, nullptr);

		if (win == nullptr) {
			cerr << "Window Create Error" << endl;
			glfwTerminate();
		}

		glfwMakeContextCurrent(win);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
		{
			cerr << "GLEW Init Error" << endl;
		}

		glfwSwapInterval(1);

	}

	void GLView::setViewport() {
		int width, height;
		glfwGetFramebufferSize(this->win, &width, &height);

		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.5f, 100.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void GLView::destroyWindow() {
		glfwDestroyWindow(this->win);
		glfwTerminate();
	}

	void GLView::beginGL() {
		setViewport();

		glShadeModel(GL_SMOOTH);
		glClearColor(0.65f, 1.0f, 1.0f, 0.0f);
		glClearDepth(1.0f);

		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_ALPHA_TEST);
		glEnable(GL_BLEND);
		glDepthFunc(GL_LEQUAL);
		glAlphaFunc(GL_GREATER, 0.0);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void GLView::endGL() {
		glfwSwapBuffers(this->win);
		glfwPollEvents();
	}

	void GLView::error_callback(int error, const char* description) {
		cerr << "GLFW Error:" << "ID:" << error << description << endl;
	}
}
