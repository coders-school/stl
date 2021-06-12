#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
	const std::array<std::array<uint8_t, width>, height>& bitmap)
{
	std::vector<std::pair<uint8_t, uint8_t>> compressedBitmap;
	compressedBitmap.reserve(30);

	for (const auto& row : bitmap)
	{
		int occurrencesCounter{ 1 };
		for (size_t j{ 1 }; j < row.size(); ++j)
		{
			// if current element is different form prev one, we have to create pair with previous one
			if (row[j-1] != row[j])
			{
				compressedBitmap.emplace_back(std::make_pair(row[j-1], occurrencesCounter));
				occurrencesCounter = 1;
			}
			else // if not, just increment occurrences of our current value
				++occurrencesCounter;

			// We reached end of the row,
		    // so create pair with the last value of the row and with its occurrences
			if (j == row.size() - 1)
				compressedBitmap.emplace_back(std::make_pair(row[j], occurrencesCounter));
		}
	}
	return compressedBitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(
	const std::vector<std::pair<uint8_t, uint8_t>>& compressedBitmap)
{
	if (compressedBitmap.empty())
		return std::array<std::array<uint8_t, width>, height>();

	std::array<std::array<uint8_t, width>, height> bitmap{};

	int arrRowIndex{0};
	int arrElIndex{0};
	for (const auto& [value, occurrences] : compressedBitmap)
	{
		if (arrElIndex + occurrences > static_cast<int>(bitmap[0].size()))
		{
			++arrRowIndex;
		    arrElIndex = 0;
		}

	    for (int i{0}; i < occurrences; ++i)
	    {
	        bitmap[arrRowIndex][arrElIndex] = value;
			++arrElIndex;
	    }
	}
	return bitmap;
}
