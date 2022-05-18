#include <iostream>

using namespace std;

void advance(int delta, int& d, int& m, int& y) {
    for (int i = delta; i>0; i--){
        switch (m)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            d+=1;
            if(d>31){
                d=1;
                m+=1;
            }
            if(m>12){
                m=1;
                y+=1;
            }
            break;

        case 4: case 6: case 9: case 11: 
            d+=1;
            if(d>30){
                d=1;
                m+=1;
            }
            break;
        
        case 2:
            if(y%100!=0 && y%4==0){
                d+=1;
                if(d>29){
                    d=1;
                    m+=1;
                    break;
                }
            }

            else if(y%400==0){
                d+=1;
                if(d>29){
                    d=1;
                    m+=1;
                    break;
                }
            }

            else{
                d+=1;
                if(d>28){
                    d=1;
                    m+=1;
                    break;
                }
            }
        }
    } 
}
