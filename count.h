//
// Created by Macarena Oyague on 2020-03-26.
//

#ifndef TRAIN_COUNT_POINTERS_MACARENAOYAGUE_COUNT_H
#define TRAIN_COUNT_POINTERS_MACARENAOYAGUE_COUNT_H

#include <map>
#include <iterator>
#include <iostream>
using namespace std;
#include <vector>

void count(int **p[]){

    map <int*, int> positions;

    int i = 0;

    while (p[i]!= nullptr){
        positions[*p[i]]++;
        i++;
    }

    vector<int> numbers;
    vector<int> counter;

    //mapping one to one and many to one
    for (auto element: positions)
    {
        numbers.push_back(*element.first);
        counter.push_back(element.second);
    }

    //integers in increasing order of the numbers of the first level pointers that can reach them
    for (int j=0; j<numbers.size(); j++)
        for (i=0; i<numbers.size(); i++)
        {
            if (counter[j]<counter[i])
            {
                swap(counter[j], counter[i]);
                swap(numbers[j], numbers[i]);
            }
        }


    //if two integers have the same numbers of the first level pointers that can reach them, print the smaller integer first
    for (int j=0; j<numbers.size(); j++)
        for (i=0; i<numbers.size(); i++)
        {
            if (counter[j]==counter[i] and numbers[j]<numbers[i])
            {
                swap(counter[j], counter[i]);
                swap(numbers[j], numbers[i]);
            }
        }

    //output
    for (int j=0; j<numbers.size(); j++)
        cout<<numbers[j]<<" "<<counter[j]<<endl;


}

#endif //TRAIN_COUNT_POINTERS_MACARENAOYAGUE_COUNT_H