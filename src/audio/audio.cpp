#include "audio.h"

#ifdef _WIN32 //TODO: Create linux audio engine implementation
#include <Windows.h>
#pragma comment(lib, "winmm.lib")
void Audio::EnginePlaySound(char sound[])
{
    PlaySound(TEXT(sound), NULL, SND_FILENAME | SND_ASYNC);
}
#endif