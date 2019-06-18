# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
/*
int dirlen(t_elem *ptr,)
{

}*/

int 	block(char *str)
{
	//DIR *dir;
	int ret;
//	struct dirent *dirent;
	struct stat		sb;

	ret = 0;
	if (lstat(str,&sb) == -1)
		ret = -1;
	else
		ret += sb.st_blocks;
	return(ret);
}

void 	print_block(char *dir)
{
	int ret;
	//struct stat  sb;

	ret = block(dir);
	//lstat(dir,&sb);
	printf("total %d", ret);
}

int main(int ac, char **av)
{
	struct stat sb;

	//lstat(av[1],&sb);
	if (ac == 1)
	{
		lstat(".",&sb);
		print_block("/");
	}
	else
	{
		lstat(av[1],&sb);
		print_block(av[1]);
	}
		//printf("%lld",sb->st_blocks);
	/*{
		printf("Taille de bloc d’E/S : %ld octets\n",
            (long) sb.st_blksize);
    	printf("Taille du fichier : %lld octets\n",
            (long long) sb.st_size);
    	printf("Blocs alloués : %lld\n",
            (long long) sb.st_blocks);
	}*/
	return(0);
}

/*
stats = malloc(sizeof(struct stat));
if (lstat(dir, stats) == -1)
	ret = -1;
else
	ret = stats->st_mtime;
free(stats);
return(ret);

int main(int ac, char **av)
{
	//time_t *mtime;
	//struct stat *buf;

	//stat(av[1], &buf);
	if (ac > 1)
		printf("%ld", get_timestamp(av[1]));
		//stat(av[1], &buf);
	//mtime = &buf.st_mtimespec.tv_sec;
	//printf("%ld",(&(*ptr)->buf)->st_mtimespec.tv_sec);

	//printf("%s", asctime(localtime(&buf.st_mtime)));
	return (0);
}*/
