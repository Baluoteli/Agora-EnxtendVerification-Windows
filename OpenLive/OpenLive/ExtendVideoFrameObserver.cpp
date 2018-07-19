#include "stdafx.h"
#include "ExtendVideoFrameObserver.h"
#include <iostream>


CExtendVideoFrameObserver::CExtendVideoFrameObserver()
{
	m_lpImageBuffer = new BYTE[0x800000];
}


CExtendVideoFrameObserver::~CExtendVideoFrameObserver()
{
	delete[] m_lpImageBuffer;
}

bool CExtendVideoFrameObserver::onCaptureVideoFrame(VideoFrame& videoFrame)
{
	SIZE_T nBufferSize = 0x800000;
	
	FILE* pFileRecord = fopen("..\\Extendaudio.txt", "ab+");
	if (pFileRecord) {

		std::string str = __FUNCTION__ + std::string("\n");
		fwrite(str.data(), 1, str.length(), pFileRecord);
		fclose(pFileRecord);
		pFileRecord = nullptr;
	}

	return true;
}

bool CExtendVideoFrameObserver::onRenderVideoFrame(unsigned int uid, VideoFrame& videoFrame)
{
	return true;
}
