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

#ifndef SERIALJSON_H
#define SERIALJSON_H
#define BUFFER_SIZE 256

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#endif

#include <string.h>

//Like strstr() but reads from right to left.
//Remember to delete allocated memory after the function has been used.
char* strstrrev(const char* str1, const char* str2){
    const char* found = strstr(str1, str2);
    if(found != NULL){
        int len = strlen(str1) - strlen(found);
        char* newStr = new char[len + 1];
        strncpy(newStr, str1, len);
        newStr[len] = '\0';
        return newStr;
    } else {
        //Return copy of the original string if no subtraction could be applied
        char* newStr = new char[strlen(str1) + 1];
        strcpy(newStr, str1);
        return newStr;
    }
}

//return value from known key on a JSON-formatted string
void quickParse(const char* str, const char* key, char* target){
    char* cutStr = (char*)strstr(str, key);
    if(cutStr != NULL){
        std::cout << cutStr << std::endl;
        char* revStr = strstrrev(cutStr, ",");
        std::cout << revStr << std::endl;
        cutStr = strstr(revStr, ":");
        std::cout << cutStr << std::endl;
        if(cutStr != NULL){
            cutStr++;
            cutStr[strlen(cutStr) - 1] = '\0';
            std::cout << cutStr << std::endl;
            strcpy(target, cutStr);
            delete[] revStr;
        } else {
            delete[] revStr;
        }
    } 
}

template<typename KeyType, typename ValueType>
struct KeyValuePair{
    public:
        KeyType key;
        ValueType value;

        KeyValuePair(KeyType key, ValueType value) : key(key), value(value) {}
};

template<typename KeyType, typename ValueType>
class SerialJSON
{
    private:
        char* data;
        int len;
        KeyValuePair<KeyType, ValueType>* dict;

        static void findIndexes(char* str, char c, int* indexes, int* count) {
            *count = 0;
            for(int i = 0; str[i] != '\0'; i++) {
                if(str[i] == c) {
                    indexes[*count] = i;
                    (*count)++;
                }
        }
}
    public:
        SerialJSON(char* data, int len){
            this->len = len;
            this->data = data;
            dict = new KeyValuePair<KeyType, ValueType>[len];
            parse(this->dict);
        }
        ~SerialJSON(){
            delete[] data;
            delete[] dict;
        }

        ValueType getValue(KeyType key){
            for(int i = 0; i < len; i++){
                if(dict[i].key == key){
                    return dict[i].value;
                }
            }
            return NULL;
        }

        ValueType elementAt(int index){
            return dict[index].value;
        }

        static void serialize(){
            //TODO
        }

        void parse(KeyValuePair<KeyType, ValueType>* target){
            /*
            int i = 1, j = 0, e = 0;
            KeyType keys[len][BUFFER_SIZE];
            ValueType values[len][BUFFER_SIZE];
            bool key = true;

            int colons, commas, lastIndex, e;
            int* colonsIndexes, commasIndexes;

            findIndexes(data, ':', colonsIndexes, &colons); //Find the positions of each ':'
            findIndexes(data, ',', commasIndexes, &commas); //Find the positions of each ','

            for(int i = 0; i < colons && i < commas; i++){
                int len = colonsIndexes[i] - commasIndexes[i];
                for(e = 0; e < len; e++){
                    //TODO
                }
                lastIndex += e;
            } */
        }

};

#endif