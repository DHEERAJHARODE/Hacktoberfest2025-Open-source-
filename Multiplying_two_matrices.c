#include <stdio.h>
int main()
{
int row,col,prod,col2;
scanf("%d %d",&row,&col);
int x[row][col];
printf("Enter Dimension of other matrix: %d*__",col); scanf("%d",&col2);
int a[col][col2];
int b[row][col2];
printf("Enter Matrix\n");
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++) {
scanf("%d",&x[i][ j]); }
}
printf("Enter Second matrix\n"); for(int i=0;i<col;i++)
{
for(int j=0;j<col2;j++) 
{
    scanf("%d",&a[i][ j]); }
}
for(int i=0;i<row;i++) {
for(int j=0;j<col2;j++) {
prod=0;
for(int k=0;k<col;k++) {
prod+=x[i][k]*a[k][ j]; }
b[i][ j]=prod; }
}
for(int i=0;i<row;i++) {
printf("\n");
for(int j=0;j<col2;j++) {
printf("%d ",b[i][j]); }
} }