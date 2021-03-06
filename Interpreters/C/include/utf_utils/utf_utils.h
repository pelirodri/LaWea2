//
// Copyright © 2021 Rodrigo Pelissier. All rights reserved.
//
// This file is part of La Weá Interpreter (C)
//
// La Weá Interpreter (C) is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//

#ifndef UTF_UTILS_H
#define UTF_UTILS_H
	#include <stdlib.h>
	#include <stdint.h>

	size_t utf8_byte_utf8_code_point_len(unsigned char);
	size_t utf16_surrogate_utf16_code_point_len(uint_least16_t);

	size_t utf8_char_utf16_code_point_len(const unsigned char *);
	size_t utf16_char_utf8_code_point_len(const uint_least16_t *);
	size_t utf32_char_utf8_code_point_len(uint_least32_t);
	size_t utf32_char_utf16_code_point_len(uint_least32_t);

	size_t utf8_str_utf16_size(const unsigned char *);
	size_t utf16_str_utf8_size(const uint_least16_t *);
	size_t utf32_str_utf8_size(const uint_least32_t *);
	size_t utf32_str_utf16_size(const uint_least32_t *);

	size_t utf8_strlen(const unsigned char *);
	size_t utf16_strlen(const uint_least16_t *);
	size_t utf32_strlen(const uint_least32_t *);

	int utf8_strcmp(const unsigned char *, const unsigned char *);
	int utf16_strcmp(const uint_least16_t *, const uint_least16_t *);
	int utf32_strcmp(const uint_least32_t *, const uint_least32_t *);

	unsigned char *utf8_strchr(const unsigned char *, const unsigned char *);
	uint_least16_t *utf16_strchr(const uint_least16_t *, const uint_least16_t *);
	uint_least32_t *utf32_strchr(const uint_least32_t *, uint_least32_t);

	uint_least16_t *utf8_char_to_utf16(const unsigned char *);
	uint_least32_t utf8_char_to_utf32(const unsigned char *);
	unsigned char *utf16_char_to_utf8(const uint_least16_t *);
	uint_least32_t utf16_char_to_utf32(const uint_least16_t *);
	unsigned char *utf32_char_to_utf8(uint_least32_t);
	uint_least16_t *utf32_char_to_utf16(uint_least32_t);

	uint_least16_t *utf8_str_to_utf16(const unsigned char *);
	uint_least32_t *utf8_str_to_utf32(const unsigned char *);
	unsigned char *utf16_str_to_utf8(const uint_least16_t *);
	uint_least32_t *utf16_str_to_utf32(const uint_least16_t *);
	unsigned char *utf32_str_to_utf8(const uint_least32_t *);
	uint_least16_t *utf32_str_to_utf16(const uint_least32_t *);
#endif
