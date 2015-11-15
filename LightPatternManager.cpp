#include "LightPatternManager.h"

LightPatternManager::LightPatternManager(Clock* pClock, LedController* pLedController)
{
  LightPatternOptions lightPatternOptions;
  lightPatternOptions.palette = CloudColors_p;
  lightPatternOptions.blendType = BLEND;
  lightPatternOptions.brightness = 100;
  lightPatternOptions.frequency = 100;
  lightPatternOptions.duration = 1000;
	_lightPatterns[0] = new LightPattern(lightPatternOptions, pClock, pLedController);
  lightPatternOptions.palette = lightPatternOptions.palette = PartyColors_p;
  lightPatternOptions.duration = 1000;
  _lightPatterns[1] = new LightPattern(lightPatternOptions, pClock, pLedController);

  _currentIndex = 0; 
  _lightPatterns[_currentIndex]->start();
}

LightPatternManager::~LightPatternManager()
{
	// TODO
}

void LightPatternManager::display()
{
  if(_lightPatterns[_currentIndex]->isCompleted())
  {
    _currentIndex++;
    _currentIndex = _currentIndex % MaxPatterns;
  }
  display(_currentIndex); // TODO: code this function
}

void LightPatternManager::display(int patternIndex)
{
	_lightPatterns[patternIndex]->display(_updateFrequency);
}

void LightPatternManager::setUpdateFrequency(int frequency)
{
	_updateFrequency = frequency;
}
