#include "Header.h"
#include "Sound.h"

#pragma comment (lib, "winmm.lib")  
#include <mmsystem.h>;                
#include <Digitalv.h>; 


void PlayBGM(wstring _soundFile, int _volume)
{
    DWORD dwVolume = (DWORD)(0xFFFF * _volume / 100);
    PlaySound(_soundFile.c_str(), NULL, SND_ASYNC | SND_LOOP | SND_NOSTOP);
    waveOutSetVolume(NULL, MAKELONG(dwVolume, dwVolume));
}

void StopBgm()
{
    PlaySound(NULL, NULL, NULL);
}
