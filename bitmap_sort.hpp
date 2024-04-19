#pragma once


#include <climits>
#include <concepts>
#include <cstdint>
#include <iterator>


template<std::forward_iterator FI>
requires (std::sortable<FI> && std::integral<typename FI::value_type>)
void bitmap_sort(FI first, FI last)
{
	int        mx;
	int        mn;
	uint8_t *  bitmap;

	mx = INT_MIN;
	mn = INT_MAX;

	for (FI i = first; i != last; ++i) {
		mx = *i > mx ? *i : mx;
		mn = *i < mn ? *i : mn;
	}
	
	bitmap = new uint8_t[((mx - mn) >> 3) + 1];

	for (FI i = first; i != last; ++i)
 		bitmap[(*i - mn) >> 3] |= 1 << (*i % 8);
	
	for (int i = mn; i <= mx; ++i)
		if (bitmap[(i - mn) >> 3] & 1 << (i % 8))
			*(first++) = i;

	delete [] bitmap;
}


template<std::forward_iterator FI>
requires (std::sortable<FI> && std::integral<typename FI::value_type>)
void bitmap_sort(FI                             first,
				 FI                             last,
				 const typename FI::value_type  mn,
				 const typename FI::value_type  mx)
{
	uint8_t *  bitmap;
	
	bitmap = new uint8_t[((mx - mn) >> 3) + 1];

	for (FI i = first; i != last; ++i)
 		bitmap[(*i - mn) >> 3] |= 1 << (*i % 8);
	
	for (int i = mn; i <= mx; ++i)
		if (bitmap[(i - mn) >> 3] & 1 << (i % 8))
			*(first++) = i;

	delete [] bitmap;
}
