#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<Mmsystem.h>                   //To Use Sound
#include <string>                      //Use String
using std::string;                     //Use String
#define STROKEFONT  GLUT_STROKE_ROMAN
///..........................................VARIABLE....................................................///

///System///
int DisplaySizeX = 50;
int DisplaySizeY = 30;
string FileLocation = "E:\\Study Note\\Computer Graphics\\Project Proposal\\Wonders of Galaxy with Rocket Journey\\sound\\";
string BackgroundMusic = "BackgroundMusic.wav";
string MusicAfterLaunch = "MusicAfterLaunch.wav";
///Animations///
//Tesla Car
GLfloat TeslaCarPosition = -70;
GLfloat TeslaCarMoveSpeed = 0.35f;
GLfloat TeslaCarAngle = 0;
//Air Plane
GLfloat AirPlanePosition = 90;
GLfloat AirPlaneMoveSpeed = 0.35f;
GLfloat AirPlaneAngle = 0;
//Background
GLfloat BackgroundPosition = 0;
GLfloat BackgroundMoveSpeed = 0.185f;
GLfloat FinalDestination =0;
bool isProcessing = false;
//Rocket
GLfloat RocketPosition = 0;
GLfloat RocketMoveSpeed = 0.15f;
GLfloat RocketAngle = 0;
GLfloat RocketSpinSpeed = 0.35f;
GLfloat RocketSize = 1;
GLfloat RocketSizeChanger = 0.001;
bool isRocketinGalaxy = false;
bool canRocketControl = false;
//Rocket Controls
GLfloat RocketPositionY = 0;
//Rocket Extra Animation
GLfloat RocketWindowAngle = 0;
GLfloat RocketWindowSpinSpeed = 0.35f;
GLfloat RocketWindowSpinSpeedFixed = 0.35f;
//Rocket Smoke
GLfloat RocektSmokeSize = 0.25;
GLfloat RocektSmokeSizeChanger = 0.005;
bool isStartRocketSmoke = false;
//Stars
GLfloat StarsPosition = 0;
GLfloat StarsMoveSpeed = 0.05f;
GLfloat StarsAngel = 0;
//Tong
int TongMaxCharecter = 4;
int TongCurrentCharecter = 0;
//NASA
GLfloat NasaCircleAngle = 0;
GLfloat NasaCircleSpinSpeed = 0.35f;
//Cloud
GLfloat CloudSize = 1;
GLfloat CloudSizeChanger = 0.0025;
bool isCloudSmall = false;
//Tower
GLfloat TowerLightAngle = 90;
GLfloat TowerLightSpinSpeed = 0.35f;
bool isTowerLightPositive = true;
//Big Planet
GLfloat BigPlanetPosition = 110;
GLfloat BigPlanetMoveSpeed = 0.35f;
//Small Planet
GLfloat SmallPlanetPosition = 100;
GLfloat SmallPlanetMoveSpeed = 0.085f;
//Robot
GLfloat RobotPosition = 0;
GLfloat RobotMoveSpeed = 0.03f;
GLfloat RobotAngle = 0;
bool isRobotRight = false;

///....................................USABLE FUNCTION...................................................///

