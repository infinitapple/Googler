#pragma once

#ifndef __FILEMANAGE
#define __FILEMANAGE

#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include "md5wrapper.h"

#define BUFF_SIZE (1024 * 32)
#define STRUCT_SIZE (BUFF_SIZE - 4)

struct packet {
	int meta;
	char buff[STRUCT_SIZE];
};

using namespace std;

class FileManage {
private:
	char* mRecvBuffer;
	string FileName;
	string make_md5;
	string receive_md5;
	fstream File;
	char FileOpenFlag;
	packet *pk;
	int SetFileName(char *name); //파일명이 이미 존재하면 애러 리턴(0:정상, 1:파일존재)
	int SetFileNameFromBuf(); //버퍼에서 직접 가져옴
	int WriteFile(); //종료인자를 읽었다면 종료인자 리턴(0:계속, 1:종료, 2:파일open안됨)
	int FileEnd();
	int FileClose();
	int GetMd5();
	int MakeMd5();
	int Complete();
	int GetFolderName();
public:
	FileManage(char* buffer);
	~FileManage();
	int IsOpen(); //파일이 열려있는지 확인(1:열림,0:닫힘)
	int RecvPacket();
};



#endif // !__FILEMANAGE
