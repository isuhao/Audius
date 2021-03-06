#pragma once
////////////////////////////////////////////////////////////////////////////////////////
//	   File: WebRequestManager.h
////////////////////////////////////////////////////////////////////////////////////////
// Description:
//
// Handles all ongoing connections for the application. Ensures that web communication
// is properly initialized.
//
////////////////////////////////////////////////////////////////////////////////////////

//#include <boost/shared_ptr.hpp>

#include "juce.h"

class WebRequest;

class WebRequestManager : public DeletedAtShutdown
{
public:
	juce_DeclareSingleton(WebRequestManager, true)

	void beginRequest(WebRequest* request);
	void closeRequest(WebRequest* request);

private:
	WebRequestManager(void);
	~WebRequestManager(void);

	class impl;
	impl* vars;
};
