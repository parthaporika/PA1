#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<string.h>

bool isVowel(char x) {
    char vowel[12] = {'A','a','E','e','I','i','O','o','U','u','Y','y'};
    for (int j = 0; j < sizeof(vowel); j++){
        if (x == vowel[j]){
            return true;
        }
    }
    return false;
}
void vowels(char str[], char res[]){
    int cnt = 0;
    for (int i = 0; i < sizeof(str); i++){
        bool add = isVowel(str[i]);
        if (add == true){
            res[cnt++] = str[i];
        }
    }
}

int main(int argc, char* argv[]){
    /*
    char input[] = "Hello World!";
    char res[sizeof(input)] = "";
    printf("%s\n", input);
    vowels(input, res);
    printf("%s\n", res);
    */
    if (argc < 2) {
		printf("error\n");
		return 0;
	}
    /*
    int num = 0;
    int cnt = 0;
    for (int x = 1; x < argc; x++){
        cnt += strlen(argv[x]);
        cnt++;
    }
    cnt--;
    char arr[cnt];
    char vowel[12] = {'A','a','E','e','I','i','O','o','U','u','Y','y'};
    for (int i = 1; i < argc; i++){
        for (int j = 0; j < strlen(argv[i]); j++){
            for (int a = 0; a < sizeof(vowel); a++){
                if (argv[i][j] == vowel[a]){
                    arr[num++] = vowel[a];
                }
            }
        }
    }
    printf("%s", arr);
    */
    int cnt = strlen(argv[1])+1;
    //printf("%d\n", cnt);
    char *str = (char *)malloc(cnt*sizeof(char));
    char *res = (char *)malloc(cnt*sizeof(char));
    strncpy(str, argv[1], cnt);
    //printf("%s\n", str);
    char vowel[12] = {'A','a','E','e','I','i','O','o','U','u'};
    int num = 0;
    for (int j = 0; j < strlen(str); j++){
        for (int i = 0; i < sizeof(vowel); i++){
            if (str[j] == vowel[i]){
                res[num++] = vowel[i];
            }
        }
    }
    //vowels(str, res);
    printf("%s", res);
    free(str);
    free(res);
}