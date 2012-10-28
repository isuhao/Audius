/*
  ==============================================================================

    App.h
    Created: 11 Oct 2012 6:03:18pm
    Author:  Pontus

  ==============================================================================
*/

#ifndef __AUDIUS_APPLICATION__
#define __AUDIUS_APPLICATION__

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"

#include "Lua/LuaLibrary.h"
#include "LuaBridge/LuaBridge.h"

//==============================================================================
class AudiusApplication  : public JUCEApplication
{
public:
    //==============================================================================
    AudiusApplication() {}

    const String getApplicationName()       { return ProjectInfo::projectName; }
    const String getApplicationVersion()    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed()       { return true; }

    //==============================================================================
    void initialise (const String& commandLine)
    {
        // This method is where you should put your application's initialisation code..

        mainWindow = new MainWindow();
    }

    void shutdown()
    {
        // Add your application's shutdown code here..

        mainWindow = nullptr; // (deletes our window)
    }

    //==============================================================================
    void systemRequestedQuit()
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }

    void anotherInstanceStarted (const String& commandLine)
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }

    //==============================================================================
    /*
        This class implements the desktop window that contains an instance of
        our MainContentComponent class.
    */
    class MainWindow    : public DocumentWindow
    {
    public:
        MainWindow()  : DocumentWindow ("MainWindow",
                                        Colours::lightgrey,
                                        DocumentWindow::allButtons)
        {
            setContentOwned (new MainContentComponent(), true);

            centreWithSize (getWidth(), getHeight());
            setVisible (true);
        }

        void closeButtonPressed()
        {
            // This is called when the user tries to close this window. Here, we'll just
            // ask the app to quit when this happens, but you can change this to do
            // whatever you need.
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

        /* Note: Be careful if you override any DocumentWindow methods - the base
           class uses a lot of them, so by overriding you might break its functionality.
           It's best to do all your work in your content component instead, but if
           you really have to override any DocumentWindow methods, make sure your
           subclass also calls the superclass's method.
        */

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow);
    };

private:
    ScopedPointer<MainWindow> mainWindow;
};



#endif  // __AUDIUS_APPLICATION__