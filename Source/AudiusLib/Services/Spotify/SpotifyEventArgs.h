#pragma once
////////////////////////////////////////////////////////////////////////////////////////
//	   File: SpotifyEventArgs.h
////////////////////////////////////////////////////////////////////////////////////////
// Description:
//
// Contains information about a Spotify event that has occurred.
//
////////////////////////////////////////////////////////////////////////////////////////

#include "juce.h"

class SpotifyEventArgs;

// Callback delegates
typedef std::function<void ()> SpotifyCallbackDelegate;
typedef std::function<void (std::shared_ptr<SpotifyEventArgs> args)> SpotifyEventDelegate;

class SpotifyEventArgs
{
public:
	SpotifyEventArgs()
	{

	}
};
