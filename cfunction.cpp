#include "cfunction.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *memcpy(void *dest, const void *src, int count)
{
	char *pDes = (char *)dest;
	const char *pSrc = (const char *)src;
	if (pDes == pSrc || count <= 0 || pDes == NULL || pSrc == NULL)
		return dest;

	while (count--)
	{
		*pDes++ = *pSrc++;
	}
	
	return dest;
}

void *memmove(void *dest, const void *src, int count)
{
	char *pTo = (char *)dest;
	const char *pFrom = (const char *)src;
	if (pTo == pFrom || count <= 0 || pTo == NULL || pFrom == NULL)
		return pTo;

	if (pTo < pFrom)
	{
		while (count--)
		{
			*pTo++ = *pFrom++;
		}
	}
	else
	{
		pTo += count;
		pFrom += count;
		while (count--)
		{
			*--pTo = *--pFrom;
		}
	}

	return dest;
}

int atoi_(const char *pszVal)
{
	int nRetval = 0;
	if (pszVal == NULL || strlen(pszVal) == 0)
		return 0;
	
	int nSign = 1;
	while (*pszVal == ' ')
		pszVal++;

	//sign;
	if (*pszVal == '-')
	{
		nSign = -1;
		pszVal++;
	}
	else if (*pszVal == '+')
	{
		pszVal++;
	}
	else if (*pszVal < '0' || *pszVal > '9')
		return nRetval;

	while (*pszVal >= '0' && *pszVal <= '9')
	{
		nRetval = nRetval * 10 + *pszVal - '0';
		pszVal++;
	}

	nRetval *= nSign;
	
	return nRetval;
}


/********************************************
* Test;
*/
#ifdef MAIN_TEST
static void test_memcpy(int argc, char *argv[])
{
	const char *szNote = "Copy string message;";
	char *pszDes = (char *)malloc(strlen(szNote) + 1);

	memcpy(pszDes, szNote, strlen(szNote) + 1);

	printf("Src: %s\nDest: %s\n", szNote, pszDes);

	//release;
	free(pszDes);
}

static void test_memmove(int argc, char *argv[])
{
	char szBuf[256] = {'\0'};
	strcpy(szBuf, "Memmove message!");

	memmove(&szBuf[4], szBuf, strlen(szBuf) + 1);
	printf("Dest:%s\n", szBuf);
}

static void test_atoi(int argc, char *argv[])
{
	printf("\" 3.45e2\"\t->%d\n", atoi_("3.45e2"));
	printf("\"99\"\t\t->%d\n", atoi_("99"));
	printf("\"99D45\"\t\t->%d\n", atoi_("99D45"));
	printf("\"+09\"\t\t->%d\n", atoi_("+09"));
	printf("\"-09\"\t\t->%d\n", atoi_("-09"));
}

int main(int argc, char *argv[])
{
	test_memcpy(argc, argv);
	test_memmove(argc, argv);
	test_atoi(argc, argv);
	
	return 0;
}

#endif
