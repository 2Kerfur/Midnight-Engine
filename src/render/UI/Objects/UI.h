#ifndef UI_H
#define UI_H
#include "render/GameObject.h"
class UI : public GameObject
{
private:
public:
    //void setGlobalPos(int x, int y);
    //int PosOnScreen;
    virtual int Create();
    virtual int Render();
};
#endif