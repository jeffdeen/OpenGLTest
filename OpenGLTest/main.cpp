#include"shader.h"
#include<glut.h>
GLuint VAO;
GLuint VBO;

void init() {
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};
	//产生一个vao对象
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	Shader shader("vertex.vert", "fragment.frag");
	shader.Use();  
}

void display() {
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glFlush();
}

int main(int argc,char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(512, 512);
	//使用freeglut需要使用以下两行
	//glutInitContextVersion(4, 2);
	//glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("123");
	if (glewInit()) {
		std::cerr << "Unable to initialize GLEW ... exiting" << std::endl;
		exit(EXIT_FAILURE);
	}
	init();
	glutDisplayFunc(display);
	//glutIdleFunc(display);
	glutMainLoop();
	
}