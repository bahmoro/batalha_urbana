//PROJETO DE COMPUTAÇÃO GRAFICA 2021
//ALUNOS: Barbara Lopes Moro e Matheus Viera Zarate
//Professor: ADAILTON JOSE ALVES DA CRUZ


#include <GL/glut.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

GLint tamPredio[5]; //vetor usado para guardar as alturas geradas aleatoriamente
GLint lineAmount = 50; //triangulos usados para desenhar o circulo
GLfloat twicePi = 2.0 * 3.14;

//Desenha o predio
void Predio ()
{
    GLint aux = 0, controleCor = 0;
    for(GLint i = 0; i < 30; i = i + 6){
        tamPredio[aux] = (rand() % 9) + 1; //gera alturas aleatorias para os predios

        // gera as cores do predio
        if(controleCor == 0){
            glColor3f(0.7, 0.7, 0.7);
            controleCor = 1;

        }else{
            glColor3f(0.5, 0.5, 0.5);
            controleCor = 0;
        }

        //desenha o predio
        glBegin(GL_QUADS);
            glVertex2f (i, 0);
            glVertex2f (i, tamPredio[aux]);
            glVertex2f (6 + i, tamPredio[aux]);
            glVertex2f (6 + i, 0);
        glEnd();


        glColor3f(0, 0, 0);
        glLineWidth(2);
        for(GLint j = 0; j < tamPredio[aux]; j++){
            //Janela Esquerda

            glBegin(GL_LINES);
                glVertex2f (1.5 + i, 0.3 + j);
                glVertex2f (2.5 + i, 0.3 + j);
                glVertex2f (1.5 + i, 0.8 + j);
                glVertex2f (2.5 + i, 0.8 + j);
                glVertex2f (1.5 + i, 0.3 + j);
                glVertex2f (1.5 + i, 0.8 + j);
                glVertex2f (2.5 + i, 0.3 + j);
                glVertex2f (2.5 + i, 0.8 + j);
            glEnd();

            //Janela Direita
            glBegin(GL_LINES);
                glVertex2f (3.5 + i, 0.3 + j);
                glVertex2f (4.5 + i, 0.3 + j);
                glVertex2f (3.5 + i, 0.8 + j);
                glVertex2f (4.5 + i, 0.8 + j);
                glVertex2f (3.5 + i, 0.3 + j);
                glVertex2f (3.5 + i, 0.8 + j);
                glVertex2f (4.5 + i, 0.3 + j);
                glVertex2f (4.5 + i, 0.8 + j);
            glEnd();

        }
        aux ++;
    }

}

void Canhao1(){

    GLint i;
	GLfloat radius = 0.18; //radius

    //BASE DO CANHAO
    glColor3f(1,0.5,0);
    glBegin(GL_QUADS);
        glVertex2f (1, 0.4 + tamPredio[0]);
        glVertex2f (3, 0.4 + tamPredio[0]);
        glVertex2f (3, 0.8 + tamPredio[0]);
        glVertex2f (1, 0.8 + tamPredio[0]);
    glEnd();

    glColor3f(0,0,0);
    //RODA ESQUEDA
	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount; i++) {
			glVertex2f(
              1.3 + (radius * cos(i *  twicePi / lineAmount)),
              0.2 + tamPredio[0] + (radius * sin(i * twicePi / lineAmount)));
		}
    glEnd();

    //RODA DIREITA
	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount; i++) {
			glVertex2f(
              2.6 + (radius * cos(i *  twicePi / lineAmount)),
              0.2 + tamPredio[0] + (radius * sin(i * twicePi / lineAmount)));
		}
    glEnd();

    //interior das rodas
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount; i++) {
			glVertex2f(
              2.6 + ((radius - 0.1) * cos(i *  twicePi / lineAmount)),
              0.2 + tamPredio[0] + ((radius - 0.1) * sin(i * twicePi / lineAmount)));
		}
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount; i++) {
			glVertex2f(
              1.3 + ((radius - 0.1) * cos(i *  twicePi / lineAmount)),
              0.2 + tamPredio[0] + ((radius - 0.1)* sin(i * twicePi / lineAmount)));
		}
    glEnd();

    //CIRCULO EXTERIOR DA CABEÇA DO CANHAO
    glColor3f(1,0.5,0);
    glBegin(GL_TRIANGLE_FAN);
        for(i = 0; i <= lineAmount; i++) {
            glVertex2f(
              2 + (0.5 * cos(i *  twicePi / lineAmount)),
              1.3 + tamPredio[0] + (0.5 * sin(i * twicePi / lineAmount)));
        }
    glEnd();

    //CANO DO CANHAO
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
        glVertex2f (2, 1.2 + tamPredio[0]);
        glVertex2f (3, 1.8 + tamPredio[0]);
        glVertex2f (3, 2.2 + tamPredio[0]);
        glVertex2f (2, 1.6 + tamPredio[0]);
    glEnd();

    glColor3f(0,0,0);

    //CIRCULO DA CABEÇA DO CANO DO CANHAO
    glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
              2 + (0.35 * cos(i *  twicePi / lineAmount)),
              1.3 + tamPredio[0] + (0.35 * sin(i * twicePi / lineAmount)));
		}
    glEnd();

    //CIRCULO INTERNO DA CABEÇA DO CANHAO
    glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
              3 + (0.24 * cos(i *  twicePi / lineAmount)),
              2 + tamPredio[0] + (0.24 * sin(i * twicePi / lineAmount)));
		}
    glEnd();

}



