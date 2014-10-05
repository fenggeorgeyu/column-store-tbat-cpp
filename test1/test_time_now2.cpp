#include <iostream>
#include <stdio.h>

#if !defined(_WIN32) && !defined(_WIN64) // Linux - Unix
    #  include <sys/time.h>
    typedef timeval sys_time_t;
    inline void system_time(sys_time_t* t) {
        gettimeofday(t, NULL);
    }
    inline long long currentTimeMill(const sys_time_t& t) {
        return t.tv_sec * 1000LL + t.tv_usec / 1000;
    }
    #else // Windows and MinGW
    #  include <sys/timeb.h>
    typedef _timeb sys_time_t;
    inline void system_time(sys_time_t* t) { _ftime(t); }
    inline long long time_to_msec(const sys_time_t& t) {
        return t.time * 1000LL + t.millitm;
    }
#endif

using namespace std;
int main() {
    sys_time_t t;
    system_time(&t);
    long currentTime1 = currentTimeMill(t);
    cout << "currentTimeMs1= " << currentTime1 << endl;

    long a=0;
    long N=10000;
    for (long i=0;i<N; i++)
    	for(long j=0;j<N;j++)
    		a++;

    cout <<"a="<<a<<endl;
    system_time(&t);
    long currentTime2 = currentTimeMill(t);
    cout << "currentTimeMs2= " << currentTime2 << endl;

    double elapsedTime=(currentTime2-currentTime1)/1000.0;
    cout << "Elapsed Time:"<<elapsedTime<<endl;

    //getchar();  // wait for keyboard input
}
