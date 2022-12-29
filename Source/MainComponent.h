#pragma once

#include <JuceHeader.h>
using namespace juce;

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public Component,
                       public Slider::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    void sliderValueChanged(Slider* slider) override
    {
        if (slider == &frequencySlider)
            durationSlider.setValue(1 / frequencySlider.getValue());
        else if (slider == &durationSlider)
            frequencySlider.setValue(1.0 / durationSlider.getValue());
    }

private:
    Slider frequencySlider;
    Label frequencyLabel;

    Slider durationSlider;
    Label durationLabel;



    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
