#include "snowman.hpp"
#include <iostream>
#include <array>
#include <stdexcept>
using namespace std;

const int PROPER_SNOWMAN_SIZE = 8;
const int CHECK_REMAINDER = 10;

string createHat(const int &hatIndex)
{
    string hat;
    switch (hatIndex)
    {
    case OPTION_ONE:
        hat = "_===_";
        break;
    case OPTION_TWO:
        hat = " ___ \n.....";
        break;
    case OPTION_THREE:
        hat = "  _  \n  /_\\";
        break;
    case OPTION_FOUR:
        hat = " ___ \n(_*_)";
        break;
    default:
        throw std::invalid_argument{"wrong digit! Please make an 8 long digit made of 1-4"};
        break;
    }
    return hat;
}

string createNose(const int &noseIndex)
{
    string nose;
    switch (noseIndex)
    {
    case OPTION_ONE:
        nose = ",";
        break;
    case OPTION_TWO:
        nose = ".";
        break;
    case OPTION_THREE:
        nose = "_";
        break;
    case OPTION_FOUR:
        nose = " ";
        break;
    default:
        throw std::invalid_argument{"wrong digit! Please make an 8 long digit made of 1-4"};
        break;
    }
    return nose;
}

string createLeftEye(const int &leftEyeIndex)
{
    string leftEye;
    switch (leftEyeIndex)
    {
    case OPTION_ONE:
        leftEye = ".";
        break;
    case OPTION_TWO:
        leftEye = "o";
        break;
    case OPTION_THREE:
        leftEye = "O";
        break;
    case OPTION_FOUR:
        leftEye = "-";
        break;
    default:
        throw std::invalid_argument{"wrong digit! Please make an 8 long digit made of 1-4"};
        break;
    }
    return leftEye;
}

string createRightEye(const int &rightEyeIndex)
{
    string rightEye;
    switch (rightEyeIndex)
    {
    case OPTION_ONE:
        rightEye = ".";
        break;
    case OPTION_TWO:
        rightEye = "o";
        break;
    case OPTION_THREE:
        rightEye = "O";
        break;
    case OPTION_FOUR:
        rightEye = "-";
        break;
    default:
        throw std::invalid_argument{"wrong digit! Please make an 8 long digit made of 1-4"};
        break;
    }
    return rightEye;
}

string createLeftArm(const int &leftArmIndex)
{
    string leftArm;
    switch (leftArmIndex)
    {
    case OPTION_ONE:
        leftArm = "<";
        break;
    case OPTION_TWO:
        leftArm = "\\";
        break;
    case OPTION_THREE:
        leftArm = "/";
        break;
    case OPTION_FOUR:
        leftArm = " ";
        break;
    default:
        throw std::invalid_argument{"wrong digit! Please make an 8 long digit made of 1-4"};
        break;
    }
    return leftArm;
}

string createRightArm(const int &rightArmIndex)
{
    string rightArm;
    switch (rightArmIndex)
    {
    case OPTION_ONE:
        rightArm = ">";
        break;
    case OPTION_TWO:
        rightArm = "/";
        break;
    case OPTION_THREE:
        rightArm = "\\";
        break;
    case OPTION_FOUR:
        rightArm = " ";
        break;
    default:
        throw std::invalid_argument{"wrong digit! Please make an 8 long digit made of 1-4"};
        break;
    }
    return rightArm;
}

string createTorso(const int &torsoIndex)
{
    string torso;
    switch (torsoIndex)
    {
    case OPTION_ONE:
        torso = "( : )";
        break;
    case OPTION_TWO:
        torso = "(] [)";
        break;
    case OPTION_THREE:
        torso = "(> <)";
        break;
    case OPTION_FOUR:
        torso = "(   )";
        break;
    default:
        throw std::invalid_argument{"wrong digit! Please make an 8 long digit made of 1-4"};
        break;
    }
    return torso;
}

string createBase(const int &baseIndex)
{
    string base;
    switch (baseIndex)
    {
    case OPTION_ONE:
        base = "( : )";
        break;
    case OPTION_TWO:
        base = "(\" \")";
        break;
    case OPTION_THREE:
        base = "(___)";
        break;
    case OPTION_FOUR:
        base = "(   )";
        break;
    default:
        throw std::invalid_argument{"wrong digit! Please make an 8 long digit made of 1-4"};
        break;
    }
    return base;
}

string ariel::snowman(int num)
{
    if (num <= 0)
    {
        throw std::invalid_argument{"The input is non positive. Please choose a positive 8 long digit made of the numbers 1-4"};
    }
    array<int, PROPER_SNOWMAN_SIZE> theSnowman = {0};
    int numCopy = num;
    for (int i = PROPER_SNOWMAN_SIZE - 1; i >= 0; i--)
    {
        if (numCopy == 0)
        {
            int isShort = i + 1;
            string err = "The length " + to_string(isShort) + " is too short. pick an 8 digit long number with numbers ranging from 1-4";
            throw std::invalid_argument{err};
        }
        theSnowman.at(i) = numCopy % CHECK_REMAINDER;
        numCopy = numCopy / CHECK_REMAINDER;
    }
    if (numCopy != 0)
    {
        throw std::invalid_argument{"The input is too long. please pick an 8 digit long number with numbers ranging from 1-4"};
    }

    string snowmanResult;
    string hat = createHat(theSnowman.at(snowmanParts::HAT));
    string nose = createNose(theSnowman.at(snowmanParts::NOSE));
    string leftEye = createLeftEye(theSnowman.at(snowmanParts::LEFT_EYE));
    string rightEye = createRightEye(theSnowman.at(snowmanParts::RIGHT_EYE));
    string leftArm = createLeftArm(theSnowman.at(snowmanParts::LEFT_ARM));
    string rightArm = createRightArm(theSnowman.at(snowmanParts::RIGHT_ARM));
    string torso = createTorso(theSnowman.at(snowmanParts::TORSO));
    string base = createBase(theSnowman.at(snowmanParts::BASE));
    if (theSnowman.at(LEFT_ARM) == 2 && theSnowman.at(RIGHT_ARM) == 2)
    {
        snowmanResult = " " + hat + "\n" + leftArm + "(" + leftEye + nose + rightEye + ")" + rightArm + "\n" + " " + torso + "\n" + " " + base;
    }
    else if (theSnowman.at(LEFT_ARM) == 2)
    {
        snowmanResult = " " + hat + "\n" + leftArm + "(" + leftEye + nose + rightEye + ")\n" + " " + torso + rightArm + "\n" + " " + base;
    }
    else if (theSnowman.at(RIGHT_ARM) == 2)
    {
        snowmanResult = " " + hat + "\n" + " (" + leftEye + nose + rightEye + ")" + rightArm + "\n" + leftArm + torso + "\n" + " " + base;
    }
    else
    {
        snowmanResult = " " + hat + "\n" + " (" + leftEye + nose + rightEye + ")\n" + leftArm + torso + rightArm + "\n" + " " + base;
    }

    return snowmanResult;
}