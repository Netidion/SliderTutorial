#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);

    addAndMakeVisible(frequencySlider);
    frequencySlider.setRange(50, 5000, 1);
    frequencySlider.setTextValueSuffix(" Hz");
    frequencySlider.addListener(this);
    
    addAndMakeVisible(frequencyLabel);
    frequencyLabel.setText("Frequency", dontSendNotification);
    frequencyLabel.attachToComponent(&frequencySlider, true);

    frequencySlider.setValue(500);
    frequencySlider.setSkewFactorFromMidPoint(500);
    frequencySlider.setTextBoxStyle(Slider::TextBoxLeft, true, 120, frequencySlider.getTextBoxHeight());

    addAndMakeVisible(durationSlider);
    durationSlider.setRange(1.0 / frequencySlider.getMaximum(), 1.0 / frequencySlider.getMinimum());
    durationSlider.setTextValueSuffix(" s");
    durationSlider.addListener(this);

    addAndMakeVisible(durationLabel);
    durationLabel.setText("Duration", dontSendNotification);
    durationLabel.attachToComponent(&durationSlider, true);

    durationSlider.setSkewFactorFromMidPoint(0.002);
    durationSlider.setTextBoxStyle(Slider::TextBoxLeft, true, 120, durationSlider.getTextBoxHeight());

}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    
}

void MainComponent::resized()
{
    const int border = 120;

    frequencySlider.setBounds(border, 20, getWidth() - border, 20);

    durationSlider.setBounds(border, 50, getWidth() - border, 50);
}
