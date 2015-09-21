// ENCRYPTFILE.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <Windows.h>
//#include "Tiny.h"
//////////////////////////////////////////////////////////////////////////
FILE *Encrypt(char *input, char *output, char *array, char *key)
{
	FILE *result; 
	FILE *result2;
	signed int v5=0; 
	int v7; 
	
	//result  = fopen(input, "rb");
	fopen_s(&result,input, "rb");
	//result2 = fopen((const char *)output, "w");
	fopen_s(&result2,(const char *)output, "w");
	fprintf(result2, "//const\nunsigned char %s[] = {", array);
	srand(atoi(key));
	while ( 1 )
		{
		v7 = getc(result);
		if ( v7 == -1 )
		break;
		if ( v5 )
		fprintf(result2, ", ");
		if ( !(v5 % 16) )
		fprintf(result2, "\n\t");
		//fprintf(result2, "0x%.2X", (unsigned __int8)~(BYTE)v7);
		//////////////////////////////////////////////////////////////////////////
		v7= v7^atoi(key);
		srand(atoi(key));
		//v7 ^= rand() % 256;
		//char *randomkey;
		//_itoa(v7,randomkey,10);
		//printf(randomkey);
		//printf("\n");
		//////////////////////////////////////////////////////////////////////////
		fprintf(result2, "0x%.2X", (unsigned __int8)(BYTE)v7);
		++v5;
		}
	fprintf(result2, "\n};\n");
	fclose(result);
	fclose(result2);
	return result2;
}
//////////////////////////////////////////////////////////////////////////
//
// 映射文件，返回映射后的地址，并保存文件的大小
//
// LPVOID MapFile(LPCTSTR lpFilePath, LPDWORD lpdwFileSize, BOOL bReadOnly)
// {
// 	DWORD dwAccess[3];
// 	
// 	if ( bReadOnly )
// 	{
// 		dwAccess[0] = GENERIC_READ;
// 		dwAccess[1] = PAGE_READONLY;
// 		dwAccess[2] = FILE_MAP_READ;
// 	}
// 	else
// 	{
// 		dwAccess[0] = (GENERIC_WRITE | GENERIC_READ);
// 		dwAccess[1] = PAGE_READWRITE;
// 		dwAccess[2] = (FILE_MAP_READ | FILE_MAP_WRITE);
// 	}
// 	
// 	HANDLE hFile = CreateFile(lpFilePath, dwAccess[0], FILE_SHARE_READ,
// 		NULL, OPEN_EXISTING, 0, NULL);
// 	
// 	if ( hFile != INVALID_HANDLE_VALUE )
// 	{
// 		if ( lpdwFileSize != NULL )
// 		{
// 			*lpdwFileSize = GetFileSize(hFile, NULL);
// 		}
// 		
// 		HANDLE hFileMap = CreateFileMapping(hFile, NULL, dwAccess[1], 0, 0, NULL);
// 		CloseHandle(hFile);
// 		
// 		if ( hFileMap != NULL )
// 		{
// 			LPVOID lpFileData = MapViewOfFile(hFileMap, dwAccess[2], 0, 0, 0);
// 			CloseHandle(hFileMap);
// 			
// 			return lpFileData;
// 		}
// 	}
// 	
// 	return NULL;
// }
//////////////////////////////////////////////////////////////////////////
// FILE *Encrypt(char *input, char *output, char *array)
// {
// 	LPVOID	lpFileData;
// 	DWORD	dwFileSize;
// 	lpFileData = MapFile(input, &dwFileSize, TRUE);
// 	for(int m = 0; m < 8; m++)
// 	{
// 		szVersionData[m] = szCurVersion[m]^0x1b;
// 	}
//////////////////////////////////////////////////////////////////////////
// 	result = fopen(input, "rb");
// 	if ( result )
// 	{
// 		result = fopen((const char *)output, "w");
// 		if ( result )
// 		{
// 			fprintf(result, "//const\nunsigned char %s[] = {", array);
// 			while ( 1 )
// 			{
// 				v7 = getc(result);
// 				if ( v7 == -1 )
// 					break;
// 				if ( v5 )
// 					fprintf(result, ", ");
// 				if ( !(v5 % 16) )
// 					fprintf(result, "\n\t");
// 				fprintf(result, "0x%.2X", (unsigned __int8)~(BYTE)v7);
// 				++v5;
// 			}
// 			fprintf(result, "\n};\n");
// 			fclose(result);
// 			result = (FILE *)1;
// 		}
// 	}
// 	return result;
// }

//////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	//system("cls");
	printf("[+] EncryptFile V2.0.0 by Eric21 \n", argv[0]);
	printf("[+] www.eric21.com \n", argv[0]);
	if ( argc < 2 )
	{
		printf("[Usage]:\n");
		printf("%s [input_file] [output_file] [array_name] [key]\n\n", argv[0]);
		printf("[Example]:\n");
		printf("%s test.exe test.h 0x12\n", argv[0]);
		printf("%s test.exe test.h test 0x12\n", argv[0]);
		exit(-1);
	}
	else
	{
	//argv[3] = (int)"filedata";
	printf("[*] [input_file]:  %s\n", argv[1]);
	printf("[*] [output_file]: %s\n", argv[2]);
	printf("[*] [array_name]:  %s\n", argv[3]);
	printf("[*] [key]:  %s\n", argv[4]);
	printf("\n");
	if (Encrypt(argv[1], argv[2], argv[3], argv[4]))
		printf("[+] EncryptFile(); Successfully! ^_^\n");
	else
		printf("[-] EncryptFile(); Failed.\n");
 	}


	return 0;
}

