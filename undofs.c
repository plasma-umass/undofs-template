#define FUSE_USE_VERSION 30

#include <fuse.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

static const char* underlying_dir_path = "~/undofs/undofs-filedata/";

static int do_getattr(const char *path, struct stat *st, struct fuse_file_info *fi)
{
	//Set a few attributes of the path
	st->st_uid = getuid();
	st->st_gid = getgid(); 
	st->st_atime = time(NULL);
	st->st_mtime = time(NULL);
	
	if (strcmp(path, "/") == 0)
	{
		st->st_mode = S_IFDIR | 0755;
	}
	else
	{
		st->st_mode = S_IFREG | 0644;
		st->st_size = 1024;
	}
	
	return 0;
}

static int do_readdir(const char *path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi, enum fuse_readdir_flags flags)
{	
	filler(buffer, ".", NULL, 0, 0); // Current Directory
	filler(buffer, "..", NULL, 0, 0); // Parent Directory
	
	if (strcmp(path, "/") == 0) //Root of the filesystem
	{
		filler(buffer, "file1", NULL, 0, 0);
	}
	
	return 0;
}

static int do_read(const char *path, char *buffer, size_t size, off_t offset, struct fuse_file_info *fi)
{
	char underlying_path[256];
	strcpy(underlying_path, underlying_dir_path);
	strcat(underlying_path, "file1"); //Assuming path is <undofs-mount-point>/file1.
	printf("underlying_path %s\n", underlying_path);
	//Read file1 from underlying file system
	int fd = open(underlying_path, O_RDONLY);
	//Assume offset is zero
	int ret = read(fd, buffer, size);
	close(fd);
		
	return ret;
}

static struct fuse_operations operations = {
    .getattr	= do_getattr,
    .readdir	= do_readdir,
    .read		= do_read,
};

int main(int argc, char *argv[])
{
	return fuse_main(argc, argv, &operations, NULL);
}
