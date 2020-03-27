#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<string.h>

void matmulti(int **mat1, int **mat2, int **res, int mat1col, int mat1row, int mat2col){
    int temp = 0;
    //int res1col = 0;
    //int res1row = 0;
    for (int i = 0; i < mat1row; i++){
        for(int k = 0; k < mat2col; k++){
            for (int j = 0; j < mat1col; j++){
                temp += mat1[i][j] * mat2[j][k];
            }
            res[i][k] = temp;
            temp = 0;
            //printf("%d  ", res[i][k]);
        }
    }
}

void printmat(int **mat, int matrow, int matcol){
    for (int a = 0; a < matrow; a++){
        for (int b = 0; b < matcol; b++){
            printf("%d", mat[a][b]);
            if (b+1 == matcol){
                continue;
            }
            printf("\t");
        }
        if (a+1 == matrow){
            continue;
        }
        printf("\n");
    } 
}

int main(int argc, char** argv){
    /*
    int mat1row = 2;
    int mat1col = 3;
    int mat1[2][3] = {{1, 2, 3},
                      {4, 5, 6}};
    int mat2row = 3;
    int mat2col = 2;
    int mat2[3][2] = {{1, 2},
                      {3, 4},
                      {5, 6}};
    int res[2][2];
    matmulti(mat1, mat2, res, mat1col, mat1row);
    printf("Matrix 1:\n");
    printmat(mat1, mat1row, mat1col);
    printf("\nMatrix 2:\n");
    printmat(mat2, mat2row, mat2col);
    printf("\nProduct Matrix:\n");
    matmulti(mat1, mat2, res, mat1col, mat1row);
    printmat(res, mat1row, mat2col);
    */
    if (argc < 2) {
		printf("error\n");
		return 0;
	}    
    FILE *fp = fopen(argv[1], "r");
    int mat1col, mat1row, mat2col, mat2row;
    fscanf(fp,"%d\t%d\n", &mat1row, &mat1col);
    int **mat1 = (int **) malloc(mat1row*mat1col*1000*sizeof(int));
    for (int x = 0; x < mat1row; x++){
        mat1[x] = (int*) malloc(mat1col*sizeof(int));
    }
    for (int i = 0; i < mat1row; i++){
        for (int j = 0; j < mat1col; j++){
            fscanf(fp,"%d", &mat1[i][j]);
        }
        fscanf(fp,"\n");
    }
    fscanf(fp,"%d\t%d\n", &mat2row, &mat2col);
    if (mat1col != mat2row){
        printf("bad-matrices");
        for (int d = 0; d < mat1row; d++){
            free(mat1[d]);
        }
        free(mat1);
        return 0;
    }
    int **mat2 = (int **) malloc(mat2row*mat2col*1000*sizeof(int));
    for (int y = 0; y < mat2row; y++){
        mat2[y] = (int *) malloc(mat2col*sizeof(int));
    }
    for (int a = 0; a < mat2row; a++){
        for (int b = 0; b < mat2col; b++){
            fscanf(fp,"%d", &mat2[a][b]);
        }
        if (a+1 < mat2row){
            continue;
        }
        fscanf(fp,"\n");
    }
    fclose(fp);
    int **res = (int **) malloc(mat1row*mat2col*1000*sizeof(int));
    for (int c = 0; c < mat1row; c++){
        res[c] = (int *) malloc(mat2col*sizeof(int));
    }
    /*
    printf("Matrix 1:\n");
    printmat(mat1, mat1row, mat1col);
    printf("Matrix 2:\n");
    printmat(mat2, mat2row, mat2col);
    printf("Product Matrix:\n");
    */
    matmulti(mat1, mat2, res, mat1col, mat1row, mat2col);
    printmat(res, mat1row, mat2col);
    for (int d = 0; d < mat1row; d++){
        free(mat1[d]);
        // free(res[d]);
    }
    free(mat1);
    for (int e = 0; e < mat2row; e++){
        free(mat2[e]);
    }
    free(mat2);
     for (int d = 0; d < mat1row; d++){
        // free(mat1[d]);
        free(res[d]);
    }
    free(res);

    return 0;
}
