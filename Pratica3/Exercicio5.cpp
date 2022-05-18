struct time_of_day {
  unsigned char h;  // hours (0 to 23)
  unsigned char m;  // minutes (0 to 59)
};
struct interval {
  time_of_day start;  // start time
  time_of_day end;    // end time
};
#include <iostream>
using namespace std;
 
//! Prints the results.
void print(int d, const interval il) {
  cout << d << " ["
       << (int) il.start.h << ':' << (int) il.start.m << ','
       << (int) il.end.h   << ':' << (int) il.end.m 
       << "[\n";
}

int search_intervals(time_of_day t, const interval a[], int n, interval& u){

    time_of_day min = {23, 59};
    time_of_day max = {0, 0};
    int cnt=0;
    
    for (int i = 0; i < n; i++)
    {
        if((t.h > a[i].start.h || (t.h == a[i].start.h && t.m >= a[i].start.m)) && (t.h < a[i].end.h || (t.h == a[i].end.h && t.m < a[i].end.m))){
            if(min.h > a[i].start.h || (min.h == a[i].start.h && min.m > a[i].start.m))
                min = a[i].start;
            if(max.h < a[i].end.h || (max.h == a[i].end.h && max.m < a[i].end.m))
                max = a[i].end;
            cnt++;
        }
    }
    
    if(cnt == 0){
        u = {t, t};
        return 0;
    }
    
    u = {min, max};
    return ((max.h - min.h) * 60) + (max.m - min.m);
}

