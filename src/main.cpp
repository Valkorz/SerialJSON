/*  Arduino Library for SerialJSON formatting
    Copyright (C) 2024 Valkorz/Vittorio Pivarci     <pivarcivittorio@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Created by Vittorio Pivarci, June 16th, 2024.

    SERIALJSON - Version 1.0.0
*/

#include <iostream>
#include <string.h>
#include "SerialJSON.h"
#define BUFFER_SIZE 256

const char* comma = ",";
const char* colon = ":";
const char* str1 = "{apples:5,bananas:12}";


int main(){

    std::cout << "initializing program..." << std::endl;
    char* str2 = new char[BUFFER_SIZE];
    int i = 0;
    //str2 = strstrrev((char*)str1, (char*)comma);
    //std::cout << "result: " << str2 << std::endl;

    int bananas = quickParse<int>(str1, "bananas");
    std::cout << "number of bananas: " << bananas << std::endl;

    /*
    while(str1[i] != '\0'){
        std::cout << "current char: " << str1[i] << std::endl;
        if(str1[i] == ':'){
            str1 = strstr(str1, colon);
            i = 0;
            delete[] str2;
            str2 = new char[BUFFER_SIZE];
        }
        else if(str1[i] == ','){
            str1 = strstr(str1, comma);
            i = 0;
            delete[] str2;
            str2 = new char[BUFFER_SIZE];
        }
        else{
            str2[i] = str1[i];
            str2[i + 1] = '\0';
            std::cout << "string: " << str2 << std::endl;
        }
        i++;
    } */
    delete str2;
    int t;
    std::cin >> t;
    return 0;
}