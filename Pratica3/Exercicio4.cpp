#include <iostream>
using namespace std;

void rleEncode(const char str[], char rle[]){
    int index = 0;
    int count = 0;
    int n = 0;

    while (str[n] != '\0'){
        char next = str[n];
        while (str[n] == next){
            count += 1;
            n += 1;
        }
        if (count > 9){
            rle[index] = char(count / 10 + '0');
            index++;
            rle[index] = char(count % 10 + '0');
            index++;
            rle[index] = next;
            index++;
            count=0;
        }else{
            rle[index] = char(count + '0');
            index++;
            rle[index] = next;
            index++;
            count=0;
        }
    }
    rle[index] = '\0';
}