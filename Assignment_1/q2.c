#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double distance(int,int,int,int);

int main(void){
    
    int pts[][2] = {{1,2},{3,5},{4,2},{7,4}};
    int size = sizeof(pts)/sizeof(int);

    int x1,y1,x2,y2;
    int rows = sizeof(pts)/sizeof(pts[0]);
    double min = -6969.0;
    
        
    for(int i=0; i<rows; i++){

        for(int j=0; j<rows; j++){

            if(pts[i][0] != pts[j][0] && pts[i][1] != pts[j][1])
            {
                double dist = distance(pts[i][0], pts[i][1], pts[j][0], pts[j][1]);
                if(dist >= min){
                    min = dist;
                    x1 = pts[i][0];
                    y1 = pts[i][1];
                    x2 = pts[j][0];
                    y2 = pts[j][1];
                }
            }
        }
         
    }
    printf("Closest pair of points are:\n");
    printf("(x1,y1) : (%d,%d)\n(x2,y2) : (%d,%d)\n",x1,y1,x2,y2);
    printf("Minimum distance is: %.2f\n",min);
}

double distance(int x1, int y1, int x2, int y2){
        
    return ((x2-x1)^2 + (y2-y1)^2)^(1/2);
}



