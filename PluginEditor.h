/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class JuceTest2AudioProcessorEditor : public juce::AudioProcessorEditor, 
                                      public juce::FileDragAndDropTarget,
                                      private juce::Slider::Listener
                                      
{
public:
    JuceTest2AudioProcessorEditor (JuceTest2AudioProcessor&);
    ~JuceTest2AudioProcessorEditor() override;


    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    bool isInterestedInFileDrag(const juce::StringArray& files) override;
    void filesDropped(const juce::StringArray& files, int x, int y) override;

private:
    void sliderValueChanged(juce::Slider* slider) override;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
   
    
    JuceTest2AudioProcessor& audioProcessor;

    

    juce::Rectangle<int> area = getLocalBounds();
    juce::File myFile;
    juce::SoundPlayer player;
    juce::Slider midiVolume;//[1]
    juce::TextButton playButton ;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceTest2AudioProcessorEditor)
};
