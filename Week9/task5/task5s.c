#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAXPATH 256

int list_dir(char *dir, int rec) {
    DIR *dirp;
    char path[MAXPATH];
    struct dirent *direntp;
    struct stat st;

    /* Open the directory */
    dirp = opendir(dir); 
    if (dirp == NULL) {
        perror(dir);
        return -1;
    }

    /* Loop to read directory entries */
    while ((direntp = readdir(dirp)) != NULL) {
        // Construct full path for stat call
        if (snprintf(path, MAXPATH, "%s/%s", dir, direntp->d_name) >= MAXPATH) {
            fprintf(stderr, "Path too long.\n");
            continue;  // Skip this entry if the path is too long
        }

        // Get file/directory information using stat
        if (stat(path, &st) == -1) {
            perror(path);
            continue;  // Skip to next entry if stat fails
        }

        // Skip "." and ".."
        if (strcmp(direntp->d_name, ".") == 0 || strcmp(direntp->d_name, "..") == 0) {
            continue; 
        }

        // Print file information
        printf("%s\t", direntp->d_name); 
        printf("%ld\t", st.st_size);  // File size
        printf("%s", ctime(&st.st_mtime));  // Modification time 
    }

    closedir(dirp); 
    return 0;
}

int main(int argc, char * * argv)
{
	int i = 1, rec = 0;
	
	if (argc > 1) {
		if (strcmp(argv[i], "-r") == 0) {
			rec = 1;
			i++;
		}
	}
		
	while (i < argc) {
		if (list_dir(argv[i], rec) == -1) exit(1);
		i++;
	}
		
	return 0;
}
