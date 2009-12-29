#pragma once
////////////////////////////////////////////////////////////////////////////////////////
//	   File: DownloadStream.h
////////////////////////////////////////////////////////////////////////////////////////
// Description:
//
// A stream used when downloading data. The stream is filled in the background but can
// be accessed before it is completely filled.
//
////////////////////////////////////////////////////////////////////////////////////////

#include "juce.h"

#include "../System/Net/DataReceivedEventArgs.h"

class WebRequest;

class DownloadStream
{
	// Only download manager can create download streams
	friend class DownloadManager;
private:
	DownloadStream(const String & url);

public:
	~DownloadStream(void);

	int64 getCurrentLength() { return _bytesRead; }
	int getEstimatedSecondsLeft() { return _secondsLeft; }

	// Waits until the download is complete (-1 = infinite)
	bool wait(int timeoutMilliseconds);

	// Private methods called by the download manager to control the stream
private:
	// Starts downloading in the background
	void start();

	// Aborts the current download (done by manager)
	void abort();

	void receiveData(boost::shared_ptr<DataReceivedEventArgs> args);

private:
	CriticalSection	_lock;

	boost::shared_ptr<WebRequest> _request;

	MemoryBlock		_buffer;

	int64	_bytesRead;
	int64	_startTime;
	int		_secondsLeft;
};