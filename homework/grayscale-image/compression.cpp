#include "compression.hpp"

compressedGrayscaleImage compressGrayscale(grayscaleImage bitmap) {
    compressedGrayscaleImage compressed;
	compressed.reserve(width * height);
	for (auto line: bitmap) {
		uint8_t counter = 1;
		for (auto it = line.begin(); it != line.end(); it++) {
			if (*it != *std::next(it) || it == line.end() - 1 ) {
				compressed.push_back(std::make_pair(*it, counter));
				counter = 1;
			}
			else {
				counter++;
			}
		}
	}
	return compressed;
}

grayscaleImage decompressGrayscale(compressedGrayscaleImage compressed) {
    grayscaleImage decompressed;
    size_t i=0;
    for(auto it : compressed){
        for(size_t j=0; j<it.second; ++j, ++i){
            decompressed[0][i]=it.first;
        }
    }
    return decompressed;
}
