#include "stdafx.h"
#include "WinUnit.h"

#include "AudiusLib/AudiusLib.h"

using namespace boost;

BEGIN_TEST(Downloader_CanDownloadStream)
{
	try
	{
		shared_ptr<DownloadStream> stream = DownloadManager::getInstance()->downloadAsync(T("http://www.google.com"));
		stream->wait(5000);

		WIN_ASSERT_TRUE( stream->getCurrentLength() >= 0 );
	}
	catch(Exception & ex)
	{
		String msg = ex.getFullMessage();
		WIN_ASSERT_FAIL(msg);
	}
}
END_TEST