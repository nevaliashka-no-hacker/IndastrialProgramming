#ifndef GENERATE
#define GENERATE

#include <ZXing/BitMatrix.h>
#include <ZXing/CharacterSet.h>
#include <ZXing/MultiFormatWriter.h>

#include <iostream>
#include <opencv2/opencv.hpp>

void generate(std::string data, std::string filename = "");

#endif  // GENERATE