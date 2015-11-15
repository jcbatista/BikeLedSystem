#ifndef LightPatternManager_h
#define LightPatternManager_h

#include "LightPattern.h"

class LightPatternManager
{
	private:
		static const int MaxPatterns = 2;
		LightPattern* _lightPatterns[MaxPatterns];
		int _updateFrequency = 500;
    int _currentIndex = 0;
	public:
		LightPatternManager(Clock* pClock, LedController* pLedController);
		~LightPatternManager();
   void display();
	 void display(int patternIndex);
	void setUpdateFrequency(int frequency);

};

#endif // LightPatternManager_h
