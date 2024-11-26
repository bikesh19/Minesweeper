// Libraries Used For This Program
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// Main Function
int main(){
    int random;
    int ran[9]={0,0,0,0,0,0,0,0,0};
    srand(time(0));			//Seeding used for Random Number Generator
    
    //Generate a random number
	random=rand()*rand();
	//Generating unique random numbers for mine placement
    for(int i=0; i<6; i++){
        target:
        for(int j=0;j<=i;j++){
            if(ran[j]==abs(random%10)  || random%10==0 ||abs(random%10)==5){
                random+=999;
                goto target;
            }
        }
        ran[i]=abs(random%10);
        random/=10;
    }
    
    // Hidden Grid
    int hidden[3][3]={
        {0,0,0},
        {0,0,0},
        {0,0,0}};
        
    //Placing mines in the hidden grid based on the random numbers    
    int count=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; ++j){
        count++;
            for(int k=0; k<3; k++){
                if(count==ran[k]){
                    hidden[i][j]=1;
                }
            }
        }
    }
    
    // Initializing the shown grid with all cells hidden('#')
    char shown[3][3]={
        {'#','#','#'},
        {'#','#','#'},
        {'#','#','#'}
	};
	
	
    int bs[3][3]={		//Array to store the neighbouring mines for each cell
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
         
    // Calculating the number of neighbouring mines for each cell
    for(int i=0; i<3;i++){
        for (int j=0; j<3; j++){
            if (hidden[i][j]==0){
                for (int k=i-1; k<=i+1; k++){
                    if (k==3 || k==-1 ){
                        continue;
                    }
                    for(int l=j-1; l<=j+1; l++){
                        if( l==3 || l==-1){
                            continue;
                        }
                        if (i==k && j==l){
                            continue;
                        }
                        if (hidden[k][l]==1){
                            bs[i][j]++;
                        }
                    }
                }
            }
        }
    }
    
    for(int i=3; i<6; i++){
        int count=0;
        for(int j=0; j<3; j++){
            for (int k=0; k<3; k++){
                count++;
                if(count==ran[i]){
                    if(bs[j][k]==0){
                        shown[j][k]='0';
                    }
                    if (bs[j][k]==1){
                        shown[j][k]='1';
                    }
                    if (bs[j][k]==2){
                        shown[j][k]='2';
                    }
                    if (bs[j][k]==3){
                        shown[j][k]='3';
                    }
                }
            }
        }
    }
    
    // Displaying the initial hidden grid with number of mines
    printf("\n");
    for(int i=0; i<3;i++){
        for (int j=0; j<3; j++){
            printf("%c\t",shown[i][j]);
        }
        printf("\n");
    }
    int mine=0;
    for(int t=0; ;t++){
        int gm=1;
        int loc;
        inp:
        printf("ENTER LOCATION CONTAINING NO MINE(1-9)\n");
        scanf("%d",&loc);
        
        // Input Validation for location
        if(loc>9 || loc<1){
            printf("invalid number\n");
            goto inp;
        }
        
        // Checking for repeated input
        for(int l=3; l<9; l++){
            if (ran[l]==loc){
                printf("repeated number\n");
                goto inp;
            }
        }
        
        // Processing the selected location
        ran[6+t]=loc;
        count=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                count++;
                if(count==loc){
                    if(hidden[i][j]==1){
                        printf("\nYOU LOST !! (you detonated a mine)\n\n");
                        gm=0;
                        break;
                    }
                    else{
                        mine++;
                        if (bs[i][j]==0){
                            shown[i][j]='0';
                        }
                        if (bs[i][j]==1){
                            shown[i][j]='1';
                        }
                        if (bs[i][j]==2){
                            shown[i][j]='2';
                        }
                        if (bs[i][j]==3){
                            shown[i][j]='3';
                        }
                        if(mine==3){
                            printf("\nYOU WIN !! (you uncovered all the mine)\n\n");
                            gm=0;
                            break;
                       }
                    }
                }
            }
            if(gm==0){
                break;
            }
        }
        if (gm==0){
            break;
        }
        for(int i=0; i<3;i++){
            for (int j=0; j<3; j++){
                printf("%c\t",shown[i][j]);
            }
            printf("\n");      
        }
    }
}
