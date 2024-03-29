/*
 * plf_int.h
 *
 * Copyright (c) 2011 scorp2kk, All rights reserved
 *
 * Description:
 *  Contains internal used declarations and defines for libplf. Not
 *  to be used by applications.
 *
 * License:
 *  This file is part of libplf.
 *
 *  libplf is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libplf is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libplf.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PLF_INT_H_
#define PLF_INT_H_

#include "types.h"
#include "plf_structs.h"
#include "plf.h"

#define PLF_MAX_ALLOWED_FILES 8

#define PLF_VERIFY_IDX(idx) if (idx >= PLF_MAX_ALLOWED_FILES || plf_files[idx].hdr.dwMagic != PLF_MAGIC_CODE) return PLF_E_FILE_IDX;

typedef struct s_plf_section_entry_tag
{
    s_plf_section                   hdr;
    u32                             offset;
    struct s_plf_section_entry_tag* next;
} s_plf_section_entry;

typedef struct s_plf_file_entry_tag
{
    s_plf_file              hdr;
    int                     fildes;
    const void*             buffer;
    u32                     buffer_size;
    u32                     num_entries;
    s_plf_section_entry*    entries;
    u32                     flags;
    u32                     current_size;
#define PLF_FILE_FLAG_READ     0x00000001u
#define PLF_FILE_FLAG_WRITE    0x00000002u
#define PLF_FILE_FLAG_OPENED   0x00000004u
#define PLF_FILE_FLAG_SECTOPEN 0x00000008u
} s_plf_file_entry;



#endif /* PLF_INT_H_ */
