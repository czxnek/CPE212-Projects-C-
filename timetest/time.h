
#ifndef TIME_H
#define TIME_H

class Time
{
  private:	
    int hrs;		// Valid range 0-23 inclusive
    int mins;		// Valid range 0-59 inclusive
    int secs;		// Valid range 0-59 inclusive


  public:	// Public members here
    
    Time();				

    Time(int initHrs, int initMins, int initSecs );   


    void Set(int hours, int minutes, int seconds ); // Sets Time based on incoming parameters

    void Increment();			 
					


    void Write() const;			 // Time has been output in the form HH:MM:SS

    bool Equal(Time otherTime ) const;		// Function value == true, if this time equals otherTime; 
					 // value false otherwise

    bool LessThan(Time otherTime ) const;  	// Function value == true, if this time is earlier; 
					 // value false otherwise
        			              
};
#endif
