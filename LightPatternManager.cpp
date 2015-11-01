#include "LightPatternManager.h"

LightPatternManager::LightPatternManager(Clock* pClock, LedController* pLedController)
{
	_lightPatterns[0] = new LightPattern(pClock, pLedController);
}

LightPatternManager::~LightPatternManager()
{
	// TODO
}

void LightPatternManager::display(int patternIndex)
{
	_lightPatterns[patternIndex]->display(_updateFrequency);
}

void LightPatternManager::setUpdateFrequency(int frequency)
{
	_updateFrequency = frequency;
}