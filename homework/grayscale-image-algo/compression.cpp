#include "compression.hpp"

CompressedImage compressGrayscale(const Image& image)
{
    CompressedImage compressedImage;
    for(const auto& iter : image) {
        auto it = iter.begin();
        while (it != iter.end()) {
            auto el = std::find_if_not(it, iter.end(), [&it](int x){return x == *it;});
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
    for(auto& iter : decompressedImage) {
        auto it = iter.begin();
        while (it != iter.end()) {
           std::fill_n(it, itV->second, itV->first);
           it = std::next(it, itV->second);
           itV = std::next(itV);
        }
    }
    return decompressedImage;
}

