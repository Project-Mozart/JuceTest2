/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JuceTest2AudioProcessorEditor::JuceTest2AudioProcessorEditor (JuceTest2AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    

    area = getLocalBounds()/2;
    area.setCentre(200,100);

    midiVolume.addListener(this);
    midiVolume.setSliderStyle(juce::Slider::LinearBarVertical);
    midiVolume.setRange(0.0, 100.0, 1.0);
    midiVolume.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled(true, false, this);
    midiVolume.setTextValueSuffix(" Volume");
    midiVolume.setValue(1.0);

    playButton.setButtonText("Generate");
    playButton.setSize(75,45);


    addAndMakeVisible(playButton);
    addAndMakeVisible(midiVolume);
}


void JuceTest2AudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    audioProcessor.noteOnVel = midiVolume.getValue();
}
JuceTest2AudioProcessorEditor::~JuceTest2AudioProcessorEditor()
{


}

//==============================================================================
void JuceTest2AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::white);

    g.setColour(juce::Colours::red);
    
    g.fillRect(area);

    g.setColour (juce::Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("Midi Volume", getLocalBounds(), juce::Justification::centred, 1);


}

void JuceTest2AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    mLoadButton.setBounds
    
    midiVolume.setBounds(40, 30, 20, getHeight() - 60);
    
    playButton.setBounds(getHeight()/2,getWidth()/2,50,50);
}

bool JuceTest2AudioProcessorEditor::isInterestedInFileDrag(const juce::StringArray& files)
{
    for (auto file : files)
    {
        if (file.contains(".wav") || file.contains(".mp3") || file.contains(".aif"))
        {
            return true;
        }
    }

    return false;
}

void JuceTest2AudioProcessorEditor::filesDropped(const juce::StringArray& files, int x, int y)
{
    for (auto file : files)
    {
        if (isInterestedInFileDrag(files))
        {
            //load file path
        }
    }
}