#include <iostream>
#include <vector>
#include <stdexcept>


int findAvg(std::vector<int> vect);

int minmaxAvg(std::vector<int> vect){
    int size = vect.size();
    int mintemp = 1000000;
    int maxtemp = 0;
    std::vector<int> tempVect;
    for(unsigned int i = 0; i<size; ++i){
        if(vect[i] < 0){
        throw std:: invalid_argument("The elements in the array must be positive!");
        } 
        if(vect[i] <  mintemp){
            mintemp = vect[i];
        }
        if(vect[i] >  maxtemp){
            maxtemp = vect[i];
        }       
    }
    tempVect.push_back(mintemp);
    tempVect.push_back(maxtemp);
    return findAvg(tempVect);   
}


int findAvg(std::vector<int> vect){
    int avg = 0;
    int size = vect.size();
     for(unsigned int i = 0; i<size; ++i){
        avg += vect[i];
    }
    return avg/size;
}

int main(){
    std::vector<int> nums = {1,2,3,4,5,6};
    int average = minmaxAvg(nums);
    std::cout << "The average of the min and max of your vector is going to be " << average << std::endl;
}