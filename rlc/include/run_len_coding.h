#ifndef _RUN_LEN_CODING_H_
#define _RUN_LEN_CODING_H_

/**
 ****************************************************************************************
 *
 * author:chao.he
 *
 * since:2016-03-21
 *
 * version:1.0
 *
 * decription:run-length coding.
 *
 *            The rlc_encode() function encode n bytes memory areas src 
 *               to m bytes memory dest.The memory areas must not overlap.
 *
 *            The rlc_decode() function decode n bytes memory areas src
 *               to m bytes memoty dest.The memory areas must not overlap.
 *
 *            The zip_len() function calculated n bytes memory space data encoded by
 *               rlc_encode() function needs of memory spaces.
 *
 *            The extract_len() function calculated n bytes memory space data decoded by
 *               rlc_decode() function needs of memory spaces.
 *
 ****************************************************************************************
 **/

int rlc_encode(void *dest, const void *src, int n);

int rlc_decode(void *dest, const void *src, int n);

int zip_len(const void *data, int n);

int extract_len(const void *data, int n);



#endif
