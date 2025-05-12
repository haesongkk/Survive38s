#include "Header.h"
#include "Sound.h"

#include <mmsystem.h>;                
#include <Digitalv.h>; 

#pragma comment (lib, "winmm.lib")  

void InitSound()
{
    Play(L"./Resource/BGM.wav", 100);
}

void UpdateSound()
{
}

void FinalSound()
{
    Stop();
}

void Play(wstring _soundFile, int _volume)
{
    DWORD dwVolume = (DWORD)(0xFFFF * _volume / 100);
    PlaySound(_soundFile.c_str(), NULL, SND_ASYNC | SND_LOOP | SND_NOSTOP);
    waveOutSetVolume(NULL, MAKELONG(dwVolume, dwVolume));
}

void Stop()
{
    PlaySound(NULL, NULL, NULL);
}
