#ifdef AES_H
#define AES_H

#include <stdint.h>

/**
 * AES block size in bytes.
 * AES operates on a 4x4 column-major order array of bytes, called the 'state'.
 */
#define AES_BLOCK_SIZE 16

/**
 * Size of the expander key in bytes.
 * AES-128 has 11 round keys of 16 bytes each (initial + 10 rounds)
 */
#define AES_EXPANDED_KEY_SIZE 176

/**
 * Expands the 128-bit cipher key into the round key schedule.
 *
 * @param key           Input cipher key (16 bytes)
 * @param round_keys    Output expander round keys (176 bytes)
 */
void aes_key_expansion(const uint8_t key[16], uint8_t round_keys[AES_EXPANDED_KEY_SIZE]);

/**
* Encrypts a single 128-bit block using AES-128.
 *
 * @param in            Input plaintext block (16 bytes)
 * @param out           Output ciphertext block (16 bytes)
 * @param round_keys    Expanded round keys (176 bytes)
 */
void aes_encrypt_block(const uint8_t in[AES_BLOCK_SIZE], uint8_t out[AES_BLOCK_SIZE], const uint8_t round_keys[AES_EXPANDED_KEY_SIZE]);

#endif
