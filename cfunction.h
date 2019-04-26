/*
 * c/c++ function.
 * memcpy, memmove...
 */

#ifndef CFUNCTION_H_
#define CFUNCTION_H_

/*
 *@brief: Copies count bits from the pointed to by src to the pointed to by dest;
 */
void *memcpy(void *dest, const void *src, int count);

/*
 *@brief: Safe copies count bits from the pointed to by src to the pointed to by dest;
 */
void *memmove(void *dest, const void *src, int count);

/*
 *@brief: Convert string to integer;
 */
int atoi_(const char *pszVal);


#endif