///Circle///
void Circle(float radius,int steps,float X,float Y,int CC1,int CC2=0,int CC3=0,int CC4=0)
{

    float Radius = radius;              //Circle's Radius
    int Steps = steps;                  //Increase to get Smooth Circle
    float Pi=3.1416f;                   //PI
    glPushMatrix();
    glTranslatef(X, Y, 0);              //Move Circle Along Axes
    glBegin(GL_POLYGON);
    if(CC2 == 0 && CC3 == 0 && CC4 == 0) glColor3ub(CC1,CC1,CC1);  //Static Color
    else glColor4ub(CC1,CC2,CC3,CC4);         //Dynamic Color
    for(int i=0;i<Steps;i++)
        {
            float A=(i*2*Pi)/Steps;
            float x = Radius * cos(A);
            float y = Radius * sin(A);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
}
///Circle Points///
void CirclePoints(float radius,int steps,float X,float Y,int PointSize,int ColorCode)
{

    float Radius = radius;              //Circle's Radius
    int Steps = steps;                  //Increase to get Smooth Circle
    float Pi=3.1416f;                   //PI
    glPushMatrix();
    glTranslatef(X, Y, 0);              //Move Circle Along Axes
    glPointSize(PointSize);             //Point Size
    glBegin(GL_POINTS);
    glColor3ub(ColorCode,ColorCode,ColorCode);  // Color

    for(int i=0;i<Steps;i++)
        {
            float A=(i*2*Pi)/Steps;
            float x = Radius * cos(A);
            float y = Radius * sin(A);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
}
///Circle One Third///
void CircleOneThird(float radius,int steps,int LessSteps,float X,float Y,float RotationAngle)
{
    float Radius = radius;              //Circle's Radius
    int Steps = steps;                  //Increase to get Smooth Circle
    float Pi=3.1416f;                   //PI
    glPushMatrix();
    glTranslatef(X, Y, 0);              //Move Circle Along Axes
    glRotatef(RotationAngle,0,0,1);     //Rotation Angle
    glBegin(GL_POINTS);
    for(int i=0;i<LessSteps;i++)
        {
            float A=(i*2*Pi)/Steps;
            float x = Radius * cos(A);
            float y = Radius * sin(A);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
}
///Circle One Third Fill///
void CircleOneThirdFill(float radius,int steps,int LessSteps,float X,float Y,float RotationAngle)
{
    float Radius = radius;              //Circle's Radius
    int Steps = steps;                  //Increase to get Smooth Circle
    float Pi=3.1416f;                   //PI
    glPushMatrix();
    glTranslatef(X, Y, 0);              //Move Circle Along Axes
    glRotatef(RotationAngle,0,0,1);     //Rotation Angle
    glBegin(GL_POLYGON);
    for(int i=0;i<LessSteps;i++)
        {
            float A=(i*2*Pi)/Steps;
            float x = Radius * cos(A);
            float y = Radius * sin(A);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
}
///TEXT Function
void DrawTextStroke(float x,float y,float z,float FSize,float Density,char *CharectersArray)  ////Render Text with Stroke
{
	char Charecter;
    glLineWidth(Density);
    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(FSize,FSize,FSize);

	for(int i = 0; *(CharectersArray+i)!='\0' ;i++)
	{
	    Charecter = *(CharectersArray + i);
        glutStrokeCharacter(STROKEFONT ,Charecter);
	}
    glPopMatrix();
}
///..............................................Music.....................................///
 //Convert String to LPSTR
LPSTR StringToSLPSTR(string s){
return const_cast<char *>(s.c_str());
}

void PlayMusicCustom(string SoundName,bool Loop,bool NullOtherSound){

if(NullOtherSound){sndPlaySound(NULL,SND_ASYNC);}

if(Loop){sndPlaySound(StringToSLPSTR(FileLocation+SoundName),SND_ASYNC|SND_LOOP);}
else{sndPlaySound(StringToSLPSTR(FileLocation+SoundName),SND_ASYNC);}
}
///..........................................SHAPES......................................................///
///Sky///
void Sky()
{
glBegin(GL_QUADS);        //1st Sky
glColor3ub(98,168, 191);
glVertex2f(-50,-15);
glVertex2f(-50,30);
glVertex2f(50,30);
glVertex2f(50,-15);
glEnd();

glBegin(GL_QUADS);        //2nd Sky
glColor3ub(98,168, 191);
glVertex2f(-50,30);
glColor3ub(0,0,0);
glVertex2f(-50,120);
glColor3ub(0,0,0);
glVertex2f(50,120);
glColor3ub(98,168, 191);
glVertex2f(50,30);
glEnd();

glBegin(GL_QUADS);        //3rd Sky
glColor3ub(0,0,0);
glVertex2f(-50,120);
glVertex2f(-50,210);
glVertex2f(50,210);
glVertex2f(50,120);
glEnd();
}
//----------------------------Sky End
///Road//
void Road()
{
glBegin(GL_POLYGON);
glColor3ub(0, 0, 0); //Color
glVertex2f(-50,-15);
glVertex2f(-50,-28);
glVertex2f(50,-28);
glVertex2f(50,-15);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(30, 30, 30); //Color
glVertex2f(-50,-28);
glVertex2f(50,-28);
glVertex2f(50,-30);
glVertex2f(-50,-30);
glEnd();
}
//----------------------------Road End
///Road Lines///
void RoadLines()
{
glLineWidth(1.5);
glBegin(GL_LINES);           //Road lines
glColor3f(1.0f, 1.0f, 1.0f); //Color

glVertex2f(-50,-21);
glVertex2f(-45,-21);

glVertex2f(-40,-21);
glVertex2f(-35,-21);


glVertex2f(-30,-21);
glVertex2f(-25,-21);

glVertex2f(-20,-21);
glVertex2f(-15,-21);

glVertex2f(-10,-21);
glVertex2f(-5,-21);

glVertex2f(0,-21);
glVertex2f(5,-21);

glVertex2f(10,-21);
glVertex2f(15,-21);

glVertex2f(20,-21);
glVertex2f(25,-21);

glVertex2f(30,-21);
glVertex2f(35,-21);

glVertex2f(40,-21);
glVertex2f(45,-21);
glEnd();
}
//----------------------------Road Lines End
///TeslaCar///
void TeslaCar()
{
glPushMatrix();
glRotatef(TeslaCarAngle,0,1,0);
glTranslatef(TeslaCarPosition,0,0);
glPushMatrix();
glTranslatef(40,0,0);
glLineWidth(0.1);

glBegin(GL_TRIANGLES); // upper part
glColor3ub(224, 224, 224);
glVertex2f(-49,-18);
glVertex2f(-34,-18);
glVertex2f(-39, -15.5);
glEnd();

glBegin(GL_TRIANGLES); // window
glColor3ub(69, 69, 69);

glVertex2f(-44,-17.5);
glVertex2f(-35,-17.5);
glVertex2f(-39, -16);
glEnd();

glBegin(GL_QUADS);   // lower part
glColor3ub(173, 173, 173);

glVertex2f(-49,-18);
glVertex2f(-48.5,-20);
glVertex2f(-34,-20);
glVertex2f(-34,-18);
glEnd();


glBegin(GL_QUADS); // front part
glColor3ub(173, 173, 173);

glVertex2f(-34,-18);
glVertex2f(-33,-18.5);
glVertex2f(-33,-20);
glVertex2f(-34,-20);
glEnd();

glBegin(GL_QUADS);   // lower small part
glColor3ub(204, 204, 204);

glVertex2f(-48.5,-20);
glVertex2f(-47,-20.5);
glVertex2f(-35,-20.5);
glVertex2f(-33,-20);

glEnd();

glBegin(GL_LINES);
glColor3ub(74, 74, 74);
glVertex2f(-39, -16);
glVertex2f(-39, -20);

glEnd();

glBegin(GL_LINES);
glColor3ub(74, 74, 74);
glVertex2f(-43, -20);
glVertex2f(-39, -20);

glEnd();

glBegin(GL_LINES);
glColor3ub(74, 74, 74);
glVertex2f(-43, -20);
glVertex2f(-43, -17.5);

glEnd();

glBegin(GL_LINES);
glColor3ub(74, 74, 74);
glVertex2f(-43, -20);
glVertex2f(-43, -17.5);

glEnd();

glBegin(GL_LINES);
glColor3ub(74, 74, 74);
glVertex2f(-35, -20);
glVertex2f(-39, -20);

glEnd();

glBegin(GL_LINES);
glColor3ub(74, 74, 74);
glVertex2f(-35, -20);
glVertex2f(-35, -17.5);

glEnd();

glBegin(GL_LINES);
glColor3ub(255, 252, 252);
glVertex2f(-46, -19.5);
glVertex2f(-45, -19.5);

glEnd();

glBegin(GL_LINES);
glColor3ub(255, 252, 252);
glVertex2f(-39, -16);
glVertex2f(-39, -17.5);

glEnd();

Circle(1.5f,20,-46, -20,0); //LeftTire
Circle(0.7f,20,-46, -20,220); //LeftTireRim
Circle(1.5f,20,-35, -20,0); //RightTire
Circle(0.7f,20,-35, -20,220); //RightTireRim
glPopMatrix();
glPopMatrix();
}
//----------------------------TeslaCar End
///StreetSideGlass
void StreetSideGlass()
{
glBegin(GL_QUADS);
glColor4ub(255,255,255,50);
glVertex2f(-50,-29);
glColor4ub(150,150,150,50);
glVertex2f(50,-29);
glColor4ub(150,150,150,50);
glVertex2f(50,-19);
glColor4ub(255,255,255,50);
glVertex2f(-50,-19);
glEnd();

glColor4ub(0,0,0,150);
for(int i =0;i<100;i+=3){
glBegin(GL_QUADS);
glVertex2f(-50+i,-29);
glVertex2f(-49+i,-29);
glVertex2f(-49+i,-19);
glVertex2f(-50+i,-19);
glEnd();
i+=6;
}

glBegin(GL_QUADS);
glColor4ub(255,255,255,50);
glVertex2f(-50,-12);
glColor4ub(150,150,150,50);
glVertex2f(50,-12);
glColor4ub(150,150,150,50);
glVertex2f(50,-15);
glColor4ub(255,255,255,50);
glVertex2f(-50,-15);
glEnd();

glColor4ub(0,0,0,150);
for(int i =0;i<100;i+=2){
glBegin(GL_QUADS);
glVertex2f(-50+i,-12);
glVertex2f(-49.5+i,-12);
glVertex2f(-49.5+i,-15);
glVertex2f(-50+i,-15);
glEnd();
i+=2;
}
}
//------------------Street Side Glass End
///Rocket///
void RocketLaunchSmoke();
void Rocket(){
glLineWidth(5); //Width
glPushMatrix();
glTranslatef(RocketPosition,RocketPositionY,0);
glRotatef(RocketAngle,0,0,1);
glScalef(RocketSize,RocketSize,0);

if(isStartRocketSmoke){RocketLaunchSmoke();}

glBegin(GL_QUADS); //Middle
glColor3ub (233,37,37);
glVertex2f(-3,5);
glVertex2f(3,5);
glVertex2f(3,-5);
glVertex2f(-3,-5);
glEnd();

glBegin(GL_TRIANGLES); //Up Face
glColor3ub (233,37,37);
glVertex2f(-3,5);
glVertex2f(0,8);
glVertex2f(3,5);
glEnd();

glBegin(GL_POLYGON); //Lower Face
glColor3ub(255,255,255);
glVertex2f(2,-5);
glVertex2f(-2,-5);
glVertex2f(0,-6);
glEnd();

glBegin(GL_POLYGON); //Right 1st PolyGone
glColor3ub(255,255,255);
glVertex2f(3,1);
glVertex2f(4,0);
glVertex2f(4,-4.5f);
glVertex2f(3,-4.5f);
glEnd();

glBegin(GL_POLYGON); //Left 1st PolyGone
glColor3ub(255,255,255);
glVertex2f(-3,1);
glVertex2f(-4,0);
glVertex2f(-4,-4.5f);
glVertex2f(-3,-4.5f);
glEnd();

glBegin(GL_POLYGON); //Left 2nd PolyGone
glColor3ub (233,37,37);
glVertex2f(-4,-4.5f);
glVertex2f(-5,-6.5f);
glVertex2f(-6,-4.5f);
glVertex2f(-6,-2);
glVertex2f(-5,-1.5f);
glVertex2f(-4,-2);
glEnd();

glBegin(GL_POLYGON); //Right 2nd PolyGone
glVertex2f(4,-4.5f);
glVertex2f(5,-6.5f);
glVertex2f(6,-4.5f);
glVertex2f(6,-2);
glVertex2f(5,-1.5f);
glVertex2f(4,-2);
glEnd();

//-------------Windows
Circle(1.55f,15,0,2.5f,0,0,0,255);
glPointSize(5);
if(isRocketinGalaxy){
glColor3ub(26, 158, 235);
CircleOneThird(1.2f,50,30,0,2.5f,RocketWindowAngle);
glColor3ub(26, 158, 235);
CircleOneThird(0.65f,30,25,0,2.5f,RocketWindowAngle+95);
}
else{
glColor3ub(186, 11, 49);
CircleOneThird(1.2f,50,30,0,2.5f,RocketWindowAngle);
glColor3ub(186, 11, 49);
CircleOneThird(0.65f,30,25,0,2.5f,RocketWindowAngle+95);
}

glBegin(GL_LINES);
glColor4ub(0,0,0,100); //Middle
glVertex2f(-3,5);
glVertex2f(3,5);
glVertex2f(3,5);
glVertex2f(3,-5);
glVertex2f(3,-5);
glVertex2f(-3,-5);
glVertex2f(-3,-5);
glVertex2f(-3,5);


glVertex2f(-3,5);  //Up Face
glVertex2f(0,8);
glVertex2f(0,8);
glVertex2f(3,5);
glVertex2f(3,5);
glVertex2f(-3,5);

glVertex2f(2,-5);  //Lower Face
glVertex2f(-2,-5);
glVertex2f(-2,-5);
glVertex2f(0,-6);
glVertex2f(0,-6);
glVertex2f(2,-5);

glVertex2f(3,1); //Right 1st PolyGone
glVertex2f(4,0);
glVertex2f(4,0);
glVertex2f(4,-4.5f);
glVertex2f(4,-4.5f);
glVertex2f(3,-4.5f);

glVertex2f(-3,1); //Left 1st PolyGone
glVertex2f(-4,0);
glVertex2f(-4,0);
glVertex2f(-4,-4.5f);
glVertex2f(-4,-4.5f);
glVertex2f(-3,-4.5f);

glVertex2f(-4,-4.5f); //Left 2nd PolyGone
glVertex2f(-5,-6.5f);
glVertex2f(-5,-6.5f);
glVertex2f(-6,-4.5f);
glVertex2f(-6,-4.5f);
glVertex2f(-6,-2);
glVertex2f(-6,-2);
glVertex2f(-5,-1.5f);
glVertex2f(-5,-1.5f);
glVertex2f(-4,-2);

glVertex2f(4,-4.5f); //Right 2nd PolyGone
glVertex2f(5,-6.5f);
glVertex2f(5,-6.5f);
glVertex2f(6,-4.5f);
glVertex2f(6,-4.5f);
glVertex2f(6,-2);
glVertex2f(6,-2);
glVertex2f(5,-1.5f);
glVertex2f(5,-1.5f);
glVertex2f(4,-2);

glVertex2f(1.125,-3); //Lower Quad Sign
glVertex2f(-1.125,-3);
glVertex2f(1,-5);
glVertex2f(1,-3);
glVertex2f(-1,-5);
glVertex2f(-1,-3);

glColor3ub(255,255,255);
glVertex2f(1.5,0); //1st Mid Line
glVertex2f(-1.5,0);
glVertex2f(1.5,-1); //2nd Mid Line
glVertex2f(-1.5,-1);
glEnd();

glBegin(GL_QUADS); //Middle Shade
glColor4ub (0,0,0,100);
glVertex2f(-3,5);
glColor4ub (80,80,80,100);
glVertex2f(3,5);
glColor4ub (0,0,0,100);
glVertex2f(3,-5);
glColor4ub (25,25,25,100);
glVertex2f(-3,-5);
glEnd();

glBegin(GL_POLYGON); //Left 2nd PolyGone Shade
glColor4ub (0,0,0,150);
glVertex2f(-4,-4.5f);
glVertex2f(-5,-6.5f);
glColor4ub (50,50,50,150);
glVertex2f(-6,-4.5f);
glVertex2f(-6,-2);
glColor4ub (-50,50,50,150);
glVertex2f(-5,-1.5f);
glColor4ub (0,0,0,150);
glVertex2f(-4,-2);
glEnd();

glBegin(GL_POLYGON); //Right 2nd PolyGone Shade
glColor4ub (0,0,0,100);
glVertex2f(4,-4.5f);
glVertex2f(5,-6.5f);
glColor4ub (95,95,95,100);
glVertex2f(6,-4.5f);
glVertex2f(6,-2);
glColor4ub (50,50,50,100);
glVertex2f(5,-1.5f);
glColor4ub (85,85,85,100);
glVertex2f(4,-2);
glEnd();

glBegin(GL_TRIANGLES); //Up Face Shade
glColor4ub (0,0,0,100);
glVertex2f(-3,5);
glColor4ub (155,155,155,100);
glVertex2f(0,8);
glColor4ub (55,55,55,100);
glVertex2f(3,5);
glEnd();

glPopMatrix();
}
//--------------------Rocket End
void RocketLaunchSmoke(){
glColor4ub(255,255,255,150);

glPointSize(5);
glPushMatrix();
glTranslatef(0,-2,0);
glScalef(RocektSmokeSize,RocektSmokeSize,1);
CircleOneThird(4.5,70,25,0,-10,207);
CircleOneThird(2.5,70,25,-5,-8.5,195);
CircleOneThird(4,70,25,4,-7.5,215);

glPushMatrix();
glTranslatef(0,-3,0);
glScalef(RocektSmokeSize,RocektSmokeSize,1);
CircleOneThird(4.5,70,25,0,-10,207);
CircleOneThird(2.5,70,25,-5,-8.5,195);
CircleOneThird(4,70,25,4,-7.5,215);
glPopMatrix();

glPopMatrix();
}

///RocketHolder///
void RocketHolder(){
glLineWidth(5);
glBegin(GL_LINES);
glColor3ub(255,255,255);
glVertex2f(4,-13); //Left Line
glVertex2f(4,11);
glVertex2f(11,-13); //Right Line
glVertex2f(11,11);
glVertex2f(7.5,-13); //Mid Line
glVertex2f(7.5,11);
glVertex2f(3.9,11); //Up Line
glVertex2f(11.15,11);

glVertex2f(4,11); //Zig Zag Left 1
glVertex2f(11,7);
glVertex2f(4,7); //Zig Zag Left 2
glVertex2f(11,3);
glVertex2f(4,3); //Zig Zag Left 3
glVertex2f(11,-1);
glVertex2f(4,-1); //Zig Zag Left 4
glVertex2f(11,-5);
glVertex2f(4,-5); //Zig Zag Left 5
glVertex2f(11,-9);
glVertex2f(4,-9); //Zig Zag Left 6
glVertex2f(11,-13);

glVertex2f(4,7); //Zig Zag Left 1
glVertex2f(11,11);
glVertex2f(4,3); //Zig Zag Left 2
glVertex2f(11,7);
glVertex2f(4,-1); //Zig Zag Left 3
glVertex2f(11,3);
glVertex2f(4,-5); //Zig Zag Left 4
glVertex2f(11,-1);
glVertex2f(4,-9); //Zig Zag Left 5
glVertex2f(11,-5);
glVertex2f(4,-13); //Zig Zag Left 6
glVertex2f(11,-9);

glEnd();

glBegin(GL_QUADS); //Bottom Stand
glColor3ub(4, 76, 135);
glVertex2f(-1,-13);
glVertex2f(-1,-15);
glVertex2f(12.5,-15);
glVertex2f(12.5,-13);
glEnd();

glBegin(GL_QUADS); //Mid Stand
glColor3ub(4, 76, 135);
glVertex2f(6,-13);
glVertex2f(9,-13);
glVertex2f(9,1);
glVertex2f(6,1);
glEnd();

glBegin(GL_QUADS); //Top Stand
glColor3ub(4, 76, 135);
glVertex2f(1,1);
glVertex2f(9,1);
glVertex2f(9,4);
glVertex2f(1,4);
glEnd();

glBegin(GL_QUADS); //Mid Stand Shade
glColor3ub(255,255,255);
glVertex2f(9,-13);
glVertex2f(8,-13);
glVertex2f(8,4);
glVertex2f(9,4);
glEnd();

glEnd();

}
//--------------------Rocket Holder End
///Tower///
void Tower()
{
glLineWidth(5);
glPushMatrix();
glTranslatef(-6.5,0,0);
glBegin(GL_QUADS);       //tower Bottom
glColor3ub(159, 134, 186);

glVertex2f(-26,-15);
glVertex2f(-26,-13);
glVertex2f(-22,-13);
glVertex2f(-22,-15);
glEnd();

glBegin(GL_QUADS);       //tower Bottom
glColor3ub(188, 177, 199);

glVertex2f(-22,-13);
glVertex2f(-21,-13.5);
glVertex2f(-21,-15);
glVertex2f(-22,-15);

glEnd();

glBegin(GL_LINES);   // tower lines
glColor3ub(25, 25, 25);

glVertex2f(-22,-13); //Right Stand
glVertex2f(-22.5, 2.5);
glVertex2f(-25, -13); //Left Stand
glVertex2f(-24.5, 2.5);


glVertex2f(-24.5, 2.5); //Zig Zag 1
glVertex2f(-22.5, 0.95);

glVertex2f(-22.5, 0.95); //Zig Zag 2
glVertex2f(-24.5, -0.6);

glVertex2f(-24.5, -0.6); //3
glVertex2f(-22.5, -2.15);

glVertex2f(-22.5, -2.15); //4
glVertex2f(-24.5, -3.7);

glVertex2f(-24.5, -3.7); //5
glVertex2f(-22.2, -5.25);

glVertex2f(-22.25, -5.25); //6
glVertex2f(-24.7, -6.8);

glVertex2f(-24.7, -6.8);//7
glVertex2f(-22.15, -8.35);

glVertex2f(-22.15, -8.35); //8
glVertex2f(-25, -9.9);

glVertex2f(-25, -9.9); //9
glVertex2f(-22, -11.45);

glVertex2f(-22, -11.45); //10
glVertex2f(-25, -13);
glEnd();

Circle(0.85,10,-23.5,3.5,255); //Light

glBegin(GL_QUADS);       //tower
glColor3ub(187, 184, 191);
glVertex2f(-25,2.5);
glVertex2f(-24.5,3.5);
glVertex2f(-22.5,3.5);
glVertex2f(-22,2.5);
glEnd();
glPopMatrix();
}
//--------------------Tower End
///Tower Light///
void TowerLight(){


glPushMatrix();
glTranslatef(-30,4,0);
glRotatef(TowerLightAngle,0,0,1);
glBegin(GL_POLYGON);
glColor4ub(255,255,255,85);
glVertex2f(0,0);
glColor4ub(255,255,255,55);
glVertex2f(55,85);
glColor4ub(255,255,255,0);
glVertex2f(75,95);
glColor4ub(255,255,255,0);
glVertex2f(95,75);
glColor4ub(255,255,255,55);
glVertex2f(85,55);
glEnd();
glPopMatrix();
}
//---------------Tower Light
///LeftSideBuilding///
void LeftSideBuilding()
{

glLineWidth(2.5);

glPushMatrix();
glTranslatef(-7.5,0,0);
glBegin(GL_QUADS);       // left-building
glColor3ub(232, 232, 232);
glVertex2f(-42,-15);
glVertex2f(-42,2);
glVertex2f(-35,2);
glVertex2f(-35,-15);
glEnd();

glBegin(GL_QUADS);       // left-building up white
glColor3ub(232, 232, 232);
glVertex2f(-41,2);
glVertex2f(-36,2);
glVertex2f(-36,4);
glVertex2f(-41,4);
glEnd();

glBegin(GL_QUADS);       // left-building up blue
glColor3ub(4, 76, 135);
glVertex2f(-40.5,3);
glVertex2f(-36.5,3);
glVertex2f(-36.5,4);
glVertex2f(-40.5,4);
glEnd();

glBegin(GL_QUADS);       // left-building up antena
glColor3ub(100, 100, 100);
glVertex2f(-40.5,4);
glVertex2f(-36.5,4);
glVertex2f(-36.5,5.5);
glVertex2f(-40.5,5.5);
glEnd();

glBegin(GL_POLYGON);       // left-building up antena
glColor3ub(100, 100, 100);
glVertex2f(-39,5.5);
glVertex2f(-38,5.5);
glVertex2f(-38,7.65);
glVertex2f(-39,7.875);
glEnd();

//Antena
glPointSize(3);
glColor3ub(255,255,255);
CircleOneThirdFill(2,30,15,-37.85,9,145);
glColor3ub(150,0,0);
CircleOneThirdFill(1.5,30,15,-38,8.75,325);
glColor3ub(0,0,0);
CircleOneThirdFill(0.85,30,15,-38,8.75,325);

glBegin(GL_QUADS);       // left-building blue glass
glColor3ub(4, 76, 135);
glVertex2f(-41,-12);
glVertex2f(-41,2);
glVertex2f(-36,2);
glVertex2f(-36,-12);
glEnd();

glBegin(GL_LINES);   // blue glass lines
glColor3ub(215, 215, 219);
glVertex2f(-37.5, -12);
glVertex2f(-37.5, 2);
glVertex2f(-39.5, -12);
glVertex2f(-39.5, 2);
glVertex2f(-41, -1);
glVertex2f(-36, -1);
glVertex2f(-41, -5);
glVertex2f(-36, -5);
glVertex2f(-41, -9);
glVertex2f(-36, -9);
glEnd();

glBegin(GL_QUADS);       // left-building door side
glColor3ub(232, 232, 232);
glVertex2f(-42.5,-15);
glVertex2f(-42.5,-12);
glVertex2f(-36.5,-12);
glVertex2f(-36.5,-15);
glEnd();

glBegin(GL_QUADS);       // left-building door
glColor3ub(156, 134, 117);
glVertex2f(-38,-13);
glVertex2f(-38,-15);
glVertex2f(-39.5,-15);
glVertex2f(-39.5,-13);
glEnd();


glBegin(GL_QUADS);       // right-building
glColor3ub(207, 207, 207);

glVertex2f(-35,8);
glVertex2f(-35,-15);
glVertex2f(-28,-15);
glVertex2f(-28,3);
glEnd();

glBegin(GL_QUADS);       // right-building blue glass
glColor3ub(4, 76, 135);

glVertex2f(-34.5,7);
glVertex2f(-34.5,-14);
glVertex2f(-28.5,-14);
glVertex2f(-28.5,2.5);
glEnd();

glBegin(GL_LINES);   // right-building blue glass lines
glColor3ub(207, 207, 207);
glVertex2f(-34.5, 4);
glVertex2f(-29.5, 4);
glVertex2f(-34.5, 2.5);
glVertex2f(-28.5, 2.5);
glVertex2f(-34.5, 1);
glVertex2f(-28.5, 1);
glVertex2f(-34.5, -0.5);
glVertex2f(-28.5, -0.5);
glVertex2f(-34.5, -2);
glVertex2f(-28.5, -2);
glVertex2f(-34.5, -3.5);
glVertex2f(-28.5, -3.5);
glVertex2f(-34.5, -5);
glVertex2f(-28.5, -5);
glVertex2f(-34.5, -6.5);
glVertex2f(-28.5, -6.5);
glVertex2f(-34.5, -8);
glVertex2f(-28.5, -8);
glVertex2f(-34.5, -9.5);
glVertex2f(-28.5, -9.5);
glVertex2f(-34.5, -11);
glVertex2f(-28.5, -11);
glVertex2f(-34.5, -12.5);
glVertex2f(-28.5, -12.5);
glEnd();
glPopMatrix();
}
//-------------------LeftSideBuilding End
///NASA///
void NASA()
{
glLineWidth(4.5);
glPushMatrix();
glTranslatef(-2,0,0);
glBegin(GL_QUADS); //front
glColor3ub(219, 219, 219);

glVertex2f(22,-15);
glVertex2f(22,3);
glVertex2f(43,3);
glVertex2f(43,-15);

glEnd();

glBegin(GL_QUADS);  //side
glColor3ub(69, 69, 69);

glVertex2f(43,3);
glVertex2f(43,-15);
glVertex2f(45,-15);
glVertex2f(45,2);

glEnd();

glBegin(GL_QUADS);  // front-middle
glColor3ub(107, 107, 107);

glVertex2f(29,3);
glVertex2f(29,-15);
glVertex2f(37,-15);
glVertex2f(37,3);
glEnd();

glBegin(GL_QUADS);  // front-middle2
glColor3ub(219, 219, 219);

glVertex2f(30,0);
glVertex2f(30,-15);
glVertex2f(36,-15);
glVertex2f(36,0);
glEnd();

glBegin(GL_QUADS);  // front-middle3
glColor3ub(121, 143, 156);

glVertex2f(31,-1);
glVertex2f(31,-15);
glVertex2f(35,-15);
glVertex2f(35,-1);
glEnd();

glBegin(GL_QUADS);  // U.S flag blue
glColor3ub(3, 10, 105);

glVertex2f(23,2.5);
glVertex2f(23,0);
glVertex2f(25,0);
glVertex2f(25,2.5);
glEnd();

glBegin(GL_LINES);      //US flag
glColor3f(1.0f, 0.0f, 0.0f); // Red
glVertex2f(25.5, 2.5);
glVertex2f(25.5, -3);
glVertex2f(26, 2.5);
glVertex2f(26, -3);
glVertex2f(26.5, 2.5);
glVertex2f(26.5, -3);
glVertex2f(23.2, 0);
glVertex2f(23.2, -3);
glVertex2f(23.7, 0);
glVertex2f(23.7, -3);
glVertex2f(24.2, 0);
glVertex2f(24.2, -3);
glVertex2f(24.8, 0);
glVertex2f(24.8, -3);
glEnd();

glBegin(GL_QUADS);  //front-upper
glColor3ub(184, 184, 184);

glVertex2f(25,-6);
glVertex2f(25,-15);
glVertex2f(32,-15);
glVertex2f(32,-6);
glEnd();

glBegin(GL_QUADS);  //front-upper2
glColor3ub(121, 143, 156);

glVertex2f(26,-7);
glVertex2f(26,-15);
glVertex2f(31,-15);
glVertex2f(31,-7);
glEnd();

glBegin(GL_QUADS);  //front-upper3-gate
glColor3ub(107, 107, 107);

glVertex2f(27,-12);
glVertex2f(27,-15);
glVertex2f(30,-15);
glVertex2f(30,-12);
glEnd();

glBegin(GL_QUADS);  //front-side
glColor3ub(69, 69, 69);

glVertex2f(32,-15);
glVertex2f(32,-6);
glVertex2f(36,-7);
glVertex2f(36,-15);
glEnd();

glColor3ub(150,0,0);
glPushMatrix();
glTranslatef(39.9,-1,0);
glRotatef(NasaCircleAngle*5,0,0,1);
glPointSize(7.5);
CircleOneThird(2.15,60,30,0,0,0);
glPopMatrix();

Circle(2,30,40, -1,20, 95, 160,150); //NASA Logo Circle
CirclePoints(1.85,7,40, -1,1.5,255); //Circle Points
CirclePoints(1.5,7,40, -1,3,255); //Circle Points
CirclePoints(1,5,40, -1,3,255); //Circle Points
CirclePoints(0.5,3,40, -1,3,255); //Circle Points

glColor3ub(255, 255, 255);
glBegin(GL_LINES);
glVertex2f(39,-2.25f);
glVertex2f(39,0.25f);

glVertex2f(39,0.25f);
glVertex2f(41,-2.25f);

glVertex2f(41,-2.25f);
glVertex2f(41,0.25f);
glEnd();
glPopMatrix();

}
//--------------------NASA End
///AirPlane///
void AirPlane(){
glPushMatrix();
glRotatef(AirPlaneAngle,0,1,0);
glTranslatef(AirPlanePosition,0,0);
glPushMatrix();
glTranslatef(-17.5,26,0);
glScalef(1,0.85,1);
//Body BG
glColor3ub(125,125,125);
glBegin(GL_POLYGON);
glVertex2f(38,7);
glVertex2f(12,7);
glVertex2f(3,5);  //Front Point
glVertex2f(12,3);
glVertex2f(38,3);
glVertex2f(45,5);
glVertex2f(44,6);
glVertex2f(45,14);
glVertex2f(43,14);
glEnd();

//Main Window
glColor3ub(22,114,148);
glBegin(GL_TRIANGLES);
glVertex2f(5,5);
glVertex2f(12,6.5);
glVertex2f(12,5);
glEnd();

//First Door - OutSide
glColor3ub(0,0,0);
glBegin(GL_QUADS);
glVertex2f(14,6.5);
glVertex2f(15.5,6.5);
glVertex2f(15.5,3.5);
glVertex2f(14,3.5);
glEnd();
//First Door - Inside
glColor3ub(255,255,255);
glBegin(GL_QUADS);
glVertex2f(14.25,6.5);
glVertex2f(15.25,6.5);
glVertex2f(15.25,3.5);
glVertex2f(14.25,3.5);
glEnd();

//Small Windows - Outside
glPointSize(10);
glBegin(GL_POINTS);
glVertex2f(17,6.15);
glVertex2f(18,6.15);
glVertex2f(19,6.15);

glVertex2f(22,6.15);
glVertex2f(23,6.15);
glVertex2f(24,6.15);
glVertex2f(25,6.15);
glVertex2f(26,6.15);
glVertex2f(27,6.15);
glVertex2f(28,6.15);

glVertex2f(31,6.15);
glVertex2f(32,6.15);
glVertex2f(33,6.15);
glVertex2f(34,6.15);
glEnd();

//Small Windows - Inside
glColor3ub(125,125,125);
glPointSize(7.5);
glBegin(GL_POINTS);
glVertex2f(17,6.15);
glVertex2f(18,6.15);
glVertex2f(19,6.15);

glVertex2f(22,6.15);
glVertex2f(23,6.15);
glVertex2f(24,6.15);
glVertex2f(25,6.15);
glVertex2f(26,6.15);
glVertex2f(27,6.15);
glVertex2f(28,6.15);

glVertex2f(31,6.15);
glVertex2f(32,6.15);
glVertex2f(33,6.15);
glVertex2f(34,6.15);
glEnd();

//Second Door - OutSide
glColor3ub(0,0,0);
glBegin(GL_QUADS);
glVertex2f(36,6.5);
glVertex2f(37,6.5);
glVertex2f(37,4.5);
glVertex2f(36,4.5);
glEnd();

//Second Door - Inside
glColor3ub(255,255,255);
glBegin(GL_QUADS);
glVertex2f(36.25,6.5);
glVertex2f(37,6.5);
glVertex2f(37,4.5);
glVertex2f(36.25,4.5);
glEnd();

//Mid Lines
glColor3ub(0,0,0);
glLineWidth(2);
glBegin(GL_LINES);
glVertex2f(16,5);
glVertex2f(34.5,5);
glEnd();

glColor3ub(255,255,255);
glBegin(GL_LINES);
glVertex2f(16,4);
glVertex2f(38,4);
glEnd();

//Back Design - 01
glColor3ub(0,0,0);
glBegin(GL_POLYGON);
glVertex2f(44.10,13);
glVertex2f(45,13);
glVertex2f(44.825,13.25);
glVertex2f(43.85,13.25);
glVertex2f(40,8);
glVertex2f(40.25,8);
glEnd();

//Back Design - 02
glColor3ub(0,0,0);
glBegin(GL_POLYGON);
glVertex2f(44.65,12.5);
glVertex2f(44.85,12.5);
glVertex2f(44.95,12.75);
glVertex2f(44.5,12.75);
glVertex2f(40.5,7.5);
glEnd();

//Color Effects
glBegin(GL_POLYGON);
glColor4ub(20,20,20,100);
glVertex2f(38,7);
glColor4ub(150,150,150,100);
glVertex2f(12,7);
glColor4ub(255,255,255,150);
glVertex2f(3,5); //Forward Center Point
glColor4ub(150,150,150,100);
glVertex2f(12,3);
glColor4ub(20,20,20,200);
glVertex2f(38,3);
glColor4ub(20,20,20,200);
glVertex2f(45,5);
glColor4ub(20,20,20,200);
glVertex2f(44,6);
glColor4ub(20,20,20,200);
glVertex2f(45,14);
glColor4ub(0,0,0,200);
glVertex2f(43,14);
glEnd();

//Back Triangle Thing
glColor3ub(0,0,0);
glBegin(GL_TRIANGLES);
glVertex2f(38,5);
glVertex2f(46.85,6.85);
glVertex2f(46,5);
glEnd();

//Mid Engine
glColor3ub(22,114,148);
glBegin(GL_POLYGON);
glVertex2f(21.85,3.75);
glVertex2f(22,3.85);
glVertex2f(25,3.85);
glVertex2f(26.5,3);
glVertex2f(25,2.15);
glVertex2f(22,2.15);
glVertex2f(21.85,2.35);
glEnd();
glPopMatrix();
glPopMatrix();
}
//......................AirPlane End
///Mountain///
void Mountain()
{
glBegin(GL_TRIANGLES);
glColor3ub(108, 85, 72);

glVertex2f(-50, -15);
glVertex2f(-27,-4);
glVertex2f(-18, -15);

glVertex2f(-21, -15);
glVertex2f(5,-1);
glVertex2f(24, -15);

glVertex2f(24, -15);
glVertex2f(50,-1);
glVertex2f(50, -15);
glEnd();
}
//.............Mountain End
///Backmountain///
void Backmountain()
{
glBegin(GL_TRIANGLES);
glColor3ub(92, 44, 17);
glVertex2f(-27,-15);
glVertex2f(-15, -6);
glVertex2f(0, -15);

glVertex2f(5,-15);
glVertex2f(17, -6);
glVertex2f(30, -15);
glEnd();
}
//................Backmountain End
///Tree///
void Tree(){
glLineWidth(10);  //Tree 1
glBegin(GL_LINES);
glColor3ub(74, 44, 0);
glVertex2f(40, -11);
glVertex2f(40, -15.5);
glEnd();

Circle(2,20,40, -11,94, 176, 74,255);

glLineWidth(10);   //Tree 2
glBegin(GL_LINES);
glColor3ub(74, 44, 0);
glVertex2f(42, -11);
glVertex2f(42, -15.5);
glEnd();

Circle(2,20,42, -11,55, 97, 45,255);

glLineWidth(10);  //Tree 3
glBegin(GL_LINES);
glColor3ub(74, 44, 0);
glVertex2f(-48, -11);
glVertex2f(-48, -15);
glEnd();

Circle(2,20,-48, -11,94, 176, 74,255);
}
//..........Tree End
///Front Tree///
void FrontTree(){

glLineWidth(5);  //Tree 1


glBegin(GL_QUADS);
glColor3ub(74, 44, 0);
glVertex2f(49, -30);
glVertex2f(50, -30);
glVertex2f(50, 15);
glVertex2f(49, 15);
glEnd();

Circle(18.5,80,55, 10,32, 87, 19,255);
}
//--------------Front Tree End
///Cloud///
void Cloud()
{
glPushMatrix();
glTranslatef(-30,35,0);
glScalef(0.5 + CloudSize,0.5 + CloudSize,0);
Circle(5,30,8,0,150,150,150,255);
Circle(5,30,9,-1,255);
Circle(6,30,-2,-8,255);
Circle(6,30,0.85,-0.65,150,150,150,255);
Circle(6,30,0,0,255);
Circle(8,35,-9,0.5,150,150,150,255);
Circle(8,35,-8,2,255);
glPopMatrix();

glPushMatrix();
glTranslatef(35,65,0);
glScalef(1.5 - CloudSize,1.5 - CloudSize,0);
Circle(6,20,-2,-8,255);
Circle(8,30,2,5,255);
Circle(6,20,0,0,255);
Circle(10,40,-12,0.5,150,150,150,255);
Circle(10,40,-11,2,255);
Circle(10,40,8,0,150,150,150,255);
Circle(10,40,9,-1,255);
glPopMatrix();

glPushMatrix();
glTranslatef(-15,85,0);
glScalef(1.85 - CloudSize,1.85 - CloudSize,0);
glRotatef(180,0,0,1);
Circle(5,30,8,0,150,150,150,200);
Circle(5,30,9,-1,255);
Circle(8,30,-2,-7,255);
Circle(6,30,0.85,-0.65,150,150,150,200);
Circle(6,30,0,0,255);
Circle(8,35,-9,0.5,150,150,150,200);
Circle(8,35,-8,2,255);
glPopMatrix();
}
//---------------------Cloud End
///Stars///
void Stars(){
glPushMatrix();
glRotatef(StarsAngel,0,0,1);
glScalef(1.5,1.5,0);
glPushMatrix();
glTranslatef(StarsPosition,125,0);
CirclePoints(30,20,0,0,5,255);
CirclePoints(20,10,0,0,5,255);
CirclePoints(10,5,0,0,5,255);
CirclePoints(5,5,0,0,5,255);
glPopMatrix();
glPushMatrix();
glTranslatef(StarsPosition+65,125,0);
CirclePoints(30,20,0,0,5,255);
CirclePoints(20,10,0,0,5,255);
CirclePoints(10,5,0,0,5,255);
CirclePoints(5,5,0,0,5,255);
glPopMatrix();
glPopMatrix();
}
//.............Stars End
///Big Planet///
void BigPlanets(){
glPushMatrix();
glTranslatef(BigPlanetPosition,180,0); //150 to -250
Circle(10,50,0,5,241,26,119,200);
Circle(15,50,-40,15,87,27,87,200);
Circle(20,50,35,-20,120,198,211,200);
Circle(13.5,50,60,170,26,113,200);
Circle(20,50,120,20,50,50,50,200);
glPopMatrix();
}
//.............Big Planet End
///Small Planet///
void SmallPlanets(){
glPushMatrix();
glTranslatef(SmallPlanetPosition,180,0);
Circle(7,25,0,5,50,50,50,185);
Circle(7,25,25,-25,241,26,119,185);
Circle(5,25,15,25,170,26,113,185);
Circle(3,25,-15,-20,87,27,87,185);
Circle(6,25,-35,-25,120,198,211,1855);
Circle(4,25,30,20,120,198,211,185);
Circle(3,25,95,15,50,50,50,185);
Circle(7,25,0,5,170,26,113,185);
Circle(7,25,95,-25,50,50,50,185);
Circle(3,25,83,-15,120,198,211,185);
Circle(6,25,67,0,170,26,113,185);
Circle(4,25,65,-20,120,198,211,185);
glPopMatrix();
}
//.............Small Planet End

///Gradient Effect///
void GradientEffect()
{
glBegin(GL_POLYGON);
glColor4ub(255,255,255,50);
glVertex2f(-50,-30);
glColor4ub(0,0,0,50);
glVertex2f(-50,150);
glColor4ub(0,0,0,50);
glVertex2f(-50,210);
glColor4ub(0,0,0,50);
glVertex2f(50,210);
glColor4ub(0,0,0,50);
glVertex2f(50,150);
glColor4ub(150,150,150,50);
glVertex2f(50,-30);
glEnd();
}
//...............Gradient Effect End
///Tong///
void Tong()
{
glLineWidth(3.5);

glPushMatrix();
glTranslatef(5,0,0);
glScalef(1.25,1,1);
glBegin(GL_QUADS);            //door wall
glColor3ub(138, 234, 237);
glVertex2f(-21,-15);
glVertex2f(-17,-15);
glVertex2f(-17,-11);
glVertex2f(-21,-11);
glEnd();

glBegin(GL_QUADS);            //door-side l
glColor3ub(212, 119, 119);
glVertex2f(-20.5,-15);
glVertex2f(-19.3,-15);
glVertex2f(-19.3,-12);
glVertex2f(-20.5,-12);
glEnd();

glBegin(GL_QUADS);            //door-side 2
glColor3ub(212, 119, 119);
glVertex2f(-19.2,-15);
glVertex2f(-17.9,-15);
glVertex2f(-17.9,-12);
glVertex2f(-19.2,-12);
glEnd();


glBegin(GL_QUADS);           //right-1
glColor3ub(60, 195, 199);
glVertex2f(-17,-15);
glVertex2f(-15,-15);
glVertex2f(-15,-11);
glVertex2f(-17,-11);
glEnd();

glBegin(GL_QUADS);           //right-2
glColor3ub(1, 88, 110);
glVertex2f(-15,-15);
glVertex2f(-10,-15);
glVertex2f(-10,-11);
glVertex2f(-15,-11);
glEnd();

glBegin(GL_QUADS);            //door-side 3
glColor3ub(209, 144, 159);
glVertex2f(-14.9,-14.7);
glVertex2f(-14,-14.7);
glVertex2f(-14,-12);
glVertex2f(-14.9,-12);
glEnd();

glBegin(GL_QUADS);            //door-side 4
glColor3ub(209, 144, 159);
glVertex2f(-13.9,-14.7);
glVertex2f(-11.1,-14.7);
glVertex2f(-11.1,-12);
glVertex2f(-13.9,-12);
glEnd();

glBegin(GL_QUADS);            //door-side 5
glColor3ub(209, 144, 159);   //pink
glVertex2f(-11,-14.7);
glVertex2f(-10.1,-14.7);
glVertex2f(-10.1,-12);
glVertex2f(-11,-12);
glEnd();

glBegin(GL_QUADS);            //2nd floor
glColor3ub(49, 165, 168);
glVertex2f(-21,-11);
glVertex2f(-16,-11);
glVertex2f(-16,-7);
glVertex2f(-21,-7);
glEnd();

glBegin(GL_QUADS);            //2nd floor-2
glColor3ub(38, 125, 128);
glVertex2f(-16,-11);
glVertex2f(-13,-11);
glVertex2f(-13,-7);
glVertex2f(-16,-7);
glEnd();

glBegin(GL_QUADS);            //smoke remove1
glColor3ub(49, 165, 168);
glVertex2f(-16.5,-6);
glVertex2f(-17,-6);
glVertex2f(-17,-5);
glVertex2f(-16.5,-5);
glEnd();

glBegin(GL_QUADS);            //smoke remove1'
glColor3ub(1, 88, 110);
glVertex2f(-16.5,-6);
glVertex2f(-16.3,-6);
glVertex2f(-16.3,-5);
glVertex2f(-16.5,-5);
glEnd();

glBegin(GL_QUADS);            //smoke remove2
glColor3ub(49, 165, 168);
glVertex2f(-17.5,-6);
glVertex2f(-18,-6);
glVertex2f(-18,-4.5);
glVertex2f(-17.5,-4.5);
glEnd();

glBegin(GL_QUADS);            //smoke remove2'
glColor3ub(1, 88, 110);
glVertex2f(-17.5,-6);
glVertex2f(-17.3,-6);
glVertex2f(-17.3,-4.5);
glVertex2f(-17.5,-4.5);
glEnd();

glBegin(GL_QUADS);            //2nd floor up
glColor3ub(204, 204, 204);
glVertex2f(-21,-7);
glVertex2f(-16,-7);
glVertex2f(-16,-6);
glVertex2f(-21,-6);
glEnd();

glBegin(GL_QUADS);            //2nd floor-2 up
glColor3ub(102, 129, 145);
glVertex2f(-16,-7);
glVertex2f(-13,-7);
glVertex2f(-13,-6);
glVertex2f(-16,-6);
glEnd();

glBegin(GL_QUADS);            //box1
glColor3ub(49, 165, 168);
glVertex2f(-14.7,-11);
glVertex2f(-14.5,-11);
glVertex2f(-14.5,-9.5);
glVertex2f(-14.7,-9.5);
glEnd();

glBegin(GL_QUADS);            //box1.
glColor3ub(33, 142, 156);
glVertex2f(-14.5,-11);
glVertex2f(-13.8,-11);
glVertex2f(-13.8,-9.5);
glVertex2f(-14.5,-9.5);
glEnd();

glBegin(GL_QUADS);            //box2
glColor3ub(49, 165, 168);
glVertex2f(-13.5,-11);
glVertex2f(-13.3,-11);
glVertex2f(-13.3,-9);
glVertex2f(-13.5,-9);
glEnd();

glBegin(GL_QUADS);            //box2.
glColor3ub(33, 142, 156);
glVertex2f(-13.3,-11);
glVertex2f(-12.5,-11);
glVertex2f(-12.5,-9);
glVertex2f(-13.3,-9);
glEnd();

glBegin(GL_QUADS);            //door wall up
glColor3ub(181, 181, 181);
glVertex2f(-21,-11);
glVertex2f(-17,-11);
glVertex2f(-17,-10);
glVertex2f(-21,-10);
glEnd();

glBegin(GL_QUADS);           //right-1 up
glColor3ub(102, 129, 145);
glVertex2f(-17,-11);
glVertex2f(-15,-11);
glVertex2f(-15,-10);
glVertex2f(-17,-10);
glEnd();

glBegin(GL_QUADS);            //colourful shed
glColor3ub(242, 240, 240);
glVertex2f(-21.5,-7.3);
glVertex2f(-21,-7.3);
glVertex2f(-20.5,-7);
glVertex2f(-21,-7);
glEnd();

glBegin(GL_QUADS);            //colourful shed2
glColor3ub(199, 56, 101);
glVertex2f(-21,-7.3);
glVertex2f(-20.5,-7.3);
glVertex2f(-20,-7);
glVertex2f(-20.5,-7);
glEnd();

glBegin(GL_QUADS);            //colourful shed3
glColor3ub(242, 240, 240);
glVertex2f(-20.5,-7.3);
glVertex2f(-20,-7.3);
glVertex2f(-19.5,-7);
glVertex2f(-20,-7);
glEnd();

glBegin(GL_QUADS);            //colourful shed4
glColor3ub(199, 56, 101);
glVertex2f(-20,-7.3);
glVertex2f(-19.5,-7.3);
glVertex2f(-19,-7);
glVertex2f(-19.5,-7);
glEnd();

glBegin(GL_QUADS);            //colourful shed5
glColor3ub(242, 240, 240);
glVertex2f(-19.5,-7.3);
glVertex2f(-19,-7.3);
glVertex2f(-18.5,-7);
glVertex2f(-19,-7);
glEnd();

glBegin(GL_QUADS);            //colourful shed6
glColor3ub(199, 56, 101);
glVertex2f(-19,-7.3);
glVertex2f(-18.5,-7.3);
glVertex2f(-18,-7);
glVertex2f(-18.5,-7);
glEnd();

glBegin(GL_QUADS);            //colourful shed7
glColor3ub(242, 240, 240);
glVertex2f(-18.5,-7.3);
glVertex2f(-18,-7.3);
glVertex2f(-17.5,-7);
glVertex2f(-18,-7);
glEnd();

glBegin(GL_QUADS);            //colourful shed8
glColor3ub(199, 56, 101);
glVertex2f(-18,-7.3);
glVertex2f(-17.5,-7.3);
glVertex2f(-17,-7);
glVertex2f(-17.5,-7);
glEnd();

glBegin(GL_QUADS);            //colourful shed9
glColor3ub(242, 240, 240);
glVertex2f(-17.5,-7.3);
glVertex2f(-17,-7.3);
glVertex2f(-16.5,-7);
glVertex2f(-17,-7);
glEnd();

glBegin(GL_QUADS);            //colourful shed10
glColor3ub(199, 56, 101);
glVertex2f(-17,-7.3);
glVertex2f(-16.5,-7.3);
glVertex2f(-16,-7);
glVertex2f(-16.5,-7);
glEnd();

glBegin(GL_LINES);   // white line
glColor3ub(255, 255, 255);
glVertex2f(-21.2, -11);
glVertex2f(-17,-11);
glEnd();

glBegin(GL_QUADS);           //sign-board
glColor3ub(1, 49, 138);
glVertex2f(-20.5,-11.5);
glVertex2f(-18,-11.5);
glVertex2f(-18,-9.5);
glVertex2f(-20.5,-9.5);
glEnd();

glBegin(GL_LINES);   // white line
glColor3ub(255, 255, 255);
glVertex2f(-17, -11);
glVertex2f(-14.8,-11);
glEnd();

glBegin(GL_LINES);   // table1
glColor3ub(176, 176, 176);
glVertex2f(-12.5, -15);
glVertex2f(-12.5,-14.5);
glEnd();

glBegin(GL_LINES);   // table1-
glColor3ub(255, 255, 255);
glVertex2f(-12, -14.5);
glVertex2f(-13,-14.5);
glEnd();

glBegin(GL_LINES);   // table2
glColor3ub(176, 176, 176);
glVertex2f(-13.5, -15);
glVertex2f(-13.5,-14.5);
glEnd();

glBegin(GL_LINES);   // table2-
glColor3ub(255, 255, 255);
glVertex2f(-13.9, -14.5);
glVertex2f(-13,-14.5);
glEnd();

//***********************************************Borders Starts*****
glLineWidth(1.5);
glBegin(GL_LINES);   // white line
glColor3ub(255, 255, 255);
glVertex2f(-20.5,-11.5);
glVertex2f(-18,-11.5);
glVertex2f(-18,-9.5);
glVertex2f(-20.5,-9.5);
glVertex2f(-18,-11.5);
glVertex2f(-18,-9.5);
glVertex2f(-20.5,-11.5);
glVertex2f(-20.5,-9.5);
glEnd();

glBegin(GL_LINES);
glColor3ub(102, 129, 145);
glVertex2f(-17.9,-11.5);
glVertex2f(-17.9,-9.5);
glEnd();

glBegin(GL_LINES);   // box1 -
glColor3ub(6, 41, 46);
glVertex2f(-14.3, -9.7);
glVertex2f(-14,-9.7);
glVertex2f(-14.3, -9.9);
glVertex2f(-14,-9.9);
glVertex2f(-14.3, -10.05);
glVertex2f(-14,-10.05);
glEnd();

glBegin(GL_LINES);   // box2 -
glColor3ub(173, 212, 0);
glVertex2f(-13.2, -9.3);
glVertex2f(-13,-9.3);
glVertex2f(-12.9, -9.3);
glVertex2f(-12.7,-9.3);
glVertex2f(-13.2, -9.7);
glVertex2f(-12.7,-9.7);
glEnd();

glBegin(GL_LINES);   // pipe
glColor3ub(0, 34, 186);
glVertex2f(-12.5, -9.3);
glVertex2f(-11.5,-9.3);
glVertex2f(-11.5, -9.3);
glVertex2f(-11.5,-11);
glVertex2f(-12.5, -9.7);
glVertex2f(-12,-9.7);
glVertex2f(-12, -9.7);
glVertex2f(-12,-11);
glEnd();

//*******************************************Borders Ends*****
glPopMatrix();

//*****Windows Starts*****
Circle(0.75,20,-19.7,-8.25,222);    //Windows 1 circle border
Circle(0.6,20,-19.7,-8.25,212,119,119,255); //Windows 1 circle

Circle(0.75,20,-17,-8.25,222);//Windows 2 circle border
Circle(0.6,20,-17,-8.25,212,119,119,255);//Windows 2 circle

//win1 lines
glLineWidth(3.5);
glBegin(GL_LINES);
glColor3ub(222, 222, 222);
glVertex2f(-20.35, -8.25);
glVertex2f(-19,-8.25);
glVertex2f(-19.7, -7.65);
glVertex2f(-19.7,-8.85);
glEnd();
//win2 lines
glBegin(GL_LINES);
glColor3ub(222, 222, 222);
glVertex2f(-16.3, -8.25);
glVertex2f(-17.6,-8.25);
glVertex2f(-17, -7.65);
glVertex2f(-17,-8.85);
glEnd();
//*****Windows End*****

//********************************** TONG TEXT******************************
glColor3ub(255,255,255);
if(TongCurrentCharecter == 1){DrawTextStroke(-20.5,-11,0,0.0085,2,"T");}
if(TongCurrentCharecter == 2){DrawTextStroke(-19.85,-11,0,0.0085,2,"O");}
if(TongCurrentCharecter == 3){DrawTextStroke(-19.1,-11,0,0.0085,2,"N");}
if(TongCurrentCharecter == 4){DrawTextStroke(-18.35,-11,0,0.0085,2,"G");}
if(TongCurrentCharecter > TongMaxCharecter){DrawTextStroke(-20.5,-11,0,0.0085,2,"TONG");}
//******************************** TONG TEXT END****************************
}
//---------------------------------Tong End
///ControlsInfo///
void ControlsInfo(){
glColor3ub(255,255,255);
DrawTextStroke(-30,15,0,0.025,5,"Press Mouse Left To Launch Rocket");
DrawTextStroke(-25,185,0,0.025,5,"Press Mouse Right To Take Off");
DrawTextStroke(-18,180,0,0.015,3,"Press W & S To Control Rocket");
DrawTextStroke(-15.5,175,0,0.015,3,"Press Q To Increase Speed");
}
//---------------------------------ControlsInfo
///Robot///
void Robot()
{
glLineWidth(3.5);

glPushMatrix();
glTranslatef(RobotPosition-22.5,0,0);
glRotatef(RobotAngle,0,1,0);
glPushMatrix();
glTranslatef(22.5,0,0);
glBegin(GL_QUADS);            //robot left ear
glColor3ub(93, 132, 140);
glVertex2f(-23,-12);
glVertex2f(-22.6,-12.4);
glVertex2f(-22.5,-13);
glVertex2f(-23,-13.3);
glEnd();

glBegin(GL_QUADS);            //robot front head
glColor3ub(224, 224, 224);
glVertex2f(-23,-12);
glVertex2f(-22.6,-12.4);
glVertex2f(-21.9,-12.4);
glVertex2f(-22.3,-12);
glEnd();

glBegin(GL_QUADS);            //robot face
glColor3ub(18, 71, 140);
glVertex2f(-22.6,-12.4);
glVertex2f(-22.5,-13);
glVertex2f(-21.8,-13);
glVertex2f(-21.9,-12.4);
glEnd();


glBegin(GL_QUADS);            //robot face down
glColor3ub(224, 224, 224);
glVertex2f(-22.5,-13);
glVertex2f(-23,-13.3);
glVertex2f(-22.3,-13.3);
glVertex2f(-21.8,-13);
glEnd();

glBegin(GL_POLYGON);       //robot body left
glColor3ub(93, 132, 140);

glVertex2f(-23,-13.4);
glVertex2f(-22.6,-13.4);
glVertex2f(-22.5, -13.7);
glVertex2f(-22.5, -15);
glVertex2f(-23, -15);

glEnd();

glBegin(GL_QUADS);            //robot body front
glColor3ub(224, 224, 224);
glVertex2f(-22.6,-13.4);
glVertex2f(-22.5,-13.7);
glVertex2f(-21.8,-13.7);
glVertex2f(-21.9,-13.4);
glEnd();


glBegin(GL_POLYGON);       //robot body left
glColor3ub(170, 181, 191);

glVertex2f(-22.5,-13.7);
glVertex2f(-22.5,-15);
glVertex2f(-22.1,-15);
glVertex2f(-21.8,-14.7);
glVertex2f(-21.8, -13.7);
glEnd();

glBegin(GL_QUADS);            //robot hand part 1
glColor3ub(209, 222, 235);
glVertex2f(-23.1,-13.6);
glVertex2f(-23.1,-14.5);
glVertex2f(-22.9,-14.5);
glVertex2f(-22.9,-13.6);
glEnd();

glBegin(GL_QUADS);            //robot hand part 2
glColor3ub(209, 222, 235);
glVertex2f(-23.1,-14.4);
glVertex2f(-23.1,-14.6);
glVertex2f(-22.5,-14.6);
glVertex2f(-22.5,-14.4);
glEnd();

glBegin(GL_LINES);   // tray
glColor3ub(108, 46, 117);
glVertex2f(-22.5, -14.5);
glVertex2f(-21,-14.5);
glEnd();


glBegin(GL_QUADS);            //juice
glColor3ub(229, 73, 235);
glVertex2f(-21.6,-14);
glVertex2f(-21.5,-14.5);
glVertex2f(-21.4,-14.5);
glVertex2f(-21.3,-14);
glEnd();

glBegin(GL_LINES);   // robot eye
glColor3ub(229, 227, 230);
glVertex2f(-22.4, -12.7);
glVertex2f(-22.3,-12.7);
glEnd();

glBegin(GL_LINES);   // robot eye2
glColor3ub(229, 227, 230);
glVertex2f(-22.2, -12.7);
glVertex2f(-22.1,-12.7);
glEnd();

//Robot Hand Circles
Circle(0.25,10,-23, -13.6,222);
Circle(0.15,10,-23, -13.6,93, 132, 140,255);
Circle(0.25,10,-23,-14.5,222);
Circle(0.15,10,-23,-14.5,93, 132, 140,255);
Circle(0.3,10,-22.25,-14.5,0);
glPopMatrix();
glPopMatrix();
}
//.................Robot End
///Print Function | (All Shapes Functions Goes Here)
void PrintFunction()
{
    ///Layer 1 - Background///
    glPushMatrix();
    glTranslatef(0,BackgroundPosition,0);
    Sky();
    //GradientEffect(); ///Gradient Layer 1
    AirPlane();
    Cloud();
    Backmountain();
    Mountain();
    NASA();
    RocketHolder();
    LeftSideBuilding();
    Tong();
    Tree();
    Robot();
    Tower();
    Road();
    RoadLines();
    TeslaCar();
    StreetSideGlass();
    //GradientEffect(); ///Gradient Layer 2
    Stars();
    SmallPlanets();
    ControlsInfo();
    glPopMatrix();

    ///Layer 2 - Rocket///
    Rocket();

    ///Layer 3 - Foreground///
    glPushMatrix();
    glTranslatef(0,BackgroundPosition,0);
    BigPlanets();
    TowerLight();
    FrontTree();
    //GradientEffect(); ///Gradient Layer 3
    glPopMatrix();
}
//............Print Function End

///...............................................UPDATE............................................... .///
///TeslaCar Move///
void TeslaCarMovement(int value){

if(TeslaCarPosition < 100){ TeslaCarPosition += TeslaCarMoveSpeed; }
else{
        TeslaCarPosition = -100;

        if(TeslaCarAngle == 0){TeslaCarAngle = 180;}
        else { TeslaCarAngle = 0;}
}
glutPostRedisplay();
glutTimerFunc(10, TeslaCarMovement, 0);
}
//-----------------TeslaCar Move End
///AirPlane Move///
void AirPlaneMovement(int value){

if(AirPlanePosition > -90){ AirPlanePosition -= AirPlaneMoveSpeed; }
else{
        AirPlanePosition = 90;

       if(AirPlaneAngle == 0){AirPlaneAngle = 180;}
       else { AirPlaneAngle = 0;}
}
glutPostRedisplay();
glutTimerFunc(10, AirPlaneMovement, 0);
}
//-----------------AirPlane Move End
///Tong Text Animation///
void TongTextAnimation(int value)
{
    if(TongCurrentCharecter <= TongMaxCharecter){TongCurrentCharecter++;}
    else{TongCurrentCharecter =0;}

    glutPostRedisplay();
    glutTimerFunc(500,TongTextAnimation,0);
}
//-----------Tong Text Animation End
///Rocket Window Animation///
void RocketWindowAnimation(int value)
{
   if(isRocketinGalaxy){RocketWindowSpinSpeed = RocketWindowSpinSpeedFixed*25;}
   else{RocketWindowSpinSpeed = RocketWindowSpinSpeedFixed; }

   if(RocketWindowAngle < 360){ RocketWindowAngle +=RocketWindowSpinSpeed;}
   else{RocketWindowAngle = 0;}
   glutPostRedisplay();
   glutTimerFunc(10,RocketWindowAnimation,0);
}
//------------Rocket Window Animation End
///Tower Light Animation///
void TowerLightAnimation(int value)
{
    if(isTowerLightPositive){
        if(TowerLightAngle > -50){ TowerLightAngle -=TowerLightSpinSpeed;}
        else{TowerLightAngle = -50; isTowerLightPositive=false;}
    }
    else
    {
    if(!isTowerLightPositive){
        if(TowerLightAngle < 90 && !isTowerLightPositive){ TowerLightAngle +=TowerLightSpinSpeed;}
        else{TowerLightAngle = 90; isTowerLightPositive=true;}
    }
    }

   glutPostRedisplay();
   glutTimerFunc(10,TowerLightAnimation,0);
}
//------------Tower Light Animation End
///Big Planet Move Animation///
void BigPlanetMoveAnimation(int value)
{
   if(BigPlanetPosition > -195){BigPlanetPosition -= BigPlanetMoveSpeed;}
   else{BigPlanetPosition = 110;}
   glutPostRedisplay();
   glutTimerFunc(10,BigPlanetMoveAnimation,0);
}
//-----------------------Big Planet Move Animation End
///Rocket Smoke Animation///
void RocketSmokeAnimation(int value)
{

///Stop Rocket Smoke

if(RocektSmokeSize < 0.55){RocektSmokeSize+=RocektSmokeSizeChanger;}
else{RocektSmokeSize = 0.15;}

glutPostRedisplay();
glutTimerFunc(10,RocketSmokeAnimation,0);
}
//-----------------------Rocket Smoke Animation End
///Small Planet Move Animation///
void SmallPlanetMoveAnimation(int value)
{
   if(SmallPlanetPosition > -155){SmallPlanetPosition -= SmallPlanetMoveSpeed;}
   else{SmallPlanetPosition = 100;}
   glutPostRedisplay();
   glutTimerFunc(10,SmallPlanetMoveAnimation,0);
}
//-----------------------Small Planet Move Animation End
///NASA Circle Animation///
void NasaCircleAnimation(int value)
{
   if(NasaCircleAngle < 360){ NasaCircleAngle += NasaCircleSpinSpeed;}
   else{NasaCircleAngle = 0;}
   glutPostRedisplay();
   glutTimerFunc(10,NasaCircleAnimation,0);
}
//------------NASA Circle Animation End
///Cloud Animation///
void CloudAnimation(int value)
{
if(CloudSize > 0.5f && !isCloudSmall){ CloudSize -= CloudSizeChanger;}
else{ isCloudSmall = true;}

if(CloudSize < 1 && isCloudSmall){ CloudSize += CloudSizeChanger;}
else{ isCloudSmall = false;}

glutPostRedisplay();
glutTimerFunc(50,CloudAnimation,0);
}
//------------Cloud Animation End
///Rocket In Galaxy///
void RocketInGalaxy(int value)
{
//Rotate
if(RocketAngle>-90){RocketAngle -= RocketSpinSpeed;}
else{RocketAngle = -90;}
//Scale Small & Translate To Left
if(RocketAngle == -90){
if(RocketPosition > -40){ RocketPosition -= RocketMoveSpeed;}else {RocketPosition = -40;}
if(RocketSize > 0.7){ RocketSize -= RocketSizeChanger;} else {RocketSize = 0.7;}
}

if(!(RocketPosition == -40)){
glutPostRedisplay();
glutTimerFunc(10,RocketInGalaxy, 0);
}else{
    ///Speed Change - Increase///
    //Press 'Q' To Increase Speed
    isProcessing = false;
    canRocketControl = true;
}
}
//------------------------Rocket In Galaxy End
///Rocket In Ground///
void BackgroundTowardGround(int);
void RocketInGround(int value)
{
//Scale Small & Translate To Left
if(RocketPosition < 0){ RocketPosition += RocketMoveSpeed;}else {RocketPosition = 0;}
if(RocketSize < 1){ RocketSize += RocketSizeChanger;} else {RocketSize = 1;}

//Reset Rocket Y Position
if(RocketPositionY < 0){ RocketPositionY += RocketMoveSpeed;}
else if(RocketPositionY > 0){ RocketPositionY -= RocketMoveSpeed;}
else {RocketPositionY = 0;}

//Rotate
if((RocketPosition == 0)){
///Speed Change - Decrease///
StarsMoveSpeed = 0.05f;
BigPlanetMoveSpeed = 0.15;
SmallPlanetMoveSpeed = 0.065;
if(RocketAngle < 0){RocketAngle += RocketSpinSpeed;}
else{RocketAngle = 0;}
}
if(!(RocketAngle == 0)){
glutPostRedisplay();
glutTimerFunc(10,RocketInGround, 0);
}
else{
glutTimerFunc(10, BackgroundTowardGround, 0);
}
}
//------------------------Rocket In Ground End
///Background Toward Galaxy///
void BackgroundTowardGalaxy(int value){

if(BackgroundPosition > FinalDestination){ BackgroundPosition -=BackgroundMoveSpeed;}
else{BackgroundPosition = FinalDestination;}

glutPostRedisplay();

if(BackgroundPosition == FinalDestination){
isRocketinGalaxy = true;
glutTimerFunc(10,RocketInGalaxy,0);
}

if(!isRocketinGalaxy){
glutTimerFunc(10, BackgroundTowardGalaxy, 0);
}
}
//-----------------Background Toward Galaxy End
///Background Toward Ground///
void BackgroundTowardGround(int value){

if(BackgroundPosition < FinalDestination){ BackgroundPosition +=BackgroundMoveSpeed;}
else{BackgroundPosition = FinalDestination;}

glutPostRedisplay();

///Run Only Once After Rocket's Landing
if(BackgroundPosition == FinalDestination){
isProcessing = false;
isRocketinGalaxy = false;
isStartRocketSmoke=false;
PlayMusicCustom(BackgroundMusic,true,true); ///Play Music
}

if(isRocketinGalaxy){
glutTimerFunc(10, BackgroundTowardGround, 0);
}
}
//-----------------Background Toward Ground End
///Stars Move///
void StarsMove(int value){
    if(StarsPosition > -65){
    StarsPosition-=StarsMoveSpeed;
    StarsAngel = 0;
    }
    else
    {
      StarsPosition = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(10,StarsMove, 0);
}
//-------------Stars Move End
void RobotMovement(int value){

if(RobotPosition < 15 && !isRobotRight){ RobotPosition += RobotMoveSpeed;}
else if(RobotPosition > 0 && isRobotRight){RobotPosition -= RobotMoveSpeed;}
else{
    if(!isRobotRight){isRobotRight = true; RobotAngle =180; }
    else{ if(isRobotRight){isRobotRight = false; RobotAngle = 0;}}

}
glutPostRedisplay();
glutTimerFunc(10, RobotMovement, 0);
}
///Main Update | (All Update Functions Goes Here)
void UpdateFunctions()
{
 glutTimerFunc(10,TeslaCarMovement, 0);
 glutTimerFunc(10, AirPlaneMovement, 0);
 glutTimerFunc(10,StarsMove, 0);
 glutTimerFunc(10,TongTextAnimation,0);
 glutTimerFunc(10,RocketWindowAnimation,0);
 glutTimerFunc(10,NasaCircleAnimation,0);
 glutTimerFunc(50,CloudAnimation,0);
 glutTimerFunc(10,TowerLightAnimation,0);
 glutTimerFunc(10,BigPlanetMoveAnimation,0);
 glutTimerFunc(10,SmallPlanetMoveAnimation,0);
 glutTimerFunc(10,RocketSmokeAnimation,0);
 glutTimerFunc(10, RobotMovement, 0);
}
//..........Main Update End

///................................................CONTROLS............................................///

///Mouse///
void mouse(int button,int state,int x,int y)
{
switch(button)
{
if(!isProcessing)
{
case GLUT_LEFT_BUTTON:
{
if(state==GLUT_DOWN && !isProcessing && !isRocketinGalaxy){
isProcessing = true;        ///Start Process - Rocket toward Galaxy
isStartRocketSmoke = true; ///Start Rocket Smoke
PlayMusicCustom(MusicAfterLaunch,true,true); ///Play Music
FinalDestination = -180;
glutTimerFunc(10, BackgroundTowardGalaxy, 0);
}
} break;

case GLUT_RIGHT_BUTTON:
{
if(state==GLUT_DOWN && !isProcessing && isRocketinGalaxy){
isProcessing = true;
canRocketControl = false;
FinalDestination = 0;
glutTimerFunc(10,RocketInGround, 0);
}
} break;

default:
    break;
}
}
}
///Keyboard///
void keyboard(unsigned char key, int x, int y)
{
if(canRocketControl)
{
if(key=='w' || key=='W')
{
RocketPositionY+=RocketMoveSpeed*5;
}
if(key=='s' || key=='S')
{
RocketPositionY-=RocketMoveSpeed*5;
}
if(key=='q' || key=='Q'){
   BigPlanetMoveSpeed = 1;
   SmallPlanetMoveSpeed = 0.35;
   StarsMoveSpeed = 0.75;
}
}
}
///................................................SYSTEM..............................................///
///Initial Default Values | (Sealed)
void inttDefaultDisplay()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 				             // Set Background Color
	glPointSize(5.0f);                    				             // Set Point Size (Default)
	glLineWidth(5.0f);                    				             // Set Lind Width (Default)
	glColor3ub(0, 0, 0);                  				             // Set Color (Default)
    glOrtho(-DisplaySizeX,DisplaySizeX,-DisplaySizeY,DisplaySizeY,-10,10); // Set "Ortho"
	glEnable(GL_BLEND);                   				             //Enable Blend
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);               //Enable Blend
}
///................Initial Default Values End
///Display | (Sealed)
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);         			   // Set "clearing"
    PrintFunction();                                   // Print Shapes
    glutSwapBuffers();                                 // Scene Change Function
}
//.................Display Function End
/// Main Function | (Sealed)
int main(int argc, char** argv) {

	glutInit(&argc, argv);                 //Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);         // Color Mode
	glutInitWindowPosition(200,100);       // Window Position
    glutInitWindowSize(480, 270);          // Set the window's initial width & height
	glutCreateWindow("Wonders of Galaxy with Rocket Journey"); // Create a window with the given title
	glutDisplayFunc(display);              // Register display callback handler for window re-paint
    inttDefaultDisplay();          	           // Set "clearing" or background color
    UpdateFunctions();                         //Call Functions To Start Animation
    PlayMusicCustom(BackgroundMusic,true,true); ///Play Music
    glutMouseFunc(mouse);                    //To Control with mouse
    glutKeyboardFunc(keyboard);               //To Control with keyboard
	glutMainLoop();                        // Enter the event-processing loop
	return 0;
}
//..............Main Function End
