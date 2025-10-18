#include "SubApp.h"
//Hello my name is Tony
SubApp::SubApp()
	: m_AppID(EAppID::InvalidApp)
{}

SubApp::SubApp(EAppID p_AppID)
	: m_AppID(p_AppID)
{}

EAppID SubApp::GetAppID() const
{
	return m_AppID;
}