#pragma once
////////////////////////////////////////////////////////////////////////////////////////
//	   File: SpotifyEventArgs.h
////////////////////////////////////////////////////////////////////////////////////////
// Description:
//
// Contains information about a Spotify event that has occured.
//
////////////////////////////////////////////////////////////////////////////////////////

#include "juce.h"

class SpotifyEventArgs;

// Callback delegates
typedef boost::function<void ()> SpotifyCallbackDelegate;
typedef boost::function<void (boost::shared_ptr<SpotifyEventArgs> args)> SpotifyEventDelegate;

class SpotifyEventArgs
{
public:
	SpotifyEventArgs()
	{

	}
};