#include "render/GameObject.h"

class UI : public GameObject
{
private:
    

public:
    int PosOnScreen;
    virtual int Create();
    virtual int Render();
};