/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  9 Jul 2009 4:37:37 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.11

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "Precompiled.h"
//[/Headers]

#include "LoginComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

#define LOGIN_KEY	T("login")
#define PWD_KEY		T("pwd")
#define RMB_KEY		T("remember")

//[/MiscUserDefs]

//==============================================================================
LoginComponent::LoginComponent ()
    : textLogin (0),
      label (0),
      label2 (0),
      textPassword (0),
      toggleRemember (0),
      buttonLogin (0),
      buttonCancel (0)
{
    addAndMakeVisible (textLogin = new TextEditor (T("Login")));
    textLogin->setMultiLine (false);
    textLogin->setReturnKeyStartsNewLine (false);
    textLogin->setReadOnly (false);
    textLogin->setScrollbarsShown (true);
    textLogin->setCaretVisible (true);
    textLogin->setPopupMenuEnabled (true);
    textLogin->setText (String::empty);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Login")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredRight);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Password")));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredRight);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (textPassword = new TextEditor (T("Password")));
    textPassword->setMultiLine (false);
    textPassword->setReturnKeyStartsNewLine (false);
    textPassword->setReadOnly (false);
    textPassword->setScrollbarsShown (true);
    textPassword->setCaretVisible (true);
    textPassword->setPopupMenuEnabled (true);
    textPassword->setText (String::empty);

    addAndMakeVisible (toggleRemember = new ToggleButton (T("Remember")));
    toggleRemember->setButtonText (T("Remember me"));
    toggleRemember->addButtonListener (this);

    addAndMakeVisible (buttonLogin = new TextButton (T("LoginButton")));
    buttonLogin->setButtonText (T("Login"));
    buttonLogin->addButtonListener (this);

    addAndMakeVisible (buttonCancel = new TextButton (T("CancelButton")));
    buttonCancel->setButtonText (T("Cancel"));
    buttonCancel->addButtonListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 150);

    //[Constructor] You can add your own custom stuff here..
	textPassword->setPasswordCharacter(0x2022);

	PropertiesFile* props = ApplicationProperties::getInstance()->getUserSettings();
	textLogin->setText(props->getValue(LOGIN_KEY));
	textPassword->setText(props->getValue(PWD_KEY));
	toggleRemember->setToggleState(props->getBoolValue(RMB_KEY), true);
    //[/Constructor]
}

LoginComponent::~LoginComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (textLogin);
    deleteAndZero (label);
    deleteAndZero (label2);
    deleteAndZero (textPassword);
    deleteAndZero (toggleRemember);
    deleteAndZero (buttonLogin);
    deleteAndZero (buttonCancel);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void LoginComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void LoginComponent::resized()
{
    textLogin->setBounds (104, 8, 150, 24);
    label->setBounds (8, 8, 89, 24);
    label2->setBounds (8, 40, 88, 24);
    textPassword->setBounds (104, 40, 150, 24);
    toggleRemember->setBounds (104, 72, 150, 24);
    buttonLogin->setBounds (152, 112, 136, 24);
    buttonCancel->setBounds (8, 112, 136, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void LoginComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleRemember)
    {
        //[UserButtonCode_toggleRemember] -- add your button handler code here..
        //[/UserButtonCode_toggleRemember]
    }
    else if (buttonThatWasClicked == buttonLogin)
    {
        //[UserButtonCode_buttonLogin] -- add your button handler code here..

		PropertiesFile* props = ApplicationProperties::getInstance()->getUserSettings();
		props->setValue(RMB_KEY, toggleRemember->getToggleState());
		if(toggleRemember->getToggleState())
		{
			props->setValue(LOGIN_KEY, getLogin());
			props->setValue(PWD_KEY, getPassword());
		}
		else
		{
			props->setValue(LOGIN_KEY, String::empty);
			props->setValue(PWD_KEY, String::empty);
		}
		ApplicationProperties::getInstance()->saveIfNeeded();

		DialogWindow* dw = findParentComponentOfClass((DialogWindow*)0);
		if(dw)
			dw->exitModalState(1);
        //[/UserButtonCode_buttonLogin]
    }
    else if (buttonThatWasClicked == buttonCancel)
    {
        //[UserButtonCode_buttonCancel] -- add your button handler code here..
		DialogWindow* dw = findParentComponentOfClass((DialogWindow*)0);
		if(dw)
			dw->exitModalState(0);
        //[/UserButtonCode_buttonCancel]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
const String LoginComponent::getLogin()
{
	return textLogin->getText();
}

const String LoginComponent::getPassword()
{
	return textPassword->getText();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="LoginComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="300" initialHeight="150">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTEDITOR name="Login" id="500f85daf57d3787" memberName="textLogin" virtualName=""
              explicitFocusOrder="0" pos="104 8 150 24" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="17e253d1d34743ff" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 8 89 24" edTextCol="ff000000" edBkgCol="0"
         labelText="Login" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="7af6f41cca143445" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="8 40 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Password" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="Password" id="2699753d3c2c4214" memberName="textPassword"
              virtualName="" explicitFocusOrder="0" pos="104 40 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="Remember" id="1da820d5c5bfc39e" memberName="toggleRemember"
                virtualName="" explicitFocusOrder="0" pos="104 72 150 24" buttonText="Remember me"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="LoginButton" id="27d5d417d550493e" memberName="buttonLogin"
              virtualName="" explicitFocusOrder="0" pos="152 112 136 24" buttonText="Login"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="CancelButton" id="b185a3e4f0879347" memberName="buttonCancel"
              virtualName="" explicitFocusOrder="0" pos="8 112 136 24" buttonText="Cancel"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
