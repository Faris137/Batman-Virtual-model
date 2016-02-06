#ifndef YP_LOADER_HPP
#define YP_LOADER_HPP

#include "CGLabmain.hpp"
#include <string>
#include <vector>

namespace CGLab01 {


class MyModelLoader
{
 public:
    MyModelLoader()
    {
    }
    ~MyModelLoader()
    {
    }
    //load a model and scale it
    void load(string filename, float scale = 1.0);
    void draw();
    void drawBack();
    void drawLogo(float rot);
 private:
    vector<GLfloat> vertices;
    vector<int> faces;
    GLuint batman; //for generating display list
    GLuint logo;
};

//------------------------------------
//the main program will call methods from this class
class MyVirtualWorld
{
 public:
    MyModelLoader      mymodelloader;

    long int timeold, timenew, elapseTime;
    float angel=0;

    void draw();

    void tickTime()
    {

     timenew    = glutGet(GLUT_ELAPSED_TIME);
     elapseTime = timenew - timeold;
     timeold    = timenew;
     angel +=     elapseTime*0.1;


    }


    void init()
    {
     glEnable(GL_LIGHTING);

     mymodelloader.load("data/batman.obj",10);
     mymodelloader.load("data/logo2.obj",1);
     timeold = glutGet(GLUT_ELAPSED_TIME);

    }
};

}; //end of namespace CGLab01

#endif //YP_CGLAB01_HPP