void Canhao2(){
    GLint i;
	GLfloat radius = 0.18; //radius

    //BASE DO CANHAO
    glColor3f(0, 0.5, 0);
    glBegin(GL_QUADS);
        glVertex2f (27, 0.4 + tamPredio[4]);
        glVertex2f (29, 0.4 + tamPredio[4]);
        glVertex2f (29, 0.8 + tamPredio[4]);
        glVertex2f (27, 0.8 + tamPredio[4]);
    glEnd();

    glColor3f(0, 0, 0);

    //RODA ESQUERDA
	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount; i++) {
			glVertex2f(
              27.3 + (radius * cos(i *  twicePi / lineAmount)),
              0.2 + tamPredio[4] + (radius * sin(i * twicePi / lineAmount)));
		}
    glEnd();


    //RODA DIREITA
	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount; i++) {
			glVertex2f(
              28.6 + (radius * cos(i *  twicePi / lineAmount)),
              0.2 + tamPredio[4] + (radius * sin(i * twicePi / lineAmount)));
		}
    glEnd();

    //interior das rodas
    glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount; i++) {
			glVertex2f(
              27.3 + ((radius - 0.1) * cos(i *  twicePi / lineAmount)),
              0.2 + tamPredio[4] + ((radius - 0.1) * sin(i * twicePi / lineAmount)));
		}
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount;i++) {
			glVertex2f(
              28.6 + ((radius - 0.1) * cos(i *  twicePi / lineAmount)),
              0.2 + tamPredio[4] + ((radius - 0.1) * sin(i * twicePi / lineAmount)));
		}
    glEnd();

    //CIRCULO EXTERIOR DA CABEÇA DO CANHAO
    glColor3f(0, 0.5, 0);
    glBegin(GL_TRIANGLE_FAN);
    for(i = 0; i <= lineAmount;i++) {
        glVertex2f(
          28 + (0.5 * cos(i *  twicePi / lineAmount)),
          1.3 + tamPredio[4] + (0.5 * sin(i * twicePi / lineAmount)));
    }
    glEnd();

    //CANO DO CANHAO
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
        glVertex2f (28, 1.2 + tamPredio[4]);
        glVertex2f (27, 1.8 + tamPredio[4]);
        glVertex2f (27, 2.2 + tamPredio[4]);
        glVertex2f (28, 1.6 + tamPredio[4]);
    glEnd();

    //CIRCULO INTERIOR DA CABEÇA DO CANHAO
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount; i++) {
			glVertex2f(
              28 + (0.35 * cos(i *  twicePi / lineAmount)),
              1.3 + tamPredio[4] + (0.35 * sin(i * twicePi / lineAmount)));
		}
    glEnd();

    //CIRCULO DA CABEÇA DO CANO
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount; i++) {
			glVertex2f(
              27 + (0.24 * cos(i *  twicePi / lineAmount)),
              2 + tamPredio[4] + (0.24 * sin(i * twicePi / lineAmount)));
		}
    glEnd();

}
//desenha o sol
void Sol(){
    GLint i;
	GLfloat radius = 1.5; //radius

    glColor3f(1, 1, 0);
	glBegin(GL_TRIANGLE_FAN);
		for(i = 0; i <= lineAmount; i++) {
			glVertex2f(
              29.5 + (radius * cos(i *  twicePi / lineAmount)),
              15 + (radius * sin(i * twicePi / lineAmount)));
		}
    glEnd();
}

//desenha as 3 nuvens

void Nuvem(){
    GLint i;
	GLfloat radius = 1; //radius

    glColor3f(1,1,1);
    for(GLint j = 0; j <= 21; j = j + 7){

       glBegin(GL_TRIANGLE_FAN);
            for(i = 0; i <= lineAmount;i++) {
                glVertex2f(
                   3 + j + (0.8 * cos(i *  twicePi / lineAmount)),
                  13 + (0.8* sin(i * twicePi / lineAmount)));
            }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
            for(i = 0; i <= lineAmount;i++) {
                glVertex2f(
                  4 + j + (radius * cos(i *  twicePi / lineAmount)),
                  13 + (radius* sin(i * twicePi / lineAmount)));
            }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
            for(i = 0; i <= lineAmount;i++) {
                glVertex2f(
                  5 + j + (0.8 * cos(i *  twicePi / lineAmount)),
                  13 + (0.8 * sin(i * twicePi / lineAmount)));
            }
        glEnd();
    }
}

//Chama o desenho
void Desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    Predio();
    Canhao1();
    Canhao2();
    Sol();
    Nuvem();
    glutSwapBuffers();
}

//Define configuracoes da janela
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização
    glClearColor(0.7, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 30.0, 0.0, 15.0);
}


//Chamada do main
int main(void)
{
    //E por fim a chamada para o OpenGL
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //Modo para nao exibir rastros na tela
    glutInitWindowSize (1200, 700); //Tamanho da janela
    glutInitWindowPosition (100, 0);  //Localizacao inicial da janela
    glutCreateWindow("Batalha Urbana"); //Nome da janela
    Inicializa(); //Define cor de fundo da janela, largura e altura
    glutDisplayFunc(Desenha); //Chama o desenho
    glutMainLoop();
    //Final das funcoes do OpenGL

}
