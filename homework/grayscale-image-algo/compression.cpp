#include "compression.hpp"

CompressedImage compressGrayscale(const Image& image)
{
    CompressedImage compressedImage;
    for(int i = 0; i < height; i++){
        auto it = image[i].begin();
        while (it != image[i].end())
        {
            auto el = std::find_if_not(it, image[i].end(), [&it](int x){return x == *it;});
            auto count = std::distance(it, el);
            compressedImage.push_back({*it, count});
            it = el;
        }
    }
    return compressedImage;
}


Image decompressGrayscale(const CompressedImage& image)
{
    Image decompressedImage;
    auto itV = image.begin();
    for(int i = 0; i < height; i++) {
        auto it = decompressedImage[i].begin();
        while (it != decompressedImage[i].end())
        {
           std::fill_n(it, itV->second, itV->first);
           it = std::next(it, itV->second);
           itV = std::next(itV);
        }
    }
    return decompressedImage;
}
