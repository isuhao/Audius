#include "Precompiled.h"
#include "PlaylistAudioSource.h"

#include "Playlist.h"

#include "../Downloader/DownloadManager.h"

PlaylistAudioSource::PlaylistAudioSource(void)
{
}

PlaylistAudioSource::~PlaylistAudioSource(void)
{
}

void PlaylistAudioSource::prepareToPlay( int samplesPerBlockExpected, double sampleRate )
{
	AudioTransportSource::prepareToPlay(samplesPerBlockExpected, sampleRate);

	if(!_playlist)
		return;

	// Initiate playing from playlist
	std::shared_ptr<PlaylistEntry> entry = _playlist->getCurrentEntry();
	if(!entry)
		return;

	//DownloadProgressDelegate callback = boost::bind(&PlaylistAudioSource::receiveData, this, _1);
	//_downloadThread = DownloadManager::getInstance()->downloadAsync(entry->getUrl(), callback);
}

void PlaylistAudioSource::receiveData(std::shared_ptr<DownloadProgressEventArgs> args)
{

}

void PlaylistAudioSource::getNextAudioBlock( const AudioSourceChannelInfo& bufferToFill )
{
	// Plocka fr�n aktuell download buffert
	// Om det inte finns n�gon buffert, starta download
	// Om download �r klar, starta eventuell n�sta download

	// StreamingSource laddar fr�n en URL

	AudioTransportSource::getNextAudioBlock(bufferToFill);
}