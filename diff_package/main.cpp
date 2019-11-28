#include <Windows.h>
#include <iostream>

extern "C" {
#include "dir.h"
#include "md5.h"
}
#include <stdio.h>
#include <string>

#define SUCCESS						0
#define ERR_CHECK					1
#define ERR_FILEOPEN				2
#define ERR_FILENOTEXIST			3
#define ERR_FILEREAD				4
#define ERR_FILEWRITE				5
#define ERR_PRIVILAGE				6
#define ERR_FILEONLYREAD		7
#define ERR_UNKOWN				8
#define ERR_TRANVERSE			9
#define ERR_PARAM					10

std::string md5_file(const  char *filepath)
{
	int		i, nbytes, ret = 0;
	md5_state_t	state;
	u_char		buf[16 * 1024];
	
	md5_byte_t	hash[MD5_DIGEST_SIZE];
	FILE *fp = NULL;

	if ((fp = fopen(filepath, "rb")) == NULL) {
		return "";
	}

	zbx_md5_init(&state);

	while (0 < (nbytes = (int)fread(buf, 1, sizeof(buf), fp)))
	{
		zbx_md5_append(&state, (const md5_byte_t *)buf, nbytes);
	}

	zbx_md5_finish(&state, hash);

	/* convert MD5 hash to text form */

	char hash_text[33] = { 0 };
	size_t		sz = sizeof(hash_text);

	/*转换成32位hash*/
	for (i = 0; i < MD5_DIGEST_SIZE; i++)
	{
		snprintf(&hash_text[i << 1], sz - (i << 1), "%02x", hash[i]);
	}
	/*转换成16位hash*/
	//for (i = 4, j = 0; i < 12; i++, j++) {
	//	snprintf(&hash_text[j << 1], sz - (j << 1), "%02x", hash[i]);
	//}
	return hash_text;
}

/************************************************************************/
/*   函数功能：计算两个文件夹的文件差异                                               */
/************************************************************************/
int directory_compare(const char *src_path, const char *dest_path)
{
	dirent **src_file_list = NULL, **dest_file_list = NULL;

	int src_file_total = z_scandir(src_path, &src_file_list, NULL, NULL);
	if (src_file_total != -1) {
		int dest_file_total = z_scandir(dest_path, &dest_file_list, NULL, NULL);
		if (dest_file_total != -1) {
			for (int i = 0; i < src_file_total; i++) {
				int add = 1;
				for (int j = 0; j < dest_file_total; j++) {
					//是否存在同名目录
					if (dest_file_list[j] && dest_file_list[j]->d_type == src_file_list[i]->d_type && !strcmp(src_file_list[i]->d_name, dest_file_list[j]->d_name)) {
						
						char temp_path1[256] = { 0 };
						sprintf(temp_path1, "%s\\%s", src_path, src_file_list[i]->d_name);
						char temp_path2[256] = { 0 };
						sprintf(temp_path2, "%s\\%s", dest_path, dest_file_list[j]->d_name);

						if (src_file_list[i]->d_type == 2) {
							directory_compare(temp_path1, temp_path2);
						}
						else if(src_file_list[i]->d_type == 1){
							if (md5_file(temp_path1) != md5_file(temp_path2))
							{
								printf("文件更新%s\n", temp_path1);
							}
						}
						free(dest_file_list[j]);
						dest_file_list[j] = NULL;
						add = 0;
						break;
					}
				}
				if (add) {
					if (src_file_list[i]->d_type == 2) {
						printf("新增目录%s\\%s\n", src_path, src_file_list[i]->d_name);
					}
					else {
						printf("新增文件%s\\%s\n", src_path, src_file_list[i]->d_name);
					}
				}
			}

			for (int j = 0; j < dest_file_total; j++) {
				if (dest_file_list[j]) {
					if (dest_file_list[j]->d_type == 2) {
						printf("删除目录%s\\%s\n", dest_path, dest_file_list[j]->d_name);
					}
					else {
						printf("删除文件%s\\%s\n", dest_path, dest_file_list[j]->d_name);
					}
				}
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	// std::string new_files;
	// std::string old_files;
	// std::cout << "新版本路径" << std::endl;
	// std::cin >> new_files;
	// std::cout << "旧版本路径" << std::endl;
	// std::cin >> old_files;
	// directory_compare(new_files.c_str(), old_files.c_str());

	directory_compare("E:\\test", "E:\\test2");
	return 0;
}