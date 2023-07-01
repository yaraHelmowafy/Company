// YARA HESHAM ELMOWAFY 19100910
#include<stdio.h>
void print_menu();
void add_branch(float company[60][12]);
void print_Matrix(float company[60][12]);
void delete_branch(float company[60][12]);
void Total_sales(float company[60][12]);
void perce(float company[60][12]);
void peakM(float company[60][12]);
void bubbleST(float company[60][12],int *rows,int n);
void selection_sort(float company [60][12],int rows,int n);
int main (){
	 int rows,i,j,n;
	float company[60][12]={0};
	 printf("Enter num of branches: ");
    scanf("%d",&rows);

    for( i=0; i<rows; i++)
        for( j=0; j<12; j++){
        printf("Enter sales data of branch %d month %d : ",i+1,j+1);
            scanf("%f",&company[i][j]);
        }

    for( i=0; i<rows; i++)
	{printf("branch %d: ",i+1);
        for(j=0; j<12; j++)
            printf("%.2f\t",company[i][j]);
        printf("\n");
    }
    
int user_input =200;
while(user_input!=0){
 print_menu();
 printf("The user input: ");
 scanf("%d",&user_input);
switch(user_input){
  case 1:
   add_branch(company);
   printf("branch added.\n");
   printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
   print_Matrix(company);
   break;
  
  case 2: delete_branch(company);
                break;
   case 3:	Total_sales(company);
    	        break;
   case 4: perce(company);
    		    break;
   case 5: peakM(company) ;
                break;
   case 6: printf("enter number of month: ");
                scanf("%d",&n);
                bubbleST(company,&rows,n-1);
                break;

  case 7: printf("enter number of branch: ");
                scanf("%d",&n);
                selection_sort(company,rows,n-1);
                break;
   case 8: print_Matrix(company);   
                break;
   case 0:printf("The program was ended : Thank You ")		;		           
                 break;
}
}
return 0;
}
void print_menu(){
    printf("\nThis is the program's menu :\n ");
    printf("--------------------------------\n");
	printf("(1) Add a record for a new branch\n");
	printf("(2) Delete record of an existing branch\n");
	printf("(3) Calculate total sales\n");
	printf("(4) Calculate percentage share of each branch\n");
	printf("(5) Determine the month of the peak sales\n");
	printf("(6) Display sales of a specific month\n");
	printf("(7) Display sales of a specific branch\n");
    printf("(8)to print The Matrix\n");
    printf("(0)to quit\n");
    printf("\n------------------------------------- \n");
}
void add_branch(float company[60][12]){
  int i,j, new_row ;
  for(i=60;i>=0;i--){
    if(company[i][0]==0.0){
      new_row=i;
    }
  }
 for(j=0;j<12;j++){
   printf("Enter The sales data for month %d ",j+1);
   scanf("%f",&company[new_row][j]);
 }
}
void print_Matrix(float company[60][12]){
  printf("++++++++++++++++++++++++++++++\n");
   int i,j;
   for(i=0;i<60;i++){
      for(j=0;j<12;j++){
      	if(company[i][j]!=0){
          printf("%.2f  ",company[i][j]);
          if(j==11)
          printf("\n");
    }
      }
   }
   printf("++++++++++++++++++++++++++++++\n");
}
void delete_branch(float company[60][12]){
    int c,num;
printf("Enter The Number of The Branch");
scanf("%d",&num);
for(c=0;c<12;c++){
company[num-1][c]=0;

}
print_Matrix(company);
}
void Total_sales(float company[60][12]){
	int i,j;
	float  total=0;
	for(i=0;i<60;i++){
		for (j=0;j<12;j++){
			total+=company[i][j];
		}
	}
	printf("Total sales of the company is : %.3f \n",total);
	printf("-------------------------------------------\n");
}
void perce(float company[60][12]){
 int c,b;
 float perc,sum;
 	int i,j;
 	float  total=0;
	for(i=0;i<60;i++){
		for (j=0;j<12;j++){
			total+=company[i][j];
		}
	}
 for(c=0;c<60;c++){
 	for(b=0;b <12;b++){
 		sum+=company[c][b];


 	}perc=(sum/total)*100;
 	sum=0;
 	   if(company[c][0]!=0)
 		printf("Branch %d Shares : %.3f%% \n",c+1,perc);

 }
 printf("--------------------------------------------\n");
}

void peakM(float company[60][12])
{
    int k,v,flag;
	float M_SUM=0,maxi= -99999999999;
    for(v=0;v<12;v++){
        for(k=0;k<60;k++){
            M_SUM+=company[k][v];
        }
        if(M_SUM > maxi){
        	maxi=M_SUM;
        	flag=v;
        	
        }
        

	    M_SUM =0;
	}
    printf("Month %d has the peak sales of = %.3f\n",flag+1,maxi);
}
void bubbleST(float company[60][12],int *rows,int n)
{
	int i,j;
    float companycp[60][12];
    for(i=0; i<*rows; i++)
        for( j=0; j<12; j++)
            companycp[i][j] = company[i][j];

    for( i=0; i<*rows-1; i++)
    {
        for(j=0; j<*rows-i-1; j++)
        {
            if(companycp[j][n] < companycp[j+1][n])
            {
                float temp = companycp[j][n];
                companycp[j][n]= companycp[j+1][n];
                companycp[j+1][n]= temp;
            }
        }
}
    for(i=0; i<*rows; i++)
        printf("branch %d : %.3f\n",i+1,companycp[i][n]);

}


void selection_sort(float company [60][12],int rows,int n)
{
	int m,z;
    int ind;
	float swap;
    float companycp[60][12];
    for( m=0; m<rows; m++)
        for(z=0; z<12; z++)
        companycp[m][z] = company[m][z];

    for (m= 0; m < 11; m++)
    { 
    
        ind = m;
        for ( z = m+1; z < 12; z++)
            if (companycp[n][z] > companycp[n][ind])
                ind = z;
               
        swap = companycp[n][ind];
        companycp[n][ind]= companycp[n][m];
        companycp[n][m]= swap;
    }

    for(m=0; m<12; m++)
        printf("month %d : %.3f\n",m+1,companycp[n][m]);
}

