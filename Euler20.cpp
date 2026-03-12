#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

int numb_digits(int v) {
    int n = 1;
    double d = 1, temp;
    temp = d * 1e32; if (v >= temp){n += 32; d = temp;}
    temp = d * 1e16; if (v >= temp){n += 16; d = temp;}
    temp = d *  1e8; if (v >= temp){n +=  8; d = temp;}
    temp = d *  1e4; if (v >= temp){n +=  4; d = temp;}
    temp = d *  1e2; if (v >= temp){n +=  2; d = temp;}
    temp = d *  1e1; if (v >= temp){n +=  1; d = temp;}
    return n;
}

int quick_pow10(int n) {
    static int pow10[10] = {
        1, 10, 100, 1000, 10000, 
        100000, 1000000, 10000000, 100000000, 1000000000
    };
    return pow10[n]; 
}

vector<int> digitsBreak(int n) {
   vector<int> dgts;
   int ord = numb_digits(n)-1;
   int d, p;
   while (ord != -1) {
       p = quick_pow10(ord);
       d = n/p;
       dgts.push_back(d);
       n -= d*p;
       ord--;
   }
   reverse(dgts.begin(), dgts.end());
   return dgts;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    //initialize
    int N, carry, shift, j;
    vector<int> numb;
    vector<int>::iterator iternumb;
    int *digits = new int [3001];
    int *digits1 = new int [3001];
    int *summa = new int [1001];
    for (int i = 0; i < 3001; ++i) {
        digits[i] = -1;
    }
    for (int i = 0; i < 1001; ++i) {
        summa[i] = 0;
    }
    digits[0] = 1;
    summa[0] = 1;
    digits[1] = 1;
    summa[1] = 1;
    
    
    for (int i = 2; i != 1001; i++) {
        if (i > 9) {
            numb = digitsBreak(i); //break the multiplier
            // prepare the buffer
            for (int i = 0; i < 3001; ++i) {
                digits1[i] = -1;
            }
            shift = 0;
            for (iternumb = numb.begin(); iternumb != numb.end(); iternumb++) {
                //init
                j = 1;
                carry = 0;
                
                while(j != 3001) {
                    if (digits[j] == -1) break; //current digits end
                    // multiply digit by digit 
                    digits1[j+shift] = (digits1[j+shift] == -1)? digits[j] * *iternumb : digits1[j+shift] + digits[j] * *iternumb;
                    digits1[j+shift] += carry;
                    carry = digits1[j+shift] / 10;
                    digits1[j+shift] = digits1[j+shift] % 10;
                    j++;
                }
                //adding the next digit
                // must do to clear the -1, even if it is zero
                digits1[j+shift] = carry;
                shift++;
            }
            //transfer the results
            j = 1;
            while(j != 3001) {
                if (digits1[j] == -1) break; //current digits end
                digits[j] = digits1[j];
                summa[i] += digits[j];
                j++;
            }
        }
        else { //single digit case
            //multiply digit by digit
            j = 1;
            carry = 0;
            while(j != 3001) {
                if (digits[j] == -1) break; //current digits end
                digits[j] *= i;
                digits[j] += carry;
                carry = digits[j] / 10;
                digits[j] = digits[j] % 10;
                summa[i] += digits[j];
                j++;
            }
            //adding the next digit if applicable
            if (carry > 0) {
                summa[i] += carry;
                digits[j] = carry;
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    cin >> N;
    cout << summa[N] << endl;
    cout << endl;
    cout << chrono::duration<double, milli>(end - start).count() << " ms\n";
    return 0;
}