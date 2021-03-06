#include "input_data.h"

#include <algorithm>
#include <string.h>

namespace cm {

Image::Image() :
    rows(0),
    cols(0),
    bytesPerPixel(0),
    data(nullptr)
{}

Image::Image(int newRows, int newCols, int newBytesPerPixel) :
    rows(newRows),
    cols(newCols),
    bytesPerPixel(newBytesPerPixel)
{
    data = new unsigned char[rows * cols * bytesPerPixel];
}

Image::~Image() {
    delete[] data;
}

void Image::updateSize(int newRows, int newCols, int newBytesPerPixel) {
    if(newRows != rows || newCols != cols || newBytesPerPixel != bytesPerPixel) {
        delete[] data;
        rows = newRows;
        cols = newCols;
        bytesPerPixel = newBytesPerPixel;
        data = new unsigned char[rows * cols * bytesPerPixel];
    }
}

void Image::swapData(unsigned char** newData) {
    std::swap(data, *newData);
}

void Image::copyData(const unsigned char* newData) {
    if (newData != nullptr)
        memcpy(data, newData, rows * cols * bytesPerPixel);
}

void Image::copyTo(Image& img) {
    img.updateSize(rows, cols, bytesPerPixel);
    img.copyData(data);
}

void Image::clear() {
    memset(data, 0, rows * cols * bytesPerPixel);
}

bool Image::empty() {
    if (rows <= 0 || cols <= 0 || data == nullptr) {
        return true;
    } else {
        return false;
    }
}

InputData::InputData()
{

}

InputData::~InputData() {

}

}
