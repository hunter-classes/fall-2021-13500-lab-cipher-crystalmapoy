#include <iostream>
#include "funcs.h"

#include <vector>
#include <float.h>
#include <cmath>

char shiftchar(char c, int newshift) {
    int original = int(c);
    int temp;
    if (original >= 65 && original <= 90) {
        if (original + newshift > 90) {
            temp = 90 - original;
            return (char)(64 + newshift - temp);
        }
        else {
            original = int(c);
            return (char)(original + newshift);
        }
    }
    else if (original >= 97 && original <= 122) {
        if (original + newshift > 122) {
            temp = 122 - original;
            return (char)(96 + newshift - temp);
        }
        else {
            original = int(c);
            return (char)(original + newshift);
        }
    }
    else {
        return c;
    }
}
std::string encryptCaesar(std::string plaintext, int newshift) {
    std::string caesar = "";
    for (int i = 0; i < plaintext.length(); i++) {
        caesar += shiftchar(plaintext[i], newshift);
    }
    return caesar;
}

bool isLetter(char letter) {
    if(((int)(letter) >= 65 && (int)(letter) <= 90) || ((int)(letter) >= 97 && (int)(letter) <= 122)) {
        return true;
    }
    else {
        return false;
    }
}
double dist(std::vector<double> first, std::vector<double> second) {
    double sum;
    for(int i = 0; i < first.size(); i++) {
        sum += pow((first[i] - second[i]), 2);
    }
    return sqrt(sum);
}
std::string solve(std::string encrypted_string) {
    std::vector<double> ENG_FREQUENCIES{0.084966, 0.020720, 0.045388, 0.033844, 0.111607, 0.018121, 0.024705, 0.030034, 0.075448, 0.001964, 0.011016, 0.054893, 0.030129, 0.066544, 0.071635, 0.031671, 0.001962, 0.075809, .057351, 0.069509, 0.036308, 0.010074, 0.012899, 0.002902, 0.017779, 0.002722};
    double minDistance = DBL_MAX;
    
    int rotation;
    int result = 0;
    for (char letter:encrypted_string) {
        if(isLetter(letter))
            result++;
    }
    
    for (int i = 0; i < 26; i++) {
        std::string tempRotation = encryptCaesar(encrypted_string, i+1);
        int index;
        std::vector<double> encryptFrequencies(26);
        
        for (char letter:tempRotation) {
            double letterCounter = 0;
            if((int)(letter) >= 65 && (int)(letter) <= 90) {
                index = (int)(letter)-65;
            }
            else if((int)(letter) >= 97 && (int)(letter) <= 122) {
                index = (int)(letter)-97;
            }
            if(isLetter(letter)) {
                for (int j = 0; j < tempRotation.length(); j++) {
                    if (tempRotation[j] == letter) {
                        letterCounter++;
                    }
                }
                encryptFrequencies[index] = letterCounter / result;
            }
            if(dist(ENG_FREQUENCIES, encryptFrequencies) < minDistance) {
                minDistance = dist(ENG_FREQUENCIES, encryptFrequencies);
                rotation = i+1;
            }
        }
    }
    return encryptCaesar(encrypted_string, rotation);
}

