#include "compression.hpp"
#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, height>, width> arg)
{
	using namespace std;

	vector<std::pair<uint8_t, uint8_t>> result;
	result.reserve(width * height);

	uint8_t temporary = 0;

	int index = 0;
	for_each(begin(arg), end(arg), [&](auto pixel)
				  {
					  pair<uint8_t, uint8_t> tmp{};

					  for (uint8_t j = 0; j < width; ++j)
					  {
						  tmp.first = arg[index][j];
						  tmp.second++;
						  if (j < width - 1)
						  {
							  if (arg[index][j] != arg[index][j + 1])
							  {
								  result.push_back(tmp);
								  tmp.second = 0;
							  }
						  }
						  else
						  {
							  result.push_back(tmp);
						  }
					  }
					  index++;
				  });

	return result;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> arg)
{
	std::array<std::array<uint8_t, width>, height> result{};

	uint8_t local_w = 0;
	uint8_t local_h = 0;
	for (auto const &x : arg)
	{
		for (int i = 0; i < x.second; ++i, ++local_w)
		{

			if (local_w == width)
			{
				local_h++;
				local_w = 0;
			}
			result[local_h][local_w] = x.first;
		}
	}
	return result;
}

void printMap(std::array<std::array<uint8_t, width>, height> arg)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (!std::isprint(arg[i][j]))
			{
				std::cout << ' ';
			}
			else
			{
				std::cout << arg[i][j];
			}
		}
		std::cout << '\n';
	}
};

void printMapIntMatrix(std::array<std::array<uint8_t, width>, height> arg)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << (unsigned)arg[i][j] << ", ";
		}
		std::cout << '\n';
	}
};
