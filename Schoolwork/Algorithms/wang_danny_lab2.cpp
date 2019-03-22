#include <iostream>
#include <string>

using namespace std;

// x can be float, y can be negative but is always an integer
float pow(float x, int y){
    if(y == 0){ return 1; }
    else if(y < 0){ return pow(1/x, -y); }
    else{ 
        float power = x;
        while(y > 1){
            power = power * x;
            y--;
        }
        return power;
    }
}

float pow2(float x, int y){
    if(y < 0){
        x = 1/x;
        y = -y;
    }
    if(y == 0){ return 1; }
    float acc = 1;
    while(y>1){
        if(y%2 == 0){
            x = x * x;
            y = y / 2;
        }
        else{
            acc = acc * x;
            x = x * x;
            y = (y - 1) / 2;
        }
    }
    return x * acc;
}

int main(int argc, char *argv[]){
    float x = stof(argv[1]);
    int y = stoi(argv[2]);
    cout << "Linear time: pow(" << argv[1] << "," << argv[2] << ") = " << pow(x,y) << "\n";
    cout << "lg n time: pow(" << argv[1] << "," << argv[2] << ") = " << pow2(x,y) << "\n";
}