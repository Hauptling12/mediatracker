#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>

int main(int argc, char **argv)
{
    int c;
    char *user = getenv("USER");
    char filename[100] = "/home/";
    char extq[100] = "/.local/share/mediatracker/data.json";
    strncat(filename, user, 100);
    strncat(filename, extq, 100);
    char tv[100];
    char name[100];
    char seasons[100];
    char episode[100];
    char wat[100];
    while ((c = getopt(argc, argv, "halv")) != -1) {
        switch (c) {
        case 'v':
            printf("0.0.3");
            break;
        case 'h':
            printf("-a      add media\n"
                   "-l      list media\n"
                   "-h      display this help\n"
                   "-v      Show version information");
            break;
        case 'l':
            system("cat ~/.local/share/mediatracker/data.json | jtbl");
            break;
        case 'a':
            printf("title: ");
            scanf("%[^\n]%*c",name);
            printf("is it a tv show? y/n: ");
            scanf("%s",tv);
            if (!strcmp(tv, "y")) {
                printf("how many seasons: ");
                scanf("%s",seasons);
                printf("how many episode's:");
                scanf("%s",episode);
            }
            printf("watched yes or no: ");
            scanf("%s",wat);
            json_object *root = json_object_from_file(filename);
            if (!root)
                return 1;
            json_object *paige = json_object_new_object();
            json_object_object_add(paige, "title", json_object_new_string(name));
            json_object_object_add(paige, "tv", json_object_new_string(tv));
            if (!strcmp(tv, "y")) {
                json_object_object_add(paige, "seasons",json_object_new_string(seasons));
                json_object_object_add(paige, "episode",json_object_new_string(episode));
            } else {
                json_object_object_add(paige, "seasons",json_object_new_string("0"));
                json_object_object_add(paige, "episode",json_object_new_string("0"));
            }
            json_object_object_add(paige, "watched",json_object_new_string(wat));
            json_object_array_add(root,paige);
            if (json_object_to_file(filename, root))
                printf("Error: failed to save %s!!\n", filename);
            else
                printf("%s saved.\n", filename);

            json_object_put(root);

        }
    }
    return 0;
}

