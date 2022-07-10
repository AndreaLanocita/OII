#include <bits/stdc++.h>

using namespace std;

int divisore;
long long counter;
vector<long long> numeri;
vector<long long> numeri1;
int B;
long long temp;

int calc(int numero_cifre) {
    for(long long i=1; i<B-2; i++) {
        for(long long j=0; j<=numeri.size()-1; j++) {
            if(numeri[j]%10 <= i) break;
            temp = pow(10, numero_cifre-1) * i + (numeri[j]-i);
            numeri1.push_back(temp);
            if(temp%divisore==0) {
                counter--;
                if(counter==0) {
                    cout << temp;
                    return 0;
                }
            }
        }
    }
    
    numeri = numeri1;
    numeri1.clear();
    calc(numero_cifre+1);
    return 0;
}

int main() {
    cin >> divisore >> B >> counter;

    if(B<10) {
        if(B%divisore==0) {
            counter--;
            if(counter==0) {
                cout << B;
                return 0;
            }
        }
        numeri.push_back(B);

        for(long long j=0; j<=numeri.size()-1; j++) {
            for(long long i=1; i<numeri[j]%10; i++) {
                temp = pow(10, 2-1) * i + (numeri[j]-i);
                numeri1.push_back(temp);
                if(temp%divisore==0) {
                    counter--;
                    if(counter==0) {
                        cout << temp;
                        return 0;
                    }
                }
            }
        }

        numeri = numeri1;
        numeri1.clear();
        calc(3);
        return 0;
    }
    
    if(B%9==0) {
        for(long long i=0; i<B/9; i++) {
            temp += 9*pow(10, i);
        }
        numeri.push_back(temp);
        if(temp%divisore==0) {
            counter--;
            if(counter==0) {
                cout << temp;
                return 0;
            }
        }
        calc(B/9+1);
        return 0;
    }

    long long temp1;
    temp = B%9 * (long long) pow(10, B/9);
    for(long long i=0; i<B/9; i++) {
        temp += 9*pow(10, i);
    }
    numeri.push_back(temp);
    if(temp%divisore==0) {
        counter--;
        if(counter==0) {
            cout << temp;
            return 0;
        }
    }

    for(long long i=B/9-1; i>0; i--) {
        for(long long j=1; j<=9-B%9; j++) {
            temp = temp - (j*pow(10, i)) + (j*pow(10, i+1));
            numeri.push_back(temp);
            if(temp%divisore==0) {
                counter--;
                if(counter==0) {
                    cout << temp;
                    return 0;
                }
            }

            temp1 = temp;
            for(long long h=i-1; h>=0; h--) {
                temp1 = temp1 - (j*pow(10, h)) + (j*pow(10, i));
                numeri.push_back(temp1);
                if(temp%divisore==0) {
                    counter--;
                    if(counter==0) {
                        cout << temp;
                        return 0;
                    }
                }
            }
        }
    }
    calc(B/9+2);
    return 0;
}