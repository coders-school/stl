#include "compression.hpp"
#include <algorithm>
#include <iostream>

compressed_bitmap compressGrayscale(bitmap& bitmap) {

  compressed_bitmap res;
  
  for (const auto& el : bitmap) {
    for (auto it = el.begin(), e = el.end(); it != e;) {
      const auto it2 =
          std::find_if(it, e, [&](const auto& x) { return x != *it; });
      res.emplace_back(*it, std::distance(it, it2));
      it = it2;
    }
  }

  return res;
}

bitmap decompressGrayscale(const compressed_bitmap& map){

    bitmap tmpMap;
    auto it = tmpMap.front().begin();

    for (auto& el : map){
        std::fill_n(it, el.second, el.first);
        std::advance(it, el.second);
    }
    return tmpMap;
}

void printCompressedVector(const compressed_bitmap& map) {
  for (const auto& el : map) {
    std::cout << "{" << static_cast<int>(el.first) << ", " << static_cast<int>(el.second) << "}"
              << " ";
  }
  std::cout << "\n";
}

void printMap(const bitmap& map) {
  for (const auto& el : map) {
      for (const auto&e :el){
        isprint(e) ? std::cout << e : std::cout << " ";
      }
    std::cout << "\n";
  }
}
