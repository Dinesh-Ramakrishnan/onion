/*
	Onion HTTP server library
	Copyright (C) 2010 David Moreno Montero

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Affero General Public License as
	published by the Free Software Foundation, either version 3 of the
	License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
	*/

#ifndef __ONION_RESPONSE__
#define __ONION_RESPONSE__

#ifdef __cplusplus
extern "C"{
#endif

#include "onion_dict.h"

/**
 * @short The response
 */
struct onion_response_t{
	onion_dict *headers;
	int code;
	int flags;
};

typedef struct onion_response_t onion_response;


/**
 * @short Possible flags
 */
enum onion_response_flags_e{
	OR_KEEP_ALIVE=1,
	OR_LENGTH_SET=2,
};

typedef enum onion_response_flags_e onion_response_flags;

/// Generates a new response object
onion_response *onion_response_new();
/// Frees the memory consumed by this object
void onion_response_free(onion_response *);
/// Adds a header to the response object
void onion_response_set_header(onion_response *, const char *key, const char *value);
/// Sets the header length. Normally it should be through set_header, but as its very common and needs some procesing here is a shortcut
void onion_response_set_length(onion_response *, int);
/// Sets the return code
void onion_response_set_code(onion_response *, int);

/// Writes all the header to the given fd
void onion_response_write(onion_response *, int fd);

#ifdef __cplusplus
}
#endif

#endif