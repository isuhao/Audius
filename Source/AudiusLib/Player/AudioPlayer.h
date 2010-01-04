#pragma once
////////////////////////////////////////////////////////////////////////////////////////
//	   File: AudioPlayer.h
////////////////////////////////////////////////////////////////////////////////////////
// Description:
//
// Handles audio playing both for local files and streaming from remote services.
// Wraps different 3rd party libs for supporting various formats.
//
////////////////////////////////////////////////////////////////////////////////////////

#include "juce.h"

#include "PlayerStatus.h"
#include "Playlist.h"

class SongInfo;

class AudioPlayer : public DeletedAtShutdown,
					public ActionBroadcaster,
					private ChangeListener
{
private:
	AudioPlayer(void);
	~AudioPlayer(void);

public:
	juce_DeclareSingleton(AudioPlayer, true)

	void initialise();
	void shutdown();

	void startPlaying();
	void pausePlaying();
	void togglePlayPause();
	void stopPlaying();
	void goToNext();
	void goToPrevious();
	void refreshPlaylist();

	Player::Status getPlayerStatus();

	boost::shared_ptr<Playlist> getPlaylist();
	boost::shared_ptr<SongInfo> getCurrentSong();

private:
	void changeListenerCallback(void* objectThatHasChanged);

	void refreshStream();

private:
	class impl;
	impl* vars;
};
