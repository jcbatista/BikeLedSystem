#ifndef Clock_h
#define Clock_h

class Clock 
{  
public:
  Clock();
  void tick();
  inline unsigned long  getCurrent() { return _current; }
  
private:
    unsigned long  _current;
};

#endif // Clock_h
